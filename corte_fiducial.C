void corte_fiducial() {

    ROOT::RDataFrame df("AnalysisTree", "CalibrationData.root");

    TCanvas *c1 = new TCanvas("c1","Histogramas",800,600);
    
    auto h = df.Histo1D({"hAmplitude","Amplitud;Amplitud;Cuentas",100,0,15000}, "Amplitude");
    
    h->SetLineColor(kBlue);
    h->DrawClone();

    // Cortes fiduciales        
    auto df2 = df.Filter("posX.posX > 27.5")
             .Filter("posX.posX < 32.5")
             .Filter("posY.posY > 27.5")
             .Filter("posY.posY < 32.5");


    auto hAmplitude = df2.Histo1D({"hAmplitude","Amplitud;Amplitud;Cuentas",100,0,15000}, "Amplitude");
    
    hAmplitude->SetLineColor(kRed);
    hAmplitude->DrawClone("same");
    
}
