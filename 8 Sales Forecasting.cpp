#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);
	int branch;
	do {
		int lowTechLastDemand, highTechLastDemand, lowTechNextDemand, highTechNextDemand;
		bool growth;
		vector <int> lowTechCSS, highTechCSS;
		cout << "Enter low-tech demand for the last round\n";
		cin >> lowTechLastDemand;
		cout << "Enter high-tech demand for the last round\n";
		cin >> highTechLastDemand;

		cout << "Enter 1 if the growth = 20% in high-tech and 10% in low-tech. Otherwise, enter 0\n";
		cin >> growth;
		if (!growth)
		{
			double lowGrowth, highGrowth;
			cout << "enter growth of low tech in percentage (for example, to write 10%, write 10)\n";
			cin >> lowGrowth;
			cout << "enter growth of high tech in percentage (for example, to write 10%, write 10)\n";
			cin >> highGrowth;
			lowTechNextDemand = (1 + (lowGrowth / 100)) * lowTechLastDemand;
			highTechNextDemand = (1 + (highGrowth / 100)) * highTechLastDemand;
		}
		else
		{
			lowTechNextDemand = 1.1 * lowTechLastDemand;
			highTechNextDemand = 1.2 * highTechLastDemand;
		}

		int myLowCSS, myHighCSS, in, sumLow = 0, sumHigh = 0;
		double lowMarketShareBasic = 0, highMarketShareBasic = 0;
		double lowMarketShareWorst = 0, highMarketShareWorst = 0;
		double lowMarketShareBest = 0, highMarketShareBest = 0;
		cout << "Enter your product's CSS in the low-tech (if not applicable, enter 0)\n";
		cin >> myLowCSS;
		if (myLowCSS)
		{
			cout << "Enter the CSS of all low-tech products (including yours) separated by spaces and ended with -1\n";
			while (cin >> in && in != -1) {
				lowTechCSS.push_back(in);
				sumLow += in;
			}
			lowMarketShareBasic = (1.0 * myLowCSS) / sumLow;
			lowMarketShareBest = lowMarketShareBasic + 0.02;
			if (lowMarketShareBasic >= 0.02)
				lowMarketShareWorst = lowMarketShareBasic - 0.02;
		}
		cout << "Enter your product's CSS in the high-tech (if not applicable, enter 0)\n";
		cin >> myHighCSS;
		if (myHighCSS)
		{
			cout << "Enter the CSS of all high-tech products (including yours) separated by spaces and ended with -1\n";
			while (cin >> in && in != -1) {
				highTechCSS.push_back(in);
				sumHigh += in;
			}
			highMarketShareBasic = (1.0 * myHighCSS) / sumHigh;
			highMarketShareBest = highMarketShareBasic + 0.02;
			if (highMarketShareBasic >= 0.02)
				highMarketShareWorst = highMarketShareBasic - 0.02;
		}

		int basicSalesForecastLowTech = ceil(lowMarketShareBasic * lowTechNextDemand);
		int basicSalesForecastHighTech = ceil(highMarketShareBasic * highTechNextDemand);
		int worstSalesForecastLowTech = ceil((lowMarketShareWorst)*lowTechNextDemand);
		int worstSalesForecastHighTech = ceil((highMarketShareWorst)*highTechNextDemand);
		int bestSalesForecastLowTech = ceil((lowMarketShareBest)*lowTechNextDemand);
		int bestSalesForecastHighTech = ceil((highMarketShareBest)*highTechNextDemand);

		int totalBasic = basicSalesForecastLowTech + basicSalesForecastHighTech;
		int totalWorst = worstSalesForecastLowTech + worstSalesForecastHighTech;
		int totalBest = bestSalesForecastLowTech + bestSalesForecastHighTech;

		cout << "Sales forecast for:\n";
		cout << "Basic forecasting = " << totalBasic << endl;
		cout << "Worst forecasting = " << totalWorst << endl;
		cout << "Best forecasting = " << totalBest << endl << endl;
		cout << "enter 1 to show calculations\nenter 2 to calculate another forecast\nenter 3 to exist\n";
		cin >> branch;
		if (branch == 1) {
			//if (myLowCSS) {
			cout << "\nyour product's CSS in low-tech = " << myLowCSS << endl;
			cout << "CSS of low-tech products:\n";
			for (int i = 0; i < lowTechCSS.size(); i++)
				cout << lowTechCSS[i] << "\n";
			cout << "\nyour basic PMS in low-tech = " << 100 * (lowMarketShareBasic) << "%" << endl;
			cout << "your basic sales forecast in low-tech = " << basicSalesForecastLowTech << endl;

			cout << "\nyour worst PMS in low-tech = " << 100 * (lowMarketShareWorst) << "%" << endl;
			cout << "your worst sales forecast in low-tech = " << worstSalesForecastLowTech << endl;

			cout << "\nyour best PMS in low-tech = " << 100 * (lowMarketShareBest) << "%" << endl;
			cout << "your best sales forecast in low-tech = " << bestSalesForecastLowTech << endl;
			//}

			//if (myHighCSS) {
			cout << "\nyour product's CSS in high-tech = " << myHighCSS << endl;
			cout << "CSS of high-tech products:\n";
			for (int i = 0; i < highTechCSS.size(); i++)
				cout << highTechCSS[i] << "\n";
			cout << "\nyour basic PMS in high-tech = " << 100 * (highMarketShareBasic) << "%" << endl;
			cout << "your basic sales forecast in high-tech = " << basicSalesForecastHighTech << endl;

			cout << "\nyour worst PMS in high-tech = " << 100 * (highMarketShareWorst) << "%" << endl;
			cout << "your worst sales forecast in high-tech = " << worstSalesForecastHighTech << endl;

			cout << "\nyour best PMS in high-tech = " << 100 * (highMarketShareBest) << "%" << endl;
			cout << "your best sales forecast in high-tech = " << bestSalesForecastHighTech << endl << endl;
			//}
			cout << "Enter 2 to calculate another forecast\nEnter 3 to exist\n";
			cin >> branch;
		}
		if (branch == 3)
			return 0;
	}while (branch == 2);
}