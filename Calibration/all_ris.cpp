// c++ -o all_ris all_ris.cpp `root-config --glibs --cflags`

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
    	
    	gStyle->SetOptFit(0);	
    	
    	TApplication* myApp = new TApplication("myApp", NULL, NULL);
  	TCanvas* myC = new TCanvas("myC","myC",0,0,700,500);
  	
  	TMultiGraph *mg = new TMultiGraph();
  	mg -> SetTitle ("Energy Resolution");
  	
  	
  	// grafico con gli errori
  	TGraphErrors* myGraph1 = new TGraphErrors(argv[1]);
  	myGraph1->SetMarkerStyle(8);
  	myGraph1->SetMarkerColor(kOrange);
  	myGraph1-> SetTitle("LYSO curve");
  	myGraph1->SetLineColor(kOrange);
  	
  	
  	// grafico con gli errori
  	TGraphErrors* myGraph2 = new TGraphErrors(argv[2]);
  	myGraph2->SetMarkerStyle(8);
  	myGraph2->SetMarkerColor(kRed-4);
  	//myGraph2->SetMarkerSize(108);
  	myGraph2-> SetTitle("BGO curve");
  	myGraph2->SetLineColor(kRed-4);
  	
  	
  	// grafico con gli errori
  	TGraphErrors* myGraph3 = new TGraphErrors(argv[3]);
  	myGraph3->SetMarkerStyle(8);
  	myGraph3->SetMarkerColor(kAzure+5);
  	myGraph3-> SetTitle("CsI curve");
  	myGraph3->SetLineColor(kAzure+5);
  	
  	TF1* myFun = new TF1 ("myFun","[0]/sqrt(x)+[1]");
  	myFun->SetParName(0,"k");
  	myFun->SetParName(1,"q");
  	TF1* myFun1 = new TF1 ("myFun1","[0]/sqrt(x)+[1]");
  	myFun1->SetParName(0,"k");
  	myFun1->SetParName(1,"q");
  	TF1* myFun2 = new TF1 ("myFun2","[0]/sqrt(x)+[1]");
  	myFun2->SetParName(0,"k");
  	myFun2->SetParName(1,"q");
  	
  	myFun->SetLineColor(kOrange);
	myFun1->SetLineColor(kRed-4);
	myFun2->SetLineColor(kAzure+5);

	// disegno
	myC->cd();
	myGraph1->Fit("myFun");
	myGraph2->Fit("myFun1");
	myGraph3->Fit("myFun2");
	
	
	mg->Add(myGraph1);
	mg->Add(myGraph2);
	mg->Add(myGraph3);
	
	myFun->Draw("same");
	myFun1->Draw("same");
	myFun2->Draw("same");
	
	mg->GetXaxis()->SetTitle("Energy [keV]");
  	mg->GetYaxis()->SetTitle("Energy Resolution R");
  	mg->Draw("AP");
  	
  	
  	myC->Modified();
  	myC->Update();
  	myC->BuildLegend();
    
    
  	myApp->Run();

	return 0;
}



