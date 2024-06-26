// c++ -o tscint tscint.cpp `root-config --glibs --cflags`

#include <iostream>

#include <TStyle.h>
#include <TApplication.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TGraphErrors.h>
#include <TAxis.h>
#include <cmath>

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
  	
  	// grafico con gli errori
  	TGraphErrors* myGraph = new TGraphErrors(argv[1]);
  	myGraph->SetMarkerStyle(11);
  	//myGraph->SetMarkerSize(1);
  	myGraph->SetTitle("LYSO Scintillation Time");
  	myGraph->GetXaxis()->SetTitle("Time [s]");
  	myGraph->GetYaxis()->SetTitle("Tension [V]");

  	
  	// funzione per il fit 

	//Total Fit
  	TF1 *g1 = new TF1("g1", "[1]/[3]*(-exp(-x/[0])+exp(-x/([2]*[3])))", -0.000000003, 0.0000005);
  	g1->SetParName(0,"#tau_{scint} [s]");
  	g1->SetParameter(0, 3.90455e-08);
  	g1->SetParName(1,"Q [C]");
  	g1->SetParameter(1, 2.96926e-08);
  	g1->SetParName(2,"R [#Omega]");
  	g1->SetParameter(2, 1.19911e+00);
  	g1->SetParName(3,"C [F]");
  	g1->SetParameter(3, 8.21101e-08);
  	g1->SetLineColor(kRed);
  	

	// disegno
	myC->cd();
  	myGraph->Draw("AP");
  	myGraph->Fit(g1, "R+");
  	g1->Draw("same");
	//myGraph->Fit(g2, "R+");
	//myGraph->Fit(g3, "R+");   
  	myC->Modified();
  	myC->Update();
  	
    
    
  	myApp->Run();

	return 0;
}
