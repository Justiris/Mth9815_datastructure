/**
 * test program for our ProductServices
 */

#include <iostream>
#include "products.hpp"
#include "productservice.hpp"

using namespace std;

int main()
{
  // Create the 10Y treasury note
  date maturityDate(2026, Nov, 16);
  string cusip = "912828M56";
  Bond treasuryBond(cusip, CUSIP, "T", 2.25, maturityDate);

  // Create the 2Y treasury note
  date maturityDate2(2018, Nov, 5);
  string cusip2 = "912828TW0";
  Bond treasuryBond2(cusip2, CUSIP, "T", 0.75, maturityDate2);

  // Create a BondProductService
  BondProductService *bondProductService = new BondProductService();

  // Add the 10Y note to the BondProductService and retrieve it from the service
  bondProductService->Add(treasuryBond);
  Bond bond = bondProductService->GetData(cusip);
  cout << "CUSIP: " << bond.GetProductId() << " ==> " << bond << endl;

  // Add the 2Y note to the BondProductService and retrieve it from the service
  bondProductService->Add(treasuryBond2);
  bond = bondProductService->GetData(cusip2);
  cout << "CUSIP: " << bond.GetProductId() << " ==> " << bond << endl;

  // Create the Spot 10Y Outright Swap
  date effectiveDate(2016, Nov, 16);
  date terminationDate(2026, Nov, 16);
  string outright10Y = "Spot-Outright-10Y";
  IRSwap outright10YSwap(outright10Y, THIRTY_THREE_SIXTY, THIRTY_THREE_SIXTY, SEMI_ANNUAL, LIBOR, TENOR_3M, effectiveDate, terminationDate, USD, 10, SPOT, OUTRIGHT);

  // Create the IMM 2Y Outright Swap
  date effectiveDate2(2016, Dec, 20);
  date terminationDate2(2018, Dec, 20);
  string imm2Y = "IMM-Outright-2Y";
  IRSwap imm2YSwap(imm2Y, THIRTY_THREE_SIXTY, THIRTY_THREE_SIXTY, SEMI_ANNUAL, LIBOR, TENOR_3M, effectiveDate2, terminationDate2, USD, 2, IMM, OUTRIGHT);

  // Create a IRSwapProductService
  IRSwapProductService *swapProductService = new IRSwapProductService();

  // Add the Spot 10Y Outright Swap to the IRSwapProductService and retrieve it from the service
  swapProductService->Add(outright10YSwap);
  IRSwap swap = swapProductService->GetData(outright10Y);
  cout << "Swap: " << swap.GetProductId() << " == > " << swap << endl;

  // Add the IMM 2Y Outright Swap to the IRSwapProductService and retrieve it from the service
  swapProductService->Add(imm2YSwap);
  swap = swapProductService->GetData(imm2Y);
  cout << "Swap: " << swap.GetProductId() << " == > " << swap << endl;

  cout << endl;
  cout << endl;
  cout << endl;

  cout << "Exercise2: \n\n";

  // test for Exercise2

  // Create a future
  date futureMaturityDate(2020, Nov, 3);
  string futureName = "future1";
  Future future1(futureName, EURODOLLARFUTURE, futureMaturityDate);
  cout << "future1: " << future1.GetMaturityDate() << ", " << future1.GetFutureIdType() << endl;

  // test for EuroDollarFuture and BondFuture
  date euroDollarFutureMaturityDate(2030, Nov, 19);
  EuroDollarFuture EDfuture1("EDfuture1", euroDollarFutureMaturityDate);
  date bondFutureMaturityDate(2040, Nov, 27);
  BondFuture Bdfuture1("Bdfuture1", bondFutureMaturityDate);
  cout << "Edfuture1: " << EDfuture1.GetMaturityDate() << ", " << EDfuture1.GetFutureIdType() << endl;
  cout << "Bdfuture1: " << Bdfuture1.GetMaturityDate() << ", " << Bdfuture1.GetFutureIdType() << endl;

  // test for FutureProductService
  // Create a FutureProductService
  FutureProductService *futureProductService = new FutureProductService();

  // Add future1 to the FutureProductService and retrieve it from the service
  futureProductService->Add(future1);
  Future future = futureProductService->GetData("future1");
  cout << "CUSIP: " << future.GetProductId() << " ==> " << future << endl;

  // Add EDfuture1 to the FutureProductService and retrieve it from the service
  futureProductService->Add(EDfuture1);
  future = futureProductService->GetData("EDfuture1");
  cout << "CUSIP: " << future.GetProductId() << " ==> " << future << endl;

  // Add Bdfuture1 to the FutureProductService and retrieve it from the service
  futureProductService->Add(Bdfuture1);
  future = futureProductService->GetData("Bdfuture1");
  cout << "CUSIP: " << future.GetProductId() << " ==> " << future << endl;

  cout << endl;
  cout << endl;
  cout << endl;

  cout << "Exercise3: \n\n";

  // test for Exercise3
  // create several bonds
  Bond bond1("bond1", CUSIP, "T", 2.25, maturityDate);
  Bond bond2("bond2", CUSIP, "C", 2.26, maturityDate);
  Bond bond3("bond3", CUSIP, "T", 2.27, maturityDate);
  Bond bond4("bond4", CUSIP, "C", 2.28, maturityDate);
  Bond bond5("bond5", CUSIP, "T", 2.29, maturityDate);

  // create a BondProductService
  BondProductService *bondProductService2 = new BondProductService();
	
  // add bonds to the BondProductService
  bondProductService2->Add(bond1);
  bondProductService2->Add(bond2);
  bondProductService2->Add(bond3);
  bondProductService2->Add(bond4);
  bondProductService2->Add(bond5);

  string ticker = "T";
  vector<Bond> findByTicker = bondProductService2->GetBonds(ticker);

  // print the results
  cout << "Bonds by Ticker T: " << endl;
  for (auto& bonds : findByTicker) {
	  cout << bonds << endl;
  }

  // tests for Swaps
  cout << endl;
  cout << endl;

  //create several swaps
  date effectiveDate3(2016, Nov, 16);
  date terminationDate3(2026, Nov, 16);
  IRSwap swap1("swap1", THIRTY_THREE_SIXTY, THIRTY_THREE_SIXTY, SEMI_ANNUAL, EURIBOR, TENOR_3M, effectiveDate3, terminationDate3, USD, 10, SPOT, FLY);

  date effectiveDate4(2016, Nov, 16);
  date terminationDate4(2027, Nov, 16);
  IRSwap swap2("swap2", THIRTY_THREE_SIXTY, THIRTY_THREE_SIXTY, SEMI_ANNUAL, LIBOR, TENOR_3M, effectiveDate4, terminationDate4, USD, 11, FORWARD, CURVE);

  date effectiveDate5(2016, Nov, 16);
  date terminationDate5(2028, Nov, 16);
  IRSwap swap3("swap3", ACT_THREE_SIXTY, ACT_THREE_SIXTY, QUARTERLY, EURIBOR, TENOR_3M, effectiveDate5, terminationDate5, USD, 12, IMM, CURVE);

  date effectiveDate6(2016, Nov, 16);
  date terminationDate6(2025, Nov, 16);
  IRSwap swap4("swap4", ACT_THREE_SIXTY, ACT_THREE_SIXTY, ANNUAL, LIBOR, TENOR_3M, effectiveDate6, terminationDate6, USD, 9, MAC, OUTRIGHT);

  date effectiveDate7(2016, Nov, 16);
  date terminationDate7(2024, Nov, 16);
  IRSwap swap5("swap5", ACT_THREE_SIXTY_FIVE, ACT_THREE_SIXTY_FIVE, QUARTERLY, LIBOR, TENOR_3M, effectiveDate7, terminationDate7, USD, 8, BASIS, FLY);

  // Create a IRSwapProductService
  IRSwapProductService *swapProductService3 = new IRSwapProductService();

  // add swaps to the IRSwapProductService
  swapProductService3->Add(swap1);
  swapProductService3->Add(swap2);
  swapProductService3->Add(swap3);
  swapProductService3->Add(swap4);
  swapProductService3->Add(swap5);
  
  // Get all Swaps with the specified fixed leg day count convention
  vector<IRSwap> swapByLDCC = swapProductService3->GetSwaps(ACT_THREE_SIXTY);

  // Get all Swaps with the specified fixed leg payment frequency
  vector<IRSwap> swapByFLPF = swapProductService3->GetSwaps(SEMI_ANNUAL);

  // Get all Swaps with the specified floating index
  vector<IRSwap> swapByFI = swapProductService3->GetSwaps(EURIBOR);

  // Get all Swaps with a term in years greater than the specified value
  vector<IRSwap> swapGreaterThan = swapProductService3->GetSwapsGreaterThan(10);

  // Get all Swaps with a term in years less than the specified value
  vector<IRSwap> swapLessThan = swapProductService3->GetSwapsLessThan(10);

  // Get all Swaps with the specified swap type
  vector<IRSwap> swapByST = swapProductService3->GetSwaps(SPOT);

  // Get all Swaps with the specified swap leg type
  vector<IRSwap> swapBySLT = swapProductService3->GetSwaps(OUTRIGHT);

  // print results

  cout << "Swap by leg day count convention: " << endl;
  for (auto& swap : swapByLDCC) {
	  cout << swap << endl;
  }
  cout << endl;

  cout << "Swap by fixed leg payment frequency: " << endl;
  for (auto& swap : swapByFLPF) {
	  cout << swap << endl;
  }
  cout << endl;

  cout << "Swap by floating index: " << endl;
  for (auto& swap : swapByFI) {
	  cout << swap << endl;
  }
  cout << endl;

  cout << "Swap with a term in years greater than the specified value: " << endl;
  for (auto& swap : swapGreaterThan) {
	  cout << swap << endl;
  }
  cout << endl;

  cout << "Swap with a term in years less than the specified value: " << endl;
  for (auto& swap : swapLessThan) {
	  cout << swap << endl;
  }
  cout << endl;

  cout << "Swap by swap type: " << endl;
  for (auto& swap : swapByST) {
	  cout << swap << endl;
  }
  cout << endl;

  cout << "Swap by swap leg type: " << endl;
  for (auto& swap : swapBySLT) {
	  cout << swap << endl;
  }
  cout << endl;

  // system("pause");
  return 0;
}
