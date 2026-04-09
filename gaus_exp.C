void gaus_exp(){

auto efunc = new TF1("efunc", "[0]*exp(-x/[1]) + gaus(2)", 100., 160.);
efunc->SetParameter(0,9000);
efunc->SetParameter(1,60);
efunc->SetParameter(2,150);
efunc->SetParameter(3,127);
efunc->SetParameter(4,3);

auto h = new TH1F ("exp+gauss","Exponencial+gaussiana",100,100.,160.);
for (int i=0;i<6e5;i++) {h->Fill(efunc->GetRandom());}
h->Draw();

auto fitFunc = new TF1 ("fitFunc","gaus(0)",123.,132.);
h->Fit(fitFunc, "R");



}
