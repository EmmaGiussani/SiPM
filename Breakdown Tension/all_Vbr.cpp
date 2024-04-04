// c++ -o all_Vbr all_Vbr.cpp `root-config --glibs --cflags`

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
  	mg -> SetTitle ("DCR vs. V_{bias}");
  	
  	
  	// grafico con gli errori
  	TGraphErrors* myGraph1 = new TGraphErrors(argv[1]);
  	myGraph1->SetMarkerStyle(26);
  	myGraph1->SetMarkerColor(60);
  	myGraph1-> SetTitle("Data at 18#circ C");
  	myGraph1->SetLineColor(kWhite);
  	
  	
  	// grafico con gli errori
  	TGraphErrors* myGraph2 = new TGraphErrors(argv[2]);
  	myGraph2->SetMarkerStyle(25);
  	myGraph2->SetMarkerColor(79);
  	//myGraph2->SetMarkerSize(108);
  	myGraph2-> SetTitle("Data at 22#circ C");
  	myGraph2->SetLineColor(kWhite);
  	
  	
  	// grafico con gli errori
  	TGraphErrors* myGraph3 = new TGraphErrors(argv[3]);
  	myGraph3->SetMarkerStyle(24);
  	myGraph3->SetMarkerColor(90);
  	myGraph3-> SetTitle("Data at 27#circ C");
  	myGraph3->SetLineColor(kWhite);
  	
  	
  	// grafico con gli errori
  	TGraphErrors* myGraph4 = new TGraphErrors(argv[4]);
  	myGraph4->SetMarkerStyle(32);
  	myGraph4->SetMarkerColor(99);
  	myGraph4-> SetTitle("Data at 32#circ C");
  	myGraph4->SetLineColor(kWhite);
  	
  	
  	

	// disegno
	myC->cd();
	mg->Add(myGraph1);
	mg->Add(myGraph2);
	mg->Add(myGraph3);
	mg->Add(myGraph4);
	mg->GetXaxis()->SetTitle("V_{Bias}[V]");
  	mg->GetYaxis()->SetTitle("DCR [Hz]");
  	mg->Draw("AP");
  	
  	
  	myC->Modified();
  	myC->Update();
  	myC->BuildLegend();
    
    
  	myApp->Run();

	return 0;
}



