//Class as data container
class dataContainer {
public:
dataContainer(){ };
float current;
float temperature;
float pressure;
};

void exampleTTree( ){

   auto ofile = TFile::Open("FileWithTree.root","RECREATE");
   // Initialise the TTree
   TTree treeData("tree_data", "Example Tree");
   dataContainer dc;
   treeData.Branch("myBranch", &dc);

   for (int i=0;i<1000;++i){
      // Fill it randomly to fake the acquired data
      dc.temperature=gRandom->Uniform(250.,350.)+gRandom->Gaus(0.,0.3);
      dc.pressure=gRandom->Uniform(0.5,1.5)*gRandom->Gaus(1.,0.02);
      dc.current= gRandom->Gaus(1.,0.5);
      // Fill the tree
      treeData.Fill();
   }
   // Save the ntuple and close the file
   treeData.Write();
   ofile->Close();
}



void exampleTTreeRead( ){

  auto infile = TFile::Open("FileWithTree.root","READ");
  dataContainer *dc;
  auto treeData = infile->Get<TTree>("tree_data");
  treeData->SetBranchAddress("myBranch", &dc);

  cout<<"Tree entries "<<treeData->GetEntries()<<endl;

    for(int i=0; i<10; i++){
      treeData->GetEntry(i);
      cout<<i<<" "<<dc->current<<" "<<dc->temperature<<" "<<dc->pressure<<endl;
    }

  treeData->Draw("temperature:pressure");

}

