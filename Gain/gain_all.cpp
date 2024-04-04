// c++ -o gain_all gain_all.cpp `root-config --glibs --cflags`

#include <iostream>

#include <TStyle.h>
#include <TApplication.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TGraphErrors.h>
#include <TAxis.h>

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
  	myGraph->SetTitle("Gain vs. Overvoltage");
  	myGraph->GetXaxis()->SetTitle("#DeltaV [V]");
  	myGraph->GetYaxis()->SetTitle("Gain");
  	
  	// funzione per il fit
  	
  	TF1* myFun = new TF1 ("myFun","[0]*x");
  	myFun->SetParName(0,"m");
  	//myFun->SetParName(1,"q");
  	//myFun->SetParameter(0,65488);
  	//myFun->SetParameter(1,20000);

	// disegno
	myC->cd();
  	myGraph->Draw("AP");
  	
  	myGraph->Fit("myFun");   
  	myC->Modified();
  	myC->Update();
  	
    
    
  	myApp->Run();

	return 0;
}



