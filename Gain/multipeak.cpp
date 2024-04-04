// c++ -o multipeak multipeak.cpp `root-config --glibs --cflags`


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
    	
    	gStyle->SetOptStat(0000);
    	//gStyle->SetOptFit(1111);	
    	
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
  	/*
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
  	*/
  	//exit(1);
  	TH1F *h1 = new TH1F("h1","histogram",462,247163.67,250851.747);
  	
  	for(unsigned i=0; i<mystring.size(); i++){
  	h1->AddBinContent(i, mystring1.at(i)); //fill with weight
  	h1->SetBinError(i,TMath::Sqrt(mystring1.at(i)));
  	}
  	
  	
  	
  	//h1->SetFillColor(kBlue+2);
  	//h1->SetLineColor(kBlue+2);
  	h1->SetFillStyle(3335);
  	h1->SetTitle("LED Emitter Spectrum Fit");
  	h1->GetXaxis()->SetTitle("ADC Channel");
  	h1->GetYaxis()->SetTitle("Counts");
  	/*
  	TH1F *h2 = new TH1F("h2","histogram",37001,225003.5,520996);
  	
  	for(unsigned i=0; i<mystring.size(); i++){
  	h2->Fill(mystring.at(i), mystring2.at(i)); //fill with weight
  	}
  	
  	h2->SetFillColor(kCyan);
  	h2->SetLineColor(kCyan);
  	//h2->SetFillStyle(3351);
  	h2->SetTitle("Data collected with shielding");
	*/
	// disegno
	
	// Define the parameter array for the total function.
   double par[33];
   
   
   
   /*
	TF1 *g0 = new TF1("g0", "gaus", 247163.67, 247500);
	TF1 *g1 = new TF1("g1", "gaus", 247500, 247860);
 	TF1 *g2 = new TF1("g2", "gaus", 247900, 248170);
	TF1 *g3 = new TF1("g3", "gaus", 248230, 248500);
	TF1 *g4 = new TF1("g4", "gaus", 248600, 248850);
	TF1 *g5 = new TF1("g5", "gaus", 248950, 249200);
	TF1 *g6 = new TF1("g6", "gaus", 249300, 249580);
	TF1 *g7 = new TF1("g7", "gaus", 249620, 249950);
	TF1 *g8 = new TF1("g8", "gaus", 249950, 250300);
	*/
	/*
	g0->SetLineColor(kCyan);
	//g1->SetLineColor(kAzure);
	g1->SetLineColor(kBlue);
	g2->SetLineColor(kViolet);
	g3->SetLineColor(kMagenta);
	g4->SetLineColor(kPink+7);
	g5->SetLineColor(kRed);
	g6->SetLineColor(kOrange);
	g7->SetLineColor(kYellow);
	g8->SetLineColor(kSpring);
	
	*/
	
	TF1 *myfunc = new TF1("myfunc", "pol2(30)+gaus(0)+gaus(3)+gaus(6)+gaus(9)+gaus(12)+gaus(15)+gaus(18)+gaus(21)+gaus(24)+gaus(27)",247500,250000);
	TF1 *myfunc1 = new TF1("myfunc1", "pol2(0)",247163.67,255500);
	myfunc->SetLineColor(kRed);
	
	myfunc1->SetLineColor(kBlue);
	myfunc1->SetLineStyle(3);
	
	/*
	h1->Fit(g0, "R+");
	h1->Fit(g1, "R+");
	h1->Fit(g2, "R+");
	h1->Fit(g3, "R+");
	h1->Fit(g4, "R+");
	h1->Fit(g5, "R+");
	h1->Fit(g6, "R+");
	h1->Fit(g7, "R+");
	h1->Fit(g8, "R+");
	
	
	
	
        //g0->GetParameters(&par[3]);
        g1->GetParameters(&par[6]);
        g2->GetParameters(&par[9]);
        g3->GetParameters(&par[12]);
        g4->GetParameters(&par[15]);
        g5->GetParameters(&par[18]);
        g6->GetParameters(&par[21]);
        //g7->GetParameters(&par[24]);
        //g8->GetParameters(&par[27]);*/
        
	
	myfunc->SetParameter(30,-3.55437e+06);
	myfunc->SetParameter(31,28.5499);
	myfunc->SetParameter(32,-5.73279e-05);
	
	//myfunc->SetParameter(0,1.07463e+02);
	//myfunc->SetParameter(1,2.47350e+05);
	//myfunc->SetParameter(2,5.59235e+01);
	myfunc->SetParameter(3,1.07463e+02);
	myfunc->SetParameter(4,2.47350e+05);
	myfunc->SetParameter(5,5.59235e+01);
	myfunc->SetParameter(6,3.88352e+02);
	myfunc->SetParameter(7,2.47693e+05);
	myfunc->SetParameter(8,5.85572e+01);
	myfunc->SetParameter(9,6.99416e+02);
	myfunc->SetParameter(10,2.48039e+05);
	myfunc->SetParameter(11,6.37952e+01);
	myfunc->SetParameter(12,7.96672e+02);
	myfunc->SetParameter(13,2.48388e+05);
	myfunc->SetParameter(14,7.35176e+01);
	myfunc->SetParameter(15,7.68865e+02);
	myfunc->SetParameter(16,2.48733e+05);
	myfunc->SetParameter(17,7.47565e+01);
	myfunc->SetParameter(18,5.34624e+02);
	myfunc->SetParameter(19,2.49081e+05);
	myfunc->SetParameter(20,9.19901e+01);
	myfunc->SetParameter(21,3.79821e+02 );
	myfunc->SetParameter(22,2.49428e+05);
	myfunc->SetParameter(23,8.92522e+01);
	myfunc->SetParameter(24,2.14106e+02);
	myfunc->SetParameter(25,2.49770e+05);
	myfunc->SetParameter(26,1.02220e+02);
	myfunc->SetParameter(27, 1.03799e+02);
	myfunc->SetParameter(28, 2.50116e+05);
	myfunc->SetParameter(29,1.16365e+02);
	
	
	//myfunc->SetParameters(par);
	
	h1->Fit(myfunc, "R+");
	h1->Fit(myfunc1, "R+");
	myC->cd();
	h1->Draw("L");
	myfunc->Draw("same");
	myfunc1->Draw("same");
	/*
	//g0->Draw("same");
	g1->Draw("same");
	g2->Draw("same");
	g3->Draw("same");
	g4->Draw("same");
	g5->Draw("same");
	g6->Draw("same");
	//g7->Draw("same");
	//g8->Draw("same");
	//g9->Draw("same");
	//h2->Draw("same");
	
	*/
	
	//myC->SetLogy();
	//mg->GetXaxis()->SetTitle("V_{Bias} [mV]");
  	//mg->GetYaxis()->SetTitle("Log Frequency [Hz]");
  	
  	
            auto legend = new TLegend(0.1,0.7,0.48,0.9);
   //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
   legend->AddEntry(h1,"Data","lep");
   legend->AddEntry("myfunc","Total fit","l");
   legend->AddEntry("myfunc1","Background","l");
   /*legend->AddEntry("g0","0 p.e.","l");
   legend->AddEntry("g1","1 p.e.","l");
   legend->AddEntry("g2","2 p.e.","l");
   legend->AddEntry("g3","3 p.e.","l");
   legend->AddEntry("g4","4 p.e.","l");
   legend->AddEntry("g5","5 p.e.","l");
   legend->AddEntry("g6","6 p.e.","l");
   legend->AddEntry("g7","7 p.e.","l");
   legend->AddEntry("g8","8 p.e.","l");*/
  // legend->AddEntry("g9","9 p.e.","l");
   legend->Draw();
   

  	
  	myC->Modified();
  	myC->Update();
  	
    
    
  	myApp->Run();

	return 0;
}



