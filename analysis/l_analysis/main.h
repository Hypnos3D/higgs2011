/*-------------------------------------------------------------------------*/

#ifndef __L_ANALYSIS
#define __L_ANALYSIS

/*-------------------------------------------------------------------------*/

#include "../../core/include/core.h"

/*-------------------------------------------------------------------------*/

#define MAX 2048

/*-------------------------------------------------------------------------*/

class TLeptonFinder: public TLeptonAnalysis
{
  public:
	TTree m_tree1;
	TTree m_tree2;

	TLeptonFinder(TChain *chain): TLeptonAnalysis(chain)
	{
		m_tree1.SetName("elSTACO");
		m_tree2.SetName("muSTACO");

		TTree *LTreeArray[2] = {&m_tree1, &m_tree2};

		/*---------------------------------------------------------*/
		/* LEPTON ANALYSIS					   */
		/*---------------------------------------------------------*/

		for(int i = 0; i < 2; i++)
		{
			TTree *tree = LTreeArray[i];

			/**/

			tree->Branch("RunNumber", &m_l[i].RunNumber, "RunNumber/I");
			tree->Branch("EventNumber", &m_l[i].EventNumber, "EventNumber/I");
			tree->Branch("LumiBlock", &m_l[i].LumiBlock, "LumiBlock/I");

			tree->Branch("nPV2", &m_l[i].nPV2, "nPV2/I");
			tree->Branch("nIntPerXing", &m_l[i].nIntPerXing, "nIntPerXing/F");

			tree->Branch("elTrigger", &m_l[i].elTrigger, "elTrigger/I");
			tree->Branch("muTrigger", &m_l[i].muTrigger, "muTrigger/I");

			/**/

			tree->Branch("n", &m_l[i].n, "n" "/I");

			tree->Branch("l_z0", m_l[i].l_z0, "l_z0[n]/F");
			tree->Branch("l_d0", m_l[i].l_d0, "l_d0[n]/F");

			tree->Branch("weight1", m_l[i].weight1, "weight1[n]/F");
			tree->Branch("weight2", m_l[i].weight2, "weight2[n]/F");
			tree->Branch("weight3", m_l[i].weight3, "weight3[n]/F");

			tree->Branch("l_tight", m_l[i].l_tight, "l_tight[n]/I");
			tree->Branch("l_triggerMatch", m_l[i].l_triggerMatch, "l_triggerMatch[n]/I");

			tree->Branch("l_charge", m_l[i].l_charge, "l_charge[n]/F");
			tree->Branch("l_e", m_l[i].l_e, "l_e[n]/F");
			tree->Branch("l_pt", m_l[i].l_pt, "l_pt[n]/F");
			tree->Branch("l_eta", m_l[i].l_eta, "l_eta[n]/F");
			tree->Branch("l_phi", m_l[i].l_phi, "l_phi[n]/F");


			tree->Branch("l_tkIso20", m_l[i].l_tkIso20, "l_tkIso20[n]/F");
			tree->Branch("l_clIso20", m_l[i].l_clIso20, "l_clIso20[n]/F");
			tree->Branch("l_d0sigma", m_l[i].l_d0sigma, "l_d0sigma[n]/F");

			tree->Branch("l_f1", m_l[i].l_f1, "l_f1[n]/F");
			tree->Branch("l_rphi", m_l[i].l_rphi, "l_rphi[n]/F");
			tree->Branch("l_nBlayerHits", m_l[i].l_nBlayerHits, "l_nBlayerHits[n]/I");
			tree->Branch("l_nPixelHits", m_l[i].l_nPixelHits, "l_nPixelHits[n]/I");
			tree->Branch("l_rTRT", m_l[i].l_rTRT, "l_rTRT[n]/F");

			/**/

			tree->Branch("l_type", m_l[i].l_type, "l_type[n]/F");
			tree->Branch("l_origin", m_l[i].l_origin, "l_origin[n]/F");
			tree->Branch("l_typebkg", m_l[i].l_typebkg, "l_typebkg[n]/F");
			tree->Branch("l_originbkg", m_l[i].l_originbkg, "l_originbkg[n]/F");
			tree->Branch("l_truth_type", m_l[i].l_truth_type, "l_truth_type[n]/F");
			tree->Branch("l_truth_mothertype", m_l[i].l_truth_mothertype, "l_truth_mothertype[n]/F");
		}

		/*---------------------------------------------------------*/
	}

	void Loop(void);

  private:

	struct __lepton_s
	{
		Int_t RunNumber;
		Int_t EventNumber;
		Int_t LumiBlock;

		Int_t nPV2;
		Float_t nIntPerXing;

		Int_t elTrigger;
		Int_t muTrigger;

		/**/

		Int_t n;

		Float_t l_z0[MAX];
		Float_t l_d0[MAX];

		Float_t weight1[MAX];
		Float_t weight2[MAX];
		Float_t weight3[MAX];

		Int_t l_tight[MAX];
		Int_t l_triggerMatch[MAX];

		Float_t l_charge[MAX];
		Float_t l_e[MAX];
		Float_t l_pt[MAX];
		Float_t l_eta[MAX];
		Float_t l_phi[MAX];

		Float_t l_clIso20[MAX];
		Float_t l_tkIso20[MAX];
		Float_t l_d0sigma[MAX];

		Float_t l_f1[MAX];
		Float_t l_rphi[MAX];
		Int_t l_nBlayerHits[MAX];
		Int_t l_nPixelHits[MAX];
		Float_t l_rTRT[MAX];

		/**/

		Float_t l_type[MAX];
		Float_t l_origin[MAX];
		Float_t l_typebkg[MAX];
		Float_t l_originbkg[MAX];
		Float_t l_truth_type[MAX];
		Float_t l_truth_mothertype[MAX];

	} m_l[2];

};

/*-------------------------------------------------------------------------*/

#endif /* __L_ANALYSIS */

/*-------------------------------------------------------------------------*/

