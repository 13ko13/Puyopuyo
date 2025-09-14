#pragma once
#include "Vec2.h"

class Puzzle
{
public:
    Puzzle();
    ~Puzzle();

    void Init();        // 初期化（位置や色の設定）
    void End();         //終了処理
    void Update();      // 更新処理
    void Draw();        // 描画処理

    bool IsAlive() const { return m_alive; }
    void SetAlive(bool flag) { m_alive = flag; }
    void SetPos(const Vec2& pos);
    Vec2 GetPos() const;
	int GetGraphHandle() const { return m_graphHandle; }

private:
    //ハンドル関係
    int m_graphHandle;    // 画像ハンドル
    
    //アニメーション関係
    int m_animFrame;       //アニメーションのどの部分か
    int m_animCounter;    //現在のアニメーションフレーム  

    //色関係
    int m_color;          // 色（0=赤, 1=青, 2=緑, …）

    //フラグ関係
    bool m_alive;         // 生存フラグ

    //インスタンス
    Vec2 m_pos;           // 座標  
};
