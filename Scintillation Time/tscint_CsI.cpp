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
  	myGraph->SetMarkerStyle(20);
  	myGraph->SetTitle("CsI Scintillation Time");
  	myGraph->GetXaxis()->SetTitle("t[s]");
  	myGraph->GetYaxis()->SetTitle("V [V]");
  	
  	// funzione per il fit  
  	
  	/*
   	//Partial Fit
  	TF1 *g1 = new TF1("g1", "-[2]*[3]*1/(0.64*[0]+0.36*[1])*exp(-(x+[5])/([4]*[3]))+[3]*[2]*((exp(-(x+[5])/[0]))/[0]*0.64 + (exp(-(x+[5])/[1]))/[1]*0.36)", -0.0000002, 0.000005);
  	g1->SetParName(0,"#tau_{scint1}");
  	g1->SetParName(1,"#tau_{scint2}");
  	g1->SetParName(2,"Q");
  	g1->SetParName(3,"R");
  	g1->SetParName(4,"C");
  	g1->SetParName(5,"t_{0}");
  	//g1->SetParName(6,"x_{0}");
  	g1->SetParameter(0, 0.00000068);
  	g1->SetParameter(1, 0.0000033);
  	g1->SetParameter(2, 0.00000007);
  	g1->SetParameter(3, 0.8);
  	g1->SetParameter(4, 0.0000001);
  	g1->SetParameter(5, 0.0000001);
  	g1->SetLineColor(kRed);
  	*/
  	
  	//Total Fit
  	TF1 *g1 = new TF1("g1", "-[2]*[3]*1/(0.64*[0]+0.36*[1])*exp(-(x+[5])/([4]*[3]))+[2]*[3]*1/(0.64*[0]+0.36*[1])*((exp(-(x+[5])/[0]))/[0]*0.64 + (exp(-(x+[5])/[1]))/[1]*0.36)", -0.00000028, 0.000005);
  	g1->SetParName(0,"#tau_{scint1}");
  	g1->SetParName(1,"#tau_{scint2}");
  	g1->SetParName(2,"Q");
  	g1->SetParName(3,"R");
  	g1->SetParName(4,"C");
  	g1->SetParName(5,"t_{0}");
  	//g1->SetParName(6,"x_{0}");
  	g1->SetParameter(0, 0.00000068);
  	g1->SetParameter(1, 0.0000033);
  	g1->SetParameter(2, 0.00000007);
  	g1->SetParameter(3, 0.8);
  	g1->SetParameter(4, 0.0000001);
  	g1->SetParameter(5, 0.0000001);
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




