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
// $Id: G4PSPassageCurrent.hh,v 1.3 2006/06/29 18:07:17 gunter Exp $
// GEANT4 tag $Name: geant4-08-01 $
//

#ifndef G4PSPassageCurrent_h
#define G4PSPassageCurrent_h 1

#include "G4VPrimitiveScorer.hh"
#include "G4THitsMap.hh"

////////////////////////////////////////////////////////////////////////////////
// (Description)
//   This is a primitive scorer class for scoring current.
//   The number of tracks passing through the geometry are taken 
//  into account.
//
// Created: 2005-11-14  Tsukasa ASO, Akinori Kimura.
// 
///////////////////////////////////////////////////////////////////////////////


class G4PSPassageCurrent : public G4VPrimitiveScorer
{

public: // with description
	G4PSPassageCurrent(G4String name, G4int depth = 0);

public:
	virtual ~G4PSPassageCurrent();

protected: // with description
	virtual G4bool ProcessHits(G4Step*, G4TouchableHistory*);

	virtual G4bool IsPassed(G4Step*);

public:
	virtual void Initialize(G4HCofThisEvent*);
	virtual void EndOfEvent(G4HCofThisEvent*);
	virtual void clear();

public:
	virtual void DrawAll();
	virtual void PrintAll();

private:
	G4int HCID;
	G4int fCurrentTrkID;
	G4double fCurrent;
	G4double fCurrentSquare;
	G4THitsMap<G4double>* EvtMap;

};

#endif

