//C++lib includes
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "json/json.h"
#include "json/json-forwards.h"

//Root includes
#include "TRandom.h"
#include "TFile.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TMath.h"
#include "TVector3.h"

//Project includes
#include "Particle.hxx"
#include "CustomRand.hxx"
#include "ScatteredParticleGen.hxx"
#include "ProductGen.hxx"
#include "TreeBuilder.hxx"
#include "Constants.hxx"
#include "DEMPEvent.hxx"
#include "SigmaCalc.hxx"
#include "TargetGen.hxx"
#include "MatterEffects.hxx"

using namespace std;
using namespace constants;

TFile * WorkFile;

Json::Value obj; //Declared here for global access


int main(){

  ifstream ifs("../Config.json");
  Json::Reader reader;
  reader.parse(ifs, obj);

  if (obj["ionization"].asBool())
    cout << "Ionization Enabled" << endl;
  if (obj["bremsstrahlung"].asBool())
    cout << "Bremsstrahlung Enabled" << endl;
  if (obj["fermi_momentum"].asBool())
    cout << "Fermi Momentum Enabled" << endl;
  if (obj["multiple_scattering"].asBool())
    cout << "Multiple Scattering Enabled" << endl;


  MatterEffects* ME = new MatterEffects();


  int nEvents = obj["n_events"].asInt();

  WorkFile = new TFile("../data/output/test.root");


  DEMPEvent* VertEvent = new DEMPEvent("Vert");
  DEMPEvent* RestEvent = new DEMPEvent("RF");
  DEMPEvent* CofMEvent = new DEMPEvent("CofM");
  DEMPEvent* TConEvent = new DEMPEvent("TCon"); //Following Trento Conventions.
  DEMPEvent* LCorEvent = new DEMPEvent("Lab"); //Lab frame with corrections applied
  SigmaCalc* Sig = new SigmaCalc(VertEvent, CofMEvent, RestEvent, TConEvent);


  Particle* VertBeamElec = VertEvent->BeamElec;
  Particle* VertTargNeut = VertEvent->TargNeut;
  Particle* VertScatElec = VertEvent->ScatElec;
  Particle* VertProdPion = VertEvent->ProdPion;
  Particle* VertProdProt = VertEvent->ProdProt;
  Particle* Photon = VertEvent->VirtPhot;

  VertBeamElec->SetThetaPhiE(0, 0, obj["beam_energy"].asDouble());

  double elecERange[2] = {obj["scat_elec_Emin"].asDouble(),
                          obj["scat_elec_Emax"].asDouble()};
  double elecThetaRange[2] = {obj["scat_elec_thetamin"].asDouble()/DEG,
                              obj["scat_elec_thetamax"].asDouble()/DEG};
  double elecPhiRange[2] = {0, 360/DEG};

  TargetGen * NeutGen = new TargetGen(neutron_mass_mev, obj["fermi_momentum"].asBool());

  ScatteredParticleGen * ElecGen =
    new ScatteredParticleGen(electron_mass_mev,
                             elecERange,
                             elecThetaRange,
                             elecPhiRange);

  /*
    Particle * Photon = new Particle();
    VertEvent->VirtPhot = Photon;
  */


  ProductGen * ProtonPionGen = new ProductGen(Photon,
                                              VertTargNeut);

  int nSuccess = 0;
  int nFail = 0;
  int nNeg = 0;

  int event_status = 0;

  TreeBuilder * Output = new TreeBuilder("Output");

  Output->AddEvent(VertEvent);
  //Output->AddEvent(CofMEvent);
  //Output->AddEvent(RestEvent);
  Output->AddEvent(LCorEvent);

  double sigma_l;
  double sigma_t;
  double sigma_tt;
  double sigma_lt;

  double sigma_uu;
  double sigma_ut;

  double sigma_k0;
  double sigma_k1;
  double sigma_k2;
  double sigma_k3;
  double sigma_k4;

  double sigma_k5 = 0;

  double sigma;

  double weight;
  double epsilon;

  double vertexX, vertexY, vertexZ;
  double targetthickness, airthickness, targwindowthickness;

  Output -> AddDouble(&sigma_l,"sigma_l");
  Output -> AddDouble(&sigma_t,"sigma_t");
  Output -> AddDouble(&sigma_tt,"sigma_tt");
  Output -> AddDouble(&sigma_lt,"sigma_lt");
  Output -> AddDouble(&sigma_uu,"sigma_uu");
  Output -> AddDouble(&sigma_ut,"sigma_ut");

  Output -> AddDouble(&sigma_k0,"sigma_k0");
  Output -> AddDouble(&sigma_k1,"sigma_k1");
  Output -> AddDouble(&sigma_k2,"sigma_k2");
  Output -> AddDouble(&sigma_k3,"sigma_k3");
  Output -> AddDouble(&sigma_k4,"sigma_k4");
  Output -> AddDouble(&sigma_k5,"sigma_k5");

  Output -> AddDouble(&sigma, "sigma");

  Output -> AddDouble(&weight,"weight");
  Output -> AddDouble(&epsilon, "epsilon");

  cout << "Starting Main Loop." << endl;

  for (int i=0; i<nEvents; i++){

    if (i%100 == 0)
      cout <<"\r"<< (double)i/nEvents * 100 << "%";
    *VertTargNeut = *NeutGen->GetParticle();
    *VertScatElec = *ElecGen->GetParticle();
    *Photon = *VertBeamElec - *VertScatElec;

    event_status = ProtonPionGen->Solve();
    if (event_status == 0)
      nSuccess ++;
    if (event_status == 1){
      nFail ++;
      continue;
    }
    *VertProdPion = *ProtonPionGen->ProdPion();
    *VertProdProt = *ProtonPionGen->ProdProton();
    //    cout<<VertProdPion->GetPid() << endl;


    VertEvent->Update();

    *CofMEvent = *VertEvent;
    CofMEvent->Boost(-VertEvent->CoM());
    CofMEvent->Update();

    *RestEvent = *VertEvent;
    RestEvent->Boost(-(VertEvent->TargNeut->Vect()*(1/VertEvent->TargNeut->E())));
    RestEvent->Update();

    *LCorEvent = *VertEvent;
    LCorEvent->Update();

    sigma_l = Sig->sigma_l();
    sigma_t = Sig->sigma_t();
    sigma_lt = Sig->sigma_lt();
    sigma_tt = Sig->sigma_tt();
    sigma_uu = Sig->sigma_uu();
    sigma_ut = Sig->sigma_ut();

    sigma_k0 = Sig->Sigma_k(0);
    sigma_k1 = Sig->Sigma_k(1);
    sigma_k2 = Sig->Sigma_k(2);
    sigma_k3 = Sig->Sigma_k(3);
    sigma_k4 = Sig->Sigma_k(4);

    sigma = Sig->sigma();

    if (sigma<0) nNeg ++;
    //if (sigma<0) continue;

    weight = Sig->weight(nEvents);

    *VertEvent->Vertex_x = gRandom->Uniform(-0.25, 0.25);
    *VertEvent->Vertex_y = gRandom->Uniform(-0.25,0.25);
    *VertEvent->Vertex_z = gRandom->Uniform(-370,-330);


    //Matter Effects~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    targetthickness = ((-330.0 - *VertEvent->Vertex_z) * Helium_Density)/
      (ME->X0(Helium_Z, Helium_A));
    // Assuming path along z only inside the target.

    targwindowthickness = 0.0120*Window_Density / Window_Thickness;

    //cout << targetthickness << endl;

    if (obj["ionization"].asBool()){

      //Scattered Electron
      ME->IonLoss(LCorEvent->ScatElec, Window_A, Window_Z,
                  Window_Density, targwindowthickness);
      ME->IonLoss(LCorEvent->ScatElec, Helium_A, Helium_Z,
                  Helium_Density, targetthickness);
      airthickness = 450 * Air_Density;
      if (LCorEvent->ScatElec->Theta() < 16) // Large Angle
        airthickness = 950 * Air_Density;
      ME->IonLoss(LCorEvent->ScatElec, Air_A, Air_Z,
                  Air_Density, airthickness);

      //Proton
      airthickness = 450 * Air_Density;
      if (LCorEvent->ProdProt->Theta() < 16) // Large Angle
        airthickness = 950 * Air_Density;

      ME->IonLoss(LCorEvent->ProdProt, Helium_A, Helium_Z,
                  Helium_Density, targetthickness);

      ME->IonLoss(LCorEvent->ProdProt, Window_A, Window_Z,
                  Window_Density, targwindowthickness);

      ME->IonLoss(LCorEvent->ProdProt, Air_A, Air_Z,
                  Air_Density, airthickness);

      //Pion
      airthickness = 450 * Air_Density;
      if (LCorEvent->ProdPion->Theta() < 16) // Large Angle
        airthickness = 950 * Air_Density;

      ME->IonLoss(LCorEvent->ProdPion, Helium_A, Helium_Z,
                  Helium_Density, targetthickness);

      ME->IonLoss(LCorEvent->ProdPion, Window_A, Window_Z,
                  Window_Density, targwindowthickness);

      ME->IonLoss(LCorEvent->ProdPion, Air_A, Air_Z,
                  Air_Density, airthickness);

    }

    if (obj["bremsstrahlung"].asBool()){

      //Scattered Electron
      ME->BremLoss(LCorEvent->ScatElec,
                   targetthickness*ME->b(Helium_Z)
                   /ME->X0(Helium_Z, Helium_A));
      ME->BremLoss(LCorEvent->ScatElec,
                   targwindowthickness*ME->b(Window_Z)
                   /ME->X0(Window_Z, Window_A));
      airthickness = 450 * Air_Density / ME->X0(Air_Z, Air_A);
      if (LCorEvent->ScatElec->Theta() < 16) // Large Angle
        airthickness = 950 * Air_Density / ME->X0(Air_Z, Air_A);
      ME->BremLoss(LCorEvent->ScatElec, airthickness*ME->b(Air_Z));

    }

    if (obj["multiple_scattering"].asBool()){
      //Scattered Electron
      ME->MultiScatter(LCorEvent->ScatElec,
                       targetthickness / ME->X0(Helium_Z, Helium_A));
      ME->MultiScatter(LCorEvent->ScatElec,
                       targwindowthickness / ME->X0(Window_Z, Window_A));
      airthickness = 450 * Air_Density / ME->X0(Air_Z,Air_A);
      if (LCorEvent->ScatElec->Theta() < 16) // Large Angle
        airthickness = 950 * Air_Density / ME->X0(Air_Z,Air_A);
      ME->MultiScatter(LCorEvent->ScatElec, airthickness);

      //Proton
      ME->MultiScatter(LCorEvent->ProdProt,
                       targetthickness / ME->X0(Helium_Z, Helium_A));
      ME->MultiScatter(LCorEvent->ProdProt,
                       targwindowthickness / ME->X0(Window_Z, Window_A));
      airthickness = 450 * Air_Density / ME->X0(Air_Z,Air_A);
      if (LCorEvent->ProdProt->Theta() < 16) // Large Angle
        airthickness = 950 * Air_Density / ME->X0(Air_Z,Air_A);
      ME->MultiScatter(LCorEvent->ProdProt, airthickness);

      //Pion
      ME->MultiScatter(LCorEvent->ProdPion,
                       targetthickness / ME->X0(Helium_Z, Helium_A));
      ME->MultiScatter(LCorEvent->ProdPion,
                       targwindowthickness / ME->X0(Window_Z, Window_A));
      airthickness = 450 * Air_Density / ME->X0(Air_Z,Air_A);
      if (LCorEvent->ProdPion->Theta() < 16) // Large Angle
        airthickness = 950 * Air_Density / ME->X0(Air_Z,Air_A);
      ME->MultiScatter(LCorEvent->ProdPion, airthickness);




    }



    Output->Fill();
  }
  cout << endl;

  if (nSuccess>0)
    Output->Save();

  cout << "Successful Events: \t" << nSuccess << endl;
  cout << "Failed Events: \t\t" << nFail << endl;
  cout << "Negative Events: \t\t" << nNeg << endl;




























  // Debug/Checks:

  if(nEvents == -1){

    TFile * Check = new TFile("../data/input/DEMP_Ee_11_Events_100000_File_0.root");
    TTree * t1 = (TTree*)Check->Get("t1");

    cout << "Running Debug/Check Values" << endl;

    Double_t Epsilon, Qsq_GeV, T_GeV, W_GeV, x, y, z, WSq_GeV, EventWeight, PhaseShiftWeight, PhaseSpaceWeight;
    Double_t Qsq_Corrected_GeV, T_Corrected_GeV, W_Corrected_GeV;

    double WilliamsWeight, DedrickWeight, CatchenWeight;

    Double_t ScatElec_Energy_Col_GeV,ScatElec_MomX_Col_GeV,ScatElec_MomY_Col_GeV,ScatElec_MomZ_Col_GeV,ScatElec_Mom_Col_GeV;
    Double_t ScatElec_Phi_Col,ScatElec_Theta_Col;

    Double_t ScatElec_Corrected_Energy_Col_GeV,ScatElec_Corrected_MomX_Col_GeV,ScatElec_Corrected_MomY_Col_GeV,ScatElec_Corrected_MomZ_Col_GeV,ScatElec_Corrected_Mom_Col_GeV;
    Double_t ScatElec_Corrected_Phi_Col,ScatElec_Corrected_Theta_Col;

    Double_t Pion_FSI_Energy_Col_GeV,Pion_FSI_MomX_Col_GeV,Pion_FSI_MomY_Col_GeV,Pion_FSI_MomZ_Col_GeV, Pion_FSI_Mom_Col_GeV;
    Double_t Pion_FSI_Phi_Col, Pion_FSI_Theta_Col;

    Double_t Pion_Energy_Col_GeV,Pion_MomX_Col_GeV,Pion_MomY_Col_GeV,Pion_MomZ_Col_GeV, Pion_Mom_Col_GeV;
    Double_t Pion_Phi_Col, Pion_Theta_Col;

    Double_t Pion_Corrected_Energy_Col_GeV,Pion_Corrected_MomX_Col_GeV,Pion_Corrected_MomY_Col_GeV,Pion_Corrected_MomZ_Col_GeV, Pion_Corrected_Mom_Col_GeV;
    Double_t Pion_Corrected_Phi_Col, Pion_Corrected_Theta_Col;

    Double_t RecoilProton_Energy_Col_GeV, RecoilProton_MomX_Col_GeV, RecoilProton_MomY_Col_GeV, RecoilProton_MomZ_Col_GeV, RecoilProton_Mom_Col_GeV;
    Double_t RecoilProton_Phi_Col, RecoilProton_Theta_Col;

    Double_t RecoilProton_Corrected_Energy_Col_GeV, RecoilProton_Corrected_MomX_Col_GeV, RecoilProton_Corrected_MomY_Col_GeV, RecoilProton_Corrected_MomZ_Col_GeV;
    Double_t RecoilProton_Corrected_Phi_Col, RecoilProton_Corrected_Theta_Col, RecoilProton_Corrected_Mom_Col_GeV;

    Double_t AsymPhiMinusPhi_S, AsymPhi_S, Asym2PhiMinusPhi_S, AsymPhiPlusPhi_S, Asym3PhiMinusPhi_S, Asym2PhiPlusPhi_S;

    double T_Para_GeV, T_Prime_GeV;

    t1->SetBranchAddress("Epsilon", &Epsilon );
    t1->SetBranchAddress("Qsq_GeV", &Qsq_GeV );
    t1->SetBranchAddress("T_GeV", &T_GeV );
    t1->SetBranchAddress("W_GeV", &W_GeV );
    t1->SetBranchAddress("T_Para_GeV", &T_Para_GeV);
    t1->SetBranchAddress("T_Prime_GeV", &T_Prime_GeV);

    t1->SetBranchAddress("Qsq_Corrected_GeV", &Qsq_Corrected_GeV );
    t1->SetBranchAddress("T_Corrected_GeV", &T_Corrected_GeV );
    t1->SetBranchAddress("W_Corrected_GeV", &W_Corrected_GeV );

    t1->SetBranchAddress("ScatElec_Energy_Col_GeV", &ScatElec_Energy_Col_GeV );
    t1->SetBranchAddress("ScatElec_MomX_Col_GeV", &ScatElec_MomX_Col_GeV );
    t1->SetBranchAddress("ScatElec_MomY_Col_GeV", &ScatElec_MomY_Col_GeV );
    t1->SetBranchAddress("ScatElec_MomZ_Col_GeV", &ScatElec_MomZ_Col_GeV );
    t1->SetBranchAddress("ScatElec_Mom_Col_GeV", &ScatElec_Mom_Col_GeV );
    t1->SetBranchAddress("ScatElec_Theta_Col", &ScatElec_Theta_Col );
    t1->SetBranchAddress("ScatElec_Phi_Col", &ScatElec_Phi_Col );

    t1->SetBranchAddress("ScatElec_Corrected_Energy_Col_GeV", &ScatElec_Corrected_Energy_Col_GeV );
    t1->SetBranchAddress("ScatElec_Corrected_MomX_Col_GeV", &ScatElec_Corrected_MomX_Col_GeV );
    t1->SetBranchAddress("ScatElec_Corrected_MomY_Col_GeV", &ScatElec_Corrected_MomY_Col_GeV );
    t1->SetBranchAddress("ScatElec_Corrected_MomZ_Col_GeV", &ScatElec_Corrected_MomZ_Col_GeV );
    t1->SetBranchAddress("ScatElec_Corrected_Mom_Col_GeV", &ScatElec_Corrected_Mom_Col_GeV );
    t1->SetBranchAddress("ScatElec_Corrected_Theta_Col", &ScatElec_Corrected_Theta_Col );
    t1->SetBranchAddress("ScatElec_Corrected_Phi_Col", &ScatElec_Corrected_Phi_Col );

    // t1->SetBranchAddress("Pion_FSI_Energy_Col_GeV", &Pion_FSI_Energy_Col_GeV );
    // t1->SetBranchAddress("Pion_FSI_MomX_Col_GeV", &Pion_FSI_MomX_Col_GeV );
    // t1->SetBranchAddress("Pion_FSI_MomY_Col_GeV", &Pion_FSI_MomY_Col_GeV );
    // t1->SetBranchAddress("Pion_FSI_MomZ_Col_GeV", &Pion_FSI_MomZ_Col_GeV );
    // t1->SetBranchAddress("Pion_FSI_Mom_Col_GeV", &Pion_FSI_Mom_Col_GeV );
    // t1->SetBranchAddress("Pion_FSI_Theta_Col", &Pion_FSI_Theta_Col );
    // t1->SetBranchAddress("Pion_FSI_Phi_Col", &Pion_FSI_Phi_Col );

    t1->SetBranchAddress("Pion_Energy_Col_GeV", &Pion_Energy_Col_GeV );
    t1->SetBranchAddress("Pion_MomX_Col_GeV", &Pion_MomX_Col_GeV );
    t1->SetBranchAddress("Pion_MomY_Col_GeV", &Pion_MomY_Col_GeV );
    t1->SetBranchAddress("Pion_MomZ_Col_GeV", &Pion_MomZ_Col_GeV );
    t1->SetBranchAddress("Pion_Mom_Col_GeV", &Pion_Mom_Col_GeV );
    t1->SetBranchAddress("Pion_Theta_Col", &Pion_Theta_Col );
    t1->SetBranchAddress("Pion_Phi_Col", &Pion_Phi_Col );

    t1->SetBranchAddress("Pion_Corrected_Energy_Col_GeV", &Pion_Corrected_Energy_Col_GeV );
    t1->SetBranchAddress("Pion_Corrected_MomX_Col_GeV", &Pion_Corrected_MomX_Col_GeV );
    t1->SetBranchAddress("Pion_Corrected_MomY_Col_GeV", &Pion_Corrected_MomY_Col_GeV );
    t1->SetBranchAddress("Pion_Corrected_MomZ_Col_GeV", &Pion_Corrected_MomZ_Col_GeV );
    t1->SetBranchAddress("Pion_Corrected_Mom_Col_GeV", &Pion_Corrected_Mom_Col_GeV );
    t1->SetBranchAddress("Pion_Corrected_Theta_Col", &Pion_Corrected_Theta_Col );
    t1->SetBranchAddress("Pion_Corrected_Phi_Col", &Pion_Corrected_Phi_Col );

    t1->SetBranchAddress("RecoilProton_Energy_Col_GeV", &RecoilProton_Energy_Col_GeV );
    t1->SetBranchAddress("RecoilProton_MomX_Col_GeV", &RecoilProton_MomX_Col_GeV );
    t1->SetBranchAddress("RecoilProton_MomY_Col_GeV", &RecoilProton_MomY_Col_GeV );
    t1->SetBranchAddress("RecoilProton_MomZ_Col_GeV", &RecoilProton_MomZ_Col_GeV );
    t1->SetBranchAddress("RecoilProton_Mom_Col_GeV", &RecoilProton_Mom_Col_GeV );
    t1->SetBranchAddress("RecoilProton_Theta_Col", &RecoilProton_Theta_Col );
    t1->SetBranchAddress("RecoilProton_Phi_Col", &RecoilProton_Phi_Col );

    t1->SetBranchAddress("RecoilProton_Corrected_Energy_Col_GeV", &RecoilProton_Corrected_Energy_Col_GeV );
    t1->SetBranchAddress("RecoilProton_Corrected_MomX_Col_GeV", &RecoilProton_Corrected_MomX_Col_GeV );
    t1->SetBranchAddress("RecoilProton_Corrected_MomY_Col_GeV", &RecoilProton_Corrected_MomY_Col_GeV );
    t1->SetBranchAddress("RecoilProton_Corrected_MomZ_Col_GeV", &RecoilProton_Corrected_MomZ_Col_GeV );
    t1->SetBranchAddress("RecoilProton_Corrected_Mom_Col_GeV", &RecoilProton_Corrected_Mom_Col_GeV );
    t1->SetBranchAddress("RecoilProton_Corrected_Theta_Col", &RecoilProton_Corrected_Theta_Col );
    t1->SetBranchAddress("RecoilProton_Corrected_Phi_Col", &RecoilProton_Corrected_Phi_Col );

    t1->SetBranchAddress("EventWeight", &EventWeight );
    t1->SetBranchAddress("WilliamsWeight", &WilliamsWeight );
    t1->SetBranchAddress("DedrickWeight", &DedrickWeight );
    t1->SetBranchAddress("CatchenWeight", &CatchenWeight );

    double ZASig_T, ZASig_L, ZASig_LT, ZASig_TT, ZASigma_Lab, ZASigma_UU, RorySigma_UT;
    double Theta, Phi, Phi_S;

    t1->SetBranchAddress("ZASig_T", &ZASig_T);
    t1->SetBranchAddress("ZASig_L", &ZASig_L);
    t1->SetBranchAddress("ZASig_LT", &ZASig_LT);
    t1->SetBranchAddress("ZASig_TT", &ZASig_TT);
    t1->SetBranchAddress("ZASigma_Lab", &ZASigma_Lab);
    t1->SetBranchAddress("ZASigma_UU", &ZASigma_UU);
    t1->SetBranchAddress("RorySigma_UT", &RorySigma_UT);

    t1->SetBranchAddress("AsymPhiMinusPhi_S", &AsymPhiMinusPhi_S);
    t1->SetBranchAddress("AsymPhi_S", &AsymPhi_S);
    t1->SetBranchAddress("Asym2PhiMinusPhi_S", &Asym2PhiMinusPhi_S);
    t1->SetBranchAddress("AsymPhiPlusPhi_S", &AsymPhiPlusPhi_S);
    t1->SetBranchAddress("Asym3PhiMinusPhi_S", &Asym3PhiMinusPhi_S);
    t1->SetBranchAddress("Asym2PhiPlusPhi_S", &Asym2PhiPlusPhi_S);

    t1->SetBranchAddress("Phi", &Phi);
    t1->SetBranchAddress("PhiS", &Phi_S);
    t1->SetBranchAddress("Photon_Theta_Col", &Theta);

    double Jacobian_CM, Jacobian_CM_RF, Jacobian_CM_Col;
    double Flux_Factor_RF, Flux_Factor_Col;

    t1->SetBranchAddress("Jacobian_CM",&Jacobian_CM);
    t1->SetBranchAddress("Jacobian_CM_RF",&Jacobian_CM_RF);
    t1->SetBranchAddress("Jacobian_CM_Col",&Jacobian_CM_Col);

    t1->SetBranchAddress("Flux_Factor_RF",&Flux_Factor_RF);
    t1->SetBranchAddress("Flux_Factor_Col",&Flux_Factor_Col);


    for (int i=0; i<10; i++){

      t1->GetEntry(i);


      VertScatElec->SetThetaPhiE(ScatElec_Theta_Col/DEG, ScatElec_Phi_Col/DEG,
                                 ScatElec_Energy_Col_GeV * 1000);
      *VertTargNeut = *NeutGen->GetParticle();

      *Photon = *VertBeamElec - *VertScatElec;

      ProtonPionGen->Solve(Pion_Theta_Col/DEG,Pion_Phi_Col/DEG);

      *VertProdPion = *ProtonPionGen->ProdPion();
      *VertProdProt = *ProtonPionGen->ProdProton();

      VertEvent->Update();

      *CofMEvent = *VertEvent;
      CofMEvent->Boost(-VertEvent->CoM());
      CofMEvent->Update();

      *RestEvent = *VertEvent;
      RestEvent->Boost(-(VertEvent->TargNeut->Vect()*(1/VertEvent->TargNeut->E())));
      RestEvent->Update();

      *TConEvent = *RestEvent;
      TConEvent->Rotate(RestEvent->VirtPhot->Theta(),-RestEvent->ScatElec->Phi());
      TConEvent->Update();

      double qsq_GeV = *VertEvent->qsq_GeV;
      double w_GeV = *VertEvent->w_GeV;
      double t_GeV = *VertEvent->t_GeV;
      double t_prime_GeV = *VertEvent->t_prime_GeV;
      double t_para_GeV = *VertEvent->t_para_GeV;
      double phi = *TConEvent->Phi;
      if (phi<0) phi+=2*TMath::Pi();
      double phi_s = *TConEvent->Phi_s;
      if (phi_s<0) phi_s+=2*TMath::Pi();
      double theta = *RestEvent->Theta;
      if (theta <0) theta+=2*TMath::Pi();


      sigma_l = Sig->sigma_l();
      sigma_t = Sig->sigma_t();
      sigma_lt = Sig->sigma_lt();
      sigma_tt = Sig->sigma_tt();
      sigma_uu = Sig->sigma_uu();
      sigma_ut = Sig->sigma_ut();

      sigma_k0 = Sig->Sigma_k(0);
      sigma_k1 = Sig->Sigma_k(1);
      sigma_k2 = Sig->Sigma_k(2);
      sigma_k3 = Sig->Sigma_k(3);
      sigma_k4 = Sig->Sigma_k(4);

      sigma = Sig->sigma();

      int printw = 20;

      cout<<left<<setw(printw)<<"Event:"<<left<<setw(printw)<<i<<endl;
      cout<<left<<setw(printw)<<"Kinematics:"<<endl;

      cout<<left<<setw(printw)<< "ElecE:"<<left<<setw(printw) << VertScatElec->E()/1000<<left<<setw(printw)<<ScatElec_Energy_Col_GeV << endl;
      cout<<left<<setw(printw)<< "ElecTh:"<<left<<setw(printw)<<VertScatElec->Theta()*DEG<<left<<setw(printw)<<ScatElec_Theta_Col << endl;
      cout<<left<<setw(printw)<< "ElecPhi:"<<left<<setw(printw)<<VertScatElec->Phi()*DEG <<left<<setw(printw)<<ScatElec_Phi_Col << endl;

      cout<<left<<setw(printw)<< "PionE:"<<left<<setw(printw)<<VertProdPion->E()/1000<<left<<setw(printw)<<Pion_Energy_Col_GeV << endl;
      cout<<left<<setw(printw)<< "PionTh:"<<left<<setw(printw)<<VertProdPion->Theta()*DEG<<left<<setw(printw)<<Pion_Theta_Col<< endl;
      cout<<left<<setw(printw)<< "PionPhi:"<<left<<setw(printw)<<VertProdPion->Phi()*DEG<<left<<setw(printw)<<Pion_Phi_Col<< endl;

      cout<<left<<setw(printw)<< "ProtE:"<<left<<setw(printw)<<VertProdProt->E()/1000<<left<<setw(printw)<<RecoilProton_Energy_Col_GeV << endl;
      cout<<left<<setw(printw)<< "ProtTh:"<<left<<setw(printw)<<VertProdProt->Theta()*DEG<<left<<setw(printw)<<RecoilProton_Theta_Col<< endl;
      cout<<left<<setw(printw)<< "ProtPhi:"<<left<<setw(printw)<<VertProdProt->Phi()*DEG<<left<<setw(printw)<<RecoilProton_Phi_Col << endl;

      cout<<left<<setw(printw)<< "Qsq:"<<left<<setw(printw) << qsq_GeV<<left<<setw(printw)<<Qsq_GeV << endl;
      cout<<left<<setw(printw)<< "W:"<<left<<setw(printw) << w_GeV<<left<<setw(printw)<<W_GeV << endl;
      cout<<left<<setw(printw)<< "t:"<<left<<setw(printw) << t_GeV<<left<<setw(printw)<<T_GeV << endl;
      cout<<left<<setw(printw)<< "t_para:"<<left<<setw(printw) << t_para_GeV<<left<<setw(printw)<<T_Para_GeV << endl;
      cout<<left<<setw(printw)<< "t':"<<left<<setw(printw) << t_prime_GeV<<left<<setw(printw)<<T_Prime_GeV << endl;
      cout<<left<<setw(printw)<<"Theta:"<<left<<setw(printw)<<theta*DEG<<left<<setw(printw)<<Theta<<endl;
      cout<<left<<setw(printw)<<"Phi"<<left<<setw(printw)<<phi*DEG<<left<<setw(printw)<<Phi<<endl;
      cout<<left<<setw(printw)<<"PhiS"<<left<<setw(printw)<<phi_s*DEG<<left<<setw(printw)<<Phi_S<<endl;
      cout<<left<<setw(printw)<< endl;

      cout<<left<<setw(printw)<<"Cross Sections: "<<endl;
      cout<<left<<setw(printw)<<"sigma:"<<left<<setw(printw)<< sigma<<left<<setw(printw)<<ZASigma_Lab << endl;
      cout<<left<<setw(printw)<<"sigma_l:"<<left<<setw(printw)<< sigma_l<<left<<setw(printw)<<ZASig_L << endl;
      cout<<left<<setw(printw)<<"sigma_t:"<<left<<setw(printw)<< sigma_t<<left<<setw(printw)<<ZASig_T << endl;
      cout<<left<<setw(printw)<<"sigma_lt:"<<left<<setw(printw)<< sigma_lt<<left<<setw(printw)<<ZASig_LT << endl;
      cout<<left<<setw(printw)<<"sigma_tt:"<<left<<setw(printw)<< sigma_tt<<left<<setw(printw)<<ZASig_TT << endl;
      cout<<left<<setw(printw)<<"sigma_uu:"<<left<<setw(printw)<< sigma_uu<<left<<setw(printw)<<ZASigma_UU << endl;
      cout<<left<<setw(printw)<<"sigma_ut:"<<left<<setw(printw)<< sigma_ut<<left<<setw(printw)<<RorySigma_UT << endl;
      cout<<left<<setw(printw)<<"AsyP-Ps:"<<left<<setw(printw)<< sigma_k0<<left<<setw(printw)<<AsymPhiMinusPhi_S << endl;
      cout<<left<<setw(printw)<<"AsyPs:"<<left<<setw(printw)<< sigma_k1<<left<<setw(printw)<<AsymPhi_S << endl;
      cout<<left<<setw(printw)<<"Asy2P-Ps:"<<left<<setw(printw)<< sigma_k2<<left<<setw(printw)<<Asym2PhiMinusPhi_S << endl;
      cout<<left<<setw(printw)<<"AsyP+Ps:"<<left<<setw(printw)<< sigma_k3<<left<<setw(printw)<<AsymPhiPlusPhi_S << endl;
      cout<<left<<setw(printw)<<"Asy3P-Ps:"<<left<<setw(printw)<< sigma_k4<<left<<setw(printw)<<Asym3PhiMinusPhi_S << endl;
      cout<<left<<setw(printw)<<"Asy2P_Ps:"<<left<<setw(printw)<< sigma_k5<<left<<setw(printw)<<Asym2PhiPlusPhi_S << endl;
      cout<<left<<setw(printw)<<"Epsilon:"<<left<<setw(printw)<< Sig->epsilon()<<left<<setw(printw)<<Epsilon << endl;
      cout<<left<<setw(printw)<<"Jacobian CM:"<<left<<setw(printw)<<Sig->jacobian_cm()<<left<<setw(printw)<<Jacobian_CM<<endl;
      cout<<left<<setw(printw)<<"Jacobian CM-Col:"<<left<<setw(printw)<<Sig->jacobian_cm_col()<<left<<setw(printw)<<Jacobian_CM_Col<<endl;
      cout<<left<<setw(printw)<<"Flux Factor Col:"<<left<<setw(printw)<<Sig->fluxfactor_col()<<left<<setw(printw)<<Flux_Factor_Col<<endl;
      cout<<left<<setw(printw)<<"Event Weight:"<<left<<setw(printw)<<Sig->weight(100000)<<left<<setw(printw)<<EventWeight<<left<<setw(printw)<< endl;
      //cout<<left<<setw(printw)<<EventWeight/Sig->weight(100000) << endl;

      cout<<left<<setw(printw)<< endl;

      cout << "--------------------------------------------------------------------------------------------"<<endl;
      // Sig->Asyms->at(0)->PrintPars();

    }
  }


  return 0;
}
