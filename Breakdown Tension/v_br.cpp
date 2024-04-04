// c++ -o v_br v_br.cpp `root-config --glibs --cflags`

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
  	myGraph->SetTitle("DCR vs. V_{bias}");
  	myGraph->GetXaxis()->SetTitle("V_{Bias}[V]");
  	myGraph->GetYaxis()->SetTitle("DCR [Hz]");
  	
  	// funzione per il fit
  	
  	TF1* myFun = new TF1 ("myFun","[0]+[1]*x");
  	myFun->SetParName(0,"q");
  	myFun->SetParName(1,"m");
  	myFun->SetParameter(0,-10^(6));
  	myFun->SetParameter(1,20000);

	// disegno
	myC->cd();
  	myGraph->Draw("AP");
  	
  	myGraph->Fit("myFun");   
  	myC->Modified();
  	myC->Update();
  	
    
    
  	myApp->Run();

	return 0;
}



