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
/// \file He3SteppingAction.cc
/// \brief Implementation of the He3SteppingAction class

#include "He3SteppingAction.hh"
#include "He3EventAction.hh"
#include "He3DetectorConstruction.hh"
#include "YBe_PrimaryGeneratorAction.hh"
//#include "YBe_PrimaryGeneratorAction.cc"

#include "G4Neutron.hh"
#include "G4Step.hh"
#include "G4RunManager.hh"

#include "globals.hh"
#include "G4Step.hh"
#include "G4StepPoint.hh"
#include "G4Track.hh"
#include "G4ThreeVector.hh"
#include "G4EventManager.hh"
#include "G4Event.hh"
//#include "StepInfo.hh"

#include "G4SteppingVerbose.hh"
#include "G4SteppingManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4VSensitiveDetector.hh"    // Include from 'hits/digi'
#include "G4StepStatus.hh"    // Include from 'tracking'
//#include "StepInfo.cc"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//G4double neutron_energy = 0;

He3SteppingAction::He3SteppingAction(
                      const He3DetectorConstruction* detectorConstruction,
                      He3EventAction* eventAction)
  : G4UserSteppingAction(),
    fDetConstruction(detectorConstruction),
    fEventAction(eventAction)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

He3SteppingAction::~He3SteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void He3SteppingAction::UserSteppingAction(const G4Step* step)
//G4double neutron_energy = 0;
{
// Collect energy and track length step by step
    G4StepPoint* postStep = step->GetPostStepPoint();
    G4StepPoint* preStep = step->GetPreStepPoint();

  // get volume of the current step
  auto volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
  
  //energy
    auto energy_i = preStep->GetKineticEnergy();
    auto energy_f = postStep->GetKineticEnergy();
    auto edep = step->GetTotalEnergyDeposit(); 

  G4Track* track = step->GetTrack();
  //G4ThreeVector position = track->GetPosition();
  
  // step length
  G4double stepLength = 0.;
  if ( step->GetTrack()->GetDefinition()->GetPDGCharge() != 0. ) {
    stepLength = step->GetStepLength();

    //G4ThreeVector position = step->GetPosition();
    //G4double time = track->GetGlobalTime();

  }
      
  if ( volume == fDetConstruction->GetAbsorberPV() ) {
    G4ThreeVector position = track->GetPosition();
    fEventAction->AddAbs(edep,stepLength, position, energy_i, energy_f);
  }
  
  if ( volume == fDetConstruction->GetGapPV() ) {
    //G4ThreeVector position = track->GetPosition();
    fEventAction->AddGap(edep,stepLength);
  }
  if ( volume == fDetConstruction->GetHoldPV_Beo()){
    G4ThreeVector position = track->GetPosition();
    //auto energy_n = neutron_energy;
     fEventAction->AddBe(energy_i, energy_f,edep, position);
  }

  if ( volume == fDetConstruction->GetHoldPV_W()){
    G4ThreeVector position = track->GetPosition();
    //auto energy_n = neutron_energy;
     fEventAction->AddW(energy_i, energy_f,edep, position);
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
