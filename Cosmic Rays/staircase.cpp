// c++ -o staircase staircase.cpp `root-config --glibs --cflags`

#include <iostream>

#include <TStyle.h>
#include <TApplication.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TGraphErrors.h>
#include <TAxis.h>
#include <TMultiGraph.h>
#include "TLegend.h"


using namespace std;


int main (int argc, char ** argv)
{
	if (argc < 2)
    	{
	      	cout << "Not enough parameters: ./v_br dati.txt" << endl;
	      	return 1;
    	}
    	
    	gStyle->SetOptFit(1112);	
    	
    	TApplication* myApp = new TApplication("myApp", NULL, NULL);
  	TCanvas* myC = new TCanvas("myC","myC",0,0,700,500);
  	
  	TMultiGraph *mg = new TMultiGraph();
  	mg -> SetTitle ("Staircase");
  	
  	
  	// grafico con gli errori
  	TGraphErrors* myGraph1 = new TGraphErrors(argv[1]);
  	myGraph1->SetMarkerStyle(7);
  	myGraph1->SetMarkerColor(99);
  	myGraph1->SetLineColor(99);
  	myGraph1->SetTitle("Data collected without the scinillator");
  	
  	
  	// grafico con gli errori
  	TGraphErrors* myGraph2 = new TGraphErrors(argv[2]);
  	myGraph2->SetMarkerStyle(7);
  	myGraph2->SetMarkerColor(57);
  	myGraph2->SetLineColor(57);
  	myGraph2->SetTitle("Data collected with the scinillator");
  	//myGraph2->SetMarkerSize(108);
  	
  	

	// disegno
	myC->cd();
	mg->Add(myGraph1);
	mg->Add(myGraph2);
	
	//myC->SetLogy();
	mg->GetXaxis()->SetTitle("Threshold [mV]");
  	mg->GetYaxis()->SetTitle("Log Frequency [Hz]");
  	mg->Draw("ALP");
  	
   myC->BuildLegend();

  	
  	myC->Modified();
  	myC->Update();
  	
    
    
  	myApp->Run();

	return 0;
}



