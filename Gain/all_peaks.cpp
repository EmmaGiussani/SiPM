// c++ -o all_peaks all_peaks.cpp `root-config --glibs --cflags`

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
  	mg -> SetTitle ("Peaks position vs. V_{bias}");
  	
  	
  	// grafico con gli errori
  	TGraphErrors* myGraph1 = new TGraphErrors(argv[1]);
  	myGraph1->SetMarkerStyle(8);
  	myGraph1->SetMarkerColor(kBlue);
  	myGraph1-> SetTitle("Peak 1");
  	myGraph1->SetLineColor(kBlue);
  	
  	
  	// grafico con gli errori
  	TGraphErrors* myGraph2 = new TGraphErrors(argv[2]);
  	myGraph2->SetMarkerStyle(8);
  	myGraph2->SetMarkerColor(kViolet);
  	//myGraph2->SetMarkerSize(108);
  	myGraph2-> SetTitle("Peak 2");
  	myGraph2->SetLineColor(kViolet);
  	
  	
  	// grafico con gli errori
  	TGraphErrors* myGraph3 = new TGraphErrors(argv[3]);
  	myGraph3->SetMarkerStyle(8);
  	myGraph3->SetMarkerColor(kMagenta);
  	myGraph3-> SetTitle("Peak 3");
  	myGraph3->SetLineColor(kMagenta);
  	
  	
  	// grafico con gli errori
  	TGraphErrors* myGraph4 = new TGraphErrors(argv[4]);
  	myGraph4->SetMarkerStyle(8);
  	myGraph4->SetMarkerColor(kPink+7);
  	myGraph4-> SetTitle("Peak 4");
  	myGraph4->SetLineColor(kPink+7);
  	
  	
  	

	// disegno
	myC->cd();
	mg->Add(myGraph1);
	mg->Add(myGraph2);
	mg->Add(myGraph3);
	mg->Add(myGraph4);
	mg->GetXaxis()->SetTitle("V_{Bias}[V]");
  	mg->GetYaxis()->SetTitle("Peaks position [ADC Channel]");
  	mg->Draw("ALP");
  	
  	
  	myC->Modified();
  	myC->Update();
  	myC->BuildLegend();
    
    
  	myApp->Run();

	return 0;
}



