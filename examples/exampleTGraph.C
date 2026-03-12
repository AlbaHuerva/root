
void exampleTGraph(){

auto gr = new TGraph();

  for (int i=0;i<10;i++){
    const double x = i;
    const double y = x*x;
    gr->SetPoint(i,x,y);
  }

gr->SetTitle("Example TGraph");
gr->Draw("ALP");
}

void exampleTGraphErrors(){

auto gr = new TGraphErrors();

  for (int i=0;i<10;i++){
    const double x = i;
    const double y = x*x;
    gr->SetPoint(i,x,y);
    gr->SetPointError(i,0.1,y*0.05);
  }

gr->SetTitle("Example TGraph");
gr->Draw("ALP");
}

