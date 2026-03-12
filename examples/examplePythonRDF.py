import ROOT

df = ROOT.RDataFrame("tree_data", "FileRdataFrame.root")
df2 = df.Filter("pressure<1").Filter("temperature<300");
h2 = df2.Histo2D(("histo2","tempvspressure",100,240,360,100,0.4,1.6),"temperature","pressure");
h2.Draw();

