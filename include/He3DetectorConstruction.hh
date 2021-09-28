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
/// \file He3DetectorConstruction.hh
/// \brief Definition of the He3DetectorConstruction class

#ifndef He3DetectorConstruction_h
#define He3DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4GlobalMagFieldMessenger;

/// Detector construction class to define materials and geometry.
/// The calorimeter is a box made of a given number of layers. A layer consists
/// of an absorber plate and of a detection gap. The layer is replicated.
///
/// Four parameters define the geometry of the calorimeter :
///
/// - the thickness of an absorber plate,
/// - the thickness of a gap,
/// - the number of layers,
/// - the transverse size of the calorimeter (the input face is a square).
///
/// In addition a transverse uniform magnetic field is defined 
/// via G4GlobalMagFieldMessenger class.

class He3DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    He3DetectorConstruction();
    virtual ~He3DetectorConstruction();

  public:
    virtual G4VPhysicalVolume* Construct();
    virtual void ConstructSDandField();

    // get methods
    //
    const G4VPhysicalVolume* GetAbsorberPV() const;
    const G4VPhysicalVolume* GetAbsorberPV1() const;
    const G4VPhysicalVolume* GetAbsorberPV2() const;
    const G4VPhysicalVolume* GetGapPV() const;
    const G4VPhysicalVolume* GetGapPV2() const;
    const G4VPhysicalVolume* GetHoldPV_Beo() const;
    
     
  private:
    // methods
    //
    void DefineMaterials();
    G4VPhysicalVolume* DefineVolumes();
  
    // data members
    //
    static G4ThreadLocal G4GlobalMagFieldMessenger*  fMagFieldMessenger; 
                                      // magnetic field messenger
     
    G4VPhysicalVolume*   fAbsorberPV; // the absorber physical volume
    G4VPhysicalVolume*   fGapPV;      // the gap physical volume
    G4VPhysicalVolume*   fGapPV2; 
    G4VPhysicalVolume*   fHoldPV;
    G4VPhysicalVolume*   fAbsorberPV1; 
    G4VPhysicalVolume*   fAbsorberPV2;
    G4VPhysicalVolume*   fHoldPV_Beo;
    
    G4bool  fCheckOverlaps; // option to activate checking of volumes overlaps
};

// inline functions

inline const G4VPhysicalVolume* He3DetectorConstruction::GetAbsorberPV() const { 
  return fAbsorberPV; 
}
inline const G4VPhysicalVolume* He3DetectorConstruction::GetAbsorberPV1() const { 
  return fAbsorberPV1; 
}
inline const G4VPhysicalVolume* He3DetectorConstruction::GetAbsorberPV2() const { 
  return fAbsorberPV2; 
}

inline const G4VPhysicalVolume* He3DetectorConstruction::GetGapPV() const  { 
  return fGapPV; 
}
inline const G4VPhysicalVolume* He3DetectorConstruction::GetGapPV2() const  { 
  return fGapPV2; 
}
inline const G4VPhysicalVolume* He3DetectorConstruction::GetHoldPV_Beo() const  { 
  return fHoldPV_Beo; 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

