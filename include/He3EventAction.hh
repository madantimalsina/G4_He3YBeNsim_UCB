//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// 
/// \file He3EventAction.hh
/// \brief Definition of the He3EventAction class

#ifndef He3EventAction_h
#define He3EventAction_h 1

#include "G4UserEventAction.hh"
#include "G4ThreeVector.hh"
#include "globals.hh"

/// Event action class
///
/// It defines data members to hold the energy deposit and track lengths
/// of charged particles in Absober and Gap layers:
/// - fEnergyAbs, fEnergyGap, fTrackLAbs, fTrackLGap
/// which are collected step by step via the functions
/// - AddAbs(), AddGap()

class He3EventAction : public G4UserEventAction
{
  public:
    He3EventAction();
    virtual ~He3EventAction();

    virtual void  BeginOfEventAction(const G4Event* event);
    virtual void    EndOfEventAction(const G4Event* event);
    
    void AddAbs(G4double de, G4double dl, G4ThreeVector position, G4double eki_abs, G4double ekf_abs);
    void AddGap(G4double de, G4double dl);
    void AddBe(G4double eki_be, G4double ekf_be, G4double de, G4ThreeVector position);
    void AddW(G4double eki_be, G4double ekf_be, G4double de, G4ThreeVector position);

  private:
    G4double  fEnergyAbs;
    G4double  fEnergyGap;
    G4double  fEnergy_gen;
    G4double  fTrackLAbs; 
    G4double  fTrackLGap;
    G4double fpositionHe3[3];
    G4double fposition_gen[3];
    G4double fpositionHe3c[3];
    
    G4double Eki_Be;
    G4double Ekf_Be;

    G4double Eki_W;
    G4double Ekf_W;

    G4double Eki_abs;
    G4double Ekf_abs;
};

// inline functions
inline void He3EventAction::AddAbs(G4double de, G4double dl, G4ThreeVector position, G4double eki_abs, G4double ekf_abs) {
  fEnergyAbs += de; 
  fTrackLAbs += dl;

  fpositionHe3[0] = position.x();
  fpositionHe3[1] = position.y();
  fpositionHe3[2] = position.z();

  fpositionHe3c[0] = position.x();
  fpositionHe3c[1] = position.y();
  fpositionHe3c[2] = position.z();

  Eki_abs += eki_abs; 
  Ekf_abs += ekf_abs;

}
inline void He3EventAction::AddGap(G4double de, G4double dl) {
  fEnergyGap += de; 
  fTrackLGap += dl;

}

inline void He3EventAction::AddBe(G4double eki_be, G4double ekf_be, G4double de, G4ThreeVector position) {
  Eki_Be = eki_be; 
  Ekf_Be = ekf_be;
  fEnergy_gen += de; 

  fposition_gen[0] = position.x();
  fposition_gen[1] = position.y();
  fposition_gen[2] = position.z();

}

inline void He3EventAction::AddW(G4double eki_w, G4double ekf_w, G4double de, G4ThreeVector position) {
  Eki_W = eki_w; 
  Ekf_W = ekf_w;
  fEnergy_gen += de; 

  fposition_gen[0] = position.x();
  fposition_gen[1] = position.y();
  fposition_gen[2] = position.z();

}


                     
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

    
