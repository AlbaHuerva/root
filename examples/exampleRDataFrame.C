//Class as data container
class dataContainer {
public:
dataContainer(){ };
float current;
float temperature;
float pressure;
};

void exampleRDataFrame( ){

ROOT::RDataFrame df("tree_data", "FileWithTree.root");
auto d = df.Display("",10);
d->Print();
auto h = df.Histo1D({"histo","temperature",100,240,360},"temperature");
h->DrawClone();
auto h2 = df.Histo2D({"histo2","tempvscurrent",100,240,360,100,0.4,1.6},"temperature","current");
h2->DrawClone();
}


void exampleRDataFrameCreate( ){

// Create a data frame with 100 rows
ROOT::RDataFrame d(1000);
 
// Define a new column `x` that contains random numbers
d.Define("temperature", [](){ return gRandom->Uniform(250.,350.)+gRandom->Gaus(0.,0.3); }).Define("pressure", [](){ return gRandom->Uniform(0.5,1.5)*gRandom->Gaus(1.,0.02); }).Define("current", [](){ return gRandom->Gaus(1.,0.5); }).Snapshot("tree_data","FileRdataFrame.root");

ROOT::RDataFrame df("tree_data", "FileRdataFrame.root");

auto df2 = df.Filter("pressure<1").Filter("temperature<300");
auto h2 = df2.Histo2D({"histo2","tempvspressure",100,240,360,100,0.4,1.6},"temperature","pressure");
h2->DrawClone();

}


void exampleRDataFrameRead( ){

ROOT::RDataFrame df("tree_data", "FileRdataFrame.root");
auto d = df.Display("",10);
d->Print();

auto df2 = df.Filter("pressure>1").Filter("temperature>300");
auto h2 = df2.Histo2D({"histo2","tempvspressure",100,240,360,100,0.4,1.6},"temperature","pressure");
h2->DrawClone();

}

