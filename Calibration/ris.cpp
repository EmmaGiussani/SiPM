// c++ -o ris ris.cpp `root-config --glibs --cflags`

#include <iostream>

#include <TStyle.h>
#include <TApplication.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TGraphErrors.h>
#include <TAxis.h>
#include <TLatex.h>

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
  	myGraph->SetTitle("BGO Energy Resolution");
  	myGraph->GetXaxis()->SetTitle("Energy [keV]");
  	myGraph->GetYaxis()->SetTitle("Energy Resolution R");
  	//TLatex *latex = new TLatex(myGraph->GetX()[0], myGraph->GetY()[0],"^{57}Co"); 
  	TLatex *latex1 = new TLatex(myGraph->GetX()[0], myGraph->GetY()[0],"^{57}Co"); 
  	TLatex *latex2 = new TLatex(myGraph->GetX()[1], myGraph->GetY()[1],"^{22}Na"); 
  	TLatex *latex3 = new TLatex(myGraph->GetX()[2], myGraph->GetY()[2],"^{22}Na"); 
  	//myGraph->GetListOfFunctions()->Add(latex); 
  	myGraph->GetListOfFunctions()->Add(latex1); 
  	myGraph->GetListOfFunctions()->Add(latex2); 
  	myGraph->GetListOfFunctions()->Add(latex3); 
  	//latex->SetTextSize(0.04); 
  	//latex->SetTextColor(kBlack);
  	latex1->SetTextSize(0.04); 
  	latex1->SetTextColor(kBlack);
  	latex2->SetTextSize(0.04); 
  	latex2->SetTextColor(kBlack);
  	latex3->SetTextSize(0.04); 
  	latex3->SetTextColor(kBlack);
  	
  	// funzione per il fit
  	
  	TF1* myFun = new TF1 ("myFun","[0]/sqrt(x)+[1]");
  	myFun->SetParName(0,"k");
  	myFun->SetParName(1,"q");
  	//myFun->SetParameter(0,1);
  	//myFun->SetParameter(1,100);

	// disegno
	myC->cd();
  	myGraph->Draw("AP");
  	
  	myGraph->Fit("myFun");   
  	myC->Modified();
  	myC->Update();
  	
    
    
  	myApp->Run();

	return 0;
}



