// ROOT macro file for plotting example He3 ntuple
// 
// Can be run from ROOT session:
// root[0] .x plotNtuple.C

void plotNtuple() {
  gROOT->Reset();
  gROOT->SetStyle("Plain");

  
  // Draw histos filled by Geant4 simulation 
  //   

  // Open file filled by Geant4 simulation 
    // Open file filled by Geant4 simulation 

char filename[80];
char moreFiles;

cout << "Name of root file: " << endl;
cin >> filename;

  TFile *f = TFile::Open(filename,"r");
  //TFile *f = TFile::Open("YBe_100kEvt_UCB_1inMThickness.root");
  // Get ntuple
  TNtuple* ntuple = (TNtuple*)f->Get("He3");
  TTree* tree = (TTree*)f->Get("He3");
  uint nentries = tree->GetEntries();

  // Inside He3 Tube
  // Central Tube
  TCanvas* c1_T = new TCanvas("c1_T", "", 20, 20, 800, 800);
  gPad->SetLogy(1);
  gPad->SetGrid();
  //gPad->GetYaxis()->SetTitle("MeV");
  Int_t y1_T = 0;
  Int_t z1_T = 0;
  Double_t Ek_f_Be;
  tree->SetBranchAddress("Ek_f_Be",&Ek_f_Be);
  ntuple->Draw("Ek_f_Be");
  TH1* hist = (TH1*) gPad->GetListOfPrimitives()->FindObject("htemp"); 
  hist->SetTitle("2 in Moderator Thickness"); 
  hist->GetXaxis()->SetTitle("Ek [MeV]"); 
  gPad->Update();
  //ntuple->Draw("Ek_f_Be");
  //ntuple->GetYaxis()->SetTitle("MeV");
  for(int i=0; i<nentries; i++){
    tree->GetEntry(i);
    if(Ek_f_Be > 0)
    { //cout<<"Center Tube: "<<Ek_f_Be<<endl;
    y1_T++;}

    if(Ek_f_Be >= 0.0)
    { //cout<<"Center Tube (Edep >= 0.0): "<< Ek_f_Be <<endl;
    z1_T++;}
  } 

      cout << "\n" << endl;
    cout << "Simulated Events: " << nentries << endl;
     cout << "\n" << endl;
    cout << "NOW INSIDE HE3 TUBES:::::.\n" << endl;
    cout << "Center Tube: " << y1_T << endl;
    //cout << "Left Side Tube1: " << y2_T << endl;
    //cout << "Right Side Tube2: " << y3_T << endl; 
    //cout << "Total = "<< y1_T + y2_T + y3_T << endl;

    cout << "\n" << endl;
    cout << "nHits (Edep >= 0.15)" << endl;
    cout << "Center Tube: " << z1_T << endl;
}
