// c++ -o histo histo.cpp `root-config --glibs --cflags`


#include <iostream>
#include <fstream>
#include <vector>
#include <TStyle.h>
#include <TApplication.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TRandom.h>
#include <TAxis.h>
#include <TH1F.h>
#include "TLegend.h"


using namespace std;


int main (int argc, char ** argv)
{
	if (argc < 1)
    	{
	      	cout << "Not enough parameters: ./v_br dati.txt" << endl;
	      	return 1;
    	}
    	
    	//gStyle->SetOptFit();	
    	gStyle->SetOptStat(0000);	
    	
    	TApplication* myApp = new TApplication("myApp", NULL, NULL);
  	TCanvas* myC = new TCanvas("myC","myC",0,0,700,500);
  	
  	ifstream myfile ;
         myfile.open (argv[1]) ;
  	vector<double> mystring;
  	
  	int i=0;
  	cout<<"uno \n";
  	while (true) {
  	   double a;
  	   myfile >> a;
  	   
  	   mystring.push_back(a);
  	   //cout<<mystring.at(i);
  	   i++;
  	   //cout<< " " +i;
  	   if (myfile.eof () == true) break ;
  	   //if (i>=100) break;
  	}
  	cout<< i;
  	
  	myfile.close();
  	
  	ifstream myfile1; 
  	myfile1.open(argv[2]);
  	vector<double> mystring1;
  	
  	 i=0;
  	cout<<"due \n";
  	while (true) {
  	   double b;
  	   myfile1 >> b;
  	   mystring1.push_back(b);
  	   i++;
  	   //cout<<mystring1.at(i);
  	   if (myfile1.eof () == true) break ;
  	}
  	
  	myfile1.close();
  	
  	ifstream myfile2; 
  	myfile2.open(argv[3]);
  	vector<double> mystring2;
  	
  	i=0;
  	cout<<"tre \n";
  	while (true) {
  	   double c;
  	   myfile2 >> c;
  	   mystring2.push_back(c);
  	   i++;
  	   //cout<<mystring.at(i);
  	   if (myfile2.eof () == true) break ;
  	}
  	
  	myfile2.close();
  	
  	//exit(1);
  	TH1F *h1 = new TH1F("h1","histogram",37001,225003.5,520996);
  	
  	for(unsigned i=0; i<mystring.size(); i++){
  	h1->AddBinContent(i, mystring1.at(i)); //fill with weight
  	}
  	
  	h1->SetFillColor(kBlue);
  	h1->SetLineColor(kBlue);
  	//h1->SetFillStyle(3351);
  	h1->SetTitle("Data collected without shielding");
  	
  	TH1F *h2 = new TH1F("h2","histogram",37001,225003.5,520996);
  	
  	for(unsigned i=0; i<mystring.size(); i++){
  	h2->AddBinContent(i, mystring2.at(i)); //fill with weight
  	}
  	
  	h2->SetFillColor(kCyan);
  	h2->SetLineColor(kCyan);
  	//h2->SetFillStyle(3351);
  	h2->SetTitle("Data collected with shielding");

	// disegno
	myC->cd();
	h1->Draw();
	h2->Draw("same");
	
	
	//myC->SetLogy();
	h1->GetXaxis()->SetTitle("ADC Channels");
  	h1->GetYaxis()->SetTitle("Counts");
  	
  	
         myC->BuildLegend();

  	
  	myC->Modified();
  	myC->Update();
  	
    
    
  	myApp->Run();

	return 0;
}



