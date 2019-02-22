from ROOT import gStyle,TCanvas,TFile,TF1,TH1F

gStyle.SetOptFit()

c1 = TCanvas("c1","c1 title", 200, 100, 800, 600) # 綺麗に見える設定らしい

file = TFile("keiko_1122_9.root")
t1 = file.Get("v1290")
t1.Draw("0.025*(drift[11]-drift[13]) >> h(2000,0.000000001,10)") # h(指定範囲の分割数,左端,右端)

# double x
f1 = TF1("f1","[0]*TMath::Gaus(x,[1],[2])",0.000000001,10) # フィッティングする為の関数の定義。[]で囲んである部分がフィットで変化させるパラメーター。関数を使うときはTMath::expのようにする。TMath::Gaus(Double_t x,Double_t mean,Double_t sigma)
f1.SetNpx(10000) # フィットした関数をプロットする細かさ
f1.SetParameters(1,0,30) # パラメータの初期値を決める
f1.SetParNames("constant","mean","sigma") # パラメータの名前を決める

h1 = TH1F("h1","h1 title",10000,-1,10)
h1.Fit("f1","","",0.000000001,10) # xが0.000000001から10の範囲についてフィット

f1.Draw("same") # 読み込んだデータに重ねて書く
c1.Print("01.png") # xxx.pngの形式で書き出す
