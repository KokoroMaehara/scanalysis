//void plott()
{
     gStyle->SetOptFit();
     //Style->SetOptFit();
     TCanvas *c1 = new TCanvas("c1", "c1 title", 200, 100, 800, 600); //綺麗に見える設定らしい
     TFile *_file0 = TFile::Open("keiko_1122_9.root");                //TFile::Open("xxx.yyy"):ファイル"xxx.yyy"を開く

     TH1F *h1 = new TH1F("h1", "h1 title", 2000, 0.0000001, 10);
     h1->SetStats(0);                                    //統計ボックスの非表示
     v1290->Draw("0.02441*(drift[11]-drift[13]) >> h1"); //h(指定範囲の分割数,左端,右端)
     double x;
     TF1 *f1 = new TF1("f1", "[0]*TMath::Gaus(x,[1],[2])", 0.000000001, 3); //フィッティングする為の関数の定義。[]で囲んである部分がフィットで変化させるパラメーター。関数を使うときはTMath::expのようにする。TMath::Gaus(Double_t x,Double_t mean,Double_t sigma)
     f1->SetNpx(10000);                                                     //フィットした関数をプロットする細かさ

     f1->SetParNames("constant", "mean[ns]", "sigma[ns]"); //パラメータの名前を決める
     h1->Fit("f1", "", "", 0.000000001, 3);                //xが0.000000001から10の範囲についてフィット

     f1->Draw("same");    //読み込んだデータに重ねて書く
     c1->Print("06.png"); //xxx.pngの形式で書き出す
}
