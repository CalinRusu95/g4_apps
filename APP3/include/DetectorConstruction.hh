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
/// \file electromagnetic/TestEm7/include/DetectorConstruction.hh
/// \brief Definition of the DetectorConstruction class
//
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "G4ThreeVector.hh"

class G4LogicalVolume;
class G4Material;
class G4UniformMagField;
class DetectorMessenger;

const G4int kMaxTally = 20000;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
  
  DetectorConstruction();
  virtual ~DetectorConstruction();
  
  G4LogicalVolume* GetScoringVolume() const { return fScoringVolume; }

  void SetSizeZ    (G4double);
  void SetSizeXY   (G4double);              
  void SetMaterial (const G4String&);            
  void SetWorldMaterial (const G4String&);            
  void SetMagField (G4double);
  //void GetSurfaceFlux(G4int);

     
  void SetTallyNumber   (G4int);     
  void SetTallySize     (G4int, G4double);
  void SetTallyPosition (G4int, const G4ThreeVector&);

  virtual G4VPhysicalVolume* Construct();
     
  inline G4double GetAbsorSizeZ()  const {return fAbsorSizeZ;};
  inline G4double GetAbsorSizeXY() const {return fAbsorSizeXY;};           
  inline G4int    GetTallyNumber() const {return fTallyNumber;};

  inline const G4Material* GetWorldMaterial() const {return fWorldMaterial;};
  inline const G4Material* GetAbsorMaterial() const {return fAbsorMaterial;};
     
  G4double GetTallyMass(G4int n) const;
  const G4LogicalVolume* GetLogicalTally(G4int n) const;
     
  void PrintParameters() const;
  virtual void ConstructSDandField(G4int j);


  
private:

  void                DefineMaterials();
  
  G4double            fAbsorSizeZ;
  G4double            fAbsorSizeXY;     

  G4Material*         fAbsorMaterial;
  G4Material*         fWorldMaterial;           

  G4UniformMagField*  fMagField;
  G4LogicalVolume*    fLAbsor;
  G4LogicalVolume*    fLWorld;
     
  G4int               fTallyNumber;                   
  G4double		      fTallySize;
  G4double            fTallyMass[kMaxTally]; 
  G4ThreeVector       fTallyPosition[kMaxTally];
  G4LogicalVolume*    fLTally[kMaxTally];
     
  DetectorMessenger*  fDetectorMessenger;

  G4String fMfdName;

  
   protected:
		G4LogicalVolume*  fScoringVolume;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
