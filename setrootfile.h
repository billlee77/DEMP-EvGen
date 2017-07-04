#include <iostream>
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <string>       // std::string
#include <sstream>      // std::stringstream, std::stringbuf
#include "TStopwatch.h"
#include "TDatime.h"

void pim::setrootfile( string rootFile ){ 

  TFile *f = new TFile(rootFile.c_str(),"recreate");
  /* TTree t1("t1","Pion Form Fator Study"); */

  t1.Branch("NRecorded",                                 &fNRecorded,                                 "fNRecorded/I");
  t1.Branch("LundRecorded",                              &fLundRecorded,                              "fLundRecorded/I");
  t1.Branch("NGenerated",                                &fNGenerated,                                "fNGeneratedd/I");
  t1.Branch("Ratio",                                     &fRatio,                                     "fRatiod/D");
  t1.Branch("WLessShell",                                &fWLessShell,                                "fWLessShell/I");
  t1.Branch("WLess1P9",                                  &fWLess1P9,                                  "fWLess1P9/I");
  t1.Branch("WSqNeg",                                    &fWSqNeg,                                    "fWSqNeg/I");
  t1.Branch("NSigmaNeg",                                 &fNSigmaNeg,                                 "fNSigmaNeg/I");
  t1.Branch("NMomConserve",                              &fNMomConserve,                              "fNMomConserve/I");
  t1.Branch("SDiff",                                     &fSDiff,                                     "fSDiff/I");
  t1.Branch("SConserve",                                 &kSConserve,                                 "kSConserve/B");
  t1.Branch("MandSConserve",                             &fMandSConserve,                             "fMandSConserve/D");
  t1.Branch("EnergyConserve",                            &fEnergyConserve,                            "fEnergyConserve/D");
  t1.Branch("XMomConserve",                              &fXMomConserve,                              "fXMomConserve/D");
  t1.Branch("YMomConserve",                              &fYMomConserve,                              "fYMomConserve/D");
  t1.Branch("ZMomConserve",                              &fZMomConserve,                              "fZMomConserve/D");
  t1.Branch("XMomConserve_RF",                           &fXMomConserve_RF,                           "fXMomConserve_RF/D");
  t1.Branch("YMomConserve_RF",                           &fYMomConserve_RF,                           "fYMomConserve_RF/D");
  t1.Branch("ZMomConserve_RF",                           &fZMomConserve_RF,                           "fZMomConserve_RF/D");
  t1.Branch("Top_Pion_Mom",                              &fTop_Pion_Mom,                              "fTop_Pion_Mom/D");
  t1.Branch("Bot_Pion_Mom",                              &fBot_Pion_Mom,                              "fBot_Pion_Mom/D");
  t1.Branch("Pion_Mom_Same",                             &fPion_Mom_Same,                             "fPion_Mom_Same/D");
  t1.Branch("Pion_Alpha",                                &fPion_Alpha,                                "fPion_Alpha/D");
  t1.Branch("Pion_Beta",                                 &fPion_Beta,                                 "fPion_Beta/D");
  t1.Branch("Beta_CM_RF",                                &fBeta_CM_RF,                                "fBeta_CM_RF/D");
  t1.Branch("Gamma_CM_RF",                               &fGamma_CM_RF,                               "fGamma_CM_RF/D");
  t1.Branch("BetaX_Col_RF",                              &fBetaX_Col_RF,                              "fBetaX_Col_RF/D");
  t1.Branch("BetaY_Col_RF",                              &fBetaY_Col_RF,                              "fBetaY_Col_RF/D");
  t1.Branch("BetaZ_Col_RF",                              &fBetaZ_Col_RF,                              "fBetaZ_Col_RF/D");
  t1.Branch("Beta_Col_RF",                               &fBeta_Col_RF,                               "fBeta_Col_RF/D");
  t1.Branch("Gamma_Col_RF",                              &fGamma_Col_RF,                              "fGamma_Col_RF/D");
  t1.Branch("S_I_Col",                                   &fS_I_Col,                                   "fS_I_Col/D");
  t1.Branch("S_F_Col",                                   &fS_F_Col,                                   "fS_F_Col/D");
  t1.Branch("S_I_RF",                                    &fS_I_RF,                                    "fS_I_RF/D");
  t1.Branch("S_F_RF",                                    &fS_F_RF,                                    "fS_F_RF/D");
  t1.Branch("S_I_Col_GeV",                               &fS_I_Col_GeV,                               "fS_I_Col_GeV/D");
  t1.Branch("S_F_Col_GeV",                               &fS_F_Col_GeV,                               "fS_F_Col_GeV/D");
  t1.Branch("S_I_RF_GeV",                                &fS_I_RF_GeV,                                "fS_I_RF_GeV/D");
  t1.Branch("S_F_RF_GeV",                                &fS_F_RF_GeV,                                "fS_F_RF_GeV/D");
  t1.Branch("W",                                         &fW,                                         "fW/D");
  t1.Branch("W_GeV",                                     &fW_GeV,                                     "fW_GeV/D");
  t1.Branch("WSq",                                       &fWSq,                                       "fWSq/D");
  t1.Branch("WSq_GeV",                                   &fWSq_GeV,                                   "fWSq_GeV/D");
  t1.Branch("WSq_PiN",                                   &fWSq_PiN,                                   "fWSq_PiN/D");

  t1.Branch("WSq_PiN_GeV",                               &fWSq_PiN_GeV,                               "fWSq_PiN_GeV/D");
  t1.Branch("WSq_Top_PiN_GeV",                           &fWSq_Top_PiN_GeV,                           "fWSq_Top_PiN_GeV/D");
  t1.Branch("WSq_Bot_PiN_GeV",                           &fWSq_Bot_PiN_GeV,                           "fWSq_Bot_PiN_GeV/D");

  t1.Branch("Qsq",                                       &fQsq,                                       "fQsq/D");
  t1.Branch("Qsq_GeV",                                   &fQsq_GeV,                                   "fQsq_GeV/D");
  t1.Branch("T_Para",                                    &fT_Para,                                    "fT_Para/D");
  t1.Branch("T_Para_GeV",                                &fT_Para_GeV,                                "fT_Para_GeV/D");
  t1.Branch("T",                                         &fT,                                         "fT/D");
  t1.Branch("T_GeV",                                     &fT_GeV,                                     "fT_GeV/D");
  t1.Branch("Epsilon",                                   &fEpsilon,                                   "fEpsilon/D");
  t1.Branch("x",                                         &fx,                                         "fx/D");
  t1.Branch("y",                                         &fy,                                         "fy/D");
  t1.Branch("z",                                         &fz,                                         "fz/D");
  t1.Branch("Target_Energy_RF",                          &fProton_Energy_RF,                          "fProton_Energy_RF/D");
  t1.Branch("Target_Mom_RF",                             &fProton_Mom_RF,                             "fProton_Mom_RF/D");
  t1.Branch("Target_MomZ_RF",                            &fProton_MomZ_RF,                            "fProton_MomZ_RF/D");
  t1.Branch("Target_MomX_RF",                            &fProton_MomX_RF,                            "fProton_MomX_RF/D");
  t1.Branch("Target_MomY_RF",                            &fProton_MomY_RF,                            "fProton_MomY_RF/D");
  t1.Branch("Target_Energy_RF_GeV",                      &fProton_Energy_RF_GeV,                      "fProton_Energy_RF_GeV/D");
  t1.Branch("Target_Mom_RF_GeV",                         &fProton_Mom_RF_GeV,                         "fProton_Mom_RF_GeV/D");
  t1.Branch("Target_MomZ_RF_GeV",                        &fProton_MomZ_RF_GeV,                        "fProton_MomZ_RF_GeV/D");
  t1.Branch("Target_MomX_RF_GeV",                        &fProton_MomX_RF_GeV,                        "fProton_MomX_RF_GeV/D");
  t1.Branch("Target_MomY_RF_GeV",                        &fProton_MomY_RF_GeV,                        "fProton_MomY_RF_GeV/D");
  t1.Branch("Elec_ScatElec_Theta_RF",                    &fElec_ScatElec_Theta_RF,                    "fElec_ScatElec_Theta_RF/D");
  t1.Branch("ScatElec_Cone_Phi_RF",                      &fScatElec_Cone_Phi_RF,                      "fScatElec_Cone_Phi_RF/D");
  t1.Branch("ScatElec_Theta_RF",                         &fScatElec_Theta_RF,                         "fScatElec_Theta_RF/D");
  t1.Branch("ScatElec_Phi_RF",                           &fScatElec_Phi_RF,                           "fScatElec_Phi_RF/D");
  t1.Branch("ScatElec_Energy_RF",                        &fScatElec_Energy_RF,                        "fScatElec_Energy_RF/D");
  t1.Branch("ScatElec_Mom_RF",                           &fScatElec_Mom_RF,                           "fScatElec_Mom_RF/D");
  t1.Branch("ScatElec_MomX_RF",                          &fScatElec_MomX_RF,                          "fScatElec_MomX_RF/D");
  t1.Branch("ScatElec_MomZ_RF",                          &fScatElec_MomZ_RF,                          "fScatElec_MomZ_RF/D");
  t1.Branch("ScatElec_MomY_RF",                          &fScatElec_MomY_RF,                          "fScatElec_MomY_RF/D");
  t1.Branch("ScatElec_Energy_RF_GeV",                    &fScatElec_Energy_RF_GeV,                    "fScatElec_Energy_RF_GeV/D");
  t1.Branch("ScatElec_Mom_RF_GeV",                       &fScatElec_Mom_RF_GeV,                       "fScatElec_Mom_RF_GeV/D");
  t1.Branch("ScatElec_MomX_RF_GeV",                      &fScatElec_MomX_RF_GeV,                      "fScatElec_MomX_RF_GeV/D");
  t1.Branch("ScatElec_MomZ_RF_GeV",                      &fScatElec_MomZ_RF_GeV,                      "fScatElec_MomZ_RF_GeV/D");
  t1.Branch("ScatElec_MomY_RF_GeV",                      &fScatElec_MomY_RF_GeV,                      "fScatElec_MomY_RF_GeV/D");
  t1.Branch("Photon_Theta_RF",                           &fPhoton_Theta_RF,                           "fPhoton_Theta_RF/D");
  t1.Branch("Photon_Phi_RF",                             &fPhoton_Phi_RF,                             "fPhoton_Phi_RF/D");
  t1.Branch("Photon_Energy_RF",                          &fPhoton_Energy_RF,                          "fPhoton_Energy_RF/D");
  t1.Branch("Photon_Mom_RF",                             &fPhoton_Mom_RF,                             "fPhoton_Mom_RF/D");
  t1.Branch("Photon_MomX_RF",                            &fPhoton_MomX_RF,                            "fPhoton_MomX_RF/D");
  t1.Branch("Photon_MomY_RF",                            &fPhoton_MomY_RF,                            "fPhoton_MomY_RF/D");
  t1.Branch("Photon_MomZ_RF",                            &fPhoton_MomZ_RF,                            "fPhoton_MomZ_RF/D");
  t1.Branch("Photon_Energy_RF_GeV",                      &fPhoton_Energy_RF_GeV,                      "fPhoton_Energy_RF_GeV/D");
  t1.Branch("Photon_Mom_RF_GeV",                         &fPhoton_Mom_RF_GeV,                         "fPhoton_Mom_RF_GeV/D");
  t1.Branch("Photon_MomX_RF_GeV",                        &fPhoton_MomX_RF_GeV,                        "fPhoton_MomX_RF_GeV/D");
  t1.Branch("Photon_MomY_RF_GeV",                        &fPhoton_MomY_RF_GeV,                        "fPhoton_MomY_RF_GeV/D");
  t1.Branch("Photon_MomZ_RF_GeV",                        &fPhoton_MomZ_RF_GeV,                        "fPhoton_MomZ_RF_GeV/D");
  t1.Branch("Electron_Theta_RF",                         &fElectron_Theta_RF,                         "fElectron_Theta_RF/D");
  t1.Branch("Electron_Phi_RF",                           &fElectron_Phi_RF,                           "fElectron_Phi_RF/D");
  t1.Branch("Electron_Energy_RF",                        &fElectron_Energy_RF,                        "fElectron_Energy_RF/D");
  t1.Branch("Electron_Mom_RF",                           &fElectron_Mom_RF,                           "fElectron_Mom_RF/D");
  t1.Branch("Electron_MomX_RF",                          &fElectron_MomX_RF,                          "fElectron_MomX_RF/D");
  t1.Branch("Electron_MomY_RF",                          &fElectron_MomY_RF,                          "fElectron_MomY_RF/D");
  t1.Branch("Electron_MomZ_RF",                          &fElectron_MomZ_RF,                          "fElectron_MomZ_RF/D");
  t1.Branch("Electron_Energy_RF_GeV",                    &fElectron_Energy_RF_GeV,                    "fElectron_Energy_RF_GeV/D");
  t1.Branch("Electron_Mom_RF_GeV",                       &fElectron_Mom_RF_GeV,                       "fElectron_Mom_RF_GeV/D");
  t1.Branch("Electron_MomX_RF_GeV",                      &fElectron_MomX_RF_GeV,                      "fElectron_MomX_RF_GeV/D");
  t1.Branch("Electron_MomY_RF_GeV",                      &fElectron_MomY_RF_GeV,                      "fElectron_MomY_RF_GeV/D");
  t1.Branch("Electron_MomZ_RF_GeV",                      &fElectron_MomZ_RF_GeV,                      "fElectron_MomZ_RF_GeV/D");
  t1.Branch("Proton_Energy_CM",                          &fProton_Energy_CM,                          "fProton_Energy_CM/D");
  t1.Branch("Proton_Mom_CM",                             &fProton_Mom_CM,                             "fProton_Mom_CM/D");
  t1.Branch("Proton_Energy_CM_GeV",                      &fProton_Energy_CM_GeV,                      "fProton_Energy_CM_GeV/D");
  t1.Branch("Proton_Mom_CM_GeV",                         &fProton_Mom_CM_GeV,                         "fProton_Mom_CM_GeV/D");
  t1.Branch("Photon_Energy_CM",                          &fPhoton_Energy_CM,                          "fPhoton_Energy_CM/D");
  t1.Branch("Photon_Mom_CM",                             &fPhoton_Mom_CM,                             "fPhoton_Mom_CM/D");
  t1.Branch("Photon_Energy_CM_GeV",                      &fPhoton_Energy_CM_GeV,                      "fPhoton_Energy_CM_GeV/D");
  t1.Branch("Photon_Mom_CM_GeV",                         &fPhoton_Mom_CM_GeV,                         "fPhoton_Mom_CM_GeV/D");
  t1.Branch("Pion_Theta_CM",                             &fPion_Theta_CM,                             "fPion_Theta_CM/D");
  t1.Branch("Pion_Phi_CM",                               &fPion_Phi_CM,                               "fPion_Phi_CM/D");
  t1.Branch("Pion_Energy_CM",                            &fPion_Energy_CM,                            "fPion_Energy_CM/D");
  t1.Branch("Pion_Mom_CM",                               &fPion_Mom_CM,                               "fPion_Mom_CM/D");
  t1.Branch("Pion_Energy_CM_GeV",                        &fPion_Energy_CM_GeV,                        "fPion_Energy_CM_GeV/D");
  t1.Branch("Pion_Mom_CM_GeV",                           &fPion_Mom_CM_GeV,                           "fPion_Mom_CM_GeV/D");
  t1.Branch("Neutron_Theta_CM",                          &fNeutron_Theta_CM,                          "fNeutron_Theta_CM/D");
  t1.Branch("Neutron_Phi_CM",                            &fNeutron_Phi_CM,                            "fNeutron_Phi_CM/D");
  t1.Branch("Neutron_Energy_CM",                         &fNeutron_Energy_CM,                         "fNeutron_Energy_CM/D");
  t1.Branch("Neutron_Mom_CM",                            &fNeutron_Mom_CM,                            "fNeutron_Mom_CM/D");
  t1.Branch("Neutron_Energy_CM_GeV",                     &fNeutron_Energy_CM_GeV,                     "fNeutron_Energy_CM_GeV/D");
  t1.Branch("Neutron_Mom_CM_GeV",                        &fNeutron_Mom_CM_GeV,                        "fNeutron_Mom_CM_GeV/D");
  t1.Branch("Pion_Theta_RF",                             &fPion_Theta_RF,                             "fPion_Theta_RF/D");
  t1.Branch("Pion_Phi_RF",                               &fPion_Phi_RF,                               "fPion_Phi_RF/D");
  t1.Branch("PiqVec_Theta_RF",                           &fPiqVec_Theta_RF,                           "fPiqVec_Theta_RF/D");
  t1.Branch("Pion_Energy_RF",                            &fPion_Energy_RF,                            "fPion_Energy_RF/D");
  t1.Branch("Pion_Mom_RF",                               &fPion_Mom_RF,                               "fPion_Mom_RF/D");
  t1.Branch("Pion_MomX_RF",                              &fPion_MomX_RF,                              "fPion_MomX_RF/D");
  t1.Branch("Pion_MomY_RF",                              &fPion_MomY_RF,                              "fPion_MomY_RF/D");
  t1.Branch("Pion_MomZ_RF",                              &fPion_MomZ_RF,                              "fPion_MomZ_RF/D");
  t1.Branch("Pion_Energy_RF_GeV",                        &fPion_Energy_RF_GeV,                        "fPion_Energy_RF_GeV/D");
  t1.Branch("Pion_Mom_RF_GeV",                           &fPion_Mom_RF_GeV,                           "fPion_Mom_RF_GeV/D");
  t1.Branch("Pion_MomX_RF_GeV",                          &fPion_MomX_RF_GeV,                          "fPion_MomX_RF_GeV/D");
  t1.Branch("Pion_MomY_RF_GeV",                          &fPion_MomY_RF_GeV,                          "fPion_MomY_RF_GeV/D");
  t1.Branch("Pion_MomZ_RF_GeV",                          &fPion_MomZ_RF_GeV,                          "fPion_MomZ_RF_GeV/D");
  t1.Branch("Neutron_qVec_Theta_RF",                     &fNeutron_qVec_Theta_RF,                     "fNeutron_qVec_Theta_RF/D");
  t1.Branch("Neutron_Theta_RF",                          &fNeutron_Theta_RF,                          "fNeutron_Theta_RF/D");
  t1.Branch("Neutron_Phi_RF",                            &fNeutron_Phi_RF,                            "fNeutron_Phi_RF/D");
  t1.Branch("Neutron_Energy_RF",                         &fNeutron_Energy_RF,                         "fNeutron_Energy_RF/D");
  t1.Branch("Neutron_Mom_RF",                            &fNeutron_Mom_RF,                            "fNeutron_Mom_RF/D");
  t1.Branch("Neutron_MomX_RF",                           &fNeutron_MomX_RF,                           "fNeutron_MomX_RF/D");
  t1.Branch("Neutron_MomY_RF",                           &fNeutron_MomY_RF,                           "fNeutron_MomY_RF/D");
  t1.Branch("Neutron_MomZ_RF",                           &fNeutron_MomZ_RF,                           "fNeutron_MomZ_RF/D");
  t1.Branch("Neutron_Energy_RF_GeV",                     &fNeutron_Energy_RF_GeV,                     "fNeutron_Energy_RF_GeV/D");
  t1.Branch("Neutron_Mom_RF_GeV",                        &fNeutron_Mom_RF_GeV,                        "fNeutron_Mom_RF_GeV/D");
  t1.Branch("Neutron_MomX_RF_GeV",                       &fNeutron_MomX_RF_GeV,                       "fNeutron_MomX_RF_GeV/D");
  t1.Branch("Neutron_MomY_RF_GeV",                       &fNeutron_MomY_RF_GeV,                       "fNeutron_MomY_RF_GeV/D");
  t1.Branch("Neutron_MomZ_RF_GeV",                       &fNeutron_MomZ_RF_GeV,                       "fNeutron_MomZ_RF_GeV/D");

  t1.Branch("Proton_Energy_Col",                         &fProton_Energy_Col,                         "fProton_Energy_Col/D");
  t1.Branch("Proton_Mom_Col",                            &fProton_Mom_Col,                            "fProton_Mom_Col/D");
  t1.Branch("Proton_Theta_Col",                          &fProton_Theta_Col,                          "fProton_Theta_Col/D");
  t1.Branch("Proton_Phi_Col",                            &fProton_Phi_Col,                            "fProton_Phi_Col/D");
  t1.Branch("Proton_MomZ_Col",                           &fProton_MomZ_Col,                           "fProton_MomZ_Col/D");
  t1.Branch("Proton_MomX_Col",                           &fProton_MomX_Col,                           "fProton_MomX_Col/D");
  t1.Branch("Proton_MomY_Col",                           &fProton_MomY_Col,                           "fProton_MomY_Col/D");
  t1.Branch("Proton_Energy_Col_GeV",                     &fProton_Energy_Col_GeV,                     "fProton_Energy_Col_GeV/D");
  t1.Branch("Proton_Mom_Col_GeV",                        &fProton_Mom_Col_GeV,                        "fProton_Mom_Col_GeV/D");
  t1.Branch("Proton_MomZ_Col_GeV",                       &fProton_MomZ_Col_GeV,                       "fProton_MomZ_Col_GeV/D");
  t1.Branch("Proton_MomX_Col_GeV",                       &fProton_MomX_Col_GeV,                       "fProton_MomX_Col_GeV/D");
  t1.Branch("Proton_MomY_Col_GeV",                       &fProton_MomY_Col_GeV,                       "fProton_MomY_Col_GeV/D");

  t1.Branch("FSIProton_Energy_Col",                      &fFSIProton_Energy_Col,                      "fFSIProton_Energy_Col/D");
  t1.Branch("FSIProton_Mom_Col",                         &fFSIProton_Mom_Col,                         "fFSIProton_Mom_Col/D");
  t1.Branch("FSIProton_Theta_Col",                       &fFSIProton_Theta_Col,                       "fFSIProton_Theta_Col/D");
  t1.Branch("FSIProton_Phi_Col",                         &fFSIProton_Phi_Col,                         "fFSIProton_Phi_Col/D");
  t1.Branch("FSIProton_MomZ_Col",                        &fFSIProton_MomZ_Col,                        "fFSIProton_MomZ_Col/D");
  t1.Branch("FSIProton_MomX_Col",                        &fFSIProton_MomX_Col,                        "fFSIProton_MomX_Col/D");
  t1.Branch("FSIProton_MomY_Col",                        &fFSIProton_MomY_Col,                        "fFSIProton_MomY_Col/D");
  t1.Branch("FSIProton_Energy_Col_GeV",                  &fFSIProton_Energy_Col_GeV,                  "fFSIProton_Energy_Col_GeV/D");
  t1.Branch("FSIProton_Mom_Col_GeV",                     &fFSIProton_Mom_Col_GeV,                     "fFSIProton_Mom_Col_GeV/D");
  t1.Branch("FSIProton_MomZ_Col_GeV",                    &fFSIProton_MomZ_Col_GeV,                    "fFSIProton_MomZ_Col_GeV/D");
  t1.Branch("FSIProton_MomX_Col_GeV",                    &fFSIProton_MomX_Col_GeV,                    "fFSIProton_MomX_Col_GeV/D");
  t1.Branch("FSIProton_MomY_Col_GeV",                    &fFSIProton_MomY_Col_GeV,                    "fFSIProton_MomY_Col_GeV/D");

  t1.Branch("Target_Energy_Col",                         &fTarget_Energy_Col,                         "fTarget_Energy_Col/D");
  t1.Branch("Target_Mom_Col",                            &fTarget_Mom_Col,                            "fTarget_Mom_Col/D");
  t1.Branch("Target_Theta_Col",                          &fTarget_Theta_Col,                          "fTarget_Theta_Col/D");
  t1.Branch("Target_Phi_Col",                            &fTarget_Phi_Col,                            "fTarget_Phi_Col/D");
  t1.Branch("Target_MomZ_Col",                           &fTarget_MomZ_Col,                           "fTarget_MomZ_Col/D");
  t1.Branch("Target_MomX_Col",                           &fTarget_MomX_Col,                           "fTarget_MomX_Col/D");
  t1.Branch("Target_MomY_Col",                           &fTarget_MomY_Col,                           "fTarget_MomY_Col/D");
  t1.Branch("Target_Energy_Col_GeV",                     &fTarget_Energy_Col_GeV,                     "fTarget_Energy_Col_GeV/D");
  t1.Branch("Target_Mom_Col_GeV",                        &fTarget_Mom_Col_GeV,                        "fTarget_Mom_Col_GeV/D");
  t1.Branch("Target_MomZ_Col_GeV",                       &fTarget_MomZ_Col_GeV,                       "fTarget_MomZ_Col_GeV/D");
  t1.Branch("Target_MomX_Col_GeV",                       &fTarget_MomX_Col_GeV,                       "fTarget_MomX_Col_GeV/D");
  t1.Branch("Target_MomY_Col_GeV",                       &fTarget_MomY_Col_GeV,                       "fTarget_MomY_Col_GeV/D");
  t1.Branch("Target_Pol0_Col",                           &fTarget_Pol0_Col,                           "fTarget_Pol0_Col/D"); 
  t1.Branch("Target_PolX_Col",                           &fTarget_PolX_Col,                           "fTarget_PolX_Col/D"); 
  t1.Branch("Target_PolY_Col",                           &fTarget_PolY_Col,                           "fTarget_PolY_Col/D"); 
  t1.Branch("Target_PolZ_Col",                           &fTarget_PolZ_Col,                           "fTarget_PolZ_Col/D"); 
  t1.Branch("Target_Pol0_RF",                            &fTarget_Pol0_RF,                            "fTarget_Pol0_RF/D"); 
  t1.Branch("Target_PolX_RF",                            &fTarget_PolX_RF,                            "fTarget_PolX_RF/D"); 
  t1.Branch("Target_PolY_RF",                            &fTarget_PolY_RF,                            "fTarget_PolY_RF/D"); 
  t1.Branch("Target_PolZ_RF",                            &fTarget_PolZ_RF,                            "fTarget_PolZ_RF/D"); 
  t1.Branch("Photon_Theta_Col",                          &fPhoton_Theta_Col,                          "fPhoton_Theta_Col/D");
  t1.Branch("Photon_Phi_Col",                            &fPhoton_Phi_Col,                            "fPhoton_Phi_Col/D");
  t1.Branch("Photon_Energy_Col",                         &fPhoton_Energy_Col,                         "fPhoton_Energy_Col/D");
  t1.Branch("Photon_Mom_Col",                            &fPhoton_Mom_Col,                            "fPhoton_Mom_Col/D");
  t1.Branch("Photon_MomX_Col",                           &fPhoton_MomX_Col,                           "fPhoton_MomX_Col/D");
  t1.Branch("Photon_MomZ_Col",                           &fPhoton_MomZ_Col,                           "fPhoton_MomZ_Col/D");
  t1.Branch("Photon_MomY_Col",                           &fPhoton_MomY_Col,                           "fPhoton_MomY_Col/D");
  t1.Branch("Photon_Energy_Col_GeV",                     &fPhoton_Energy_Col_GeV,                     "fPhoton_Energy_Col_GeV/D");
  t1.Branch("Photon_Mom_Col_GeV",                        &fPhoton_Mom_Col_GeV,                        "fPhoton_Mom_Col_GeV/D");
  t1.Branch("Photon_MomX_Col_GeV",                       &fPhoton_MomX_Col_GeV,                       "fPhoton_MomX_Col_GeV/D");
  t1.Branch("Photon_MomZ_Col_GeV",                       &fPhoton_MomZ_Col_GeV,                       "fPhoton_MomZ_Col_GeV/D");
  t1.Branch("Photon_MomY_Col_GeV",                       &fPhoton_MomY_Col_GeV,                       "fPhoton_MomY_Col_GeV/D");
  t1.Branch("Electron_Theta_Col",                        &fElectron_Theta_Col,                        "fElectron_Theta_Col/D");
  t1.Branch("Electron_Phi_Col",                          &fElectron_Phi_Col,                          "fElectron_Phi_Col/D");
  t1.Branch("Electron_Mom_Col",                          &fElectron_Mom_Col,                          "fElectron_Mom_Col/D");
  t1.Branch("Electron_Energy_Col",                       &fElectron_Energy_Col,                       "fElectron_Energy_Col/D");
  t1.Branch("Electron_MomZ_Col",                         &fElectron_MomZ_Col,                         "fElectron_MomZ_Col/D");
  t1.Branch("Electron_MomX_Col",                         &fElectron_MomX_Col,                         "fElectron_MomX_Col/D");
  t1.Branch("Electron_MomY_Col",                         &fElectron_MomY_Col,                         "fElectron_MomY_Col/D");
  t1.Branch("Electron_Energy_Col_GeV",                   &fElectron_Energy_Col_GeV,                   "fElectron_Energy_Col_GeV/D");
  t1.Branch("Electron_MomZ_Col_GeV",                     &fElectron_MomZ_Col_GeV,                     "fElectron_MomZ_Col_GeV/D");
  t1.Branch("Electron_MomX_Col_GeV",                     &fElectron_MomX_Col_GeV,                     "fElectron_MomX_Col_GeV/D");
  t1.Branch("Electron_MomY_Col_GeV",                     &fElectron_MomY_Col_GeV,                     "fElectron_MomY_Col_GeV/D");
  t1.Branch("Electron_Targ_Bremss_Loss",                 &fElectron_Targ_Bremss_Loss,                 "fElectron_Targ_Bremss_Loss/D");
  t1.Branch("Electron_Targ_Ion_Loss",                    &fElectron_Targ_Ion_Loss,                    "fElectron_Targ_Ion_Loss/D");
  t1.Branch("Electron_Air_Bremss_Loss",                  &fElectron_Air_Bremss_Loss,                  "fElectron_Air_Bremss_Loss/D");
  t1.Branch("Electron_Air_Ion_Loss",                     &fElectron_Air_Ion_Loss,                     "fElectron_Air_Ion_Loss/D");
  t1.Branch("Electron_Corrected_Energy_Col",             &fElectron_Corrected_Energy_Col,             "fElectron_Corrected_Energy_Col/D");
  t1.Branch("Electron_Corrected_Mom_Col",                &fElectron_Corrected_Mom_Col,                "fElectron_Corrected_Mom_Col/D");
  t1.Branch("Electron_Corrected_MomX_Col",               &fElectron_Corrected_MomX_Col,               "fElectron_Corrected_MomX_Col/D");
  t1.Branch("Electron_Corrected_MomY_Col",               &fElectron_Corrected_MomY_Col,               "fElectron_Corrected_MomY_Col/D");
  t1.Branch("Electron_Corrected_MomZ_Col",               &fElectron_Corrected_MomZ_Col,               "fElectron_Corrected_MomZ_Col/D");
  t1.Branch("Electron_Corrected_Theta_Col",              &fElectron_Corrected_Theta_Col,              "fElectron_Corrected_Theta_Col/D");
  t1.Branch("Electron_Corrected_Phi_Col",                &fElectron_Corrected_Phi_Col,                "fElectron_Corrected_Phi_Col/D");
  t1.Branch("Electron_Delta_Mom_Col",                    &fElectron_Delta_Mom_Col,                    "fElectron_Delta_Mom_Col/D");
  t1.Branch("Electron_Corrected_Energy_Col_GeV",         &fElectron_Corrected_Energy_Col_GeV,         "fElectron_Corrected_Energy_Col_GeV/D");
  t1.Branch("Electron_Corrected_Mom_Col_GeV",            &fElectron_Corrected_Mom_Col_GeV,            "fElectron_Corrected_Mom_Col_GeV/D");
  t1.Branch("Electron_Corrected_MomX_Col_GeV",           &fElectron_Corrected_MomX_Col_GeV,           "fElectron_Corrected_MomX_Col_GeV/D");
  t1.Branch("Electron_Corrected_MomY_Col_GeV",           &fElectron_Corrected_MomY_Col_GeV,           "fElectron_Corrected_MomY_Col_GeV/D");
  t1.Branch("Electron_Corrected_MomZ_Col_GeV",           &fElectron_Corrected_MomZ_Col_GeV,           "fElectron_Corrected_MomZ_Col_GeV/D");
  t1.Branch("Electron_Delta_Mom_Col_GeV",                &fElectron_Delta_Mom_Col_GeV,                "fElectron_Delta_Mom_Col_GeV/D");
  t1.Branch("ScatElec_Theta_Col",                        &fScatElec_Theta_Col,                        "fScatElec_Theta_Col/D");
  t1.Branch("ScatElec_Phi_Col",                          &fScatElec_Phi_Col,                          "fScatElec_Phi_Col/D");
  t1.Branch("ScatElec_Energy_Col",                       &fScatElec_Energy_Col,                       "fScatElec_Energy_Col/D");
  t1.Branch("ScatElec_Mom_Col",                          &fScatElec_Mom_Col,                          "fScatElec_Mom_Col/D");
  t1.Branch("ScatElec_MomX_Col",                         &fScatElec_MomX_Col,                         "fScatElec_MomX_Col/D");
  t1.Branch("ScatElec_MomY_Col",                         &fScatElec_MomY_Col,                         "fScatElec_MomY_Col/D");
  t1.Branch("ScatElec_MomZ_Col",                         &fScatElec_MomZ_Col,                         "fScatElec_MomZ_Col/D");
  t1.Branch("ScatElec_Energy_Col_GeV",                   &fScatElec_Energy_Col_GeV,                   "fScatElec_Energy_Col_GeV/D");
  t1.Branch("ScatElec_Mom_Col_GeV",                      &fScatElec_Mom_Col_GeV,                      "fScatElec_Mom_Col_GeV/D");
  t1.Branch("ScatElec_MomX_Col_GeV",                     &fScatElec_MomX_Col_GeV,                     "fScatElec_MomX_Col_GeV/D");
  t1.Branch("ScatElec_MomY_Col_GeV",                     &fScatElec_MomY_Col_GeV,                     "fScatElec_MomY_Col_GeV/D");
  t1.Branch("ScatElec_MomZ_Col_GeV",                     &fScatElec_MomZ_Col_GeV,                     "fScatElec_MomZ_Col_GeV/D");
  t1.Branch("ScatElec_Targ_Bremss_Loss",                 &fScatElec_Targ_Bremss_Loss,                 "fScatElec_Targ_Bremss_Loss/D");
  t1.Branch("ScatElec_Targ_Ion_Loss",                    &fScatElec_Targ_Ion_Loss,                    "fScatElec_Targ_Ion_Loss/D");
  t1.Branch("ScatElec_Air_Bremss_Loss",                  &fScatElec_Air_Bremss_Loss,                  "fScatElec_Air_Bremss_Loss/D");
  t1.Branch("ScatElec_Air_Ion_Loss",                     &fScatElec_Air_Ion_Loss,                     "fScatElec_Air_Ion_Loss/D");

  t1.Branch("ScatElec_TargWindow_Bremss_Loss",           &fScatElec_TargWindow_Bremss_Loss,           "fScatElec_TargWindow_Bremss_Loss/D");
  t1.Branch("ScatElec_TargWindow_Ion_Loss",              &fScatElec_TargWindow_Ion_Loss,              "fScatElec_TargWindow_Ion_Loss/D");

  t1.Branch("ScatElec_Corrected_Energy_Col",             &fScatElec_Corrected_Energy_Col,             "fScatElec_Corrected_Energy_Col/D");
  t1.Branch("ScatElec_Corrected_Mom_Col",                &fScatElec_Corrected_Mom_Col,                "fScatElec_Corrected_Mom_Col/D");
  t1.Branch("ScatElec_Corrected_MomX_Col",               &fScatElec_Corrected_MomX_Col,               "fScatElec_Corrected_MomX_Col/D");
  t1.Branch("ScatElec_Corrected_MomY_Col",               &fScatElec_Corrected_MomY_Col,               "fScatElec_Corrected_MomY_Col/D");
  t1.Branch("ScatElec_Corrected_MomZ_Col",               &fScatElec_Corrected_MomZ_Col,               "fScatElec_Corrected_MomZ_Col/D");
  t1.Branch("ScatElec_Corrected_Theta_Col",              &fScatElec_Corrected_Theta_Col,              "fScatElec_Corrected_Theta_Col/D");
  t1.Branch("ScatElec_Corrected_Phi_Col",                &fScatElec_Corrected_Phi_Col,                "fScatElec_Corrected_Phi_Col/D");
  t1.Branch("ScatElec_Delta_Mom_Col",                    &fScatElec_Delta_Mom_Col,                    "fScatElec_Delta_Mom_Col/D");
  t1.Branch("ScatElec_Corrected_Energy_Col_GeV",         &fScatElec_Corrected_Energy_Col_GeV,         "fScatElec_Corrected_Energy_Col_GeV/D");
  t1.Branch("ScatElec_Corrected_Mom_Col_GeV",            &fScatElec_Corrected_Mom_Col_GeV,            "fScatElec_Corrected_Mom_Col_GeV/D");
  t1.Branch("ScatElec_Corrected_MomX_Col_GeV",           &fScatElec_Corrected_MomX_Col_GeV,           "fScatElec_Corrected_MomX_Col_GeV/D");
  t1.Branch("ScatElec_Corrected_MomY_Col_GeV",           &fScatElec_Corrected_MomY_Col_GeV,           "fScatElec_Corrected_MomY_Col_GeV/D");
  t1.Branch("ScatElec_Corrected_MomZ_Col_GeV",           &fScatElec_Corrected_MomZ_Col_GeV,           "fScatElec_Corrected_MomZ_Col_GeV/D");
  t1.Branch("ScatElec_Delta_Mom_Col_GeV",                &fScatElec_Delta_Mom_Col_GeV,                "fScatElec_Delta_Mom_Col_GeV/D");
  t1.Branch("Pion_Theta_Col",                            &fPion_Theta_Col,                            "fPion_Theta_Col/D");
  t1.Branch("Pion_Phi_Col",                              &fPion_Phi_Col,                              "fPion_Phi_Col/D");
  t1.Branch("Pion_Mom_Col",                              &fPion_Mom_Col,                              "fPion_Mom_Col/D");
  t1.Branch("Pion_Energy_Col",                           &fPion_Energy_Col,                           "fPion_Energy_Col/D");
  t1.Branch("Pion_MomZ_Col",                             &fPion_MomZ_Col,                             "fPion_MomZ_Col/D");
  t1.Branch("Pion_MomX_Col",                             &fPion_MomX_Col,                             "fPion_MomX_Col/D");
  t1.Branch("Pion_MomY_Col",                             &fPion_MomY_Col,                             "fPion_MomY_Col/D");
  t1.Branch("Pion_Energy_Col_GeV",                       &fPion_Energy_Col_GeV,                       "fPion_Energy_Col_GeV/D");
  t1.Branch("Pion_Mom_Col_GeV",                          &fPion_Mom_Col_GeV,                          "fPion_Mom_Col_GeV/D");
  t1.Branch("Pion_MomZ_Col_GeV",                         &fPion_MomZ_Col_GeV,                         "fPion_MomZ_Col_GeV/D");
  t1.Branch("Pion_MomX_Col_GeV",                         &fPion_MomX_Col_GeV,                         "fPion_MomX_Col_GeV/D");
  t1.Branch("Pion_MomY_Col_GeV",                         &fPion_MomY_Col_GeV,                         "fPion_MomY_Col_GeV/D");
  t1.Branch("Pion_TargWindow_Ion_Loss",                  &fPion_TargWindow_Ion_Loss,                  "fPion_TargWindow_Ion_Loss/D");
  t1.Branch("Pion_Targ_Bremss_Loss",                     &fPion_Targ_Bremss_Loss,                     "fPion_Targ_Bremss_Loss/D");
  t1.Branch("Pion_Targ_Ion_Loss",                        &fPion_Targ_Ion_Loss,                        "fPion_Targ_Ion_Loss/D");
  t1.Branch("Pion_Air_Bremss_Loss",                      &fPion_Air_Bremss_Loss,                      "fPion_Air_Bremss_Loss/D");
  t1.Branch("Pion_Air_Ion_Loss",                         &fPion_Air_Ion_Loss,                         "fPion_Air_Ion_Loss/D");
  t1.Branch("Pion_Corrected_Theta_Col",                  &fPion_Corrected_Theta_Col,                  "fPion_Corrected_Theta_Col/D");
  t1.Branch("Pion_Corrected_Phi_Col",                    &fPion_Corrected_Phi_Col,                    "fPion_Corrected_Phi_Col/D");
  t1.Branch("Pion_Corrected_Energy_Col",                 &fPion_Corrected_Energy_Col,                 "fPion_Corrected_Energy_Col/D");
  t1.Branch("Pion_Corrected_Mom_Col",                    &fPion_Corrected_Mom_Col,                    "fPion_Corrected_Mom_Col/D");
  t1.Branch("Pion_Corrected_MomX_Col",                   &fPion_Corrected_MomX_Col,                   "fPion_Corrected_MomX_Col/D");
  t1.Branch("Pion_Corrected_MomY_Col",                   &fPion_Corrected_MomY_Col,                   "fPion_Corrected_MomY_Col/D");
  t1.Branch("Pion_Corrected_MomZ_Col",                   &fPion_Corrected_MomZ_Col,                   "fPion_Corrected_MomZ_Col/D");
  t1.Branch("Pion_Delta_Mom_Col",                        &fPion_Delta_Mom_Col,                        "fPion_Delta_Mom_Col/D");
  t1.Branch("Pion_Corrected_Energy_Col_GeV",             &fPion_Corrected_Energy_Col_GeV,             "fPion_Corrected_Energy_Col_GeV/D");
  t1.Branch("Pion_Corrected_Mom_Col_GeV",                &fPion_Corrected_Mom_Col_GeV,                "fPion_Corrected_Mom_Col_GeV/D");
  t1.Branch("Pion_Corrected_MomX_Col_GeV",               &fPion_Corrected_MomX_Col_GeV,               "fPion_Corrected_MomX_Col_GeV/D");
  t1.Branch("Pion_Corrected_MomY_Col_GeV",               &fPion_Corrected_MomY_Col_GeV,               "fPion_Corrected_MomY_Col_GeV/D");
  t1.Branch("Pion_Corrected_MomZ_Col_GeV",               &fPion_Corrected_MomZ_Col_GeV,               "fPion_Corrected_MomZ_Col_GeV/D");
  t1.Branch("Pion_Delta_Mom_Col_GeV",                    &fPion_Delta_Mom_Col_GeV,                    "fPion_Delta_Mom_Col_GeV/D");
  t1.Branch("Neutron_Theta_Col",                         &fNeutron_Theta_Col,                         "fNeutron_Theta_Col/D");
  t1.Branch("Neutron_Phi_Col",                           &fNeutron_Phi_Col,                           "fNeutron_Phi_Col/D");
  t1.Branch("Neutron_Mom_Col",                           &fNeutron_Mom_Col,                           "fNeutron_Mom_Col/D");
  t1.Branch("Neutron_Energy_Col",                        &fNeutron_Energy_Col,                        "fNeutron_Energy_Col/D");
  t1.Branch("Neutron_MomZ_Col",                          &fNeutron_MomZ_Col,                          "fNeutron_MomZ_Col/D");
  t1.Branch("Neutron_MomX_Col",                          &fNeutron_MomX_Col,                          "fNeutron_MomX_Col/D");
  t1.Branch("Neutron_MomY_Col",                          &fNeutron_MomY_Col,                          "fNeutron_MomY_Col/D");
  t1.Branch("Neutron_Mom_Col_GeV",                       &fNeutron_Mom_Col_GeV,                       "fNeutron_Mom_Col_GeV/D");
  t1.Branch("Neutron_Energy_Col_GeV",                    &fNeutron_Energy_Col_GeV,                    "fNeutron_Energy_Col_GeV/D");
  t1.Branch("Neutron_MomZ_Col_GeV",                      &fNeutron_MomZ_Col_GeV,                      "fNeutron_MomZ_Col_GeV/D");
  t1.Branch("Neutron_MomX_Col_GeV",                      &fNeutron_MomX_Col_GeV,                      "fNeutron_MomX_Col_GeV/D");
  t1.Branch("Neutron_MomY_Col_GeV",                      &fNeutron_MomY_Col_GeV,                      "fNeutron_MomY_Col_GeV/D");
  t1.Branch("Neutron_TargWindow_Ion_Loss",               &fNeutron_TargWindow_Ion_Loss,               "fNeutron_TargWindow_Ion_Loss/D");
  t1.Branch("Neutron_Targ_Bremss_Loss",                  &fNeutron_Targ_Bremss_Loss,                  "fNeutron_Targ_Bremss_Loss/D");
  t1.Branch("Neutron_Targ_Ion_Loss",                     &fNeutron_Targ_Ion_Loss,                     "fNeutron_Targ_Ion_Loss/D");
  t1.Branch("Neutron_Air_Bremss_Loss",                   &fNeutron_Air_Bremss_Loss,                   "fNeutron_Air_Bremss_Loss/D");
  t1.Branch("Neutron_Air_Ion_Loss",                      &fNeutron_Air_Ion_Loss,                      "fNeutron_Air_Ion_Loss/D");
  t1.Branch("Neutron_Corrected_Theta_Col",               &fNeutron_Corrected_Theta_Col,               "fNeutron_Corrected_Theta_Col/D");
  t1.Branch("Neutron_Corrected_Phi_Col",                 &fNeutron_Corrected_Phi_Col,                 "fNeutron_Corrected_Phi_Col/D");
  t1.Branch("Neutron_Corrected_Energy_Col",              &fNeutron_Corrected_Energy_Col,              "fNeutron_Corrected_Energy_Col/D");
  t1.Branch("Neutron_Corrected_Mom_Col",                 &fNeutron_Corrected_Mom_Col,                 "fNeutron_Corrected_Mom_Col/D");
  t1.Branch("Neutron_Corrected_MomX_Col",                &fNeutron_Corrected_MomX_Col,                "fNeutron_Corrected_MomX_Col/D");
  t1.Branch("Neutron_Corrected_MomY_Col",                &fNeutron_Corrected_MomY_Col,                "fNeutron_Corrected_MomY_Col/D");
  t1.Branch("Neutron_Corrected_MomZ_Col",                &fNeutron_Corrected_MomZ_Col,                "fNeutron_Corrected_MomZ_Col/D");
  t1.Branch("Neutron_Delta_Mom_Col",                     &fNeutron_Delta_Mom_Col,                     "fNeutron_Delta_Mom_Col/D");
  t1.Branch("Neutron_Corrected_Energy_Col_GeV",          &fNeutron_Corrected_Energy_Col_GeV,          "fNeutron_Corrected_Energy_Col_GeV/D");
  t1.Branch("Neutron_Corrected_Mom_Col_GeV",             &fNeutron_Corrected_Mom_Col_GeV,             "fNeutron_Corrected_Mom_Col_GeV/D");
  t1.Branch("Neutron_Corrected_MomX_Col_GeV",            &fNeutron_Corrected_MomX_Col_GeV,            "fNeutron_Corrected_MomX_Col_GeV/D");
  t1.Branch("Neutron_Corrected_MomY_Col_GeV",            &fNeutron_Corrected_MomY_Col_GeV,            "fNeutron_Corrected_MomY_Col_GeV/D");
  t1.Branch("Neutron_Corrected_MomZ_Col_GeV",            &fNeutron_Corrected_MomZ_Col_GeV,            "fNeutron_Corrected_MomZ_Col_GeV/D");
  t1.Branch("Neutron_Delta_Mom_Col_GeV",                 &fNeutron_Delta_Mom_Col_GeV,                 "fNeutron_Delta_Mom_Col_GeV/D");
  t1.Branch("RecoilProton_Theta_Col",                    &fRecoilProton_Theta_Col,                    "fRecoilProton_Theta_Col/D");
  t1.Branch("RecoilProton_Phi_Col",                      &fRecoilProton_Phi_Col,                      "fRecoilProton_Phi_Col/D");
  t1.Branch("RecoilProton_Mom_Col",                      &fRecoilProton_Mom_Col,                      "fRecoilProton_Mom_Col/D");
  t1.Branch("RecoilProton_Energy_Col",                   &fRecoilProton_Energy_Col,                   "fRecoilProton_Energy_Col/D");
  t1.Branch("RecoilProton_MomZ_Col",                     &fRecoilProton_MomZ_Col,                     "fRecoilProton_MomZ_Col/D");
  t1.Branch("RecoilProton_MomX_Col",                     &fRecoilProton_MomX_Col,                     "fRecoilProton_MomX_Col/D");
  t1.Branch("RecoilProton_MomY_Col",                     &fRecoilProton_MomY_Col,                     "fRecoilProton_MomY_Col/D");
  t1.Branch("RecoilProton_Mom_Col_GeV",                  &fRecoilProton_Mom_Col_GeV,                  "fRecoilProton_Mom_Col_GeV/D");
  t1.Branch("RecoilProton_Energy_Col_GeV",               &fRecoilProton_Energy_Col_GeV,               "fRecoilProton_Energy_Col_GeV/D");
  t1.Branch("RecoilProton_MomZ_Col_GeV",                 &fRecoilProton_MomZ_Col_GeV,                 "fRecoilProton_MomZ_Col_GeV/D");
  t1.Branch("RecoilProton_MomX_Col_GeV",                 &fRecoilProton_MomX_Col_GeV,                 "fRecoilProton_MomX_Col_GeV/D");
  t1.Branch("RecoilProton_MomY_Col_GeV",                 &fRecoilProton_MomY_Col_GeV,                 "fRecoilProton_MomY_Col_GeV/D");
  t1.Branch("RecoilProton_Targ_Bremss_Loss",             &fRecoilProton_Targ_Bremss_Loss,             "fRecoilProton_Targ_Bremss_Loss/D");
  t1.Branch("RecoilProton_Targ_Ion_Loss",                &fRecoilProton_Targ_Ion_Loss,                "fRecoilProton_Targ_Ion_Loss/D");
  t1.Branch("RecoilProton_Air_Bremss_Loss",              &fRecoilProton_Air_Bremss_Loss,              "fRecoilProton_Air_Bremss_Loss/D");
  t1.Branch("RecoilProton_Air_Ion_Loss",                 &fRecoilProton_Air_Ion_Loss,                 "fRecoilProton_Air_Ion_Loss/D");
  t1.Branch("RecoilProton_Corrected_Theta_Col",          &fRecoilProton_Corrected_Theta_Col,          "fRecoilProton_Corrected_Theta_Col/D");
  t1.Branch("RecoilProton_Corrected_Phi_Col",            &fRecoilProton_Corrected_Phi_Col,            "fRecoilProton_Corrected_Phi_Col/D");
  t1.Branch("RecoilProton_Corrected_Energy_Col",         &fRecoilProton_Corrected_Energy_Col,         "fRecoilProton_Corrected_Energy_Col/D");
  t1.Branch("RecoilProton_Corrected_Mom_Col",            &fRecoilProton_Corrected_Mom_Col,            "fRecoilProton_Corrected_Mom_Col/D");
  t1.Branch("RecoilProton_Corrected_MomX_Col",           &fRecoilProton_Corrected_MomX_Col,           "fRecoilProton_Corrected_MomX_Col/D");
  t1.Branch("RecoilProton_Corrected_MomY_Col",           &fRecoilProton_Corrected_MomY_Col,           "fRecoilProton_Corrected_MomY_Col/D");
  t1.Branch("RecoilProton_Corrected_MomZ_Col",           &fRecoilProton_Corrected_MomZ_Col,           "fRecoilProton_Corrected_MomZ_Col/D");
  t1.Branch("RecoilProton_Delta_Mom_Col",                &fRecoilProton_Delta_Mom_Col,                "fRecoilProton_Delta_Mom_Col/D");
  t1.Branch("RecoilProton_Corrected_Energy_Col_GeV",     &fRecoilProton_Corrected_Energy_Col_GeV,     "fRecoilProton_Corrected_Energy_Col_GeV/D");
  t1.Branch("RecoilProton_Corrected_Mom_Col_GeV",        &fRecoilProton_Corrected_Mom_Col_GeV,        "fRecoilProton_Corrected_Mom_Col_GeV/D");
  t1.Branch("RecoilProton_Corrected_MomX_Col_GeV",       &fRecoilProton_Corrected_MomX_Col_GeV,       "fRecoilProton_Corrected_MomX_Col_GeV/D");
  t1.Branch("RecoilProton_Corrected_MomY_Col_GeV",       &fRecoilProton_Corrected_MomY_Col_GeV,       "fRecoilProton_Corrected_MomY_Col_GeV/D");
  t1.Branch("RecoilProton_Corrected_MomZ_Col_GeV",       &fRecoilProton_Corrected_MomZ_Col_GeV,       "fRecoilProton_Corrected_MomZ_Col_GeV/D");
  t1.Branch("RecoilProton_Delta_Mom_Col_GeV",            &fRecoilProton_Delta_Mom_Col_GeV,            "fRecoilProton_Delta_Mom_Col_GeV/D");
  t1.Branch("RecoilProton_Energy_RF",                    &fRecoilProton_Energy_RF,                    "fRecoilProton_Energy_RF/D");
  t1.Branch("RecoilProton_Mom_RF",                       &fRecoilProton_Mom_RF,                       "fRecoilProton_Mom_RF/D");
  t1.Branch("RecoilProton_MomX_RF",                      &fRecoilProton_MomX_RF,                      "fRecoilProton_MomX_RF/D");
  t1.Branch("RecoilProton_MomY_RF",                      &fRecoilProton_MomY_RF,                      "fRecoilProton_MomY_RF/D");
  t1.Branch("RecoilProton_MomZ_RF",                      &fRecoilProton_MomZ_RF,                      "fRecoilProton_MomZ_RF/D");
  t1.Branch("RecoilProton_Energy_RF_GeV",                &fRecoilProton_Energy_RF_GeV,                "fRecoilProton_Energy_RF_GeV/D");
  t1.Branch("RecoilProton_Mom_RF_GeV",                   &fRecoilProton_Mom_RF_GeV,                   "fRecoilProton_Mom_RF_GeV/D");
  t1.Branch("RecoilProton_MomX_RF_GeV",                  &fRecoilProton_MomX_RF_GeV,                  "fRecoilProton_MomX_RF_GeV/D");
  t1.Branch("RecoilProton_MomY_RF_GeV",                  &fRecoilProton_MomY_RF_GeV,                  "fRecoilProton_MomY_RF_GeV/D");
  t1.Branch("RecoilProton_MomZ_RF_GeV",                  &fRecoilProton_MomZ_RF_GeV,                  "fRecoilProton_MomZ_RF_GeV/D");
  t1.Branch("RecoilProton_Theta_RF",                     &fRecoilProton_Theta_RF,                     "fRecoilProton_Theta_RF/D");
  t1.Branch("RecoilProton_Phi_RF",                       &fRecoilProton_Phi_RF,                       "fRecoilProton_Phi_RF/D");
  t1.Branch("ZASigma_UU",                                &fZASigma_UU,                                "fZASigma_UU/D");
  t1.Branch("RorySigma_UT",                              &fRorySigma_UT,                              "fRorySigma_UT/D");
  t1.Branch("ZASigma_UUPara",                            &fZASigma_UUPara,                            "fZASigma_UUPara/D");
  t1.Branch("ZASigma_Lab",                               &fZASigma_Lab,                               "fZASigma_Lab/D");
  t1.Branch("Flux_Factor_RF",                            &fFlux_Factor_RF,                            "fFlux_Factor_RF/D");
  t1.Branch("Flux_Factor_Col",                           &fFlux_Factor_Col,                           "fFlux_Factor_Col/D");
  t1.Branch("Jacobian_CM",                               &fJacobian_CM,                               "fJacobian_CM/D");
  t1.Branch("Jacobian_CM_RF",                            &fJacobian_CM_RF,                            "fJacobian_CM_RF/D");
  t1.Branch("Jacobian_CM_Col",                           &fJacobian_CM_Col,                           "fJacobian_CM_Col/D");  
  t1.Branch("PhaseSpaceWeight",                          &fPhaseSpaceWeight,                          "fPhaseSpaceWeight/D");
  t1.Branch("PhaseShiftWeight",                          &fPhaseShiftWeight,                          "fPhaseShiftWeight/D");
  t1.Branch("EventWeight",                               &fEventWeight,                               "fEventWeight/D");
  t1.Branch("WFactor",                                   &fWFactor,                                   "fWFactor/D");
  t1.Branch("A",                                         &fA,                                         "fA/D");
  t1.Branch("ZASig_T",                                   &fZASig_T,                                   "fZASig_T/D");
  t1.Branch("ZASig_L",                                   &fZASig_L,                                   "fZASig_L/D");
  t1.Branch("ZASig_LT",                                  &fZASig_LT,                                  "fZASig_LT/D");
  t1.Branch("ZASig_TT",                                  &fZASig_TT,                                  "fZASig_TT/D");
  t1.Branch("testsig",                                   &ftestsig,                                   "ftestsig/D");
  t1.Branch("Vertex_X",                                  &fVertex_X,                                  "fVertex_X/D");
  t1.Branch("Vertex_Y",                                  &fVertex_Y,                                  "fVertex_Y/D");
  t1.Branch("Vertex_Z",                                  &fVertex_Z,                                  "fVertex_Z/D");

  t1.Branch("Phi_Pion_LeptonPlane_RF",                   &fPhi_Pion_LeptonPlane_RF,                   "fPhi_Pion_LeptonPlane_RF/D");
  t1.Branch("Cos_Phi_Pion_LeptonPlane_RF",               &fCos_Phi_Pion_LeptonPlane_RF,               "fCos_Phi_Pion_LeptonPlane_RF/D");
  t1.Branch("Sin_Phi_Pion_LeptonPlane_RF",               &fSin_Phi_Pion_LeptonPlane_RF,               "fSin_Phi_Pion_LeptonPlane_RF/D");
  t1.Branch("Phi_TargPol_LeptonPlane_RF",                &fPhi_TargPol_LeptonPlane_RF,                "fPhi_TargPol_LeptonPlane_RF/D");
  t1.Branch("Cos_Phi_TargPol_LeptonPlane_RF",            &fCos_Phi_TargPol_LeptonPlane_RF,            "fCos_Phi_TargPol_LeptonPlane_RF/D");
  t1.Branch("Sin_Phi_TargPol_LeptonPlane_RF",            &fSin_Phi_TargPol_LeptonPlane_RF,            "fSin_Phi_TargPol_LeptonPlane_RF/D");
  t1.Branch("Theta_Pion_Photon_RF",                      &fTheta_Pion_Photon_RF,                      "fTheta_Pion_Photon_RF/D");

  t1.Branch("SSAsym",                                    &fSSAsym,                                    "fSSAsym/D");
  t1.Branch("SineAsym",                                  &fSineAsym,                                  "fSineAsym/D");
  t1.Branch("AsymPhiMinusPhi_S",                         &fAsymPhiMinusPhi_S,                         "fAsymPhiMinusPhi_S/D");
  t1.Branch("AsymPhi_S",                                 &fAsymPhi_S,                                 "fAsymPhi_S/D");
  t1.Branch("Asym2PhiMinusPhi_S",                        &fAsym2PhiMinusPhi_S,                        "fAsym2PhiMinusPhi_S/D");
  t1.Branch("AsymPhiPlusPhi_S",                          &fAsymPhiPlusPhi_S,                          "fAsymPhiPlusPhi_S/D");
  t1.Branch("Asym3PhiMinusPhi_S",                        &fAsym3PhiMinusPhi_S,                        "fAsym3PhiMinusPhi_S/D");

  /* t1.Branch("Asym_Hermes_1",                             &fAsym_Hermes_1,                             "fAsym_Hermes_1/D"); */
  /* t1.Branch("Asym_Hermes_2",                             &fAsym_Hermes_2,                             "fAsym_Hermes_2/D"); */
  /* t1.Branch("Asym_Hermes_3",                             &fAsym_Hermes_3,                             "fAsym_Hermes_3/D"); */
  /* t1.Branch("Asym_Hermes_4",                             &fAsym_Hermes_4,                             "fAsym_Hermes_4/D"); */
  /* t1.Branch("Asym_Hermes_5",                             &fAsym_Hermes_5,                             "fAsym_Hermes_5/D"); */
  /* t1.Branch("Asym_Hermes_6",                             &fAsym_Hermes_6,                             "fAsym_Hermes_6/D"); */
  /* t1.Branch("Coef_Hermes_1",                             &fCoef_Hermes_1,                             "fCoef_Hermes_1/D"); */
  /* t1.Branch("Coef_Hermes_2",                             &fCoef_Hermes_2,                             "fCoef_Hermes_2/D"); */
  /* t1.Branch("Coef_Hermes_3",                             &fCoef_Hermes_3,                             "fCoef_Hermes_3/D"); */
  /* t1.Branch("Coef_Hermes_4",                             &fCoef_Hermes_4,                             "fCoef_Hermes_4/D"); */
  /* t1.Branch("Coef_Hermes_5",                             &fCoef_Hermes_5,                             "fCoef_Hermes_5/D"); */
  /* t1.Branch("Coef_Hermes_6",                             &fCoef_Hermes_6,                             "fCoef_Hermes_6/D"); */
  /* t1.Branch("Coef_ZA_1",                                 &fCoef_ZA_1,                                 "fCoef_ZA_1/D"); */
  /* t1.Branch("Coef_ZA_2",                                 &fCoef_ZA_2,                                 "fCoef_ZA_2/D"); */
  /* t1.Branch("Coef_ZA_3",                                 &fCoef_ZA_3,                                 "fCoef_ZA_3/D"); */
  /* t1.Branch("Coef_ZA_4",                                 &fCoef_ZA_4,                                 "fCoef_ZA_4/D"); */
  /* t1.Branch("Coef_ZA_5",                                 &fCoef_ZA_5,                                 "fCoef_ZA_5/D"); */
  /* t1.Branch("Coef_ZA_6",                                 &fCoef_ZA_6,                                 "fCoef_ZA_6/D"); */

}
