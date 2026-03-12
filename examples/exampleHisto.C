void exampleHisto () {

auto efunc = new TF1 ("efunc","gaus(0)",0.,10.);
efunc->SetParameter(0,1);
efunc->SetParameter(1,5);
efunc->SetParameter(2,0.5);

auto h = new TH1F ("example histo","example histogram",100,0.,10.);
for (int i=0;i<1000;i++) {h->Fill(efunc->GetRandom());}
h->Draw();

}

void exampleHistoFit () {

auto efunc = new TF1 ("efunc","gaus(0)",0.,10.);
efunc->SetParameter(0,1);
efunc->SetParameter(1,5);
efunc->SetParameter(2,0.5);

auto h = new TH1F ("example histo","example histogram",100,0.,10.);
for (int i=0;i<1000;i++) {h->Fill(efunc->GetRandom());}
h->Draw();

auto fitFunc = new TF1 ("fitFunc","gaus(0)",0.,10.);
h->Fit(fitFunc);
}

void exampleHisto2D () {

auto efunc = new TF2 ("2DGauss","[0]*TMath::Exp(- (x - [1])^2/(2*[2]*[2]) - (y - [3])^2/(2*[4]*[4]) )",0.,10.,0,10);
efunc->SetParameter(0,1);
efunc->SetParameter(1,5);efunc->SetParameter(3,5);
efunc->SetParameter(2,0.5);efunc->SetParameter(4,0.5);

auto h = new TH2F ("example histo","example histogram",100,0.,10.,100,0.,10.);
  for (int i=0;i<10000;i++) {
    double x,y;
    efunc->GetRandom2(x,y);
    h->Fill(x,y);
  }
h->Draw("COLZ");

}
