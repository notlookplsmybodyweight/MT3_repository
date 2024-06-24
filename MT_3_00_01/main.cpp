#include <Novice.h>
#include"Calculasion.h"

const char kWindowTitle[] = "GC1D_ワタナベ_リョウイチ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	Calculation *cal = new Calculation;
	
	
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		cal->VectorScreenPrintf(0, 0, cal->GetAdd(), "Add");
		cal->VectorScreenPrintf(0, 13, cal->GetSubtract(), "Subtract");
		cal->VectorScreenPrintf(0, 26, cal->GetMultiply(), "Multiply");
		cal->VectorScreenPrintf(0, 39, cal->GetDot(), "Dot");
		cal->VectorScreenPrintf(0, 42, cal->GetLength(), "Length");
		cal->VectorScreenPrintf(0, 55, cal->GetNormalize(), "Normalize");




		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}