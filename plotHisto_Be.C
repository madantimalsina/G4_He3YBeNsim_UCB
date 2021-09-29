// ROOT macro file for plotting example He3 histograms 
// 
// Can be run from ROOT session:
// root[0] .x plotHisto.C

{
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  
  // Draw histos filled by Geant4 simulation 
  //   

  // Open file filled by Geant4 simulation 
  TFile f("YBe_2mEvt_UCB_2inMThickness.root");

  // Create a canvas and divide it into 2x2 pads
  TCanvas* c1 = new TCanvas("c1", "", 20, 20, 2000, 1000);
  //gPad->SetLogy(1);
  //gPad->SetGrid();
  c1->Divide(2,2);
  
  // Draw Eabs histogram in the pad 1
  c1->cd(1);
  gPad->SetLogy(1);
  gPad->SetGrid();
  TH1D* hist1 = (TH1D*)f.Get("Ek_f_Be");
  hist1->SetTitle("Neutron K.E. coming out Be Metal that hits He3 tube (2 in PE)"); 
  hist1->GetXaxis()->SetTitle("Ek [MeV]"); 
  hist1->Draw("HIST");

  c1->cd(2);
  gPad->SetGrid();
  //TH1D* hist1 = (TH1D*)f.Get("Ek_f_Be");
  hist1->SetTitle("Neutron K.E. coming out Be Metal that hits He3 tube (2 in PE)"); 
  hist1->GetXaxis()->SetTitle("Ek [MeV]"); 
  hist1->Draw("HIST");

  c1->cd(3);
  gPad->SetLogy(1);
  gPad->SetGrid();
  TH1D* hist2 = (TH1D*)f.Get("Ek_f_Be_detected");
  hist2->SetTitle("Neutron K.E. coming out Be Metal that detected (2 in PE)"); 
  hist2->GetXaxis()->SetTitle("Ek [MeV]"); 
  hist2->Draw("HIST");

  c1->cd(4);
  gPad->SetGrid();
  //TH1D* hist1 = (TH1D*)f.Get("Ek_f_Be");
  hist2->SetTitle("Neutron K.E. coming out Be Metal that detected (2 in PE)"); 
  hist2->GetXaxis()->SetTitle("Ek [MeV]"); 
  hist2->Draw("HIST");

  /*
  // Draw Labs histogram in the pad 2
  c1->cd(2);
  TH1D* hist2 = (TH1D*)f.Get("Labs");
  hist2->Draw("HIST");
  
  // Draw Egap histogram in the pad 3
  // with logaritmic scale for y
  TH1D* hist3 = (TH1D*)f.Get("Egap");
  c1->cd(3);
  gPad->SetLogy(1);
  hist3->Draw("HIST");
  
  // Draw Lgap histogram in the pad 4
  // with logaritmic scale for y
  c1->cd(4);
  gPad->SetLogy(1);
  TH1D* hist4 = (TH1D*)f.Get("Lgap");
  hist4->Draw("HIST");
  */
}  
