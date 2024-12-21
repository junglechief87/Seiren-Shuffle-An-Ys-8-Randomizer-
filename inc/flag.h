// フラグヘッダ
//
//	TEMP_FLAG_MAX までがテンポラリフラグ（ローカルフラグ）　マップ切り替えまで有効
//	GLOBAL_FLAG_MAX までがグローバルフラグ　ゲーム終了、もしくはセーブデータのロードまで有効
//

enum {
	// テンポラリフラグ群
	TF_START = 0,

	TF_0001_4EV,			// TalkMesの書式指定「#?X」用に確保している領域。直接番号指定用。
	TF_0002_4EV,			// TalkMesの書式指定「#?X」用に確保している領域。直接番号指定用。
	TF_0003_4EV,			// TalkMesの書式指定「#?X」用に確保している領域。直接番号指定用。
	TF_0004_4EV,			// TalkMesの書式指定「#?X」用に確保している領域。直接番号指定用。
	TF_0005_4EV,			// TalkMesの書式指定「#?X」用に確保している領域。直接番号指定用。
	TF_0006_4EV,			// TalkMesの書式指定「#?X」用に確保している領域。直接番号指定用。
	TF_0007_4EV,			// TalkMesの書式指定「#?X」用に確保している領域。直接番号指定用。
	TF_0008_4EV,			// TalkMesの書式指定「#?X」用に確保している領域。直接番号指定用。
	TF_0009_4EV,			// TalkMesの書式指定「#?X」用に確保している領域。直接番号指定用。
	TF_0010_4EV,			// TalkMesの書式指定「#?X」用に確保している領域。直接番号指定用。

	TF_GAMEOVER_SEL,		// ゲームオーバー時のセレクト
	TF_OLDMMINIMAP_LAYER,	// ミニマップ全画面時に覚えておくレイヤー番号
	TF_TEMPROTATE_CAMERA,	// ミニマップ全画面時のテンポラリ回転
	TF_TEMPROTATE_CAMERA2,	// ミニマップ全画面時のテンポラリ回転、目標値

	// 超古い体験版フラグ（TF_TRIAL～）は危険なので削除しました。（山）
	//
	// その場限りのテンポラリは基本的にマップテンポラリで作成して下さい。
	// マップテンポラリは /bin/inc/maptmp/mp_xxxx.inc で定義する事。
	// マップテンポラリには以下のような物を定義します。
	//	・一時的なギミック状況フラグ
	//	・一般会話等で初回かどうかを判定するフラグ
	//	・とにかくマップ限定のテンポラリフラグ
	//
	// 汎用的なテンポラリが必要な場合は専用の名前で作成して下さい。
	//	例）TF_MENU_SELECT		// メニューセレクト用。全マップで使用。

	// ギミック用（あえてテンポラリフラグにしていたような気がする）
	TF_TALK_ZOOMCAMERA,			// STOPFLAG_TALKING中、カメラを寄せる。STOPFLAG_TALKINGが降りると同時に自動で解除される
	TF_TALK_ZOOMRATIO,			// TF_TALK_ZOOMCAMERAの時のズーム率設定。0～100で100がTF_TALK_ZOOMCAMERAを使っていない時と同じ。０はシステムが設定した値（2015/01/16現在は40）になる。TF_TALK_ZOOMCAMERAがリセットされるのと同じタイミングで自動的に０に再設定される。
	TF_TALK_ZOOMNOINTERPOLATE,	// １を設定するとTF_TALK_ZOOMCAMERAに関する補間処理を一瞬で終わらせる。処理後には０が設定される。
	TF_TALK_NOTURNANIME,		// STOPFLAG_TALKで会話開始・終了する際に、キャラ回転に合わせてキャラモーションさせない場合に立てる

	// アクション用
	TF_MENU_SELECT,				// メニューセレクト用テンポラリ
	TF_MENU_SELECT2,			// メニューセレクト用テンポラリ
	TF_TORCHLIGHT,				// たいまつ使用済み（プログラム用）
	
	TF_VOICEPLY_CHR,			// WK_RANDBTLMB/WK_RANDJOINMBでピックアップしたキャララベルの置き場所

	TF_TRORHY_COUNT,			// トロフィー用テンポラリ

	TF_KILLENEMY_CNT,			// 撃破数カウント（テンポラリ）
	TF_NO_RETRY,				// リトライ前判定用（テンポラリ）
	TF_CHECK_DISTANCE,			// PLAYER1とPLAYER2の距離判定用（テンポラリ）
	TF_CHECK_DISTANCE2,			// PLAYER1とPLAYER3の距離判定用（テンポラリ）

	TF_LOADING_TIPS_OFF,		// NowLoading 時の Tips 表示をカット
	TF_MAPNAME_SHOWN,			// 地名表示した（テンポラリ）

	TF_EVSKIP,					// イベントスキップした

	TF_TALK_TYPE,				// 一般会話の条件判定用

	TF_BREAK_RND,				// ブレイクオブジェクトのドロップ判定ランダム用

	TF_ENDROGRAM_STATE,			// テオス・デ・エンドログラム状況判定用
	TF_NPC_NOLOAD,				// 立っているとNPCPositionを呼び出さない（漂流村派生マップ限定）

	TF_SIENEVENT,				//支援イベントの再生パターンを判定するフラグ

	//*****************************************************************
	// 100～349 マップギミックテンポラリ
	// 違うマップに行ったら同じ番号でも全く違うフラグと思うべし
	// 数値直指定もありえるので注意
	// 定義数多くなると重くなるので、マップ別に.hを用意する方法に変更。
	// なので100～349は絶対に使ってはいけない
	//
	// DUNGEON_START～DUNGEON_ENDの間は、ダンジョンテンポラリで、
	// argの[MAP_SET]セクションで指定しているPAGE_NO単位で共有するテンポラリフラグです。
	// inc/mp23xx.h等で、共通のフラグを使うようにしてください。
	TF_MAP_START = 100,			// マップテンポラリ開始（マップ切替で０に戻るフラグ）
	TF_DUNGEON_START = 200,		// ダンジョンテンポラリ開始（PAGE_NOが切り替わると０に戻るフラグ）
	TF_DUNGEON_END = 350,		// ダンジョンテンポラリここまで

	//*****************************************************************
	// 350番以降 ここからは重複しないように！！
	// ザコＡＩチャンネル用
	TF_AI_CHANNEL0 = TF_DUNGEON_END,
	TF_AI_CHANNEL1,
	TF_AI_CHANNEL2,
	TF_AI_CHANNEL3,
	TF_AI_CHANNEL4,
	TF_AI_CHANNEL5,
	TF_AI_CHANNEL6,
	TF_AI_CHANNEL7,

	TEMP_FLAG_MAX,				// テンポラリフラグ　ここまで

	TEMP_FLAG_RESERVE_MAX = 400,// テンポラリフラグのリザーブマックス

	// 移動済みマップチェックフラグ。ビットで持つ。フラグはint型なので、念の為３１個までとしておく。	SF_MAP_CHECK_POINT03/04もあるが、他の場所に散らばっている
	SF_MAP_CHECK_POINT01,		// マップチェックポイント（バッファ１）
	SF_MAP_CHECK_POINT02,		// マップチェックポイント（バッファ２）

	// システムフラグ系
	SF_SAVEMENU,				// セーブ系メニュー起動中
	SF_DIFFICULT,				// 難易度
	SF_LOADING,					// ロード処理中フラグ	// 1～100 通常ロード	200 RAMロード
	SF_ENTRY,					// エントリー処理中
	SF_ALLMUTEKI,				// 敵も味方も全員無敵フラグ
	SF_MINIGAME,				// ミニゲームモードフラグ
	SF_TOWNMODE,				// 街中																									// マップ切り替え毎に毎回リセットされる。argのエリアフラグでセットすべし
	SF_HEALAREA,				// 回復可能エリア（放置時に武装解除するかどうかの判定にもつかっている。）								// マップ切り替え毎に毎回リセットされる。argのエリアフラグでセットすべし
	SF_DEFEAT_ANCIENT,			// 古代獣を倒せる
	SF_CANTSAVE,				// セーブ不可能！（ボス戦等、メニューが開けないようになる）												// マップ切り替え毎に毎回リセットされる。argのエリアフラグでセットすべし

		//キャラ
	SF_ADOL_JOINOK,				// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）
	SF_LAXIA_JOINOK,			// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）
	SF_SAHAD_JOINOK,			// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）
	SF_HUMMEL_JOINOK,			// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）
	SF_RICOTTA_JOINOK,			// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）
	SF_DANA_JOINOK,				// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）

	SF_DANACOPY_JOINOK,			// ダーナ控え用領域なので触ってはいけない

	SF_DANA2_JOINOK,			// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）
	SF_DANA3_JOINOK,			// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）
	
	SF_DANAOLD_JOINOK,			// 過去編ダーナ控え用領域なので触ってはいけない

	SF_RESERVE10_JOINOK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）
	SF_RESERVE11_JOINOK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）
	SF_RESERVE12_JOINOK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）
	SF_RESERVE13_JOINOK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）
	SF_RESERVE14_JOINOK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）
	SF_RESERVE15_JOINOK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）
	SF_RESERVE16_JOINOK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）
	SF_RESERVE17_JOINOK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）
	SF_RESERVE18_JOINOK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）
	SF_RESERVE19_JOINOK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）

	SF_MINIMAP_VIEWMODE,		// ミニマップビューモード。０－別マップはグレー		１－別マップは非表示	２－別マップも普通に表示
	SF_DARKAREA,				// 暗闇扱いにするマップ。ターゲット可能範囲が縮む。	// マップ切り替え毎に毎回リセットされる。argのエリアフラグでセットすべし。SF_TORCHPOWER, SF_TORCHRANGEでマップ毎に夜光石の強さと範囲を変更できる
	SF_MINIMAP_LAYER,			// ミニマップレイヤー番号。エリア切り替え時に自動的に０になる。
	
	SF_CAMP_CANT_SYSTEM,		// システムメニュー禁止（チュートリアル制御用など）
	SF_CAMP_CANT_ITEM,			// アイテムメニュー禁止（チュートリアル制御用など）

	__SF_TORCHTIMER,			// 夜光石の残り時間カウント用（SF_DARKAREAでは減少する）
	__SF_TORCHPOWER,			// 夜光石の強さ設定（0～100。デフォルトは100。マップ切り替え時にリセットされる）
	__SF_TORCHRANGE,			// 夜光石の範囲％設定（0～100。デフォルトは100。マップ切り替え時にリセットされる）

		// その他
	SF_REDENTRYLINE,			// エントリー線を赤色表示にする	// マップ切り替え毎に毎回リセットされる。リトライスクリプト等での指定忘れ注意
	SF_LASTENTRY_NO,			// 最後に通ったエントリーの番号。スクリプトでワープした時は－１が入っている。
	SF_LOADMAP,					// マップ読んだ直後
	SF_MINIMAP_MODE,			// ミニマップの表示モード
	SF_EXPOWER,					// 超必殺ゲージ値
	SF_DONTSTOPSEALL,			// ＳＥ全停止させたくない場合に立てる。※マップ切り替え後initスクリプト後にリセットされる。

	SF_SETRAMSAVE,				// プレイヤーが行動できるようになったらRAMセーブ取る
	SF_RAMSAVED,				// 既にRAMセーブを持っているかどうか

		// 新仕様用、チュートリアルとかシナリオとかの追加や変更で必要になった物
	SF_ITEMSLOT_NUM,			// 冒険具スロット数（-1：スロット非表示	1以上：使えるスロット数	※1未満は装備できるスロット数は1扱い。）
	SF_CAN_EXSKILL,				// EXスキルが使えるようになる（EXメーターが溜まるようになる）
	SF_SPMAX,					// SP最大値（100～200。それ以外は100扱い）
	SF_STAMMINA_LV,				// スタミナレベル（０～）
	SF_CHARANORECVSHADOW,		// キャラは影受けない	// マップ切り替え毎に毎回リセットされる。argのエリアフラグでセットすべし。

		// チュートリアル確認用
	SF_USE_TAMEATK,				// ため攻撃で敵にダメージを与えると１が入る
	SF_USE_SKILLATK,			// スキル攻撃で敵にダメージを与えると１が入る

		// タイムアタック系
	SF_TIMEATK,					// タイムアタック中フラグ（このフラグが立っている時はメニューからのセーブが不可能になる予定）
	SF_TIMEATKCT,				// タイムアタック計測時間（プログラム用）


	SF_CHRSWITCH_MODE,			// 仲間は後ろについてくるのではなく、ＨＰ等を共有して切り替える（ZWEI式）。

		// その他後日追加系
	SF_MAP_CHECK_POINT03,		// マップチェックポイント（バッファ３）
	SF_MAP_CHECK_POINT04,		// マップチェックポイント（バッファ４）

	SF_NOCHANGEBGM,				// マップ切り替え時にＢＧＭを切り替えない	※マップ切り替え後initスクリプト後にリセットされる。

	SF_TEAR_CANT_HEAL,			// １を指定するとティアが回復行動をしてくれなくなる。

	SF_LOADINIT,				// ロードで飛んできた。※次回マップ切り替え後initスクリプト前にリセットされる。

	SF_BESTIARYPOTION,			// ベスティアリーポーションを使った事がある（システムセーブに以降するかも）
	SF_ITEMSLOT_NUMBK,			// 冒険具スロット数バックアップ

	SF_2ND_TAKEOVER_LV,			// レベル引き継いだ
	SF_2ND_TAKEOVER_SKILL,		// スキル引き継いだ
	SF_2ND_TAKEOVER_EQUIP,		// （武器を除く）装備品を引き継いだ
	SF_2ND_TAKEOVER_USEITEM,	// 消耗品を引き継いだ
	SF_2ND_TAKEOVER_MATERIAL,	// 素材・食材を引き継いだ
	SF_2ND_TAKEOVER_MAPRATIO,	// 地図開封率を引き継いだ
	SF_2ND_GET_MATERIAL,		// 周回特典「各種鉱石」を選んだ
	SF_2ND_GET_BOTTLE,			// 周回特典「空き瓶」を選んだ
	SF_2ND_TAKEOVER_MAPMARKER,	// 地図マーカーを引き継いだ

	SF_CANTUSE_SKILL,			// スキル使用禁止（SPが溜まらない）

	SF_VOICE_LAXIA_1ST,			// ラクシャボイス前半
	SF_VOICE_RICOTTA_1ST,		// リコッタボイス前半

	SF_EPILOGUE_MODE,			// エピローグモード（禁止設定の水晶石マーカーを非表示にし、水晶石とメインマーカー以外のマーカーも非表示にする。選択も出来なくする。）
	SF_CANTUSE_MAP,				// 地図使用禁止
	SF_WEAKENEMY_COUNT,			// 敵弱体化カウント
	SF_WEAKENEMY_UPDATE,		// 敵弱体化カウントアップデートしたよ（だから消さないで）
	SF_CANTUSE_TOOL,			// 冒険具使用禁止（冒険具スロットの非表示化と機能を禁止する）

	SF_GALLERY_EVENT,			// イベントギャラリーから呼び出している
	SF_GALLERY_AUTOMODE,		// ギャラリーが自動再生モード

	SF_DANA_WATERSTYLE_LV,		// ダーナ編スタイルレベル（※2016/10/24現在は現代編でも有効）	0-デフォルト
	SF_DANA_EARTHSTYLE_LV,		// ダーナ編スタイルレベル（※2016/10/24現在は現代編でも有効）	0-デフォルト
	SF_DANA_LIGHTSTYLE_LV,		// ダーナ編スタイルレベル（※2016/10/24現在は現代編でも有効）	0-デフォルト

	SF_INFERNO,					// インフェルノモード（ナイトメアでかつインフェルノの時のみインフェルノになる）

	SF_SYS_CLEARED,				// （システムセーブ・ロードされる）クリア済み
	SF_SYS_TRUECLEARED,			// （システムセーブ・ロードされる）トゥルーエンド済み
	SF_SYS_GALLERYMODE,			// ギャラリーモード中（システムセーブのロード・セーブがギャラリーモード用になる）
	SF_SYS_TIMEATKMODE,			// タイムアタックモード中（システムセーブのロード・セーブがタイムアタックモード用になる）
	SF_AUTOSAVING,				// オートセーブ中
	SF_CANTLOAD,				// ロード不可能！											// マップ切り替え毎に毎回リセットされる。argのエリアフラグでセットすべし
	SF_MAPDATAID,				// 地図を開く際に読み込むデータを決めるデータセットのＩＤ入れ。scr_inc.hのEMAPDATA_ID_～を参照。
	SF_INFINITY,				// インフィニティモード（LV1の敵がLV70になる。LV99の敵はLV130？になる）
	SF_ATKMEMBERNUM,			// 戦闘に参加するメンバー数（１～３）現在の人数よりこの数字が少ない状態で、JoinParty/RestorePartyMemberをすると、自動的に減らされる。JoinParty(-1)でＯＫ。

	SF_CANTUSE_DLC_MENU,		// DLCメニュー使用禁止

	SF_SYS_TIMEATKHELP,			// タイムアタックのヘルプ見た事がある

	//-- （リザーブ） --------------------------------------
	__SF_TOPIC_34,				// topic_34 
	__SF_TOPIC_35,				// topic_35 
	__SF_TOPIC_36,				// topic_36 
	__SF_TOPIC_37,				// topic_37 
	__SF_TOPIC_38,				// topic_38 
	__SF_TOPIC_39,				// topic_39 
	__SF_TOPIC_40,				// topic_40 
	__SF_TOPIC_41,				// topic_41 
	__SF_TOPIC_42,				// topic_42 
	__SF_TOPIC_43,				// topic_43 
	__SF_TOPIC_44,				// topic_44 
	__SF_TOPIC_45,				// topic_45 
	__SF_TOPIC_46,				// topic_46 
	__SF_TOPIC_47,				// topic_47 
	__SF_TOPIC_48,				// topic_48 
	__SF_TOPIC_49,				// topic_49 
	__SF_TOPIC_50,				// topic_50 
	__SF_TOPIC_51,				// topic_51 
	__SF_TOPIC_52,				// topic_52 
	__SF_TOPIC_53,				// topic_53 
	__SF_TOPIC_54,				// topic_54 
	__SF_TOPIC_55,				// topic_55 
	__SF_TOPIC_56,				// topic_56 
	//--------------------------------------------------------------------

	SF_NOUSE_MTD_VIBRATION,		// MTD の振動コマンドを無視します (マップ切替でクリア) 

	SF_NOBACKGROUNDTG,			// 遠景用ターゲットバッファ（低解像度）を使わない			(マップ切替で自動リセット)
	SF_ADDCONT_CHECKING,		// ダウンロードコンテンツを確認中
	SF_KILLDRAGON_COUNT,		// 竜型古代種撃破数

	SF_SAVENPCMODE,				// 護衛イベントモード（0-通常	1-NPCのHPが０になったらゲームオーバー）　(マップ切替で自動リセット)
	SF_DISABLE_FISHING,			// 釣りを禁止する (マップ切替で自動リセット)

	SF_INDOORMODE,				// 屋内モード（移動速度が0.75倍される）
	SF_SAVEBITDATA,				// プログラム用、ビットフラグのデータ。SAVEBIT_～で判定。

	SF_MEMORYEVENT,				// プログラムがオンオフする。記憶メニューから記憶イベントを実行中（セーブ不可、スキップ可、スキップ時 or ReturnMemoryMenuでメニューに戻る）
	SF_MEMORYEVENT_SCP,			// スクリプトでオンオフする。メインイベント等で記憶イベントを実行中を示すフラグ。（キャラチェンジ不可、ＳＴＡＲＴボタンで直接システムメニューが開く）

	SF_BOSS_BATTLE,				// ボスバトル中
	SF_EVENT_ON,				// イベント発生ＯＮ。基本たちっぱ

	SF_CANUSE_MAPWARP,			// 地図の移動機能が転移機能になる。-1指定時は移動機能自体が無くなる。（アイコンは黒落ちにならず、移動するボタンが消える。）
	SF_CANUSE_MEMORYMENU,		// 記憶の欠片メニューが使える

	SF_WARP_DISABLED,			// ワープ禁止フラグ。ストッパー用。このフラグが立っていると、ワープ先を選択してもワープしません。

	SF_KILLMONSTER_COUNT,	// 敵倒した数カウント（ZOKU_ABILITY_SPECIAL用）

	SF_WAITPROMPT_NOSE,		// WaitPromptで音を鳴らさない（マップ切り替えで自動的にリセットされる）

	// ver1.01で追加
	SF_AFTERLOAD_CT,		// ロード直後にプレイヤーに操作させない為のフラグ

	// ys4で追加
	SF_NOTMAPPING,			// マッピングさせたくない時に立てるフラグ（街中等、マッピングの不要な時に立てる）	※マップ切替毎に毎回リセット
	SF_MAPPING_OFFSET_X,	// マッピングのオフセットＸ
	SF_MAPPING_OFFSET_Y,	// マッピングのオフセットＹ

	SF_MISSIONNO,			// 地図に表示する「現在の目的」を指定する。sce_inc.hにあるMS_～を設定する。

	SF_SPMAXBK,				// SP最大値（100～200。それ以外は100扱い）バックアップ

	SF_NOUSE_ITC_SUPPORT,		// 迎撃戦でサポートスキルを使わない（初回迎撃戦用）
	SF_NODRAWMAP,				// マップを描画しない（マップ切り替えでリセットされる）
	SF_REALTIMETOUT,			// リアルタイムヘルプのタイムアウト時間。-1の時はタイムアウトしない。（マップ切り替えでリセットされる）
	SF_REALTIMEHELP,			// リアルタイムヘルプ用のＩＤ格納フラグ。-1で無効。（マップ切り替えでリセットされる）

	SF_CAN_DASH,			// ダッシュできるようになる
	SF_RETRY,				// リトライしてきた

	SF_WARPGROUP,				// ワープ時のグループ設定
	SF_OVERWRITENOTICE,			// セーブ上書き注意文表示する（マップ切り替えでリセットされる）
	SF_TIMEATK_RUSH,			// ボスラッシュ中
	SF_TIMEATK_RUSHCT,			// ボスラッシュ中時間カウント
	SF_CANTGAINEXP,				// 経験値入手できない設定

	SF_CLEARFLG,				// クリアフラグ
	SF_2NDSTART,				// ２周目引き継いだフラグ

	SF_CHANGEDDIFFICULT,		// 難易度変更した

	SF_NOUSE_MTDSE,				// MTDのSE命令を無視する（エリアフラグと同様、マップ読み替え時に自動リセット）
	SF_FORCELEARN_SKILL,		// スキルを覚えるタイミングでスキルを強制的に覚えさせる。覚えたらフラグは降りる
	SF_CANTLEARN_SKILL,			// スキル習得禁止

	SF_DONTSTOP_VIBRATION,		// マップ切替時に振動を自動停止させたくない場合は立ててください (マップ切替後自動リセット)

	SF_CAMP_CANT_FORMATION,		// 編成メニュー禁止
	SF_CAMP_CANT_MEMORYMENU,	// 記憶メニュー禁止
	SF_CAMP_CANT_DIARY,			// 冒険日誌メニュー禁止
	SF_CAMP_CANT_MAP,			// 地図メニュー禁止。地図開いている最中に立てると、閉じれなくします。
	SF_CAMP_CANT_EQUIP,			// 装備メニュー禁止
	SF_CAMP_CANT_SKILL,			// スキルメニュー禁止

		// デバッグ用
	SF_DEBUG,					// デバッグ中フラグ
	SF_DEBUG_RELOADSCR,			// 全スクリプトの読み直し
	SF_DEBUG_LOADMAP,			// デバッグ機能によるロードマップ

		// 追加系
	SF_CAMP_ONLY_SAVE_ERASE,	// システムメニュー：セーブ＆削除以外を禁止（クリアデータセーブ時など）

	SF_NPCJOINSTATE,			// NPC集落加入状況保存用フラグ（プログラムでビット制御）

	SF_ADOL_JOINOKBK,			// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_LAXIA_JOINOKBK,			// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_SAHAD_JOINOKBK,			// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_HUMMEL_JOINOKBK,			// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_RICOTTA_JOINOKBK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_DANA_JOINOKBK,			// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_DANACOPY_JOINOKBK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_DANA2_JOINOKBK,			// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_DANA3_JOINOKBK,			// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_DANAOLD_JOINOKBK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ

	SF_RESERVE10_JOINOKBK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_RESERVE11_JOINOKBK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_RESERVE12_JOINOKBK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_RESERVE13_JOINOKBK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_RESERVE14_JOINOKBK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_RESERVE15_JOINOKBK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_RESERVE16_JOINOKBK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_RESERVE17_JOINOKBK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_RESERVE18_JOINOKBK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_RESERVE19_JOINOKBK,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ

	SF_ADOL_JOINED,				// パーティーに加入したことがある
	SF_LAXIA_JOINED,			// パーティーに加入したことがある
	SF_SAHAD_JOINED,			// パーティーに加入したことがある
	SF_HUMMEL_JOINED,			// パーティーに加入したことがある
	SF_RICOTTA_JOINED,			// パーティーに加入したことがある
	SF_DANA_JOINED,				// パーティーに加入したことがある
	SF_DANACOPY_JOINED,			// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_DANA2_JOINED,			// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_DANA3_JOINED,			// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_DANAOLD_JOINED,			// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ

	SF_RESERVE10_JOINED,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_RESERVE11_JOINED,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_RESERVE12_JOINED,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_RESERVE13_JOINED,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_RESERVE14_JOINED,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_RESERVE15_JOINED,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_RESERVE16_JOINED,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_RESERVE17_JOINED,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_RESERVE18_JOINED,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ
	SF_RESERVE19_JOINED,		// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）バックアップ

	SF_CAMP_CLOSE_CHECK,		// キャンプ閉じ時にチュートリアル判定を行う
	
	SF_PAST_MODE,				// 過去編用のシステム判定フラグ（０：現代	１：過去	２：過去（紋章あり））
	SF_PAST_AGAIN,				// 過去編再訪用のシステム判定フラグ（０：メニューから意識交代が使えない		０以外：メニューから意識交代が使える）

	SF_CAMP_FORCE_CAN_EQUIP,	// 装備メニューを強制許可（セーブ禁止中などでもOK）			// マップ切り替え毎に毎回リセットされる。

	SF_TAIKEN_MODE, 			// 体験版用告知画面中か 2017.12.19 m.arai

	SF_MAX,
	SF_RESERVE_MAX = 620,		// システムフラグのリザーブマックス

	// グローバルフラグ群
	//---------------------------------------------------
	// 本編用　６００番からスタート
	//
	// 各章　　　　　　	 ２００個　　200 * 11　計　2200個(プロローグ及びエピローグは1章及び11章に含みます)
	// ギミック			 １００個　　100 * 11  計　1100個(ギミックは仮に地域ごとに分けておきます)
	// その他　　　　　　４００個
	//
	// 宝箱系　　　　　　５００個
	// アイテムポイント　５００個
	// 予備　　　　　　　２００個

	//---------------------------------------------------
	// □プロローグ 9/20
	GF_00MPxxxx_START = 680,		// プロローグ		// システムフラグが侵食してきた為、第一部の後ろの空き領域に移動。

	GF_00MP0011_GO_CAPTAINROOM,		// 船長室へ向かう
	GF_00MP0012_START_PATROL,		// 巡回を開始する
	GF_00MP0012_GO_CAPTAINROOM2,	// 船長室へ向かう（２回目）
	GF_00MP0016_HEAR_SCREAM,		// 悲鳴が聞こえる
	GF_00MP0011b_DIVE_OCEAN,		// 海中に飛び込む

	GF_00MP1102_TALK_LAXIA,			// ラクシャと話した
	GF_00MP1102_TALK_SAHAD,			// サハドと話した
	GF_00MP1102_TALK_HUMMEL,		// ヒュンメルと話した
	GF_00MP1102_TALK_DOGI,			// ドギと話した
	
	GF_00MPxxxx_MAX,				// プロローグフラグ終端（フラグ数チェック用なので、GF_01Mxxxx_STARTの直前に置く）

	//---------------------------------------------------
	// □１：第一部「セイレン島」 38/60
	GF_01MPxxxx_START = 620,		// １：第一部「セイレン島」

	GF_01MP1110_DRIFT,				// 漂着した
	GF_01MP1110_GET_SWORD,			// 錆びたショートソードを手に入れた
	GF_01MP1102_DRINK_WATER,		// 水を飲んだ
	GF_01MP1101_JOIN_LAXIA,			// ラクシャと行動を開始した
	GF_01MP1201_IN_BASE,			// 拠点に到着した
	GF_01MP1201_TALK_LAXIA,			// ラクシャと話した
	GF_01MP1201_GET_DRIFT,			// 漂流物を入手した
	GF_01MP1201_CHECK_STONE,		// 水晶石を調べた
	GF_01MP1201_LOOK_MAN,			// 人影を見つけた
	GF_01MP7301_IN_CAVE,			// 洞窟に入った
	GF_01MP7301_KILL_SLUG,			// アメフラシを撃破した					//※  未使用  ※
	GF_01MP7302_IN_RUIN,			// 海賊の住処跡に入った
	GF_01MP7302_GET_ITEM,			// ポーションを入手した
	GF_01MP7302_GET_ARMOR,			// 鎧を入手した
	GF_01MP7302_GET_SWORD,			// 剣を入手した
	GF_01MP7303_ADVICE_LAXIA,		// ラクシャにアドバイスされた
	GF_01MP7303_CHECK_SKELETON,		// 骸骨を調べた
	GF_01MP7304_KILL_BAT,			// 蝙蝠を撃破した
	GF_01MP1201_MEET_BARBAROSS,		// バルバロスと再会した
	GF_01MP1101_DRAW_MAP,			// 地図を描いた
	GF_01MP1201_DRUG,				// バルバロスに調薬の説明を聞く
	GF_01MP1111_DASH_HELP,			// ダッシュチュートリアルを見た
	GF_01MP1103_JOIN_SAHAD,			// サハドと行動を開始した
	GF_01MP1201_JOIN_DOGI,			// ドギと再会する２

//	GF_KARI_END,
	GF_01MP1101_IAM_ADVENTURER,		// 冒険家と名乗った		※冒険日誌用
	GF_01MP1101_TEACH_SEIREN,		// セイレン島を教えた	※冒険日誌用
	GF_01MP7303_ADVICE_LAXIA_NOTEA,	// ラクシャにアドバイスされたA	※冒険日誌用
	GF_01MP7303_ADVICE_LAXIA_NOTEB,	// ラクシャにアドバイスされたB	※冒険日誌用
	GF_01MP7301_GET_SKILL,			// いい技を思いついた
	GF_01MP7301_SET_SKILL,			// スキルを装備した
	GF_01MP1202_IN_MP1202,			// mp1202に入った
	GF_01MP7304_KILL_BAT_HALF,		// 蝙蝠を途中まで撃破した				//※  未使用  ※
	GF_01MP7302_RUIN_END,			// 海賊の住処・調査終了
	GF_01MP1110_BATTLE_WIN,			// オオカミを倒した
	GF_01MP7302_TUTO_SET_ARMOR,		// 鎧をアドルとラクシャに装備した		//※  未使用  ※
	GF_01MPxxxx_1ST_CHAPTER_FINISH,	// 第一部了

//追加

	GF_01MPxxxx_MAX,				// １：第一部「セイレン島」フラグ終端（フラグ数チェック用なので、GF_02Mxxxx_STARTの直前に置く）

	GF_00MP_RESERVED = GF_00MPxxxx_START,	// 680:ここから後ろはプロローグ用にリザーブ

	//---------------------------------------------------
	// □２：第二部「漂流者たちの狂宴」 77/100
	GF_02MPxxxx_START = 700,		// ２：第二部「漂流者たちの狂宴」

	GF_02MP1202_GET_CLOTHES,		// ラクシャから探索服をもらう
	GF_02MP1201_TALK_DOGISAHAD,		// ドギとサハドと話す
	GF_02MP1203_START_FISHING,		// 朝食用の魚を釣りに行く
	GF_02MP1203_GET_FISH,			// 朝食用の魚を釣った
	GF_02MP1201_TEST_SMITH,			// 武器の強化を試す
	GF_02MP1201_TEST_TRADE,			// アイテム交換を試す
	GF_02MP1201_TEST_DRUG,			// 調薬を試す
	GF_02MP1201_TAKE_BREAKFAST,		// ドギが料理を説明する
	GF_02MP1201_INFO_QUEST,			// 依頼の説明を受けた
	GF_02MP1101_START_EXPLORE,		// 探索を開始した
	GF_02MP1110_REMOVE_OBSTACLE,	// 倒木を撤去した
	GF_02MP1132_LOOK_LOCE,		// 初めてロケーションポイントを発見
	GF_02MP1201_JOIN_ALISON,		// アリスンを救出した
	GF_02MP1202_OPEN_DRESS,			// アリスンが仕立屋を始める
	GF_02MP1105_MAKE_CAMP,			// はじめて野営をした
	GF_02MP1301_IN_CORAL,			// 珊瑚の森に突入した
	GF_02MP1307_JOIN_KIERGAARD,		// カーランとキルゴールに出会った
	GF_02MP1306_KILL_MIDBOSS,		// 珊瑚の森中ボスを倒した
	GF_02MP1306_GET_GROVE,			// グローブを入手した
	GF_02MP1305_CALL_PARO,			// パロから緊急連絡をうけた
	GF_02MP1201_BEFORE_INTERCEPT,	// 迎撃戦の準備をはじめた
	GF_02MP1201_START_INTERCEPT,	// 迎撃戦を開始した
	GF_02MP1201_AFTER_INTERCEPT,	// 迎撃戦一回目が終わった
	GF_02MP1308_KILL_CHAMELEON,		// 珊瑚の森ボスを撃破した
	GF_02MP1201_JOIN_KATRIN,		// カトリーンが合流した（武器の強化が可能になる２）
	GF_02MP1201_TEST_RENSEI,		// 武器の強化した
	GF_02MP2101_REMOVE_OBSTACLE,	// 土砂崩れを撤去した
	GF_02MP2102_LOOK_MONSTER,		// 古代種を目撃した
	GF_02MP2102_NEAR_MONSTER,		// 古代種に見つかった
	GF_02MP2102_LOOK_MONSTER2,		// 古代種を目撃した２
	GF_02MP1120_MEET_HUMMEL,		// ヒュンメルに出会った
	GF_02MP1121_FIND_CAMP,			// mp1121に野営地を決まった				//※  未使用  ※
	GF_02MP1121_MAKE_CAMP,			// mp1121に野営地を築いた
	GF_02MP3103_LOOK_LOOKOUT,		// 見張り台を見つけた
	GF_02MP3103_CHECK_LOOKOUT,		// 見張り台を調べた
	GF_02MP3104_LOOK_CANYON,		// 大峡谷を発見した
	GF_02MP1108_JOIN_HUMMEL,		// ヒュンメルが仲間になった
	GF_02MP4102_MAKE_CAMP,			// mp4102に野営地を築いた
	GF_02MP2103_MAKE_CAMP,			// mp2103に野営地を築いた
	GF_02MP4306_KILL_MIDBOSS,		// 浸食谷中ボスを倒した
	GF_02MP4309_KILL_SPIDER,		// 浸食谷ボスを倒した
	GF_02MP1119_LOOK_DINA,			//漂流者ディナを発見
	GF_02MP1119_JOIN_DINA,			//漂流者ディナが合流
	GF_02MP2301_JOIN_AARON,			// エアランに出会った
	GF_02MP2302_LOOK_MAN,			// 人影を見つけた
	GF_02MP2304_KILL_MIDBOSS,		// 密林中ボスを倒した
	GF_02MP2308_KILL_HIPPO,			// 密林ボスを撃破した
	GF_02MP1118_IN_MP1118,			// 密林を抜けた
	GF_02MP1118_CALL_PARO,			// パロの呼び出しを受けた
	GF_02MP1202_HEAR_SHOUT,			// 叫び声を聞いた
	GF_02MP1201_BEFORE_INTERCEPT2,	// 迎撃戦の準備をはじめた
	GF_02MP1201_START_INTERCEPT2,	// 迎撃戦を開始した
	GF_02MP1201_LOST_CURRAN,		// カーラン卿が行方不明になった
	GF_02MP1203_CHECK_ROPE,			// 水面を漂うロープを調べた				//※  未使用  ※
	GF_02MP1201_LOOK_CURRAN,		// カーラン卿を発見した
	GF_02MP1101_START_RESCUE,		// カーラン卿を助けに向かった
	GF_02MP1113_WIN_ENEMY,			// オケアノスの取り巻きを退けた
	GF_02MP1201_START_HEARING,		// 聞き込みを開始した
	GF_02MP1201_END_HEARING,		// 聞き込みで情報を集めた
	GF_02MP1201_LOOK_MAN,			// 人影を見つけた
	GF_02MP1101_LOOK_WAIE,			// 鋼線トラップを見つけた
	GF_02MP1201_UNMASK_NEMO,		// 名無しの正体が判明した
	GF_02MP1201_CHASE_KIERGAARD,	// キルゴールが逃げた
	GF_02MP1101_GUIDE_PARO,			// パロが案内をはじめた
	GF_02MP1111_WOUND_BARBAROSS,	// バルバロスが致命傷を負う
	GF_02MP1103_KILL_KIERGAARD,		// キルゴールを撃破した

	GF_02MP43xx_OCCUR_INTERCEPT2,	// 迎撃戦２が発生した
	GF_02MP43xx_AFTER_INTERCEPT2,	// 迎撃戦２が終了した
	GF_02MP23xx_OCCUR_INTERCEPT3,	// 迎撃戦３が発生した
	GF_02MP23xx_AFTER_INTERCEPT3,	// 迎撃戦３が終了した
	GF_02MPxxxx_AFTER_INTERCEPT2OR3,	// 迎撃戦２か３が終了した（ショップ制御用）				//※  未使用  ※
	GF_02MP1201_TUTO_NUMA_BOOTS,		//▼チュートリアル：浮き靴（mp1201）					//※  未使用  ※
	GF_02MP1201_TUTO_WEAPON_EVOLVE,		//▼チュートリアル：武器進化（mp1201）					//※  未使用  ※
	GF_02MP1201_TUTO_WEAPON_EVOLVED,	//▼チュートリアル：武器進化させた（mp1201）			//※  未使用  ※
	GF_02MP1201_AFTER_INTERCEPT2,	// 迎撃戦が終了した。古代種に襲われるカーランをヒュンメルが助け、ドギが追い払うイベントを見た
	GF_02MP1201_DOGITUTO_COMP,		// 第二部冒頭のドギチュートリアルを一通り終えた				//※パッチ1.01前は立たないケースがあった
	GF_02MP1201_TUTO_QS220,			// バルバロスが通りかかり必須クエスト(「見張り台の建設【必須】)
	GF_02MPxxxx_2ND_CHAPTER_FINISH,	// 第二部了

//追加

	GF_02MP1110_REMOVE_OBSTACLE_1ST,	// 倒木を撤去した の前半を見た
	GF_02MPxxxx_MAX,				// ２：第二部「漂流者たちの狂宴」フラグ終端（フラグ数チェック用なので、GF_03Mxxxx_STARTの直前に置く）

	//---------------------------------------------------
	// □３：第三部　「ジャンダルムを越えて」 32/50
	GF_03MPxxxx_START = 800,		// ３：第三部「ジャンダルムを越えて」

	GF_03MP6410M_HEAR_TREE,			//ダーナ編①	植樹祭の説明を受ける						//※２回立てている
	GF_03MP6410M_TALK_C350,			//ダーナ編①	仮会話フラグ								//※  未使用  ※
	GF_03MP3109M_MOVE_CANYON,		//ダーナ編①	大峡谷へ向かう
									//ダーナ編①	植樹祭開始を宣言する
									//ダーナ編①	渓谷奥へ進む
									//ダーナ編①	植樹の儀を始める
	
	GF_03MP1202_AWAKE_ADOL,			//夢に驚くアドル
	GF_03MP1201_STRIKE_KUINA,		//クイナとぶつかるアドル
	GF_03MP1204_VISIT_GRAVE,		//墓前でラクシャと話す
	GF_03MP1201_GOTO_GENSD,			//ジャンダルムへ向かうことになる
	GF_03MP1101_LEAVE_CAMP,			//ジャンダルムへ出発する
	GF_03MP3104_IN_GENSD,			//大峡谷に到着する
	GF_03MP3104_CROSS_BRIDGE,		//大木の橋を渡り終える
	GF_03MP3105_MAKE_CAMP,			//ジャンダルム麓の野営地を出発する
	GF_03MP4202_IN_LODGE,			//タナトスの小屋に到着する
	GF_03MP4202_LOOK_LODGE,			//小屋の中を調べる
	GF_03MP4202_LOOK_NOTE,			//机の上の手帳を調べる
	GF_03MP4202_LOOK_FLOWER,		//飾られた花を調べる
	GF_03MP4202_LOOK_BOOK,			//本棚を調べる
	GF_03MP4202_TALK_LODGE,			//小屋の中央で会話
	GF_02MP4337_KILL_MIDBOSS,		//リコッタが助太刀に入る（中ボス撃破	※不使用？		//※同時に立ててる
	GF_03MP4202_JOIN_RICOTTA,		//リコッタの話を聞く									//※同時に立ててる
	GF_03MP1201_VISIT_RICOTTA,		//リコッタが初めて漂流村へやって来る	※不使用		//※同時に立ててる
	GF_03MP1201_TALK_KATRIN,		//カトリーンに相談する									//※同時に立ててる
	GF_03MP1107_REPAIR_ROPE,		//吊り橋を修理する
	GF_03MP7401_IN_CAVERN,			//古代洞窟入口に到着する
	GF_03MP7401_DEPTH_CAVERN,		//古代洞窟の最奥に到着する
	GF_03MP7401_GET_MATERIAL,		//古代洞窟の最奥に到着する2
	GF_03MP1201_ALARM_INTERCEPT,	//警鐘が鳴り響く
	GF_03MP1201_BACK_GENSD,			//再びジャンダルムへ向けて出発する
									//翼竜型古代種登場
	GF_03MP4341_KILL_ANCIENT,		//翼竜型古代種ボス戦終了
	GF_03MP4107_TOP_GENSD,			//ジャンダルムの頂上に到着する
	GF_03MP433x_OCCUR_INTERCEPT5,	// 迎撃戦５が発生した
	GF_03MP433x_AFTER_INTERCEPT5,	// 迎撃戦５が終了した
	GF_03MPxxxx_3RD_CHAPTER_FINISH,	// 第三部了

//追加

	GF_03MPxxxx_MAX,				// ３：第三部「ジャンダルムを越えて」フラグ終端（フラグ数チェック用なので、GF_04Mxxxx_STARTの直前に置く）

	//---------------------------------------------------
	// □４：第四部　「失われし世界」 40/50
	GF_04MPxxxx_START = 850,		// □４：第四部「失われし世界」

	GF_04MP4107_GOTO_NORTH,			//北部の探索を決意する２	
	GF_04MP4111_SEE_ORITREE,		//はじまりの大樹を眺める
	GF_04MP4111_MAKE_CAMP,			//大樹前の野営地に到着する	//※不使用					＜実際は使っている
	GF_04MP6201_IN_AIGIUS,			//ダーナ③ アイギスを散策する
	GF_04MP6201_SEE_TOWER,			//ダーナ③ 塔堂を見る
	GF_04MP6204_MEET_DORAN,			//ダーナ③ ドランに会う
	GF_04MP4111_OUT_CAMP,			//野営地を出発する
	GF_04MP5102_MISS_RICOTTA,		//リコッタが行方不明になる
	GF_04MP5102_CATCH_MONS,			//小型古代種を追っていく
	GF_04MP5401_ENTER_DEN,			//古代種の住処へ突入する
	GF_04MP5401_FIND_RICOTTA,		//リコッタを発見する
	GF_04MP5401_TALK_RICOTTA, 		//リコッタを住処から救出する
	GF_04MP5102_RESCUE_RICOTTA,		//リコッタを住処から救出する３
	GF_04MP5101_IN_PLAIN,			//山道が終わり平野部に出る
	GF_04MP6102_LOOK_GIANT,			//超大型古代種に遭遇する
	GF_04MP6101_MAKE_CAMP,			//王都前で立ち往生する
	GF_04MP6101_CRYSTAL_FLASH, 		// 水晶前で不思議な現象が起こる
	GF_04MP6401M_GO_MP6101M,		//過去Ⅰ アドルの夢を見る２
	GF_04MP5101_OUT_CAMP,			//王都前野営地を出発する
	GF_04MP6202_IN_EAST,			//王都東街区に到着する
	GF_04MP6202_SEE_FIGURE,			//東街区で人影を見る
	GF_04MP6201_RUN_WEST,			//人影が西街区へ逃げていく
	GF_04MP6203_SEE_BUILD,			//西街区の崩落した建物を見る
	GF_04MP6203_RUN_AWAY,			//人影はさらに端へ逃げていく
	GF_04MP6203_IN_BUILD,			//人影は建物に逃げ込む
	GF_04MP6214_GOTO_2F,			//建物内で気配を感じて２階へ向かう
	GF_04MP6203_LOOK_BUILD,			//建物内を調べる
	GF_04MP6203_RUN_CENTER,			//人影が中央方面に逃げてい
	GF_04MP6201_LOOK_PAGOIDA,		//塔堂を見つける
	GF_04MP6211_LOOK_STATUE,		//塔堂内の石像を見る
	GF_04MP6211_RUN_PAGOIDA,		//塔堂内の奥へ人影が逃げる
	GF_04MP6204_IN_PAGOIDA,			//崩落した橋を眺める
	GF_04MP6204_SEE_THANATOS,		//橋の上でタナトスに出会う２
	GF_04MP6101M_KNOW_DOWNFALL,		//過去Ⅱ ダーナが王国滅亡を知る２
	GF_04MP6201_TALK_THANATOS,		//参道の障害で立ち往生する
	GF_04MP6201_DIS_OBSTACLE,		//参道の障害が消滅する
	GF_04MP6409_IN_TEM,				//大樹の寺院に到着する
	GF_04MP6402_CHECK_GIM,			//扉の開閉装置を操作する
	GF_04MP6402_IN_DANAROOM,		//ダーナの部屋に到着する
	GF_04MP6410_KILL_GUARDIAN,		//寺院ボス戦終了
	GF_04MP6409_LOOKUP_ORITREE,		//はじまりの大樹を見る
	GF_04MP5101_OCCUR_INTERCEPT7,	// 迎撃戦７が発生した
	GF_04MP5101_AFTER_INTERCEPT7,	// 迎撃戦７が終了した
	GF_04MPxxxx_4TH_CHAPTER_FINISH,	// 第四部了

//追加

	GF_04MP6409_LOOK_1ST_CUT,		//大樹に捕らわれているダーナのカットを見た
	GF_04MPxxxx_MAX,				// ４：第四部「失われし世界」フラグ終端（フラグ数チェック用なので、GF_05Mxxxx_STARTの直前に置く）

	//---------------------------------------------------
	// □５：第五部　「大樹の巫女」 64/100
	GF_05MPxxxx_START = 900,		// □５：第五部「大樹の巫女」

	GF_05MP1201_IN_MEETING,			//ドギたちに北部の状況を伝える
	GF_05MP1213_INTERCEPT_DANA,		//ダーナが迎撃戦に参加する２
	GF_05MP1201_JOIN_DANA,			//ダーナがアドル班に加わる２
	GF_05MP1201_GOTO_BAHA,			//バハの塔へ向かうことになる
	GF_05MP6204_SEE_RUIN,			//ダーナが王宮跡を見る
	GF_05MP6201_IN_EAST,			//東方面の通路に出る
	GF_05MP6203_SEE_BAHA,			//バハの塔を眺める
	GF_05MP6115_SEE_HOLLOW,			//ダーナが頭痛に見舞われる
	GF_05MP6201M_GOTO_BAHA,			//過去Ⅲ　ダーナが塔へ向かう
	GF_05MP6201M_IN_BAHA,			//過去Ⅲ　ダーナが塔に到着する　	//※	未使用	※
	GF_05MP6110_OUT_CAMP,			//塔前の野営地を出発する
	GF_05MP6321_ATTACK_TOWER,		//塔の探索を開始した
	GF_05MP6325_KILL_MIDBOSS,		//バハの塔中ボス戦闘終了
	GF_05MP6325_GET_DOUBLEJUMP,		//始祖鳥の指環を入手
	GF_05MP6329_KILL_BAHABOSS,		//バハの塔大ボス戦闘終了
	GF_05MP6330_FIND_MONOLITH,		//知識の間にたどり着く
	GF_05MP6330_LOOK_MONOLITH,		//ダーナがモノリスを起動する
	GF_05MP1201_NOTICE_MIST,		//漂流村の騒がしさに気づく
	GF_05MP1201_UP_LOOKOUT,			//見張り台を登ることにする
	GF_05MP1201_GOTO_GHOSTHIP,		//幽霊船を調査することになる
	GF_05MP7411_SEE_GHOSTHIP,		//エレフセリア号を発見する
	GF_05MP7411_INTO_GHOSTHIP,		//エレフセリアの入り口を探す
	GF_05MP7411_READ_NOTE1,			//リードの航海日誌①を読む
	GF_05MP7411_SAIL_GHOSTSHIP,		//エレフセリア号が出航する
	GF_05MP0404_READ_NOTE2,			//リードの航海日誌②を読む
	GF_05MP0404_READ_NOTE3,			//リードの航海日誌③を読む
	GF_05MP0404_READ_NOTE4,			//リードの航海日誌④を読む
	GF_05MP0405_WIN_BOSS,			//キャプテン・リード戦闘後
	GF_05MP0405_READ_NOTE5,			//最後の航海日誌を読む
	GF_05MP0404_KILL_MIDBOSS,		//※未使用フラグ					//※	未使用	※
	GF_05MP0405_READ_REED,			//キャプテン・リードと別れる２
	GF_05MP1202_CHECK_MAP,			//大空洞へ向かうことになる２
	GF_05MP1201_GOTO_HOLLOW,		//王都に転移で到着する２
	GF_05MP6204_FIND_CRYSTAL,		//空中回廊に到達する
	GF_05MP6202_GOTO_SKYWAY,		//過去Ⅳ　兵士の一団に遭遇する
	GF_05MP6204_APPEAR_CASTLE,		//消滅した王宮が復活する
	GF_05MP6362_SEE_FALLS,			//大穴の大瀑布を見る２
	GF_05MP6366_KILL_MIDBOSS,		//大空洞中ボス戦闘終了
	GF_05MP6365_GET_OXYGEN,			//《水竜の鱗》を手に入れる
	GF_05MP1201_OCEANUS_STANDBY,	//オケアノス討伐戦の準備
	GF_05MP6371_START_OPS,			//オケアノス討伐戦を開始する		//※	未使用	※
	GF_05MP6367_KILL_OCEANUS,		//オケアノスに勝利する				//※	未使用	※
	GF_05MP1201_HOLD_PARTY,			//漂流村で決起会が催される
	GF_05MP1201_REGAIN_MEMORY,		//記憶を取り戻すのを手伝うよ と返事する
	GF_05MP6231M_GOTO_SKYWAY,		//過去Ⅳ－２　王都に星が落下する
	GF_05MP1201_GOTO_VALLAY,		//王家の谷へ向かうことにする
	GF_05MP4105_PASS_TEM,			//寺院の山門を西側へ抜ける
	GF_05MP6105_CATCH_DANA,			//ダーナに追いつく２
	GF_05MP6203_GOTO_VALLEY,		//過去Ⅴ　ダーナが王家の谷へ出発
	GF_05MP6106M_SOLDIER_ASK,		// 過去Ⅴ　衛士たちに誰何を受ける
	GF_05MP6105_GOTO_VALLAY,		//王都の谷を目指す
	GF_05MP6108_MALK_CAMP,			//墓所前で野営する
	GF_05MP6345_KILL_MIDBOSS,		//王家の谷中ボス戦闘終了
	GF_05MP6349_KILL_BOSS,			//王家の谷大ボス戦闘終了
	GF_05MP6350_INTO_GARDEN,		//墓所の広い空間に出る
	GF_05MP6351_SEE_WALLPAINT,		//壁画の間にたどり着く

	GF_05MP1201_OCCUR_INTERCEPT9,	// 迎撃戦９が発生した
	GF_05MP1201_AFTER_INTERCEPT9,	// 迎撃戦９が終了した
	GF_05MP1202_QUEST_QS510,			// 【QS510】故郷の花クエスト開始イベントを見た
	GF_05MPxxxx_5TH_CHAPTER_FINISH,	// 第五部了

//追加
	GF_05MP7411_LOOK_BRIDGE,		// 岬の桟橋を発見した　[M05S143][幽霊船を調査することになる]で使用するフラグ
	GF_05MP0404_IN_GHOSTSHIP,		// 幽霊船の船内に入った　→ GF_05MP7411_SAIL_GHOSTSHIPの後ろにおく
	GF_05MP6370_BOSS_HELP,			// オケアノス戦中の弱点を見せるカメラ移動を見た
	GF_05MP1213_CHECK_DANA,			// 迎撃戦中にダーナ加入した後ゲームオーバーした判定用

//PS4追加
	GF_05MP1201_INTO_LOOKOUT,		//見張り台を登った

	GF_05MPxxxx_MAX,				// ５：第五部「大樹の巫女」フラグ終端（フラグ数チェック用なので、GF_05Mxxxx_STARTの直前に置く）
	
	//---------------------------------------------------
	// □６：第六部　「絶海のラクリモサ」 31/50
	GF_06MPxxxx_START = 1000,	// □６：第六部「絶海のラクリモサ」

	GF_06MP1201_BEFORE_INTERCEPT,		//王家の谷について報告する
	GF_06MP1215_APPEAR_ANCIENT,			//迎撃戦で新種に遭遇する
	GF_06MP1201_GOTO_GEND,				//調査のためジャンダルムへ向かう		//★  "EV_M07S121_ED"に二回セット  ※
	GF_06MP4341_SEE_COCOON,				//大樹の異変を目撃する
	GF_06MP4109_IN_GATE,				//霧の漂う山門に入る
	GF_06MP4105B_START_ROOP,			//霧の中で異形の古代種と戦う１
	GF_06MP4105B_NONE_PARTY,			//霧の中で異形の古代種と戦う２
	GF_06MP6202M_GOTO_GARDEN,			//過去Ⅵ　セレンの園へ向かう
	GF_06MP6350M_IN_GARDEN,				//過去Ⅵ　セレンの園に到着する
	GF_06MP4109_GOTO_GARDEN,			//アドルがセレンの園を目指す
	GF_06MP6350_IN_GARDEN,				//アドルたちがセレンの園に到着する
	GF_06MP6350_TALK_GUARDIAN,			//護り人たちが転移してくる
	GF_06MP4109_CLEAR_MIST,				//山門の霧を突破する
	GF_06MP6409_OPEN_GATE,				//オクトゥスへ侵入する
	GF_06MP6301_INTO_WORLDTREE,			//オクトゥスの攻略を開始する
	GF_06MP6301_ATTACK_OXTOS,			//オクトゥスの攻略を開始する２
	GF_06MP6305_IN_OCEAN,				//海の回廊へ突入した
	GF_06MP6305_TALK_HYDRA,				//ヒドゥラと話す
	GF_06MP6301_RETURN_CENTER,			//オクトゥス中央の間に戻る 
	GF_06MP6306_TALK_MINOS,				//ミノスと話す
	GF_06MP6301_OPEN_INSECT,			//蟲の回廊へ進めるようになる
	GF_06MP6307_TALK_NESTOR,			//ネストールと話す
	GF_06MP6301_OPEN_HEAVENS,			//天の回廊へ進めるようになる
	GF_06MP6308_TALK_SARAI,				//サライが想念を取り戻す
	GF_06MP6301_OPEN_STAIRS,			//卵へ続く階段が現れる
	GF_06MP6350_GET_MISTILTEINN,		//想剣ミストルティンを入手する
	GF_06MP6301_GOTO_BOSSROOM,			//《選択の間》へ進む
	GF_06MP6301_OPEN_BOSSROOM,			//《選択の間》への扉を開く
	GF_06MP6310_ATTACK_BOSSROOM,		//《選択の間》攻略を開始する
	GF_06MP6409_OCCUR_INTERCEPT12,		// 迎撃戦12が発生した
	GF_06MP6409_AFTER_INTERCEPT12,		// 迎撃戦12が終了した
	GF_06MPxxxx_6TH_CHAPTER_FINISH,	// 第六部了


//追加
	GF_06MP1201_OCCUR_INTERCEPT21,		// 迎撃戦21が発生した
	GF_06MP1201_AFTER_INTERCEPT21,		// 迎撃戦21が終了した
	GF_06MP1201_OCCUR_INTERCEPT22,		// 迎撃戦22が発生した
	GF_06MP1201_AFTER_INTERCEPT22,		// 迎撃戦22が終了した
	GF_06MP1201_OCCUR_INTERCEPT23,		// 迎撃戦23が発生した
	GF_06MP1201_AFTER_INTERCEPT23,		// 迎撃戦23が終了した
	GF_06MP1201_OCCUR_INTERCEPT24,		// 迎撃戦24が発生した
	GF_06MP1201_AFTER_INTERCEPT24,		// 迎撃戦24が終了した
	GF_06MP1201_OCCUR_INTERCEPT25,		// 迎撃戦25が発生した
	GF_06MP1201_AFTER_INTERCEPT25,		// 迎撃戦25が終了した
	GF_06MP1201_OCCUR_INTERCEPT26,		// 迎撃戦26が発生した
	GF_06MP1201_AFTER_INTERCEPT26,		// 迎撃戦26が終了した
	GF_06MP1201_INTERCEPT_ALL_CLEAR,	// 迎撃戦全てクリア（アドル＆ドギのサブイベントを見た）

	GF_06MPxxxx_MAX,				// ６：第六部「絶海のラクリモサ」フラグ終端（フラグ数チェック用なので、GF_05Mxxxx_STARTの直前に置く）

	//---------------------------------------------------
	// □７：エピローグ 11/150
	GF_07MPxxxx_START = 1050,	// □７：エピローグ

	GF_07MP1202_AWAKE_ADOL,			//漂流村でアドルが目を覚ます
	GF_07MP6409_PARTY_JOIN,			// ＥＤⅢ 山門で仲間と合流
	GF_07MP6409_MEET_MAIA,			// ＥＤⅢ 大地神マイアとの邂逅
	GF_07MP6409_GOTO_ABYSS,			//ＥＤⅢ 《はじまりの深淵》突入					//※未使用だった物をパッチ1.01で立てる形に修正
	GF_07MP6409_DUNGEON_CLEAR, 	//ＥＤⅢ 《はじまりの深淵》突破
	GF_07MP1201_CHECK_VILLAGE,		//ＥＤⅢ セイレン島を脱出する

//追加
	GF_07MP1201_VILLAGE_WALK,		// 漂流村を回ってみる
	GF_07MP1201_TALK_HUMMEL,		// 漂流村を回ってみる後（ヒュンメルと話した）
	GF_07MP1201_TALK_RICOTTA,		// 漂流村を回ってみる後（リコッタと話した）
	GF_07MP1201_TALK_SAHAD,			// 漂流村を回ってみる後（サハドと話した）
	GF_07MP1201_TALK_ALL,			// 漂流村を回ってみる後（全員と話して北部に向かうことにした）
	GF_07MPxxxx_MAX,				// ７：エピローグフラグ終端（フラグ数チェック用なので、GF_05Mxxxx_STARTの直前に置く）

	//---------------------------------------------------

	GF_EVENT_CTL = 1199,		// イベント汎用フラグ

	/////////////////////////////////////////////////////
	// その他（サブイベントや地域またぎ等）全般
	/////////////////////////////////////////////////////
	GF_OTHER_START = 1200,		// その他全般
	
	GF_NORMAL_END,				// 仮◆ノーマルエンド判定用
	GF_TRUE_END,				// 仮◆トゥルーエンド判定用

	// 地名表示用
	GF_MPxxxx_MAP_NAME_NO_DRAW,	// 地名表示(0)/非表示(1)の切り替え用

	//---------------------------------------------------
	// 集落制御
	GF_BASECAMP_LV,					// 集落レベル
	GF_SMITHY_LV,					// 鍛冶場レベル
	GF_TOOLSHOP_LV,					// 道具屋レベル
	GF_CLINIC_LV,					// 診療所レベル
	GF_KITCHEN_LV,					// 調理場レベル
	GF_SHED_LV,						// 物置レベル
	GF_SHIPYARD_LV,					// 造船所レベル
	GF_FARM_LV,						// 農場畑レベル
	GF_FARMFENCE_LV,				// 農場レベル
	
	GF_CAMP_VILLAGE_LV,				// 漂流村の発展設定：集落LV
//	GF_CAMP_GATE_LV,				// 漂流村の発展設定：海と丘方面の防衛柵		//後ろに追加してます
	GF_CAMP_GRAVE_LV,				// 漂流村の発展設定：バルバロスの墓LV
	GF_CAMP_SHIPYARD_LV,			// 漂流村の発展設定：造船所LV
	GF_CAMP_FARM_LV,				// 漂流村の発展設定：農場LV
	GF_CAMP_FARMFENCE_LV,			// 漂流村の発展設定：農場柵LV
	GF_CAMP_WISHTREE_LV,			// 漂流村の発展設定：願いの木LV
	GF_CAMP_PAROWOOD_LV,			// 漂流村の発展設定：パロの止まり木LV
	GF_CAMP_ROOM_LV,				// 漂流村の発展設定：拠点屋内
	GF_CAMP_BED_LV,					// 漂流村の発展設定：寝床
	GF_CAMP_CURTAIN_LV,				// 漂流村の発展設定：女部屋のカーテン
	GF_CAMP_TAILOR_LV,				// 漂流村の発展設定：仕立て屋
	GF_CAMP_GATE_LV,				// 漂流村の発展設定：海と丘方面の防衛柵

	GF_MP1202_NOW,					// 屋内屋外判定用

	//---------------------------------------------------
	// アドルお一人様判定
	GF_PARTY_NONE,					// パーティ全員行動

	//---------------------------------------------------
	//---------------------------------------------------
	//---------------------------------------------------
	//---------------------------------------------------
	// <!-- ここから、テストや検証版用のフラグなので、不要になったら消すべし
	// □戦闘新仕様検証用
	GF_BTLNEWSPEC_TRIAL2,			// 戦闘先行検証用
	GF_GEIGEKIBATTLE_TRIAL,			// 迎撃戦検証版

	// ここまで、テストや検証版用のフラグなので、不要になったら消すべし -->
	//---------------------------------------------------
	//---------------------------------------------------
	//---------------------------------------------------
	//---------------------------------------------------

	//---------------------------------------------------
	// ボス戦制御用（同一マップでのボス戦等）　の続き
	GF_MP6310B_ENDROGRAM_STEP,		// テオス・デ・エンドログラムの段階
	GF_MP1103_KIERGAARD,			// キルゴール戦判定用
	GF_MP8323_2NDBATTLE,			// はじまりの命、第二段階（親戦）判定用

	//---------------------------------------------------
	//↓追加分
	GF_ADOLWEAPON_BACKUP,	//ミストルティンに変わる前の武器をバックアップ
	GF_NO_UNIWAIT,			//待機モーション制御用

	GF_NIGHTHUNT,			//夜マップ攻略中判定
	GF_OPEN_CORAL_T2,		//夜マップ解放（珊瑚の森
	GF_OPEN_GENSD_T2,		//夜マップ解放（ジャンダルム
	GF_OPEN_PANGAIA_T2,		//夜マップ解放（パンガイア
	
	GF_MP7304_KONG,			// マスターコング戦判定用
	
	GF_EXPOWER_BAK_ADOL,	//EXゲージのバックアップ（アドル
	GF_EXPOWER_BAK_DANA,	//EXゲージのバックアップ（ダーナ

	GF_ADOLSIDE_FAME,			//レコード：アドルとダーナの名声値を切り替えるフラグ
	GF_DANASIDE_FAME,			//レコード：アドルとダーナの名声値を切り替えるフラグ
	GF_ADOLSIDE_VIRTURE,		//レコード：アドルとダーナの徳を切り替えるフラグ
	GF_DANASIDE_VIRTURE,		//レコード：アドルとダーナの徳を切り替えるフラグ

	GF_OTHER_MAX,		// その他終端
	//---------------------------------------------------
	//記憶の玉フラグ ->ロケーション発見フラグに変更予定
	GF_MEMORY_START = 1300,		// 記憶の欠片状況

	GF_LOCATION01,//鳥鳴き岩
	GF_LOCATION02,//碧岩
	GF_LOCATION03,//七色の滝
	GF_LOCATION04,//メタボリカレス
	GF_LOCATION05,//パラセコイア
	GF_LOCATION06,
	GF_LOCATION07,
	GF_LOCATION08,//煙突岩
	GF_LOCATION09,//藍色の鉱脈
	GF_LOCATION10,//打ち上げられた遺骸
	GF_LOCATION11,//薬草の群生地
	GF_LOCATION12,
	GF_LOCATION13,//エアーズロックケルン
	GF_LOCATION14,
	GF_LOCATION15,
	GF_LOCATION16,//清風の丘
	GF_LOCATION17,//瑠璃色の鉱脈
	GF_LOCATION18,//乳白色の鉱脈
	GF_LOCATION19,//蜂塚
	GF_LOCATION20,
	GF_LOCATION21,//船の墓場
	GF_LOCATION22,//隠し倉
	GF_LOCATION23,//マングローダ
	GF_LOCATION24,//虹色の鉱脈
	GF_LOCATION25,//ユニカラミテス
	GF_LOCATION26,
	GF_LOCATION27,//実りの丘
	GF_LOCATION28,//老竜樹
	GF_LOCATION29,
	GF_LOCATION30,
	GF_LOCATION31,
	GF_LOCATION32,//スカイガーデン
	GF_LOCATION33,//静寂の間
	GF_LOCATION34,//古き勇士達の墓碑
	GF_LOCATION35,
	GF_LOCATION36,

	GF_MEMORY_MAIN01,		//テスト使用。mp1135ロケーション発見
	GF_MEMORY_MAIN02,		//テスト使用。mp3104ロケーション発見
	GF_MEMORY_MAIN03,		//テスト使用。mp1304ロケーション発見

	GF_MEMORY_END,				// 記憶の欠片状況

	//---------------------------------------------------
	//ギミック系フラグ
	GF_GIMMICK_START = 1400,		// ギミック系フラグ
	
	// 迎撃戦控え
	GF_INTERCEPT_NO,				// 現在発生中の迎撃戦控え

	// フィールド
	GF_MP1104_SHORTCUT,				// mp1104のショートカット

	// 珊瑚の森
	GF_MP130x_GIM_01,				// 珊瑚の森ギミック１
	GF_MP130x_GIM_02,				// 珊瑚の森ギミック２
	GF_MP130x_GIM_03,				// 珊瑚の森ギミック３
	GF_MP1305_INTERCEPT,			// 珊瑚の森迎撃戦

	//----
	// 浸食谷
	GF_MP430x_GIM_01,				//
	GF_MP430x_GIM_02,				//
	GF_MP430x_GIM_03,				//

	//----
	// ジャンダルム
	GF_MP433x_GIM_01,				// mp4331 ショートカット_入り口正面の倒木
	GF_MP433x_GIM_02,				// mp4333 ショートカット_縄梯子
	GF_MP433x_GIM_03,				// mp4334 ショートカット_復帰用倒木
	GF_MP433x_GIM_04,				// mp4335 ショートカット_復帰用倒木
	GF_MP433x_GIM_05,				// mp4335 ショートカット_縄梯子

	//----
	// 王家の谷
	GF_MP634x_GIM_01,				// mp6341 ショートカット
	GF_MP634x_GIM_02,				// mp6341 ショートカット
	GF_MP634x_GIM_03,				// mp6341 ショートカット

	GF_MP634x_FIRE_01,				// mp6341 上から一番目の燭台。一体目の大型不死雑魚を倒すと点火する
	GF_MP634x_FIRE_02,				// mp6341 上から二番目の燭台。二体目の大型不死雑魚を倒すと点火する
	GF_MP634x_FIRE_03,				// mp6341 上から三番目の燭台。三体目の大型不死雑魚を倒すと点火する
	GF_MP634x_FIRE_04,				// mp6341 上から四番目の燭台。四体目の大型不死雑魚を倒すと点火する

	GF_MP6346_RESET_SWITCH,			// 初期化を行ったかどうかのフラグ
	GF_MP6346_SWITCH_01R,			// mp6346 回転スイッチ１右
	GF_MP6346_SWITCH_01L,			// mp6346 回転スイッチ１左
	GF_MP6346_SWITCH_02R,			// mp6346 回転スイッチ２右
	GF_MP6346_SWITCH_02L,			// mp6346 回転スイッチ２左
	GF_MP6346_SWITCH_03R,			// mp6346 回転スイッチ３右
	GF_MP6346_SWITCH_03L,			// mp6346 回転スイッチ３左
	GF_MP6346_DOOR_01,				// mp6346 ドアの開閉状態 0=close, 1=open
	GF_MP6346_DOOR_02,				// mp6346 ドアの開閉状態 0=close, 1=open
	GF_MP6346_DOOR_03,				// mp6346 ドアの開閉状態 0=close, 1=open

	GF_MP6347_RESET_SWITCH,			// 初期化を行ったかどうかのフラグ
	GF_MP6347_SWITCH_01,			// mp6347 回転スイッチ１
	GF_MP6347_SWITCH_02,			// mp6347 回転スイッチ２
	GF_MP6347_SWITCH_03,			// mp6347 回転スイッチ３
	GF_MP6347_SWITCH_04,			// mp6347 回転スイッチ４
	GF_MP6347_DOOR_01,				// mp6347 ドアの開閉状態 0=close, 1=open

	//----
	// バハの斜塔
	GF_MP6328_SWITCH_00,			// mp6328 スイッチ00
	GF_MP6328_SWITCH_01,			// mp6328 スイッチ01
	GF_MP6328_SWITCH_02,			// mp6328 スイッチ02
	GF_MP6328_SWITCH_03,			// mp6328 スイッチ03

	//----
	// 水没寺院
	GF_MP7481_SWITCH_00,			// mp7481 スイッチ00

	//----
	// 大僧院
	GF_MP642x_SWITCH_01,			// mp6422 スイッチ01
	GF_MP642x_SWITCH_02,			// mp6421 スイッチ02
	GF_MP642x_SWITCH_03,			// mp6421 スイッチ03
	GF_MP6422_SWITCH_00,			// mp6422 スイッチ00
//	GF_MP6422_SWITCH_01,			// mp6422 スイッチ01	//後ろに追加

	//----
	// ラスダン・オクトゥス
	GF_MP630x_SMALLBOSS_00,			// mp630x 小ボス撃破①
	GF_MP630x_SMALLBOSS_01,			// mp630x 小ボス撃破②
	GF_MP630x_SMALLBOSS_02,			// mp630x 小ボス撃破③
	GF_MP630x_SMALLBOSS_03,			// mp630x 小ボス撃破④
	GF_MP630x_SMALLBOSS_04,			// mp630x 小ボス撃破⑤
	GF_MP630x_SMALLBOSS_05,			// mp630x 小ボス撃破⑥
	GF_MP630x_SMALLBOSS_06,			// mp630x 小ボス撃破⑦
	GF_MP630x_SMALLBOSS_07,			// mp630x 小ボス撃破⑧
	GF_MP630x_SMALLBOSS_08,			// mp630x 小ボス撃破⑨
	GF_MP630x_SMALLBOSS_09,			// mp630x 小ボス撃破⑨
	GF_MP630x_SMALLBOSS_10,			// mp630x 小ボス撃破⑩

	//----
	// 始生代の大穴
	GF_MP6369_SWITCH_00,			// mp6369 スイッチ00

	//----
	// 大樹の寺院・現代
	GF_MP6401_SWITCH_01R,			// mp6401理力扉２階右スイッチ
	GF_MP6401_SWITCH_01L,			// mp6401理力扉２階左スイッチ
	GF_MP6401_SWITCH_02,			// mp6401理力扉１階スイッチ
	GF_MP6401_SWITCH_03,			// mp6401扉用レバー

	//----
	// 水源地
	GF_MP745x_GIM_01,				// mp7451 ショートカット_倒木




	//----
	// クノス
	GF_MP1108_FOUNDKNOS,			// mp1108、クノスマーカー設定した
	GF_MP1108_KNOS01,				// mp1108、密林への道を塞ぐクノス（ビットフラグ）
	GF_MP1108_KNOS02,				// mp1108、サブルートへの道を塞ぐクノス（ビットフラグ）

	GF_MP2301_FOUNDKNOS,			// mp2301、クノスマーカー設定した
	GF_MP2301_KNOS,					// mp2301、袋小路塞ぐクノス（ビットフラグ）

	GF_MP2306_FOUNDKNOS,			// mp2306、クノスマーカー設定した
	GF_MP2306_KNOS,					// mp2306、袋小路塞ぐクノス（ビットフラグ）


//◆◆◆追加分◆◆◆
	// 大僧院
	GF_MP6422_SWITCH_01,			// mp6422 スイッチ01

	// 地下聖堂
	GF_MP6511_SWITCH_01,			// mp6511 スイッチ01
	GF_MP6511_SWITCH_02,			// mp6511 スイッチ02
	GF_MP6511_SWITCH_03,			// mp6511 スイッチ03
	GF_MP6511_SWITCH_04,			// mp6511 スイッチ04
	GF_MP6511_SWITCH_05,			// mp6511 スイッチ05
	GF_MP6511_TUTO_02,				// mp6511 スイッチ02・初回
	GF_MP6521_SWITCH_01,			// mp6521 スイッチ01
	GF_MP6521_TUTO_03,				// mp6521 回数制限扉・初回
	GF_MP6531_SWITCH_01,			// mp6531 スイッチ01
	GF_MP6521_SWITCH_01A,			// mp6521 スイッチ01 レバー左
	GF_MP6521_SWITCH_01B,			// mp6521 スイッチ01 レバー右
	GF_MP6521_SHORTCUT_01,			// mp6521 ショートカット1
	GF_MP6541_SWITCH_02A,			// mp6541 スイッチ01 レバー右
	GF_MP6541_SWITCH_02B,			// mp6541 スイッチ01 レバー左
	GF_MP6541_SWITCH_01,			// mp6541 スイッチ01 像
	GF_MP6541_SWITCH_02,			// mp6541 スイッチ02 凍結解除
	GF_MP6541_TUTO_03,				// mp6541 回数制限扉・初回
	GF_MP6541_SHORTCUT_01,			// mp6541 ショートカット1
	GF_MP6541_SWITCH_04,			// mp6541 スイッチ04 扇風機解除
	GF_MP6531_SHORTCUT_01,			// mp6531 ショートカット1

	// 珊瑚の森（夜）
	GF_MP130xt2_GIM_01,				// 珊瑚の森ギミック１
	GF_MP130xt2_GIM_02,				// 珊瑚の森ギミック２
	GF_MP130xt2_GIM_03,				// 珊瑚の森ギミック３

	// 追加分（互換性のため後ろに付け足す）
	GF_MP6511_SWITCH_06,			// mp6511 スイッチ06 扇風機解除
	GF_MP6521_SWITCH_02,			// mp6521 スイッチ02
	GF_MP6521_SWITCH_02A,			// mp6521 スイッチ02 レバー左
	GF_MP6521_SWITCH_02B,			// mp6521 スイッチ02 レバー右

	GF_MP6511_WALL_01,				// mp6511 障壁01 解除
	GF_MP6511_WALL_02,				// mp6511 障壁02 解除
	GF_MP6521_WALL_01,				// mp6521 障壁01 解除
	GF_MP6531_WALL_01,				// mp6531 障壁01 解除
	GF_MP6531_WALL_02,				// mp6531 障壁02 解除
	GF_MP6541_WALL_01,				// mp6541 障壁01 解除
	GF_MP6551_WALL_01,				// mp6551 障壁01 解除
	GF_MP6551_WALL_02,				// mp6551 障壁02 解除
	GF_MP6551_WALL_03,				// mp6551 障壁03 解除

	//----
	// クノス追加分	▼PS4追加
	GF_MP1114_FOUNDKNOS,			// mp1114、クノスマーカー設定した
	GF_MP1114_KNOS01,				// mp1114、クノス（ビットフラグ）
	
	GF_MP7451_FOUNDKNOS,			// mp7451、クノスマーカー設定した
	GF_MP7451_KNOS01,				// mp7451、クノス（ビットフラグ）

	GF_MP6201_FOUNDKNOS,			// mp6201、クノスマーカー設定した
	GF_MP6201_KNOS01,				// mp6201、クノス（ビットフラグ）

	GF_MP6108_FOUNDKNOS,			// mp6108、クノスマーカー設定した
	GF_MP6108_KNOS01,				// mp6108、クノス（ビットフラグ）

	GF_MP3103_FOUNDKNOS,			// mp3103、クノスマーカー設定した
	GF_MP3103_KNOS01,				// mp3103、クノス（ビットフラグ）
	
	//追加分
	GF_MP6541_CLOSE_CNT,			//封石ヘルプメッセージ表示までのカウント
	GF_MP6521_CLOSE_CNT,			//封石ヘルプメッセージ表示までのカウント

	GF_GIMMICK_MAX,					// ギミック系終端

	//---------------------------------------------------
	// 釣り目玉魚フラグ
	GF_FISH_FEATURE_START = 1700,

	GF_FISH_FEATURE_000,
	GF_FISH_FEATURE_001,
	GF_FISH_FEATURE_002,
	GF_FISH_FEATURE_003,
	GF_FISH_FEATURE_004,
	GF_FISH_FEATURE_005,
	GF_FISH_FEATURE_006,
	GF_FISH_FEATURE_007,
	GF_FISH_FEATURE_008,
	GF_FISH_FEATURE_009,

	GF_FISH_FEATURE_010,
	GF_FISH_FEATURE_011,
	GF_FISH_FEATURE_012,
	GF_FISH_FEATURE_013,
	GF_FISH_FEATURE_014,
	GF_FISH_FEATURE_015,
	GF_FISH_FEATURE_016,
	GF_FISH_FEATURE_017,
	GF_FISH_FEATURE_018,
	GF_FISH_FEATURE_019,

	GF_FISH_FEATURE_020,
	GF_FISH_FEATURE_021,
	GF_FISH_FEATURE_022,
	GF_FISH_FEATURE_023,
	GF_FISH_FEATURE_024,		//　クエスト専用魚用
	
	GF_FISH_FEATURE_B00,	//　ヌシ
	GF_FISH_FEATURE_B01,	//　ヌシ
	GF_FISH_FEATURE_B02,	//　ヌシ

	GF_FISH_FEATURE_M00,	//　暴魚00用
	GF_FISH_FEATURE_M01,	//　暴魚01用
	GF_FISH_FEATURE_M02,	//　暴魚02用
	GF_FISH_FEATURE_M03,	//　暴魚03用
	GF_FISH_FEATURE_M04,	//　暴魚04用
	GF_FISH_FEATURE_M05,	//　暴魚05用
	GF_FISH_FEATURE_M06,	//　暴魚06用
	GF_FISH_FEATURE_M07,	//　暴魚07用
	GF_FISH_FEATURE_M08,	//　暴魚08用
	GF_FISH_FEATURE_M09,	//　暴魚09用

	GF_FISH_FEATURE_T00,		//　宝箱
	GF_FISH_FEATURE_T01,		//　宝箱
	GF_FISH_FEATURE_T02,		//　宝箱
	GF_FISH_FEATURE_T03,		//　宝箱
	GF_FISH_FEATURE_T04,		//　宝箱
	GF_FISH_FEATURE_T05,		//　宝箱
	GF_FISH_FEATURE_T06,		//　宝箱
	GF_FISH_FEATURE_T07,		//　宝箱
	GF_FISH_FEATURE_T08,		//　宝箱
	GF_FISH_FEATURE_T09,		//　宝箱
	GF_FISH_FEATURE_T10,		//　宝箱
	GF_FISH_FEATURE_T11,		//　宝箱

	//追加分
	GF_FISH_FEATURE_B03,		//ヌシ

	GF_FISH_FEATURE_END,

	//---------------------------------------------------
	//サブシナリオ系フラグ

	//一般メッセージ切り替え用フラグ
	GF_NPC_START = 1800,

	GF_NPC_00_01_GO_CAPTAINROOM,		//船長室に向かう
	GF_NPC_00_02_START_PATROL,			//巡回を開始する
	GF_NPC_00_03_GO_CAPTAINROOM2,		//船長室に向かう２
	GF_NPC_00_04_HEAR_SCREAM,			//悲鳴が聞こえる
	GF_NPC_01_01_IN_BASE,				//漂流村予定地に到着
	GF_NPC_01_02_MEET_BARBAROSS,		//バルバロスと再会した
	GF_NPC_2A_01_START_EXPLORE,			//探索を開始した	
	GF_NPC_2A_02_OBSTACLE_REMOVE,		//がれきを撤去した	
	GF_NPC_2A_03_JOIN_ALISON,			//アリスンを保護
	GF_NPC_2A_04_BEFORE_INTERCEPT,		//迎撃戦（一回目）準備
	GF_NPC_2A_05_AFTER_INTERCEPT,		//迎撃戦一回目が終わった
	GF_NPC_2B_01_JOIN_KIERGAARD,		//漂流者二人を保護
	GF_NPC_2B_02_MEET_KATRIN,			//カトリーンを見つけた
	GF_NPC_2B_03_CAMP_MP1121,			//高台前の洞窟で野営した
	GF_NPC_2B_04_JOIN_HUMMEL,			//ヒュンメルと再会した
	GF_NPC_2B_05_MEET_AARON,			//エアランに出会った
	GF_NPC_2B_05_HEAR_SHOUT,			//カーラン卿の悲鳴を聞いた	
	GF_NPC_2B_06_BEFORE_INTERCEPT,		//迎撃戦の準備をはじめた
	GF_NPC_2B_07_CURRAN_LOST,			//カーラン卿が行方不明になった
	GF_NPC_2B_08_HEARING_START,			//聞き込みを開始した
	GF_NPC_2B_09_UNMASK_NEMO,			//名無しの正体が判明した
	                                      

	GF_NPC_00_PROLOGUE,				//０：鉱山に向かうまで（プロローグ）
	GF_NPC_01_START_CASNAN,			//①：キャスナンを出発
	GF_NPC_02_A_ASSALUT_COMODU,		//②Ａ：カーナ合流直前or後
	GF_NPC_02_A2_COMODU_CLEAR,		//②ＡⅡ：コモドの事件解決後
	GF_NPC_02_B_JOIN_OZMA,			//②Ｂ：オズマ合流後
	GF_NPC_02_B2_SELRAY_CLEAR,		//②ＢⅡ：セルレイの事件解決後
	GF_NPC_02_C_ONESIDE_CLEAR,		//②Ｃ：コモドorセルレイ片方クリア
	GF_NPC_02_C2_BOTH_CLEAR,		//②ＣⅡ：コモド＆セルレイ両方クリア
	GF_NPC_03_WALK_CASNAN,			//③：アドル１人で街散策
	GF_NPC_03_2_JOIN_CARNA,			//③Ⅱ：カーナと合流した後
	GF_NPC_04_WALK_HIGHLAND,		//④：町長宅で一泊後、街を散策
	GF_NPC_05_ASSALUT_HIGHLAND,		//⑤：ハイランド襲撃後
	GF_NPC_06_WALK_DANAN,			//⑥：ダナンを案内される
	GF_NPC_07_JOIN_FRIDA,			//⑦：フリーダ合流後
	GF_NPC_08_ARRIVE_ELEDUK,		//⑧：エルドゥークに到着後
	GF_NPC_09_3DUNGEON_CLEAR,		//⑨：コロニア遺跡クリア後


	GF_NPC_MAX,						// 一般メッセージ切り替えようフラグ終端
	//---------------------------------------------------
	// 料理レシピ
	GF_RECIPE_START = 1850,
	GF_RECIPE_01 = GF_RECIPE_START,	// 魚介スープ
	GF_RECIPE_02,					// キノコオムレツ
	GF_RECIPE_03,					// 肉厚ラタトゥイユ
	GF_RECIPE_04,					// 彩りムニエル
	GF_RECIPE_05,					// 海鮮キッシュ
	GF_RECIPE_06,					// ロールキャベツ
	GF_RECIPE_07,					// 肉巻きキノコーン
	GF_RECIPE_08,					// フィッシュフライ
	GF_RECIPE_09,					// パイレーツディッシュ
	GF_RECIPE_10,					// 贅沢コールスロー
	GF_RECIPE_11,					// 真心ボロネーゼ
	GF_RECIPE_12,					// 王様パンプキンパイ
	GF_RECIPE_13,					// ◆野菜ジュース（※料理手帳に載る）

	GF_RECIPE_END,
	GF_RECIPE_13_DUMMY,				// メニュー登録用ダミー（※立てなくていい）

	//---------------------------------------------------
	GF_LOVEPT_START = 1870,

//何かやりこみに使用予定
//	GF_SUB01_LOVEPT_CAT,			// 【人懐っこい猫】				の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB01_LOVEPT_PICARD,			// 【ビールで育ったピッカード】	の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB01_LOVEPT_DOG,			// 【ヨダレが止まらない犬】		の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB01_LOVEPT_HORSE,			// 【体格の良い馬】				の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB02_LOVEPT_CHICKENA,		// 【ササミ】					の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB02_LOVEPT_CHICKENB,		// 【テバ】						の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB02_LOVEPT_CHICKENC,		// 【ツクネ】					の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB02_LOVEPT_PICARDA,		// 【雄々しいピッカード】		の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB02_LOVEPT_PICARDB,		// 【女々しいピッカード】		の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB02_LOVEPT_SIKAA,			// 【勇ましい鹿】				の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB02_LOVEPT_SIKAB,			// 【大人しい鹿】				の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB02_LOVEPT_SIKAC,			// 【人懐っこい鹿】				の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB03_LOVEPT_DUCKA,			// 【優しい親ガモ】				の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB03_LOVEPT_DUCKB,			// 【元気な子ガモ】				の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB03_LOVEPT_PICARDA,		// 【ふわふわ毛質のピッカード】	の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB03_LOVEPT_PICARDB,		// 【ごわごわ毛質のピッカード】	の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB03_LOVEPT_FLOG,			// 【目がいやらしいカエル】		の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB04_LOVEPT_PICARD,			// 【輝くピッカード】			の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB04_LOVEPT_URPACA,			// 【素朴なウルパカ】			の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB04_LOVEPT_CAMEBULL,		// 【温和なキャメブル】			の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB04_LOVEPT_DOG,			// 【番犬ペロ】					の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB04_LOVEPT_CAT,			// 【アルノー】					の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB05_LOVEPT_CAT,			// 【ビャンコ】					の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）
//	GF_SUB05_LOVEPT_FLOG,			// 【ヴェルデ】					の好感度（-2：非常に悪い　-1：悪い　0：普通（初期状態）　1：良い　2:非常に良い）

	GF_LOVEPT_END,

	//現代編用
	GF_SUB01_START = 1900,			// サブシナリオ系フラグ

	GF_SUBEV_1201_CHECK_RIVER,		//【拠点の小川を調べる】
	GF_SUBEV_7302_CHECK_CLOTH,		//【ＬＰ：垂れ幕を調べる】
	GF_SUBEV_7302_CHECK_TARU,		//【ＬＰ：樽を調べる】
	GF_SUBEV_7302_CHECK_BOTTLE,		//【ＬＰ：瓶を調べる】
	GF_SUBEV_1133_LOOK_MARK,		//アリスンの足跡に気付く
	GF_SUBEV_1203_CHECK_ROPE,		//【拠点、海岸のロープを調べる】
	GF_SUBEV_NEMO_TALK_LICHT,		//名無しについてリヒトと話した
	GF_SUBEV_NEMO_TALK_BARBAROSS,	//名無しについてバルバロス船長と話した
	GF_SUBEV_NEMO_TALK_HUMMEL,		//名無しについてヒュンメルと話した
	GF_SUBEV_NEMO_TALK_KIERGAARD,	//名無しについてキルゴールと話した
	GF_SUBEV_LP_1107_BRIDGE,		//【ＬＰ：3108の落ちた釣り橋を見る】ＧＦ初回
	GF_SUBEV_LP_1202_IN_CAVE,		//【ＬＰ：水音の洞窟に入る】ＧＦ初回
	GF_SUBEV_LP_4202_FIREPLACE,		//【ＬＰ：暖炉を調べる】タナトスの小屋
	GF_SUBEV_LP_4202_HAMMOCK,		//【ＬＰ：ハンモックを調べる】タナトスの小屋
	GF_SUBEV_LP_4202_SHELF,			//【ＬＰ：棚を調べる】タナトスの小屋
	GF_SUBEV_ST_6201_DOOR_OPEN,		//【ストッパー：王都東の竜人扉】扉を開いた
	GF_SUBEV_ST_410x_DOOR_OPEN,		//【ストッパー：山門屋上東の竜人扉】扉を開いた
	GF_SUBEV_ST_DOOR_1STTALK,		//【ストッパー：山門屋上東の竜人扉】【ストッパー：山門屋上東の竜人扉】ＧＦ初回
	GF_SUBEV_ST_6203_DOOR,			//【ストッパー：大僧院の扉】ＧＦ初回
	GF_SUBEV_LP_6211_INSCRIPTION,	//【ＬＰ：中央塔の碑文】ＧＦ初回
	GF_SUBEV_ST_0404_DECK,			//【ＬＰ＆ストッパー：船内から甲板に出れない】ストッパーのイベントを見た	※未使用になりました
	GF_SUBEV_03_2102_SWAMP,			//【古代洞窟への誘導／沼への誘導と沼でのサブイベント】
	GF_SUBEV_04_6201_LOOK_BRIDGE,	//【王都アイギアス：西の橋を見る】
	GF_SUBEV_05_7411_KILL_MONS,		//【沖の洞窟でのイベント戦闘】モンスターを討伐した
	GF_SUBEV_05_6435_GET_BELL,		//【銀の鈴入手時のイベント】
	GF_SUBEV_06_6413_KILL_BOSS,		//【沈黙の塔でのボス戦闘】ボスを倒した
	GF_SUBEV_06_1111_LOOK_BOAT,		//【小舟を発見する】
	GF_SUBEV_GET_MEMO,				//Ｔ・海賊のメモを手に入れた（１つでも手に入れたら立つ）
	GF_SUBEV_GET_MEMO_T_01,			//Ｔのメモ①を手に入れた
	GF_SUBEV_GET_MEMO_T_02,			//Ｔのメモ②を手に入れた
	GF_SUBEV_GET_MEMO_T_03,			//Ｔのメモ③を手に入れた
	GF_SUBEV_GET_MEMO_T_04,			//Ｔのメモ④を手に入れた
	GF_SUBEV_GET_MEMO_P_01,			//海賊のメモ①を手に入れた
	GF_SUBEV_GET_MEMO_P_02,			//海賊のメモ②を手に入れた
	GF_SUBEV_GET_MEMO_P_03,			//海賊のメモ③を手に入れた
	GF_SUBEV_GET_MEMO_P_04,			//海賊のメモ④を手に入れた
	GF_SUBEV_GET_MEMO_P_05,			//海賊のメモ⑤を手に入れた
	GF_SUBEV_GET_MEMO_P_06,			//海賊のメモ⑥を手に入れた
	GF_SUBEV_AREANAME_4301,			//【エリアカメラ演出：侵食谷】
	GF_SUBEV_AREANAME_3105,			//【エリアカメラ演出：ジャンダルム】
	GF_SUBEV_AREANAME_6321,			//【エリアカメラ演出：バハの塔】
	GF_SUBEV_KIKIKOMI_KIERGAARD,	//【名無しの聞き込み：キルゴール】								◆未入力
	GF_SUBEV_BACKTO_MP5104,			// 古代種の住処を再訪したら
	GF_SUBEV_ARRIVE_MP7451,			// 追加サブイベント【水源地の最奥にきたら】
	GF_SUBEV_MP6341_KILLMONS01,		// 不死ザコを倒した
	GF_SUBEV_MP6341_KILLMONS02,		// 不死ザコを倒した
	GF_SUBEV_MP6341_KILLMONS03,		// 不死ザコを倒した
	GF_SUBEV_MP6341_KILLMONS04,		// 不死ザコを倒した
	GF_SUBEV_MP1201_FOLLOW_TALK,	// ▼エドとアリスンのフォロー会話 を見た
	GF_SUBEV_MEMO_P_TALK,			// 海賊のメモ：▼タナトスに海賊のメモについて聞く を見た
	GF_SUBEV_MEMO_T_TALK,			// Ｔのメモ：▼初めてＴのメモを見つけたメッセージ を見た
	GF_SUBEV_HELP_AURA,				// ディナからアウラ草の話を聞いた
	GF_SUBEV_FIRST_TIMEATK,			// 初めて黒い水晶石を調べたメッセージ

	//■■追加
	GF_SUBEV_1117_INTOSEASHORE,		//遠鳴り浜に初めて入った
	GF_SUBEV_2102_BIGFISH_TUTO,		//ヌシ釣りチュートリアル見た
	GF_SUBEV_UNTOUCHABLE,			//2周目かくしボスを倒した
	GF_SUBEV_LASTINT_START,			//2周目迎撃戦を受注した
	GF_SUBEV_LASTINT_CLEAR,			//2周目迎撃戦を受注した
	GF_SUBEV_CONTROL3_START,		//制圧戦３を開放した

	GF_SUBEV_CONTROL_ALLCLEAR,		// 制圧戦を全てクリアした

	//制圧戦勝利フラグ
	GF_CLEAR_CONTROL31,			// 制圧戦１・密林１			
	GF_CLEAR_CONTROL32,			// 制圧戦２・密林２			
	GF_CLEAR_CONTROL33,			// 制圧戦３・浸食谷１		
	GF_CLEAR_CONTROL34,			// 制圧戦４・浸食谷２		
	GF_CLEAR_CONTROL35,			// 制圧戦５・王家の谷１		
	GF_CLEAR_CONTROL36,			// 制圧戦６・王家の谷２		
	GF_CLEAR_CONTROL37,			// 制圧戦７・密林３			
	GF_CLEAR_CONTROL38,			// 制圧戦８・浸食谷３		
	GF_CLEAR_CONTROL39,			// 制圧戦９・王家の谷３		

	//過去編から引き継ぎ可能なアイテムを持ってきた
	GF_OLDITEM_GET_01,				//万世の奉輪 を過去編で入手したら立てるフラグ（ディナの宝石交換に並ぶ
	GF_OLDITEM_GET_02,				//万象の奉冠 を過去編で入手したら立てるフラグ（ディナの宝石交換に並ぶ
	GF_OLDITEM_GET_03,				//万古の奉石 を過去編で入手したら立てるフラグ（ディナの宝石交換に並ぶ
	GF_OLDITEM_GET_04,				//万言の奉袢 を過去編で入手したら立てるフラグ（ディナの宝石交換に並ぶ
	GF_OLDITEM_GET_05,				//万理の奉腕 を過去編で入手したら立てるフラグ（ディナの宝石交換に並ぶ

	//PS4追加分
	GF_SUBEV_HELP_VEGG,					//ミラルダの野菜ジュース導入イベント
	GF_SUBEV_HELP_NUSHI,				//ヌシ釣り導入イベント

	//過去編から引き継ぎ可能なアイテムを交換した
	GF_OLDITEM_TRADE_01,				//万世の奉輪 を交換した
	GF_OLDITEM_TRADE_02,				//万象の奉冠 を交換した
	GF_OLDITEM_TRADE_03,				//万古の奉石 を交換した
	GF_OLDITEM_TRADE_04,				//万言の奉袢 を交換した
	GF_OLDITEM_TRADE_05,				//万理の奉腕 を交換した

	GF_RESS02_TRADECNT,					//大樹の雫交換に必要な宝石個数

	GF_CRYPT_MARKER_SETED,				//旧地下聖堂のマーカーをセットした

	GF_OLDITEM_TBOX_KEY,				//過去クエスト：はぐれた避難民クリア報酬の引き継ぎ

	GF_PAST_CRYSTAL,					//漂流村水晶石の過去現代切り替えフラグ


	GF_SUB01_MAX,					// サブシナリオ系１フラグ終端

	//過去編用
	GF_SUB02_START = 2100,			// サブシナリオ系フラグ

	GF_SUBEV_PAST_D1_ROOM,			// ダーナ編①：【サブイベント：ダーナの私室に入る】を見た
	GF_SUBEV_PAST_D1_LP_1ST,		// ダーナ編①：【ＬＰ：ダーナの部屋の書架】初回
	
	GF_SUBEV_PAST_D3_EASTBLOCK,		// ダーナ編③：【サブイベント：東街区に入った】を見た
	GF_SUBEV_PAST_D3_TALK_RAS_TRA,	// ダーナ編③：【サブイベント：ラステル・衛士トラキルと会う】を見た
	GF_SUBEV_PAST_D3_ST_1ST,		// ダーナ編③：【ストッパー：西街道方面へ行けない】初回

	GF_SUBEV_PAST_01_TREE,			// 過去編Ⅰ：【サブイベント：大樹に祈りを捧げる】を見た
	GF_SUBEV_PAST_01_ULUGNATA,		// 過去編Ⅰ：【サブイベント：教導師ウルグナータと出会う】を見た
	GF_SUBEV_PAST_01_VIEW,			// 過去編Ⅰ：【サブイベント：過去世界を眺める】を見た
	GF_SUBEV_PAST_01_SPIRITA_1,		// 過去編Ⅰ：【精霊救出Ａ：精霊の声が聞こえる（必須）】
	GF_SUBEV_PAST_01_SPIRITA_2,		// 過去編Ⅰ：【精霊救出Ａ：渦から精霊を助ける（必須）】

	//GF_SUBEV_PAST_01_GIMMICK_L,	// 過去編Ⅰ：【過去ギミック①：水路の修理】を見た	※追加分に追加
	GF_SUBEV_PAST_01_GIMMICK_A,		// 過去編Ⅰ：【過去ギミック①：水路の修理】を達成した
	GF_SUBEV_PAST_01_GIMMICK_C,		// 過去編Ⅰ：【過去ギミック①：現代編への反映】を見た
	GF_SUBEV_PAST_01_LP_1ST,		// 過去編Ⅰ：【ＬＰ：ダーナの部屋の書架】初回
	
	GF_SUBEV_PAST_02_QUEST_A,		// 過去編Ⅱ：【過去クエスト②Ａ：かくれんぼの話を聞く】を見た
	GF_SUBEV_PAST_02_QUEST_B,		// 過去編Ⅱ：【過去クエスト②Ｂ：ミーアを見つける】を見た
	GF_SUBEV_PAST_02_QUEST_D,		// 過去編Ⅱ：【過去クエスト②Ｄ：塔堂に戻ってくる】を見た
	GF_SUBEV_PAST_02_QUEST_E,		// 過去編Ⅱ：【過去クエスト②Ｅ：像に灯った光を調べる】を見た
	GF_SUBEV_PAST_02_QUEST_F,		// 過去編Ⅱ：【過去クエスト②Ｆ：地下への仕掛け扉を開く】を見た		※フラグ数が厳しいため例外的に値（ = 2）を判定に使っている
	GF_SUBEV_PAST_02_QUEST_G,		// 過去編Ⅱ：【過去クエスト②Ｇ：地下聖堂フロア１に到達する】を見た
	GF_SUBEV_PAST_02_SPIRITB,		// 過去編Ⅱ：【精霊救出Ｂ：渦から精霊を救出する（必須）】を見た
	GF_SUBEV_PAST_02_BOSS,			// 過去編Ⅱ：【サブイベント：地下聖堂フロア１・ボスが出現】を見た
	GF_SUBEV_PAST_02_MONOLITH,		// 過去編Ⅱ：【サブイベント：地下聖堂フロア１のモノリスを読む】を見た
	GF_SUBEV_PAST_02_DOOR_B1,		// 過去編Ⅱ：【サブイベント：地下聖堂フロア１の大扉を調べる】を見た
	GF_SUBEV_PAST_02_QUEST_C,		// 過去編Ⅱ：【過去クエスト②Ｃ：達成イベント】を見た

	GF_SUBEV_PAST_02_GIMMICK_A,		// 過去編Ⅱ：【過去ギミック②：鍵の話を聞く】のイベントを見た
	GF_SUBEV_PAST_02_GIMMICK_B,		// 過去編Ⅱ：【過去ギミック②：鍵の話を聞く】扉を開いた

	GF_SUBEV_PAST_02_FIRECNT_A,		// 過去編Ⅱ：【過去クエスト②Ｅ：像に灯った光を調べる】　３つの燭台に灯火を付ける
	GF_SUBEV_PAST_02_FIRECNT_B,		// 過去編Ⅱ：【過去クエスト②Ｅ：像に灯った光を調べる】　３つの燭台に灯火を付ける
	GF_SUBEV_PAST_02_FIRECNT_C,		// 過去編Ⅱ：【過去クエスト②Ｅ：像に灯った光を調べる】　３つの燭台に灯火を付ける
	
	GF_SUBEV_PAST_03_RASTELL,		// 過去編Ⅲ：【サブイベント：ラステルと話す】を見た
	GF_SUBEV_PAST_03_OLGA,			// 過去編Ⅲ：【サブイベント：オルガと話す】を見た
	GF_SUBEV_PAST_03_ROAD,			// 過去編Ⅲ：【サブイベント：修理中の道を見る】を見た
	GF_SUBEV_PAST_03_HUNTA_LOOK,	// 過去編Ⅲ：【精霊救出Ｃ：渦から精霊を救出する（必須）】を見た
	GF_SUBEV_PAST_03_HUNTA_KILL,	// 過去編Ⅲ：【討伐イベントＡ：撃破後】を見た
	GF_SUBEV_PAST_03_GIMMICK_L,		// 過去編Ⅲ：【過去ギミック③：動物を助ける】を見た
	GF_SUBEV_PAST_03_GIMMICK_A,		// 過去編Ⅲ：【過去ギミック③：動物を助ける】を達成した（2を代入）
	GF_SUBEV_PAST_03_GIMMICK_B,		// 過去編Ⅲ：【過去ギミック③：現代編への反映】を見た

	GF_SUBEV_PAST_OPEN_B2,			// 過去編Ⅲ：【サブイベント：地下聖堂フロア１の大扉を開く】を見た	
	GF_SUBEV_PAST_GETTO_B2,			// 過去編Ⅲ：【サブイベント：地下聖堂フロア２に到達する】を見た	
	GF_SUBEV_PAST_BOSS_B2,			// 過去編Ⅲ：【サブイベント：地下聖堂フロア２・ボスが出現】を見た
	GF_SUBEV_PAST_MONOLITH_B2,		// 過去編Ⅲ：【サブイベント：地下聖堂フロア２のモノリスを読む】を見た
	GF_SUBEV_PAST_SPIRITD,			// 過去編Ⅲ：【精霊救出Ｄ：渦から精霊Ｄを救出する】を見た
	
	GF_SUBEV_PAST_04_TREE,			// 過去編Ⅳ：【サブイベント：大樹に祈りを捧げる】ＧＦ初回を見た
	GF_SUBEV_PAST_04_GIMMICK_L,		// 過去編Ⅳ：【過去ギミック④：大僧院の扉を直す】を見た
	GF_SUBEV_PAST_04_GIMMICK,		// 過去編Ⅳ：【過去ギミック④：大僧院の扉を直す】を達成した（2を代入）
	GF_SUBEV_PAST_04_IO_BARO,		// 過去編Ⅳ：【サブイベント：大樹に祈りを捧げる】ＧＦ初回を見た

	GF_SUBEV_PAST_SPIRITE,			// 過去編Ⅳ：【精霊救出Ｅ：渦から精霊を救出する】を見た
	GF_SUBEV_PAST_SPIRITF,			// 過去編Ⅳ：【精霊救出Ｆ：渦から精霊を救出する】を見た
	GF_SUBEV_PAST_OPEN_B3,			// 過去編Ⅳ：【サブイベント：地下聖堂フロア２の大扉を開く】を見た	
	GF_SUBEV_PAST_BOSS_B3,			// 過去編Ⅳ：【サブイベント：地下聖堂フロア３・ボスが出現】を見た
	GF_SUBEV_PAST_MONOLITH_B3,		// 過去編Ⅳ：【サブイベント：地下聖堂フロア３モノリスを読む】を見た

	GF_SUBEV_PAST_04_ENCOUNT,		// 過去編Ⅳ-2：【サブイベント：不可視の敵と遭遇】を見た
	GF_SUBEV_PAST_04_SPIRITG,		// 過去編Ⅳ-2：【精霊救出Ｇ：渦から精霊を救出する】を見た

	GF_SUBEV_PAST_05_QUEST_A,		// 過去編Ⅴ：【過去クエスト⑤Ａ：避難民に話を聞く】を見た
	GF_SUBEV_PAST_05_QUEST_C,		// 過去編Ⅴ：【過去クエスト⑤Ｃ：達成イベント】を見た
	GF_SUBEV_PAST_05_HUNTB_LOOK,	// 過去編Ⅴ：【討伐イベントＢ：竜種と遭遇】を見た
	GF_SUBEV_PAST_05_HUNTB_KILL,	// 過去編Ⅴ：【討伐イベントＢ：撃破後】を見た

	GF_SUBEV_PAST_SPIRITH,			// 過去編Ⅴ：【精霊救出Ｈ：渦から精霊を救出する】を見た
	GF_SUBEV_PAST_SPIRITI,			// 過去編Ⅴ：【精霊救出Ｉ：渦から精霊を救出する】を見た
	GF_SUBEV_PAST_OPEN_B4,			// 過去編Ⅴ：【サブイベント：地下聖堂フロア３の大扉を開く】を見た	
	GF_SUBEV_PAST_GETTO_B4,			// 過去編Ⅴ：【サブイベント：地下聖堂フロア４に到達する】
	GF_SUBEV_PAST_BOSS_B4,			// 過去編Ⅴ：【サブイベント：地下聖堂フロア４・ボスが出現】を見た
	GF_SUBEV_PAST_MONOLITH_B4,		// 過去編Ⅴ：【サブイベント：地下聖堂フロア４モノリスを読む】を見た

	GF_SUBEV_PAST_06_WEST,			// 過去編Ⅵ：【サブイベント：西街区→中央区にいけない】を見た
	GF_SUBEV_PAST_06_EAST,			// 過去編Ⅵ：【サブイベント：東街区でダリオス執政官と会う】を見た
	GF_SUBEV_PAST_06_GATE,			// 過去編Ⅵ：【サブイベント：山門で修道女たちに見送られる】を見た
	GF_SUBEV_PAST_06_THEA,			// 過去編Ⅵ：【サブイベント：シーアと話す】を見た
	GF_SUBEV_PAST_06_PATH,			// 過去編Ⅵ：【サブイベント：中央区に抜ける】を見た
	GF_SUBEV_PAST_06_HUNTC_LOOK,	// 過去編Ⅵ：【討伐イベントＣ：竜種と遭遇】を見た
	GF_SUBEV_PAST_06_HUNTC_KILL,	// 過去編Ⅵ：【討伐イベントＣ：撃破後】を見た
	GF_SUBEV_PAST_06_GIMMICK_A,		// 過去編Ⅵ：【過去ギミック⑥：毒沼を発見】を見た
	GF_SUBEV_PAST_06_GIMMICK_B,		// 過去編Ⅵ：【過去ギミック⑥：毒沼の浄化】で流星の欠片を動かした
	GF_SUBEV_PAST_06_GIMMICK_C,		// 過去編Ⅵ：【過去ギミック⑥：現代編への反映】を見た

	GF_SUBEV_PAST_06_SPIRITJ,		// 過去編Ⅵ：【精霊救出Ｊ：渦から精霊を救出する】をクリアした
	GF_SUBEV_PAST_OPEN_B5,			// 過去編Ⅵ：【サブイベント：地下聖堂フロア４の大扉を開く】を見た	
	GF_SUBEV_PAST_BOSS_B5,			// 過去編Ⅵ：【サブイベント：地下聖堂フロア５・ボスが出現】を見た
	GF_SUBEV_PAST_MONOLITH_B5,		// 過去編Ⅵ：【サブイベント：地下聖堂フロア５のモノリスを読む】を見た
	GF_SUBEV_PAST_LOOK_RELIEF,		// 過去編Ⅵ：【サブイベント：地下聖堂フロア５のレリーフを見た】を見た

	GF_SUBEV_PAST_07_ADD,			// 過去編Ⅶ：▼漂流村の水晶柱が変化する　を見た
	GF_SUBEV_PAST_07_IN_CASTLE,		// 過去編Ⅶ：▼王宮内部に入る　を見た
	GF_SUBEV_PAST_07_LOOK_OLGA,		// 過去編Ⅶ：▼玉座の間でオルガと再会する　を見た
	GF_SUBEV_PAST_07_TALK_OLGA,		// 過去編Ⅶ：▼オルガに報告する２　を見た
	GF_SUBEV_PAST_07_LOOK_IO,		// 過去編Ⅶ：▼イオを見つける　を見た
	GF_SUBEV_PAST_07_TALK_IO,		// 過去編Ⅶ：▼イオと再会する　を見た
	GF_SUBEV_PAST_07_INTO_6211,		// 過去編Ⅶ：▼地下聖堂入口が開いているのを見る　を見た
	GF_SUBEV_PAST_07_LOOK_STEP,		// 過去編Ⅶ：▼地下聖堂入口が開いているのを見る２　を見た
	GF_SUBEV_PAST_07_INTO_LAST,		// 過去編Ⅶ：▼聖堂最下層に足を踏み入れる　を見た
	GF_SUBEV_PAST_07_KILL_IO,		// 過去編Ⅶ：▼イオと対決する　を見た
	GF_SUBEV_PAST_07_CLEAR,			// 過去編Ⅶ：▼現代に戻ってくる　を見た

	GF_SUBEV_PAST_07_QUEST_A,		// 過去編Ⅶ：【過去クエスト⑦：理術士オドの遺体を見る】を見た
	GF_SUBEV_PAST_07_QUEST_B,		// 過去編Ⅶ：【過去クエスト⑦：花を見つける】を見た
	GF_SUBEV_PAST_07_QUEST_C,		// 過去編Ⅶ：【過去クエスト⑦：達成イベント】を見た
	GF_SUBEV_PAST_07_QUEST_NO,		// 過去編Ⅶ：【過去クエスト⑦：理術士オドの遺体を見る】を見たが受託しなかった

	GF_SUBEV_PAST_D1_TALK_ULUGNATA,	// ダーナ編①：聞き込みフラグ：教導師ウルグナータ
	GF_SUBEV_PAST_D1_TALK_SHENNA,	// ダーナ編①：聞き込みフラグ：修道女シェンナ
	GF_SUBEV_PAST_D1_TALK_CESIL,	// ダーナ編①：聞き込みフラグ：修道女セシル
	GF_SUBEV_PAST_D1_TALK_ALL,		// ダーナ編①：聞き込みフラグ：全て集めた

	GF_SUBEV_PAST_D3_TALK_DARIOS,	// ダーナ編③：聞き込みフラグ：ダリオス執政官
	GF_SUBEV_PAST_D3_TALK_MOB,		// ダーナ編③：聞き込みフラグ：Citizen_D3_B01						未使用になった 0519
	GF_SUBEV_PAST_D3_TALK_SUBEV,	// ダーナ編③：聞き込みフラグ：【サブイベント：東街区に入った】
	GF_SUBEV_PAST_D3_TALK_ALL,		// ダーナ編③：聞き込みフラグ：全て集めた

	GF_SUBEV_PAST_VIEW_MP7451M,		// 追加サブイベント【塔堂の水晶柱を見る】
	GF_SUBEV_PAST_VIEW_MP6204M,		// 追加サブイベント【エタニア王宮を眺める】
	GF_SUBEV_PAST_04_CESIL,			// 追加サブイベント【セシルと話す】
	GF_SUBEV_PAST_04_RASTELL,		// 追加サブイベント【ラステルと話す】
	GF_SUBEV_PAST_04_LP,			// 過去編Ⅳ：【ＬＰ：過去編Ⅱで植えたヒモロギを調べる】初回を見た

	//追加分
	GF_SUBEV_PAST_01_GIMMICK_L,		// 過去編Ⅰ：【過去ギミック①：水路の修理】を見た
	GF_SUBEV_PAST_06_SPIRITJ_L,		// 過去編Ⅵ：【精霊救出Ｊ：渦から精霊を救出する】を見た

	//過去編追加エピソード用
	GF_BOSSFLOOR_NUM,				//どこまでボス前フロアに到達しているか
	GF_GET_GRATICA,					//ダーナがグラティカへの変身能力を獲得した
	GF_GET_LUMINOUS,				//ダーナがルミナスへの変身能力を獲得した

	GF_OPEN_FLOOR_02,				//第２階層が開く予知を見た
	GF_OPEN_FLOOR_03,				//第３階層が開く予知を見た
	GF_OPEN_FLOOR_04,				//第４階層が開く予知を見た
	GF_OPEN_FLOOR_05,				//第５階層が開く予知を見た

	//追加分
	GF_SUBEV_PAST_02_BOSSMAE,		// 過去編Ⅱ：地下聖堂フロア１・ボス部屋前まできた（エイミー移動用）
	GF_SUBEV_PAST_GETTO_B3,			// 過去編Ⅳ：【サブイベント：地下聖堂フロア３に到達する】
	GF_SUBEV_PAST_GETTO_B5,			// 過去編Ⅵ：【サブイベント：地下聖堂フロア５に到達する】

	GF_SUB02_MAX,					// サブシナリオ系２フラグ終端

	//過去編一般ＧＦ
	GF_1STTALK_PAST_START = 2220,	// 過去編一般ＧＦ開始

	GF_1STTALK_PAST_4_MEER = GF_1STTALK_PAST_START,			//過去編Ⅳ：ミーアＧＦ初回
	GF_1STTALK_PAST_2_FAN,			//過去編Ⅱ：衛士ファンＧＦ初回
	GF_1STTALK_PAST_D3_CESIL,		//ダーナ編③：修道女セシルＧＦ初回
	GF_1STTALK_PAST_D3_TRAKIL,		//ダーナ編③：衛士トラキルＧＦ初回
	GF_1STTALK_PAST_D3_BAROSSA,		//ダーナ編③：バロッサＧＦ初回
	GF_1STTALK_PAST_D3_DARIOS,		//ダーナ編③：ダリオス執政官ＧＦ初回
	GF_1STTALK_PAST_1_ULUGNATA,		//過去編Ⅰ：教導師ウルグナータＧＦ初回
	GF_1STTALK_PAST_1_CESIL,		//過去編Ⅰ：修道女セシルＧＦ初回
	GF_1STTALK_PAST_4_CESIL,		//過去編Ⅳ：修道女セシルＧＦ初回
	GF_1STTALK_PAST_1_MOB03,		//過去編Ⅰ：Citizen_1_A03ＧＦ初回
	GF_1STTALK_PAST_4_DARIOS,		//過去編Ⅳ：ダリオス執政官ＧＦ初回
	GF_1STTALK_PAST_1B_OLGA,		//▽過去編ⅠＢ：オルガ祭司長ＧＦ初回
	GF_1STTALK_PAST_4_ATRA,			//過去編Ⅳ：侍女アトラＧＦ初回
	GF_1STTALK_PAST_6_OLGA,			//過去編Ⅳ：オルガ祭司長ＧＦ初回
	GF_1STTALK_PAST_1_ATRA,			//過去編Ⅰ：侍女アトラＧＦ初回
	GF_1STTALK_PAST_3_DIOR,			//過去編Ⅲ：ディオル隊長ＧＦ初回
	GF_1STTALK_PAST_4_ULUGNATA,		//過去編Ⅳ：教導師ウルグナータＧＦ初回

	GF_1STTALK_PAST_7_FREDO,		//過去編Ⅶ：フレドＧＦ初回
	GF_1STTALK_PAST_7_SHENNA,		//過去編Ⅶ：シェンナＧＦ初回
	GF_1STTALK_PAST_7_ANTHEA,		//過去編Ⅶ：アンシアＧＦ初回
	GF_1STTALK_PAST_7_THEA,			//過去編Ⅶ：シーアＧＦ初回
	GF_1STTALK_PAST_7_THEA2,		//過去編Ⅶ：シーアＧＦ初回（２回目）
	GF_1STTALK_PAST_7_CESIL,		//過去編Ⅶ：セシルＧＦ初回

	//PS4追加
	GF_1STTALK_PAST_3_EIMY,			//過去編Ⅲ：エイミーＧＦ初回
	GF_1STTALK_PAST_7_EIMY,			//過去編Ⅶ：エイミーＧＦ初回
	GF_1STTALK_PAST_4_PULA_EL,		//過去編Ⅳ：プラウ・エルドＧＦ初回
	GF_SUBEV_PAST_D1_TALK_IO,		// ダーナ編①：聞き込みフラグ：イオ

	GF_SUBEV_SPIRIT_ALL,			//過去編：精霊を全て救出した
	GF_SUBEV_PAST_07_SPIRIT,		//サブイベント：精霊たちと別れを告げる
	GF_SUBEV_PAST_07_EIMY,			//サブイベント：精霊エイミーと会う
	GF_SUBEV_PAST_04_IO_MONO,		//過去編Ⅳ：モノリスを読んでいる時にイオと出会う
	GF_SUBEV_PAST_04_IO_RETURN,		//過去編Ⅳ：イオと一緒に地上へ帰った
	GF_SUBEV_PAST_06_SPIRITJ_M,		//精霊セレネ　MOB出現
	GF_SPIRITJ_MOBKILL_CNT,			//精霊セレネ　MOBキルカウント
	GF_1ST_FORESIGHT,				//地下聖堂開放の予知を見た（チュートリアル用）
	GF_1ST_REARRIVE,				//始めて過去篇に再訪した（チュートリアル用）

	GF_1STTALK_PAST_MAX,			// 過去編一般ＧＦ終端

	//過去編判定用
	GF_PAST_EPISODE_START = 2260,	// 過去編判定用開始

	GF_PAST_EPISODE_D1A_TEM = GF_PAST_EPISODE_START,		//▼ダーナ編①Ａ寺院内を歩く
	GF_PAST_EPISODE_D1B_CANYON,			//▼ダーナ編①Ｂ大峡谷を攻略する
	GF_PAST_EPISODE_D3_WALK_CAPITAL,	//▼ダーナ編③王都を歩く
	GF_PAST_EPISODE_1_GO_CAMP,			//▼過去編Ⅰアドルがいたポイントへ向かう		※過去編Ⅰ再訪時は両方立てる。他のエピソードも同様
	GF_PAST_EPISODE_1B_REARRIVE,		//▽過去編ⅠＢ再訪時							※過去編Ⅰ再訪時は両方立てる。他のエピソードも同様
	GF_PAST_EPISODE_2_GO_SOUTHGATE,		//▼過去編Ⅱ南門へ向かう
	GF_PAST_EPISODE_2B_REARRIVE,		//▽過去編ⅡＢ再訪時
	GF_PAST_EPISODE_3_GO_BAHA,			//▼過去編Ⅲバハの塔へ向かう
	GF_PAST_EPISODE_3B_REARRIVE,		//▽過去編ⅢＢ再訪時
	GF_PAST_EPISODE_4_GO_CASTLE,		//▼過去編Ⅳ王宮前へ向かう
	GF_PAST_EPISODE_4B_REARRIVE,		//▽過去編ⅣＢ再訪時
	GF_PAST_EPISODE_4_2_GO_OUT,			//▼過去編Ⅳ-２王宮の外へ向かう
	GF_PAST_EPISODE_5_GO_VALLAY,		//▼過去編Ⅴ王家の谷へ向かう
	GF_PAST_EPISODE_5B_REARRIVE,		//▽過去編ⅤＢ再訪時
	GF_PAST_EPISODE_6_GO_GARDEN,		//▼過去編Ⅵセレンの園へ向かう
	GF_PAST_EPISODE_6B_REARRIVE,		//▽過去編ⅥＢ再訪時
	GF_PAST_EPISODE_7_ENDEPISODE,		//▼過去編Ⅶエンドエピソード
	GF_PAST_EPISODE_7B_REARRIVE,		//▽過去編ⅦＢ再訪時

	GF_BACKUP_SF_MISSIONNO,				//冒険メモのＩＤバックアップ（過去編処理用）

	GF_PAST_EPISODE_MAX,				// 過去編判定用終端

	//フィールド用
	GF_SUB03_START = 2300,			// サブシナリオ系フラグ

	GF_SUBEV_1111_CHECKED_ROCK_EV,	//【ＬＰ：1111⇒1112の岩を調べる】サブイベント用フラグ
	GF_SUBEV_1111_CHECKED_ROCK,		//【ＬＰ：1111⇒1112の岩を調べる】
	GF_SUBEV_1111_REMOVE_ROCK,		//【ＬＰ：1111⇒1112の岩を撤去した】
	GF_SUBEV_2101_CHECKED_ROCK,		//【ＬＰ：2101⇒2102の岩を調べた】
	GF_SUBEV_2101_REMOVE_ROCK,		//【ＬＰ：2101⇒2102の岩を撤去した】
	GF_SUBEV_1107_CHECKED_BRIDGE,	//【ＬＰ：1107⇒1108の吊り橋を調べた】
	GF_SUBEV_1107_REPAIR_BRIDGE,	//【ＬＰ：1107⇒1108の吊り橋を修理した】
	GF_SUBEV_1131_CHECKED_ROCK,		//【ＬＰ：1131⇒3101の岩を調べた】
	GF_SUBEV_1131_REMOVE_ROCK,		//【ＬＰ：1131⇒3101の岩を撤去した】
	GF_SUBEV_1120_CHECKED_ROCK,		//【ＬＰ：1120⇒洞窟前の岩を調べた】
	GF_SUBEV_1120_REMOVE_ROCK,		//【ＬＰ：1120⇒洞窟前の岩を撤去した】
	GF_SUBEV_1117_CHECKED_ROCK,		//【ＬＰ：1117⇒1135の岩を調べた】
	GF_SUBEV_1117_REMOVE_ROCK,		//【ＬＰ：1117⇒1135の岩を撤去した】
	GF_SUBEV_2105_CHECKED_ROCK,		//【ＬＰ：1117⇒1135の倒木を調べた】
	GF_SUBEV_2105_REMOVE_ROCK,		//【ＬＰ：1117⇒1135の倒木を撤去した】
	GF_SUBEV_1116_CHECKED_ROCK,		//【ＬＰ：1116⇒1116の瓦礫を調べた】
	GF_SUBEV_1116_REMOVE_ROCK,		//【ＬＰ：1116⇒1116の瓦礫を撤去した】

	GF_SUBEV_1109_CHECKED_ROCK,		//【ＬＰ：1109⇒がけ崩れを調べた】
	GF_SUBEV_1109_REMOVE_ROCK,		//【ＬＰ：1109⇒がけ崩れを補強去した】
	GF_SUBEV_6102_CHECKED_ROCK,		//【ＬＰ：6102⇒7491の岩を調べた】
	GF_SUBEV_6102_REMOVE_ROCK,		//【ＬＰ：6102⇒7491の岩を撤去した】
	GF_SUBEV_1132_CHECKED_SAND,		//【ＬＰ：1132⇒泥砂を調べた】
	GF_SUBEV_1132_REMOVE_SAND,		//【ＬＰ：1132⇒泥砂を撤去した】
	GF_SUBEV_4110_CHECKED_LADDER,	//【ＬＰ：4110⇒縄梯子を調べた】
	GF_SUBEV_4110_REMOVE_LADDER,	//【ＬＰ：4110⇒縄梯子を設置した】
	GF_SUBEV_6107_CHECKED_SAND,		//【ＬＰ：6107⇒7481の土砂を調べた】
	GF_SUBEV_6107_REMOVE_SAND,		//【ＬＰ：6107⇒7481の土砂を撤去した】
	GF_SUBEV_6362_CHECKED_PILLAR,	//【ＬＰ：6362⇒石柱を調べた】
	GF_SUBEV_6362_REMOVE_PILLAR,	//【ＬＰ：6362⇒石柱を撤去した】
	GF_SUBEV_2104_CHECKED_SAND,		//【ＬＰ：2104⇒6411の土砂を調べた】
	GF_SUBEV_2104_REMOVE_SAND,		//【ＬＰ：2104⇒6411の土砂を撤去した】

	GF_SUBEV_2101_SIEN03_LOOK,		//【ＬＰ：2101⇒2102の岩を調べた】の支援イベントNo.03でカーラン卿が帰るのを見た


	GF_SUB03_MAX,					// サブシナリオ系３フラグ終端

	//一般会話用ＧＦ
	GF_SUB04_START = 2500,			// サブシナリオ系フラグ

	GF_1STTALK_2A_03_DOGI,			//ドギＧＦ初回
	GF_1STTALK_2A_03_BARBAROSS,		//バルバロスＧＦ初回
	GF_1STTALK_2B_01_KIERGAARD,		//キルゴールＧＦ初回
	GF_1STTALK_2B_04_DINA,			//ディナＧＦ初回
	GF_1STTALK_2B_05_ALISON,		//アリスンＧＦ初回

	GF_1STTALK_2_12_AARON,			// エアランＧＦ初回（※会話後消去）
	GF_1STTALK_3_01_SAHAD,			// サハドＧＦ初回
	GF_1STTALK_2_05_KIERGAARD,		// キルゴールＧＦ初回
	GF_1STTALK_0_02_DOGI,			// ドギＧＦ初回
	GF_1STTALK_2_11_DOGI_AARON,		// ドギ、エアランの共通会話ＧＦ初回
	GF_1STTALK_2_13_DOGI,			// ドギＧＦ初回
	GF_1STTALK_4_01_DOGI,			// ドギＧＦ初回
	GF_1STTALK_6_03_DOGI,			// ドギＧＦ初回
	GF_1STTALK_0_02_BARBAROSS,		// バルバロス船長ＧＦ初回（クイナのサブイベントを見た後）
	GF_1STTALK_4_01_MIRALDA,		// ミラルダＧＦ初回
	GF_1STTALK_6_03_MIRALDA,		// ミラルダＧＦ初回
	GF_1STTALK_2_03_LAXIA,			// ラクシャ、サハドの共通会話ＧＦ初回
	GF_1STTALK_2_10_LAXIA,			// ラクシャＧＦ初回
	GF_1STTALK_3_05_RICOTTA,		// リコッタＧＦ初回
	GF_1STTALK_7_01_RICOTTA,		// リコッタ、タナトスの共通会話ＧＦ初回
	GF_1STTALK_3_01_LICHT,			// リヒトＧＦ初回（※診療所ショップが開く）
	GF_1STTALK_2_15_REJA,			// レーヤＧＦ初回	◆未使用になりました
	GF_1STTALK_3_02_REJA,			// レーヤ、クイナの共通会話ＧＦ初回
	GF_1STTALK_7_01_REJA,			// レーヤＧＦ初回
	GF_1STTALK_5_06_NIA,			// シスター・ニアＧＦ初回

	GF_SUBEV_0_02_KUINA,			// 序②船長室でクイナのサブイベントを見た
	GF_1STTALK_6_03_2H_DOGI,		// ドギ 六部後半ＧＦ初回


	GF_SUB04_MAX,			// サブシナリオ系４フラグ終端

	// 任意迎撃戦 期限内クリア報酬
	GF_INTERCEPT_REWARD_START = 2680,	// Ｆ迎撃戦、期限内クリア報酬スタート

	GF_INTERCEPT_REWARD_02 = GF_INTERCEPT_REWARD_START,	// F迎撃戦② 期限内クリア報酬
	GF_INTERCEPT_REWARD_03,			// F迎撃戦③ 期限内クリア報酬
	GF_INTERCEPT_REWARD_05,			// F迎撃戦⑤ 期限内クリア報酬
	GF_INTERCEPT_REWARD_07,			// F迎撃戦⑦ 期限内クリア報酬
	GF_INTERCEPT_REWARD_09,			// F迎撃戦⑨ 期限内クリア報酬
	GF_INTERCEPT_REWARD_12,			// F迎撃戦⑫ 期限内クリア報酬


	GF_INTERCEPT_REWARD_MAX,	// Ｆ迎撃戦、期限内クリア報酬終端

	//親愛・プレゼント・合流イベント
	GF_SUB05_START = 2700,			// サブシナリオ系フラグ

	GF_SUBEV_PRESENT_HUMMEL,		// プレゼントイベント1を見た（ヒュンメル）
	GF_SUBEV_PRESENT_PARO,			// プレゼントイベント1を見た（リトル・パロ）
	GF_SUBEV_PRESENT_REJA,			// プレゼントイベントを見た（レーヤ）

	GF_SUBEV_SINAI_ALISON,			// 親愛イベントを見た（アリスン）
	GF_SUBEV_SINAI_AARON,			// 親愛イベントを見た（エアラン）
	GF_SUBEV_SINAI_ED,				// 親愛イベントを見た（エド）
	GF_SUBEV_SINAI_AUSTEN,			// 親愛イベントを見た（オースティン）
	GF_SUBEV_SINAI_CURRAN,			// 親愛イベントを見た（カーラン）
	GF_SUBEV_SINAI_KASHU,			// 親愛イベントを見た（カシュー）
	GF_SUBEV_SINAI_KATRIN,			// 親愛イベントを見た（カトリーン）
	GF_SUBEV_SINAI_KUINA,			// 親愛イベントを見た（クイナ）
	GF_SUBEV_SINAI_GRISELDA,		// 親愛イベントを見た（グリゼルダ）
	GF_SUBEV_SINAI_SAHAD,			// 親愛イベントを見た（サハド）
	GF_SUBEV_SINAI_NIA,				// 親愛イベントを見た（シスター・ニア）
	GF_SUBEV_SINAI_SILVIA,			// 親愛イベントを見た（シルヴィア）
	GF_SUBEV_SINAI_DANA,			// 親愛イベントを見た（ダーナ）
	GF_SUBEV_SINAI_THANATOS,		// 親愛イベントを見た（タナトス）
	GF_SUBEV_SINAI_DINA,			// 親愛イベントを見た（ディナ）
	GF_SUBEV_SINAI_DOGI,			// 親愛イベントを見た（ドギ）
	GF_SUBEV_SINAI_HUMMEL,			// 親愛イベントを見た（ヒュンメル）
	GF_SUBEV_SINAI_FRANZ,			// 親愛イベントを見た（フランツ）
	GF_SUBEV_SINAI_MIRALDA,			// 親愛イベントを見た（ミラルダ）
	GF_SUBEV_SINAI_LAXIA,			// 親愛イベントを見た（ラクシャ）
	GF_SUBEV_SINAI_RICOTTA,			// 親愛イベントを見た（リコッタ）
	GF_SUBEV_SINAI_PARO,			// 親愛イベントを見た（リトル・パロ）
	GF_SUBEV_SINAI_LICHT,			// 親愛イベントを見た（リヒト）
	GF_SUBEV_SINAI_REJA,			// 親愛イベントを見た（レーヤ）
	
	GF_SUBEV_JOIN_AUSTEN,			// オースティンと合流した
	GF_SUBEV_LOOK_KASHU1,			// カシューの合流イベント①を見た
	GF_SUBEV_JOIN_KASHU,			// カシューと合流した
	GF_SUBEV_JOIN_GRISELDA,			// グリゼルダと合流した
	GF_SUBEV_LOOK_NIA1,				// シスター・ニアの合流イベント①を見た
	GF_SUBEV_JOIN_NIA,				// シスター・ニアと合流した
	GF_SUBEV_LOOK_SILVIA1,			// シルヴィアの合流イベント①を見た
	GF_SUBEV_LOOK_SILVIA2,			// シルヴィアの合流イベント②を見た
	GF_SUBEV_JOIN_SILVIA,			// シルヴィアと合流した
	GF_SUBEV_JOIN_ED,				// エドと合流した	
	GF_SUBEV_JOIN_FRANZ,			// フランツと合流した
	GF_SUBEV_JOIN_MIRALDA,			// ミラルダと合流した
	GF_SUBEV_LOOK_REJA1,			// レーヤの合流イベント①を見た
	GF_SUBEV_JOIN_REJA,				// レーヤと合流した
	GF_SUBEV_JOIN_CURRAN2,			// カーラン卿が改めて合流した
	
	GF_SPEEDRUN_SKILL_BATTLE,		// やり込みスキル習得：戦闘中管理用（1＝戦闘中）
	GF_SPEEDRUN_SKILL_SAHAD,		// やり込みスキル習得：②▼サハドＶＳマスターコングを勝利した
	GF_SPEEDRUN_SKILL_SAHAD_1ST,	// やり込みスキル習得：②▼サハドＶＳマスターコング　初回会話
	GF_SPEEDRUN_SKILL_DANA,			// やり込みスキル習得：③▼ダーナＶＳマスターコングを勝利した
	GF_SPEEDRUN_SKILL_DANA_1ST,		// やり込みスキル習得：③▼ダーナＶＳマスターコング　初回会話
	GF_SPEEDRUN_SKILL_LAXIA,		// やり込みスキル習得：④▼ラクシャＶＳマスターコングを勝利した
	GF_SPEEDRUN_SKILL_LAXIA_1ST,	// やり込みスキル習得：④▼ラクシャＶＳマスターコング　初回会話
	GF_SPEEDRUN_SKILL_HUMMEL,		// やり込みスキル習得：⑤▼ヒュンメルＶＳマスターコングを勝利した
	GF_SPEEDRUN_SKILL_HUMMEL_1ST,	// やり込みスキル習得：⑤▼ヒュンメルＶＳマスターコング　初回会話
	GF_SPEEDRUN_SKILL_ADOL,			// やり込みスキル習得：⑥▼アドルＶＳマスターコングを勝利した
	GF_SPEEDRUN_SKILL_ADOL_1ST,		// やり込みスキル習得：⑥▼アドルＶＳマスターコング　初回会話
	GF_SPEEDRUN_LOC_1STTALK,		// やり込みロケーション報告：オースティン初回会話
	GF_SPEEDRUN_LOC_HALF,			// やり込みロケーション報告：ロケーションを半分発見してアイテムを貰った
	GF_SPEEDRUN_LOC_COMP,			// やり込みロケーション報告：ロケーションを全て発見してアイテムを貰った
	GF_SPEEDRUN_FISH_1STTALK,		// やり込み魚渡し：ハシビロコウ・初回会話イベント
	GF_SPEEDRUN_FISH_ENCOUNTER,		// やり込み魚渡し：リコッタとハシビロコウの遭遇イベント
	GF_SPEEDRUN_FISH_PRESENT00,		// やり込み魚渡し：サディーナを渡した
	GF_SPEEDRUN_FISH_PRESENT01,		// やり込み魚渡し：ボレを渡した
	GF_SPEEDRUN_FISH_PRESENT02,		// やり込み魚渡し：ブルーサディを渡した
	GF_SPEEDRUN_FISH_PRESENT03,		// やり込み魚渡し：アマナを渡した
	GF_SPEEDRUN_FISH_PRESENT04,		// やり込み魚渡し：セイレンマスを渡した
	GF_SPEEDRUN_FISH_PRESENT05,		// やり込み魚渡し：ガーヴィスを渡した
	GF_SPEEDRUN_FISH_PRESENT06,		// やり込み魚渡し：ロブシュを渡した
	GF_SPEEDRUN_FISH_PRESENT07,		// やり込み魚渡し：クイーンボレを渡した
	GF_SPEEDRUN_FISH_PRESENT08,		// やり込み魚渡し：サーマンを渡した
	GF_SPEEDRUN_FISH_PRESENT09,		// やり込み魚渡し：ゲーテマグロを渡した
	GF_SPEEDRUN_FISH_PRESENT10,		// やり込み魚渡し：ミラージュを渡した
	GF_SPEEDRUN_FISH_PRESENT11,		// やり込み魚渡し：リュンガを渡した
	GF_SPEEDRUN_FISH_PRESENT12,		// やり込み魚渡し：ロワーナを渡した
	GF_SPEEDRUN_FISH_PRESENT13,		// やり込み魚渡し：ディプロミスを渡した
	GF_SPEEDRUN_FISH_PRESENT14,		// やり込み魚渡し：アルケドンを渡した
	GF_SPEEDRUN_FISH_PRESENT15,		// やり込み魚渡し：キングサーマンを渡した
	GF_SPEEDRUN_FISH_PRESENT16,		// やり込み魚渡し：アクアマリナを渡した
	GF_SPEEDRUN_FISH_PRESENT17,		// やり込み魚渡し：ピラルーを渡した
	GF_SPEEDRUN_FISH_PRESENT18,		// やり込み魚渡し：ダイナステュクスを渡した
	GF_SPEEDRUN_FISH_PRESENT19,		// やり込み魚渡し：ゴリアテスを渡した
	GF_SPEEDRUN_FISH_PRESENT20,		// やり込み魚渡し：ガイアウェルズを渡した
	GF_SPEEDRUN_FISH_PRESENT21,		// やり込み魚渡し：シラル＝カンスを渡した
	GF_SPEEDRUN_FISH_PRESENT22,		// やり込み魚渡し：ハイネリアを渡した
	GF_SPEEDRUN_FISH_PRESENT23,		// やり込み魚渡し：カルカロドンを渡した
	GF_SPEEDRUN_FISH_04OVER,		// やり込み魚渡し：４種類渡した
	GF_SPEEDRUN_FISH_08OVER,		// やり込み魚渡し：８種類渡した
	GF_SPEEDRUN_FISH_12OVER,		// やり込み魚渡し：１２種類渡した
	GF_SPEEDRUN_FISH_16OVER,		// やり込み魚渡し：１６種類渡した
	GF_SPEEDRUN_FISH_20OVER,		// やり込み魚渡し：２０種類渡した
	GF_SPEEDRUN_FISH_24OVER,		// やり込み魚渡し：２４種類渡した
	GF_SPEEDRUN_MAP_1STREPO_B,		// やり込み地図踏破率報告：地図踏破率１０％以上の報告をバルバロスに初めてした
	GF_SPEEDRUN_MAP_HALFREPO_B,		// やり込み地図踏破率報告：地図踏破率５０％以上の報告をバルバロスに初めてした
	GF_SPEEDRUN_MAP_1STREPO_A,		// やり込み地図踏破率報告：地図踏破率１０％以上の報告をエアランに初めてした
	GF_SPEEDRUN_MAP_HALFREPO_A,		// やり込み地図踏破率報告：地図踏破率５０％以上の報告をエアランに初めてした
	GF_SPEEDRUN_MAP_1ST_ITEM,		// やり込み地図踏破率報告：初めてアイテムを貰った
	GF_SPEEDRUN_MAP_10P,			// やり込み地図踏破率報告：地図踏破率１０％の報告をしてアイテムを貰った
	GF_SPEEDRUN_MAP_20P,			// やり込み地図踏破率報告：地図踏破率２０％の報告をしてアイテムを貰った
	GF_SPEEDRUN_MAP_30P,			// やり込み地図踏破率報告：地図踏破率３０％の報告をしてアイテムを貰った
	GF_SPEEDRUN_MAP_40P,			// やり込み地図踏破率報告：地図踏破率４０％の報告をしてアイテムを貰った
	GF_SPEEDRUN_MAP_50P,			// やり込み地図踏破率報告：地図踏破率５０％の報告をしてアイテムを貰った
	GF_SPEEDRUN_MAP_60P,			// やり込み地図踏破率報告：地図踏破率６０％の報告をしてアイテムを貰った
	GF_SPEEDRUN_MAP_70P,			// やり込み地図踏破率報告：地図踏破率７０％の報告をしてアイテムを貰った
	GF_SPEEDRUN_MAP_80P,			// やり込み地図踏破率報告：地図踏破率８０％の報告をしてアイテムを貰った
	GF_SPEEDRUN_MAP_90P,			// やり込み地図踏破率報告：地図踏破率９０％の報告をしてアイテムを貰った
	GF_SPEEDRUN_MAP_COMP,			// やり込み地図踏破率報告：地図踏破率１００％の報告をしてアイテムを貰った
	GF_SPEEDRUN_BOOK_1ST_K,			// やり込み調合書渡し：調合書をキルゴールに初めて渡した
	GF_SPEEDRUN_BOOK_1ST_L,			// やり込み調合書渡し：調合書をリヒトに初めて渡した
	GF_SPEEDRUN_FARM_GETPICARD,		// やり込み農場：たくましいピッカードを手に入れた
	GF_SPEEDRUN_FARM_PAPRIKA,		// やり込み農場：パプリカの種を渡した
	GF_SPEEDRUN_FARM_CABBAGE,		// やり込み農場：キャベツの種を渡した
	GF_SPEEDRUN_FARM_CORN,			// やり込み農場：コーンの種を渡した
	GF_SPEEDRUN_FARM_TOMATO,		// やり込み農場：トマトの種を渡した
	GF_SPEEDRUN_FARM_PUMPKIN,		// やり込み農場：パンプキンの種を渡した
	GF_SPEEDRUN_FARM_PICARD,		// やり込み農場：ピッカードを渡した
	GF_SPEEDRUN_FARM_NASUBI_LV,		// やり込み農場：ナスビの収穫可能数（0:収穫不可、1:３個、2:６個、3:９個）
	GF_SPEEDRUN_FARM_PAPRIKA_LV,	// やり込み農場：パプリカの収穫可能数（0:収穫不可、1:３個、2:６個、3:９個）
	GF_SPEEDRUN_FARM_CABBAGE_LV,	// やり込み農場：キャベツの収穫可能数（0:収穫不可、1:３個、2:６個、3:９個）
	GF_SPEEDRUN_FARM_CORN_LV,		// やり込み農場：コーンの収穫可能数（0:収穫不可、1:３個、2:６個、3:９個）
	GF_SPEEDRUN_FARM_TOMATO_LV,		// やり込み農場：トマトの収穫可能数（0:収穫不可、1:３個、2:６個、3:９個）
	GF_SPEEDRUN_FARM_PUMPKIN_LV,	// やり込み農場：パンプキンの収穫可能数（0:収穫不可、1:３個、2:６個、3:９個）
	GF_SPEEDRUN_FARM_NASUBI_KC,		// やり込み農場：ナスビ用敵撃破回数
	GF_SPEEDRUN_FARM_PAPRIKA_KC,	// やり込み農場：パプリカ用敵撃破回数
	GF_SPEEDRUN_FARM_CABBAGE_KC,	// やり込み農場：キャベツ用敵撃破回数
	GF_SPEEDRUN_FARM_CORN_KC,		// やり込み農場：コーン用敵撃破回数
	GF_SPEEDRUN_FARM_TOMATO_KC,		// やり込み農場：トマト用敵撃破回数
	GF_SPEEDRUN_FARM_PUMPKIN_KC,	// やり込み農場：パンプキン用敵撃破回数
	GF_SPEEDRUN_COOK_ENCOUNTER,		// やり込み料理渡し：みっしぃと遭遇した
	GF_SPEEDRUN_COOK_PRESENT00,		// やり込み料理渡し：魚介スープを渡した
	GF_SPEEDRUN_COOK_PRESENT01,		// やり込み料理渡し：キノコオムレツを渡した
	GF_SPEEDRUN_COOK_PRESENT02,		// やり込み料理渡し：肉厚ラタトゥイユを渡した
	GF_SPEEDRUN_COOK_PRESENT03,		// やり込み料理渡し：彩りムニエルを渡した
	GF_SPEEDRUN_COOK_PRESENT04,		// やり込み料理渡し：海鮮キッシュを渡した
	GF_SPEEDRUN_COOK_PRESENT05,		// やり込み料理渡し：ロールキャベツを渡した
	GF_SPEEDRUN_COOK_PRESENT06,		// やり込み料理渡し：肉巻きキノコを渡した
	GF_SPEEDRUN_COOK_PRESENT07,		// やり込み料理渡し：フィッシュフライを渡した
	GF_SPEEDRUN_COOK_PRESENT08,		// やり込み料理渡し：パイレーツディッシュを渡した
	GF_SPEEDRUN_COOK_PRESENT09,		// やり込み料理渡し：贅沢コールスローを渡した
	GF_SPEEDRUN_COOK_PRESENT10,		// やり込み料理渡し：真心ボロネーゼを渡した
	GF_SPEEDRUN_COOK_PRESENT11,		// やり込み料理渡し：王様パンプキンパイを渡した
	GF_SPEEDRUN_COOK_2,				// やり込み料理渡し：料理を２種類渡した
	GF_SPEEDRUN_COOK_4,				// やり込み料理渡し：料理を４種類渡した
	GF_SPEEDRUN_COOK_6,				// やり込み料理渡し：料理を６種類渡した
	GF_SPEEDRUN_COOK_8,				// やり込み料理渡し：料理を８種類渡した
	GF_SPEEDRUN_COOK_10,			// やり込み料理渡し：料理を１０種類渡した
	GF_SPEEDRUN_COOK_COMP,			// やり込み料理渡し：料理を全種類渡した

	GF_DRUG_RECIPE01,				// 蒼き調合書《視》	目薬のレシピ			渡して調合可能になった。
	GF_DRUG_RECIPE02,				// 蒼き調合書《甘》	甘い妙薬のレシピ		渡して調合可能になった。
	GF_DRUG_RECIPE03,				// 蒼き調合書《血》	止血薬のレシピ			渡して調合可能になった。
	GF_DRUG_RECIPE04,				// 蒼き調合書《快》	フルポーションのレシピ	渡して調合可能になった。
	GF_DRUG_RECIPE05,				// 蒼き調合書《苦》	苦い妙薬のレシピ		渡して調合可能になった。
	GF_DRUG_RECIPE06,				// 蒼き調合書《恵》	大樹の雫のレシピ		渡して調合可能になった。
	GF_DRUG_RECIPE07,				// 蒼き調合書《命》	命の霊薬のレシピ		渡して調合可能になった。
	GF_DRUG_RECIPE08,				// 蒼き調合書《隠》	隠者の妙薬のレシピ		渡して調合可能になった。
	GF_DRUG_RECIPE09,				// 蒼き調合書《力》	力の霊薬のレシピ		渡して調合可能になった。
	GF_DRUG_RECIPE10,				// 蒼き調合書《守》	守の霊薬のレシピ		渡して調合可能になった。
	GF_DRUG_RECIPE11,				// 蒼き調合書《覇》	覇王水のレシピ			渡して調合可能になった。
	GF_DRUG_RECIPE12,				// QS301達成 奮迅水

	GF_SPEEDRUN_COOK_COUNT,			// やり込み料理渡し：数のカウント格納

	GF_SUBEV_SILVIA_MODE,			// シルヴィアの状態 0=老婆 1=戦士

// 追加

	GF_SUBEV_PRESENT_LAXIA1,		// プレゼント1を渡した（ラクシャ）
	GF_SUBEV_PRESENT_LAXIA2,		// プレゼント2を渡した（ラクシャ）
	GF_SUBEV_PRESENT_SAHAD1,		// プレゼント1を渡した（サハド）
	GF_SUBEV_PRESENT_SAHAD2,		// プレゼント2を渡した（サハド）
	GF_SUBEV_PRESENT_HUMMEL1,		// プレゼント1を渡した（ヒュンメル）
	GF_SUBEV_PRESENT_HUMMEL2,		// プレゼント2を渡した（ヒュンメル）
	GF_SUBEV_PRESENT_RICOTTA1,		// プレゼント1を渡した（リコッタ）
	GF_SUBEV_PRESENT_RICOTTA2,		// プレゼント2を渡した（リコッタ）
	GF_SUBEV_PRESENT_DANA1,			// プレゼント1を渡した（ダーナ）
	GF_SUBEV_PRESENT_DANA2,			// プレゼント2を渡した（ダーナ）
	GF_SUBEV_PRESENT_DOGI1,			// プレゼント1を渡した（ドギ）
	GF_SUBEV_PRESENT_DOGI2,			// プレゼント2を渡した（ドギ）

	GF_SPEEDRUN_FARM_1ST_KC,		// やり込み農場：敵撃破回数（初回ナスビ用）
	GF_SPEEDRUN_FARM_1ST_PAPRIKA,	// やり込み農場：敵撃破回数（初回パプリカ用）
	GF_SPEEDRUN_FARM_1ST_CABBAGE,	// やり込み農場：敵撃破回数（初回キャベツ用）
	GF_SPEEDRUN_FARM_1ST_CORN,		// やり込み農場：敵撃破回数（初回コーン用）
	GF_SPEEDRUN_FARM_1ST_TOMATO,	// やり込み農場：敵撃破回数（初回トマト用）
	GF_SPEEDRUN_FARM_1ST_PUMPKIN,	// やり込み農場：敵撃破回数（初回パンプキン用）

//PS4追加
	GF_SPEEDRUN_FISH_PRESENT24,		// やり込み魚渡し：グランアングロを渡した
	GF_SPEEDRUN_FISH_PRESENT25,		// やり込み魚渡し：ネビロブリムを渡した
	GF_SPEEDRUN_FISH_PRESENT26,		// やり込み魚渡し：ボルダートを渡した
	GF_SPEEDRUN_FISH_PRESENT27,		// やり込み魚渡し：エンシェントアビスを渡した

	GF_SUB05_MAX,				// サブシナリオ系５フラグ終端

	//クエスト・サブイベント
	GF_SUB06_START = 2900,			// サブシナリオ系フラグ
	GF_SUBEV_MAKE_LOOKOUT,			// 見張り台を作成した（【QS220】を達成した時に立てています）


	GF_SUB06_MAX,				// クエスト・サブ系フラグ終端

	///////////////////////////////////////////////

	///////////////////////////////////////////////
	// エタニアクエストトロフィーチェック用
	///////////////////////////////////////////////
	GF_TROPHY_PAST_CHECK01			= GF_SUBEV_PAST_01_GIMMICK_A,	// 01. 忘れ去られた水路
	GF_TROPHY_PAST_CHECK02			= GF_SUBEV_PAST_02_QUEST_C,		// 02. 双子のかくれんぼ
	GF_TROPHY_PAST_CHECK03			= GF_SUBEV_PAST_02_GIMMICK_A,	// 03. 水底に消えた鍵
	GF_TROPHY_PAST_CHECK04			= GF_SUBEV_PAST_03_HUNTA_KILL,	// 04. 竜種討伐①
	GF_TROPHY_PAST_CHECK05			= GF_SUBEV_PAST_03_GIMMICK_A,	// 05. 巫女の施し
	GF_TROPHY_PAST_CHECK06			= GF_SUBEV_PAST_04_GIMMICK,		// 06. 古き祝福の大扉
	GF_TROPHY_PAST_CHECK07			= GF_SUBEV_PAST_05_QUEST_C,		// 07. はぐれた避難民
	GF_TROPHY_PAST_CHECK08			= GF_SUBEV_PAST_05_HUNTB_KILL,	// 08. 竜種討伐②
	GF_TROPHY_PAST_CHECK09			= GF_SUBEV_PAST_06_HUNTC_KILL,	// 09. 竜種討伐③
	GF_TROPHY_PAST_CHECK10			= GF_SUBEV_PAST_06_GIMMICK_B,	// 10. 枯れゆく大地に恵みを
	GF_TROPHY_PAST_CHECK11			= GF_SUBEV_PAST_07_QUEST_C,		// 11. 感謝の花

	///////////////////////////////////////////////
	//一般メッセージ切り替え用フラグ
	///////////////////////////////////////////////

	GF_NPC_0_01_GO_CAPTAINROOM		= GF_00MP0011_GO_CAPTAINROOM,		// ▼序①バルバロス船長の所へ向かう
	GF_NPC_0_02_START_PATROL		= GF_00MP0012_START_PATROL,			// ▼序②船内を巡回する（夜）
	GF_NPC_0_03_ATTACK_SHIP			= GF_00MP0016_HEAR_SCREAM,			// ▼序③船が襲われる（夜）
	
	GF_NPC_1_01_IN_BASE				= GF_01MP1201_IN_BASE,				// ▼第一部①漂流村予定地に到着
	GF_NPC_1_02_MEET_BARBAROSS		= GF_01MP1201_MEET_BARBAROSS,		// ▼第一部②バルバロス船長と合流した
	
	GF_NPC_2_01_SEARCH_BARBAROSS	= GF_02MP1201_TAKE_BREAKFAST,		// ▼第二部①バルバロス船長を探しに行く
	GF_NPC_2_02_START_EXPLORE		= GF_02MP1201_INFO_QUEST,			// ▼第二部②探索開始
	GF_NPC_2_03_REMOVE_OBSTACLE		= GF_02MP1110_REMOVE_OBSTACLE,		// ▼第二部③障害物を撤去した（碧の珊瑚礁）	◆要確認：「倒木を撤去した」を利用しています
	GF_NPC_2_04_JOIN_ALISON			= GF_02MP1201_JOIN_ALISON,			// ▼第二部④アリスンを助けた
	GF_NPC_2_05_JOIN_KIERGAARD		= GF_02MP1307_JOIN_KIERGAARD,		// ▼第二部⑤カーランとキルゴールを助けた
	GF_NPC_2_06_BEFORE_INTERCEPT	= GF_02MP1201_BEFORE_INTERCEPT,		// ★第二部⑥迎撃戦①が発生
	GF_NPC_2_07_AFTER_INTERCEPT		= GF_02MP1201_AFTER_INTERCEPT,		// ▼第二部⑦迎撃戦①を済ませた
	GF_NPC_2_08_JOIN_KATRIN			= GF_02MP1201_JOIN_KATRIN,			// ▼第二部⑧カトリーンを助けた
	GF_NPC_2_09_CHECK_LOOKOUT		= GF_SUBEV_MAKE_LOOKOUT,			// ▼第二部⑨見張り台を作成した
	GF_NPC_2_10_JOIN_HUMMEL			= GF_02MP1108_JOIN_HUMMEL,			// ▼第二部⑩ヒュンメルが仲間になった
	GF_NPC_2_10_OCCUR_INTERCEPT2	= GF_02MP43xx_OCCUR_INTERCEPT2,		// ☆第二部Ｆ迎撃戦②が発生
	GF_NPC_2_10_AFTER_INTERCEPT2	= GF_02MP43xx_AFTER_INTERCEPT2,		// ☆第二部Ｆ迎撃戦②を済ませた
	GF_NPC_2_11_JOIN_DINA			= GF_02MP1119_JOIN_DINA,			// ▼第二部⑪ディナを助けた
	GF_NPC_2_11_OCCUR_INTERCEPT3	= GF_02MP23xx_OCCUR_INTERCEPT3,		// ☆第二部Ｆ迎撃戦③が発生
	GF_NPC_2_11_AFTER_INTERCEPT3	= GF_02MP23xx_AFTER_INTERCEPT3,		// ☆第二部Ｆ迎撃戦③を済ませた
	GF_NPC_2_12_HEAR_SHOUT			= GF_02MP1202_HEAR_SHOUT,			// ▼第二部⑫カーラン卿の悲鳴を聞いた
	GF_NPC_2_13_BEFORE_INTERCEPT2	= GF_02MP1201_BEFORE_INTERCEPT2,	// ★第二部⑬迎撃戦④が発生（夕方）
	GF_NPC_2_14_LOST_CURRAN			= GF_02MP1201_LOST_CURRAN,			// ▼第二部⑭カーラン卿を探しに行く
	GF_NPC_2_15_START_HEARING		= GF_02MP1201_START_HEARING,		// ▼第二部⑮名無しの捜査を開始する
	GF_NPC_2_16_GOTO_KIERGAARD		= GF_02MP1201_UNMASK_NEMO,			// ▼第二部⑯キルゴールの所へ向かう
	GF_NPC_2_17_CHASE_KIERGAARD		= GF_02MP1201_CHASE_KIERGAARD,		// ▼第二部⑰キルゴールが正体を明かす
	GF_NPC_2_18_WOUND_BARBAROSS		= GF_02MP1111_WOUND_BARBAROSS,		// ▽第二部⑱バルバロスが致命傷を負った（浜辺）
	
	GF_NPC_3_01_GOTO_LAXIA			= GF_03MP1202_AWAKE_ADOL,			// ▼第三部①ラクシャの元へ向かう
	GF_NPC_3_02_GOTO_GENSD			= GF_03MP1201_GOTO_GENSD,			// ▼第三部②ジャンダルムに向かう
	GF_NPC_3_02_OCCUR_INTERCEPT5	= GF_03MP433x_OCCUR_INTERCEPT5,		// ☆第三部Ｆ迎撃戦⑤が発生
	GF_NPC_3_02_AFTER_INTERCEPT5	= GF_03MP433x_AFTER_INTERCEPT5,		// ☆第三部Ｆ迎撃戦⑤を済ませた
	GF_NPC_3_03_JOIN_RICOTTA		= GF_03MP4202_JOIN_RICOTTA,			// ▼第三部③リコッタが仲間になった
	GF_NPC_3_04_ALARM_INTERCEPT		= GF_03MP1201_ALARM_INTERCEPT,		// ★第三部④迎撃戦⑥が発生
	GF_NPC_3_05_BACK_GENSD			= GF_03MP1201_BACK_GENSD,			// ▼第三部⑤再びジャンダルムに向かう
	
	GF_NPC_4_01_GOTO_NORTH			= GF_04MP4107_GOTO_NORTH,			// ▼第四部①島北部に足を踏み入れた
	GF_NPC_4_01_OCCUR_INTERCEPT7	= GF_04MP5101_OCCUR_INTERCEPT7,		// ☆第四部Ｆ迎撃戦⑦が発生
	GF_NPC_4_01_AFTER_INTERCEPT7	= GF_04MP5101_AFTER_INTERCEPT7,		// ☆第四部Ｆ迎撃戦⑦を済ませた
	GF_NPC_4_02_SEE_THANATOS		= GF_04MP6204_SEE_THANATOS,			// ▼第四部②タナトスと出会った
	
	GF_NPC_5_01_BEFORE_INTERCEPT8	= GF_05MP1201_IN_MEETING,			// ★第五部①迎撃戦⑧が発生
	GF_NPC_5_02_GOTO_BAHA			= GF_05MP1201_GOTO_BAHA,			// ▼第五部②バハの塔に向かう
	GF_NPC_5_02_GOTO_LOOKOUT		= GF_05MP1201_NOTICE_MIST,			// ▽第五部見張り台に向かう
	GF_NPC_5_03_GOTO_GHOSTHIP		= GF_05MP1201_GOTO_GHOSTHIP,		// ▼第五部③幽霊船を調べに向かう
	GF_NPC_5_03_OCCUR_INTERCEPT9	= GF_05MP1201_OCCUR_INTERCEPT9,		// ☆第五部Ｆ迎撃戦⑨が発生（アリスン出産後）
	GF_NPC_5_03_AFTER_INTERCEPT9	= GF_05MP1201_AFTER_INTERCEPT9,		// ☆第五部Ｆ迎撃戦⑨を済ませた
	GF_NPC_5_04_GOTO_HOLLOW			= GF_05MP1201_GOTO_HOLLOW,			// ▼第五部④大空洞へ向かう
	GF_NPC_5_05_BEFORE_INTERCEPT10	= GF_05MP1201_OCEANUS_STANDBY,		// ☆第五部⑤迎撃戦⑩（対オケアノス）が発生
	GF_NPC_5_06_HOLD_PARTY			= GF_05MP1201_HOLD_PARTY,			// ▼第五部⑥宴の漂流村を散策（夜）
	GF_NPC_5_07_GOTO_VALLAY			= GF_05MP1201_GOTO_VALLAY,			// ▼第五部⑦王家の谷へ向かう
	GF_NPC_5_08_MEET_DANA			= GF_05MP6105_GOTO_VALLAY,			// ▼第五部⑧ダーナと合流する
	
	GF_NPC_6_01_BEFORE_INTERCEPT11	= GF_06MP1201_BEFORE_INTERCEPT,		// ★第六部①迎撃戦⑪が発生
	GF_NPC_6_02_GOTO_GEND			= GF_06MP1201_GOTO_GEND,			// ▼第六部②ジャンダルム頂上へ向かう
	GF_NPC_6_03_GOTO_GARDEN			= GF_06MP4109_GOTO_GARDEN,			// ▽第六部③セレンの園を目指す
	GF_NPC_6_03_OCCUR_INTERCEPT12	= GF_06MP6409_OCCUR_INTERCEPT12,	// ★第六部Ｆ迎撃戦⑫が発生（セレンの園到着後）
	GF_NPC_6_03_AFTER_INTERCEPT12	= GF_06MP6409_AFTER_INTERCEPT12,	// ☆第六部Ｆ迎撃戦⑫を済ませた
	GF_NPC_6_04_GET_MISTILTEINN		= GF_06MP6350_GET_MISTILTEINN,		// ▼第六部④想剣ミストルティンを入手
	
	GF_NPC_7_01_GOTO_TEM			= GF_07MP1202_AWAKE_ADOL,			// ▼エピローグ①寺院前へ向かう
	GF_NPC_7_02_GOTO_ABYSS			= GF_07MP6409_GOTO_ABYSS,			// ▼エピローグ②はじまりの深淵を攻略
	GF_NPC_7_03_CHECK_VILLAGE		= GF_07MP1201_CHECK_VILLAGE,		// ▼エピローグ③漂流村を最後に見回る

	///////////////////////////////////////////////
	// ショップ更新フラグ
	///////////////////////////////////////////////

	GF_SHOP_RANK_2_08				= GF_02MP1201_JOIN_KATRIN,			// ▼第二部⑧カトリーンを助けた
	GF_SHOP_RANK_2_11				= GF_02MP1119_JOIN_DINA,			// ▼第二部⑪ディナを助けた
	GF_SHOP_RANK_3_02				= GF_03MP1201_STRIKE_KUINA,			//クイナとぶつかるアドル
	GF_SHOP_RANK_3_05				= GF_03MP1201_BACK_GENSD,			// ▼第三部⑤再びジャンダルムに向かう
	GF_SHOP_RANK_4_01				= GF_04MP4107_GOTO_NORTH,			// ▼第四部①島北部に足を踏み入れた
	GF_SHOP_RANK_5_02				= GF_05MP1201_GOTO_BAHA,			// ▼第五部②バハの塔に向かう
	GF_SHOP_RANK_5_04				= GF_05MP1201_GOTO_HOLLOW,			// ▼第五部④大空洞へ向かう
	GF_SHOP_RANK_5_07				= GF_05MP1201_GOTO_VALLAY,			// ▼第五部⑦王家の谷へ向かう
	GF_SHOP_RANK_6_01				= GF_06MP1201_BEFORE_INTERCEPT,		// ★第六部①迎撃戦⑪が発生
	GF_SHOP_RANK_EDO				= GF_05MP1201_GOTO_HOLLOW,			// エドが合流

	///////////////////////////////////////////////
	// 第○部、終了判定用フラグ
	///////////////////////////////////////////////
	GF_CHAPTER_0_END				= GF_00MP0011b_DIVE_OCEAN,			// プロローグ終了
	GF_CHAPTER_1_END				= GF_01MPxxxx_1ST_CHAPTER_FINISH,	// 第一部終了
	GF_CHAPTER_2_END				= GF_02MPxxxx_2ND_CHAPTER_FINISH,	// 第二部終了
	GF_CHAPTER_3_END				= GF_03MPxxxx_3RD_CHAPTER_FINISH,	// 第三部終了
	GF_CHAPTER_4_END				= GF_04MPxxxx_4TH_CHAPTER_FINISH,	// 第四部終了
	GF_CHAPTER_5_END				= GF_05MPxxxx_5TH_CHAPTER_FINISH,	// 第五部終了
	GF_CHAPTER_6_END				= GF_06MPxxxx_6TH_CHAPTER_FINISH,	// 第六部終了
//	GF_EPILOGUE_1_END				= 0,								// エンディング１	// 専用フラグ無し（真エンドでもノーマルエンドでもなければＯＫ）
//	GF_EPILOGUE_2_END				= GF_NORMAL_END,					// エンディング２	// 第○部判定と違って、専用フラグがあるので別名定義しない
//	GF_EPILOGUE_3_END				= GF_TRUE_END,						// 真エンディング	// 第○部判定と違って、専用フラグがあるので別名定義しない

	///////////////////////////////////////////////
	// 宝箱フラグ
	///////////////////////////////////////////////
	//
	// ↑に別名定義が続いている為わかりづらいが、test:testflagではGF_SUB06_MAXで定義数オーバー判定しているので注意
	//
	GF_TBOX_START_dummy = 3000,		// 宝箱スタートダミー

	// この間に宝箱フラグ作ること
	// ※セーブデータ互換性の為、小さい変更の時はGF_TBOX_END手前に追記していくこと。
	//   大掛かりな変更の時はセーブデータ自体が変化する可能性が高いので気にしない

	// 拠点(ボツ)	消すとずれるのでそのまま残す
	GF_MP1201_dummy_TBOX01,		//漂着物用（ボツ・未使用）
	GF_MP1201_dummy_TBOX02,		//漂着物用（ボツ・未使用）
	GF_MP1201_dummy_TBOX03,		//漂着物用（ボツ・未使用）
	GF_MP1201_dummy_TBOX04,		//漂着物用（ボツ・未使用）
	GF_MP1201_dummy_TBOX05,		//漂着物用（ボツ・未使用）
	GF_MP1201_dummy_TBOX06,		//漂着物用（ボツ・未使用）
	GF_MP1201_dummy_TBOX07,		//漂着物用（ボツ・未使用）
	GF_MP1201_dummy_TBOX08,		//漂着物用（ボツ・未使用）
	GF_MP1201_dummy_TBOX09,		//漂着物用（ボツ・未使用）
	GF_MP1201_dummy_TBOX10,		//漂着物用（ボツ・未使用）
	GF_MP1201_dummy_TBOX11,		//漂着物用（ボツ・未使用）
	GF_MP1201_dummy_TBOX12,		//漂着物用（ボツ・未使用）
	GF_MP1201_dummy_TBOX13,		//漂着物用（ボツ・未使用）
	GF_MP1201_dummy_TBOX14,		//漂着物用（ボツ・未使用）
	GF_MP1201_dummy_TBOX15,		//漂着物用（ボツ・未使用）
	GF_MP1201_dummy_TBOX16,		//漂着物用（ボツ・未使用）

	GF_TBOX_START = GF_MP1201_dummy_TBOX16,		// 宝箱スタート

	// 水音の洞窟
	GF_MP7302_TBOX02,
	GF_MP7302_TBOX03,
	GF_MP7303_TBOX01,

	// 名も無き海岸
	GF_MP1131_TBOX01,
	GF_MP1111_TBOX01,
	GF_MP1104_TBOX01,
	GF_MP1104_TBOX02,
	GF_MP1104_TBOX03,	// ▼PS4追加
	GF_MP1112_TBOX01,
	GF_MP1112_TBOX02,
	GF_MP2101_TBOX01,
	GF_MP2101_TBOX02,
	GF_MP1106_TBOX01,

	// 珊瑚礁
	GF_MP1113_TBOX01,
	GF_MP1132_TBOX01,
	GF_MP1132_TBOX02,
//	GF_MP1132_TBOX03,	//後半に追加
	GF_MP1133_TBOX01,
	GF_MP1134_TBOX01,
//	GF_MP1134_TBOX02,	//後半に追加

	// 珊瑚の森
	GF_MP1301_TBOX01,
	GF_MP1301_TBOX02,
	GF_MP1302_TBOX03,
	GF_MP1302_TBOX04,
	GF_MP1302_TBOX05,
	GF_MP1302_TBOX06,
	GF_MP1303_TBOX01,
	GF_MP1303_TBOX02,
	GF_MP1303_TBOX03,
	GF_MP1303_TBOX04,
	GF_MP1304_TBOX01,
	GF_MP1304_TBOX02,
	GF_MP1304_TBOX03,
	GF_MP1304_TBOX04,
	GF_MP1304_TBOX05,
	GF_MP1305_TBOX01,
	GF_MP1307_TBOX01,

	// 遠鳴り浜(西の浜辺)
	GF_MP1117_TBOX01,
//	GF_MP1117_TBOX02,	//後半に追加
	GF_MP1135_TBOX01,
	GF_MP1135_TBOX02,

	// 島中央部
	GF_MP2102_TBOX01,
	GF_MP2102_TBOX02,
	GF_MP2102_TBOX03,
	GF_MP2102_TBOX04,
	GF_MP2102_TBOX05,
	GF_MP1120_TBOX01,
	GF_MP1120_TBOX02,
	GF_MP1120_TBOX03,

	GF_MP3103_TBOX01,
	GF_MP3104_TBOX01,

	//滝裏の鍾乳洞
	GF_MP7471_TBOX01,
	GF_MP7471_TBOX02,

	// 島東部
	GF_MP1108_TBOX01,

	GF_MP1109_TBOX01,
	GF_MP1109_TBOX02,
	GF_MP1109_TBOX03,

	// 浸食谷
	GF_MP4301_TBOX01,
	GF_MP4301_TBOX02,
	GF_MP4301_TBOX03,
	GF_MP4301_TBOX04,
	GF_MP4301_TBOX05,
	GF_MP4302_TBOX01,
	GF_MP4302_TBOX02,
	GF_MP4302_TBOX03,
	GF_MP4303_TBOX01,
	GF_MP4305_TBOX01,
	GF_MP4305_TBOX02,
	GF_MP4305_TBOX03,
//	GF_MP4306_TBOX01,	//後ろに追加
	GF_MP4307_TBOX01,
	GF_MP4307_TBOX02,
	GF_MP4307_TBOX03,
	GF_MP4308_TBOX01,
//	GF_MP4309_TBOX01,	//後ろに追加

	// 北東の浜辺

	//風見の高原
	GF_MP3101_TBOX01,
//	GF_MP3101_TBOX02,	//後半に追加
	GF_MP3102_TBOX01,

	//水源地
	GF_MP7451_TBOX01,
	GF_MP7451_TBOX02,
	GF_MP7451_TBOX03,
	GF_MP7451_TBOX04,
	GF_MP7451_TBOX05,

	GF_MP7461_TBOX01,
	GF_MP7461_TBOX02,
	GF_MP7461_TBOX03,

	//霧の海岸
	GF_MP1114_TBOX01,
	GF_MP1115_TBOX01,
	GF_MP1115_TBOX02,
	GF_MP1115_TBOX03,

	//濃霧の森
	GF_MP2105_TBOX01,

	// 密林
	GF_MP2301_TBOX01,
	GF_MP2301_TBOX02,
	GF_MP2301_TBOX03,
	GF_MP2302_TBOX01,
//	GF_MP2304_TBOX01,		後ろに追加
	GF_MP2305_TBOX01,
//	GF_MP2305_TBOX02,		後ろに追加
	GF_MP2306_TBOX01,
	GF_MP2306_TBOX02,
	GF_MP2307_TBOX01,

	// 東の浜辺

	//高原
	GF_MP1107_TBOX01,
	GF_MP3106_TBOX01,
	GF_MP3107_TBOX01,

	//ジャンダルム
	GF_MP4331_TBOX01,
	GF_MP4333_TBOX01,
//	GF_MP4333_TBOX02,		//後半に追加
	GF_MP4334_TBOX01,
	GF_MP4334_TBOX02,
//	GF_MP4334_TBOX03,		後ろに追加
	GF_MP4335_TBOX01,
	GF_MP4336_TBOX01,
	GF_MP4336_TBOX02,
	GF_MP4338_TBOX01,
//	GF_MP4338_TBOX02,		後ろに追加
	GF_MP4339_TBOX01,

// 風雲山道
	GF_MP4103_TBOX01,
	GF_MP7101_TBOX01,
	GF_MP4104_TBOX01,
	GF_MP4106_TBOX01,
	GF_MP4108_TBOX01,
	GF_MP4108_TBOX02,

// 原生林
	GF_MP5103_TBOX01,
	GF_MP5102_TBOX01,
	GF_MP5102_TBOX02,
	GF_MP5102_TBOX03,
	GF_MP5101_TBOX01,

// 太古の大平原
	GF_MP6116_TBOX01,
	GF_MP6116_TBOX02,
	GF_MP6111_TBOX01,
	GF_MP6112_TBOX01,

//大石柱の風穴
	GF_MP7491_TBOX01,
	GF_MP7491_TBOX02,
	GF_MP7491_TBOX03,
	GF_MP7491_TBOX04,
	GF_MP7491_TBOX05,

//トワル街道
//	GF_MP6115_TBOX01,		後ろに追加
	GF_MP6104_TBOX01,

	//バハの塔
	GF_MP6322_TBOX01,
	GF_MP6322_TBOX02,
	GF_MP6322_TBOX03,
	GF_MP6323_TBOX01,
	GF_MP6323_TBOX02,
	GF_MP6323_TBOX03,
	GF_MP6323_TBOX04,
	GF_MP6325_TBOX01,	//理法具
	GF_MP6326_TBOX01,
	GF_MP6326_TBOX02,
	GF_MP6328_TBOX01,
	GF_MP6328_TBOX02,
	GF_MP6328_TBOX03,
	GF_MP6328_TBOX04,
	GF_MP6328_TBOX05,

	//喜望峰
	GF_MP1116_TBOX01,

//沈黙の塔外観
//	GF_MP2104_TBOX01,		後ろに追加
//	GF_MP2104_TBOX02,		後ろに追加

// 海岸洞窟_mp741x
	GF_MP7411_TBOX01,
	GF_MP7411_TBOX02,
	GF_MP7411_TBOX03,

//幽霊船
	GF_MP0404_TBOX01,
	GF_MP0404_TBOX02,
	GF_MP0404_TBOX03,
	GF_MP0404_TBOX04,
	GF_MP0404_TBOX05,

	GF_MP0403_TBOX01,
	GF_MP0403_TBOX02,
	GF_MP0403_TBOX03,
	GF_MP0403_TBOX04,

	GF_MP0402_TBOX01,
	GF_MP0402_TBOX02,
	GF_MP0402_TBOX03,
	GF_MP0402_TBOX04,

	GF_MP0408_TBOX01,
	GF_MP0408_TBOX02,
	GF_MP0408_TBOX03,
	GF_MP0408_TBOX04,

	GF_MP0405_TBOX01,
//水中
	GF_MP0401_TBOX01,
	GF_MP0401_TBOX02,
	GF_MP0401_TBOX03,
	GF_MP0401_TBOX04,

//始生代の大穴
	GF_MP6361_TBOX01,
	GF_MP6362_TBOX01,
    GF_MP6362_TBOX02,
    GF_MP6364_TBOX01,
    GF_MP6364_TBOX02,
    GF_MP6365_TBOX01,
    GF_MP6365_TBOX02,
    GF_MP6365_TBOX03,
    GF_MP6367_TBOX01,
    GF_MP6367_TBOX02,
    GF_MP6368_TBOX01,
    GF_MP6369_TBOX01,
    GF_MP6369_TBOX02,
    GF_MP6369_TBOX03,

//天崖丘陵
	GF_MP4110_TBOX01,
	GF_MP4110_TBOX02,

//湿原地帯
	GF_MP6106_TBOX01,
	GF_MP6106_TBOX02,
	GF_MP6106_TBOX03,

	GF_MP6113_TBOX01,
	GF_MP6113_TBOX02,
	GF_MP6113_TBOX03,

	GF_MP6107_TBOX01,
	GF_MP6107_TBOX02,

	GF_MP6114_TBOX01,
	GF_MP6114_TBOX02,
	GF_MP6114_TBOX03,

//王家の谷
	GF_MP6341_TBOX01,
	GF_MP6341_TBOX02,
	GF_MP6341_TBOX03,
	GF_MP6341_TBOX04,
	GF_MP6341_TBOX05,
	GF_MP6341_TBOX06,

	GF_MP6342_TBOX01,
	GF_MP6342_TBOX02,

	GF_MP6345_TBOX01,

	GF_MP6346_TBOX01,
	GF_MP6346_TBOX02,
	GF_MP6346_TBOX03,
	GF_MP6346_TBOX04,

	GF_MP6347_TBOX01,
	GF_MP6347_TBOX02,
	GF_MP6347_TBOX03,
	GF_MP6347_TBOX04,

//悠久の丘
	GF_MP6109_TBOX01,

//水没墓地
	GF_MP7481_TBOX01,
	GF_MP7481_TBOX02,

//大僧院
	GF_MP6421_TBOX01,
	GF_MP6421_TBOX02,
	GF_MP6421_TBOX03,
	GF_MP6421_TBOX04,
	GF_MP6421_TBOX05,

	GF_MP6422_TBOX01,
	GF_MP6422_TBOX02,
	GF_MP6422_TBOX03,
	GF_MP6422_TBOX04,
	GF_MP6422_TBOX05,

//埋没した塔
	GF_MP6412_TBOX01,
	GF_MP6412_TBOX02,
	GF_MP6412_TBOX03,

	GF_MP6413_TBOX01,
	GF_MP6413_TBOX02,
	GF_MP6413_TBOX03,
	GF_MP6413_TBOX04,

//オクトゥス・海の回廊
	GF_MP6305_TBOX01,
	GF_MP6305_TBOX02,

//オクトゥス・氷の回廊
	GF_MP6306_TBOX01,
	GF_MP6306_TBOX02,
	GF_MP6306_TBOX03,

//オクトゥス・蟲の回廊
	GF_MP6307_TBOX01,
	GF_MP6307_TBOX02,
	GF_MP6307_TBOX03,

//オクトゥス・天の回廊
	GF_MP6308_TBOX01,
	GF_MP6308_TBOX02,
	GF_MP6308_TBOX03,

//オクトゥス・選択の間
	GF_MP6310_TBOX01,
	GF_MP6310_TBOX02,
	GF_MP6310_TBOX03,





//密林
	GF_MP2305_TBOX02,
//ジャンダルム
	GF_MP4334_TBOX03,
	GF_MP4338_TBOX02,
//古代種の抜け道
	GF_MP3109_TBOX01,
//タナトスのメモ関連
	GF_MP1134_TBOX02,		//白砂岬
	GF_MP1117_TBOX02,		//遠鳴り浜
	GF_MP3101_TBOX02,		//風見の高原
	GF_MP4333_TBOX02,		//ジャンダルム
//風雲山道
	GF_MP4104_TBOX02,
//古代種の抜け道
	GF_MP3109_TBOX02,
//トワル街道
	GF_MP6115_TBOX01,
//エタニア王都室内
	GF_MP6213_TBOX01,
	GF_MP6213_TBOX02,
	GF_MP6213_TBOX03,
	GF_MP6214_TBOX01,
//離れ島
	GF_MP1123_TBOX01,
//白浜岬（支援20）
	GF_MP1132_TBOX03,	//後半に追加
//冒険具
	GF_MP2304_TBOX01,	//浮き輪靴
	GF_MP4306_TBOX01,	//夜光石
//沈黙の塔外観
	GF_MP2104_TBOX01,
	GF_MP2104_TBOX02,
//エタニア王都室内
	GF_MP6214_TBOX02,

//◆◆◆◆PS4追加分◆◆◆◆
	// エタニア王都、クノスの奥
	GF_MP6201_TBOX01,
	GF_MP6201_TBOX02,
	
	// 現代編、大峡谷流域追加分
	GF_MP1107_TBOX02,	// ベスティア利ポーション
	
	// 王家の谷入口
	GF_MP6108_TBOX01,	
	
	GF_TBOX_END,				// 宝箱エンド（フラグ数チェック用なので、GF_ITEMPOINT_START直前に置くように）
								// ここまでのフラグを宝箱の数とする。
								// ただし、最初の１６個は計算から除外する（漂流物は計算に入れない。）

//ここからは宝箱のトロフィーに計算されないもの
	GF_TBOX_START2 = 3700,				//トロフィーに計算されない宝箱フラグ
		
//◆◆◆◆PS4追加分◆◆◆◆
	// 旧地下聖堂１層
	GF_MP6511_TBOX01,
	GF_MP6511_TBOX02,
	GF_MP6511_TBOX03,
	GF_MP6512_TBOX01,
//	GF_MP6512_TBOX02,			//★後から追加したので別の所に定義してある
	GF_MP6513_TBOX01,
	GF_MP6513_TBOX02,
	GF_MP6519_TBOX01,

	// 旧地下聖堂２層
	GF_MP6521_TBOX01,
	GF_MP6521_TBOX02,
	GF_MP6521_TBOX03,
	GF_MP6522_TBOX01,
	GF_MP6522_TBOX02,
	GF_MP6529_TBOX01,

	// 旧地下聖堂３層
	GF_MP6531_TBOX01,
	GF_MP6531_TBOX02,
	GF_MP6531_TBOX03,
	GF_MP6531_TBOX04,
	GF_MP6531_TBOX05,
	GF_MP6531_TBOX06,
	GF_MP6532_TBOX01,
	GF_MP6532_TBOX02,
	GF_MP6532_TBOX03,
	GF_MP6539_TBOX01,
//	GF_MP6531_TBOX07,			//★後から追加したので別の所に定義してある

	// 旧地下聖堂４層
	GF_MP6541_TBOX01,
	GF_MP6541_TBOX02,
	GF_MP6541_TBOX03,
	GF_MP6541_TBOX04,
	GF_MP6542_TBOX01,
	GF_MP6542_TBOX02,
	GF_MP6542_TBOX03,
	GF_MP6542_TBOX04,
	GF_MP6549_TBOX01,

	// 旧地下聖堂５層
	GF_MP6551_TBOX01,
	GF_MP6551_TBOX02,
	GF_MP6551_TBOX03,
	GF_MP6552_TBOX01,
	GF_MP6554_TBOX01,
	GF_MP6554_TBOX02,
	GF_MP6554_TBOX03,
//	GF_MP6554_TBOX04,			//★後から追加したので別の所に定義してある
	GF_MP6555_TBOX01,
	GF_MP6555_TBOX02,
	GF_MP6559_TBOX01,

	// 旧地下聖堂６層
	GF_MP6561_TBOX01,
	GF_MP6561_TBOX02,
	GF_MP6561_TBOX03,
	GF_MP6561_TBOX04,

	//過去編・地下聖堂：ボス撃破後宝箱
	GF_MP6519m_TBOX01,
	GF_MP6529m_TBOX01,
	GF_MP6539m_TBOX01,
	GF_MP6549m_TBOX01,
	GF_MP6559m_TBOX01,

	// 現代編・地下聖堂３層
	GF_MP6531_TBOX07,			//
	
	// 珊瑚の森夜追加分
	GF_MP1303t2_TBOX02,
	
	// 現代編・地下聖堂１層追加分
	GF_MP6512_TBOX02,

	// 現代編・地下聖堂５層追加分
	GF_MP6554_TBOX04,
	
	// 過去編・地下聖堂１層追加分
	GF_MP6512m_TBOX01,
	GF_MP6513m_TBOX01,
	
	// 現代編・地下聖堂６層メダル宝箱
	GF_MP6569_TBOX01,

	// 過去編・地下聖堂２層追加分
	GF_MP6522m_TBOX01,
	//Appropriating these for additional rando flags, this will allow for things like better handling of castaway itemization, mostly for the NPCs that provide facilities 
	GF_TBOX_DUMMY058, //Kathleen Joining Scene
	GF_TBOX_DUMMY059, //Alison Joining Scene
	GF_TBOX_DUMMY060, //Use this to better force the first Avolodriagil fight
	GF_TBOX_DUMMY061, //guarantee the kuina event doesn't go away once activated
	GF_TBOX_DUMMY062, //Dina Joining Scene
	GF_TBOX_DUMMY063, //Miralda Joining Scene
	GF_TBOX_DUMMY064, //Reja Joining Scene
	GF_TBOX_DUMMY065, //Kiergaard and Sir Carlan Joining Scene
	GF_TBOX_DUMMY066, //Euron Joining Scene
	GF_TBOX_DUMMY067, //Set Ghostship available at the start of the game.
	GF_TBOX_DUMMY068, //Orichalcum Ore spot
	GF_TBOX_DUMMY069, //Used to isolate the ED event
	GF_TBOX_DUMMY070, //Isolates first prayer tree spawn
	GF_TBOX_DUMMY071, //Use this for getting Mistilteinn before Adol joins, he will then get it if he joins after
	//The next few are for controlling shop ranks better, the shop ranks flag will now be more logically tied to flame stones and me progressive, initial shops still come from crew(other than Kathleen).
	GF_TBOX_DUMMY072, //replaces flag for getting kuina, GF_SHOP_RANK_2_11
	GF_TBOX_DUMMY073, //replaces flag for returning to gendarme, GF_SHOP_RANK_3_05
	GF_TBOX_DUMMY074, //replaces flag for killing spider boss, Forge level 2
	GF_TBOX_DUMMY075, //replaces flag for heading down gendarme, GF_SHOP_RANK_4_01
	GF_TBOX_DUMMY076, //replaces flag for going to Baja Tower, GF_SHOP_RANK_5_02
	GF_TBOX_DUMMY077, //replaces flag for going to Chasm, GF_SHOP_RANK_5_04
	GF_TBOX_DUMMY078, //replaces flag for going to valley of kings, GF_SHOP_RANK_5_07
	GF_TBOX_DUMMY079, //replaces flag for intercepts leading into chapter 6, GF_SHOP_RANK_6_01
	GF_TBOX_DUMMY080, //replaces flag for beating Valley of Kings boss, forge rank final
	GF_TBOX_DUMMY081, //Shop rank 2: shop ranks 1 are finding dina and kathleen
	GF_TBOX_DUMMY082, //Shop rank 3
	GF_TBOX_DUMMY083, //Shop rank 4
	GF_TBOX_DUMMY084, //Shop rank 5
	GF_TBOX_DUMMY085, //Shop rank 6
	GF_TBOX_DUMMY086, //Shop rank MAX
	GF_TBOX_DUMMY087, //replaces GF_06MP1201_GOTO_GEND for shop control
	GF_TBOX_DUMMY088, //replaces GF_NPC_6_03_AFTER_INTERCEPT12 for shop control
	GF_TBOX_DUMMY089, //Dogi reward for intercept2
	GF_TBOX_DUMMY090, //Dogi reward for intercept3
	GF_TBOX_DUMMY091, //Dogi reward for intercept5
	GF_TBOX_DUMMY092, //Dogi reward for intercept7
	GF_TBOX_DUMMY093, //Dogi reward for intercept9
	GF_TBOX_DUMMY094, //Dogi control option unlocked
	//All of Dina's Jewel Trades need to be acquireable only once, her dana past items already are so they don't need new flags
	GF_TBOX_DUMMY095, //Dina item 1 for 1 jewel
	GF_TBOX_DUMMY096, //Dina item 2 for 1 jewel
	GF_TBOX_DUMMY097, //Dina item 3 for 2 jewels
	GF_TBOX_DUMMY098, //Dina item 4 for 10 jewels
	GF_TBOX_DUMMY099, //Dina item 5 for 25 jewels
	GF_TBOX_DUMMY100, //Intercept Set 1
	GF_TBOX_DUMMY101, //Intercept Set 2
	GF_TBOX_DUMMY102, //Intercept Set 3
	GF_TBOX_DUMMY103, //Intercept Set 4
	GF_TBOX_DUMMY104, //Austen Joining Event
	GF_TBOX_DUMMY105, //replaces flag for MISTILTEINN
	GF_TBOX_DUMMY106, //flag for ship blueprints
	GF_TBOX_DUMMY107, //new flag for second carlan join check
	GF_TBOX_DUMMY108, //flag for spirit ring Celesdia
	GF_TBOX_DUMMY109, //flag for progressive super weapons
	GF_TBOX_DUMMY110, //Silvia fight
	GF_TBOX_DUMMY111, //flag for skill shuffle
	GF_TBOX_DUMMY112, //flag for release the psyches
	GF_TBOX_DUMMY113, //open octus paths
	GF_TBOX_DUMMY114, //expMult boss check 1
	GF_TBOX_DUMMY115, //expMult boss check 2
	GF_TBOX_DUMMY116, //expMult boss check 3
	GF_TBOX_DUMMY117, //expMult boss check 4
	GF_TBOX_DUMMY118, //expMult boss check 5
	GF_TBOX_DUMMY119, //expMult boss check 6
	GF_TBOX_DUMMY120, //expMult boss check 7
	GF_TBOX_DUMMY121, //expMult boss check 8
	GF_TBOX_DUMMY122, //expMult boss check 9
	GF_TBOX_DUMMY123, //expMult boss check 10
	GF_TBOX_DUMMY124, //expMult boss check 11
	GF_TBOX_DUMMY125, //expMult boss check 12
	GF_TBOX_DUMMY126, //expMult boss check 13
	GF_TBOX_DUMMY127, //Used to check if in a warden fight
	GF_TBOX_DUMMY128, //Remove monolith flag from tower top
	GF_TBOX_DUMMY129, //Past Dana Mode
	GF_TBOX_DUMMY130, //Used for hints
	GF_TBOX_DUMMY131,
	GF_TBOX_DUMMY132,
	GF_TBOX_DUMMY133,
	GF_TBOX_DUMMY134,
	GF_TBOX_DUMMY135,
	GF_TBOX_DUMMY136,
	GF_TBOX_DUMMY137,
	GF_TBOX_DUMMY138,
	GF_TBOX_DUMMY139,
	GF_TBOX_DUMMY140,
	GF_TBOX_DUMMY141,
	GF_TBOX_DUMMY142,
	GF_TBOX_DUMMY143,
	GF_TBOX_DUMMY144,
	GF_TBOX_DUMMY145,
	GF_TBOX_DUMMY146,
	GF_TBOX_DUMMY147,
	GF_TBOX_DUMMY148,
	GF_TBOX_DUMMY149,
	GF_TBOX_DUMMY150,
	GF_TBOX_DUMMY151,
	GF_TBOX_DUMMY152,
	GF_TBOX_DUMMY153,
	GF_TBOX_DUMMY154,
	GF_TBOX_DUMMY155,
	GF_TBOX_DUMMY156,
	GF_TBOX_DUMMY157,
	GF_TBOX_DUMMY158,
	GF_TBOX_DUMMY159,
	GF_TBOX_DUMMY160,
	GF_TBOX_DUMMY161,
	GF_TBOX_DUMMY162,
	GF_TBOX_DUMMY163,
	GF_TBOX_DUMMY164,
	GF_TBOX_DUMMY165,
	GF_TBOX_DUMMY166,
	GF_TBOX_DUMMY167,
	GF_TBOX_DUMMY168,
	GF_TBOX_DUMMY169,
	GF_TBOX_DUMMY170,
	GF_TBOX_DUMMY171,
	GF_TBOX_DUMMY172,
	GF_TBOX_DUMMY173,
	GF_TBOX_DUMMY174,
	GF_TBOX_DUMMY175,
	GF_TBOX_DUMMY176,
	GF_TBOX_DUMMY177,
	GF_TBOX_DUMMY178,
	GF_TBOX_DUMMY179,
	GF_TBOX_DUMMY180,
	GF_TBOX_DUMMY181,
	GF_TBOX_DUMMY182,
	GF_TBOX_DUMMY183,
	GF_TBOX_DUMMY184,
	GF_TBOX_DUMMY185,
	GF_TBOX_DUMMY186,
	GF_TBOX_DUMMY187,
	GF_TBOX_DUMMY188,
	GF_TBOX_DUMMY189,
	GF_TBOX_DUMMY190,
	GF_TBOX_DUMMY191,
	GF_TBOX_DUMMY192,
	GF_TBOX_DUMMY193,
	GF_TBOX_DUMMY194,
	GF_TBOX_DUMMY195,
	GF_TBOX_DUMMY196,
	GF_TBOX_DUMMY197,
	GF_TBOX_DUMMY198,
	GF_TBOX_DUMMY199,

	// 拠点
	GF_MP1201_TBOX01,		//漂着物用（確保）▼チュートリアル
	GF_MP1201_TBOX02,		//漂着物用（確保）▼第二部②探索開始					霊薬セット
	GF_MP1201_TBOX03,		//漂着物用（確保）▼第二部⑧カトリーンを助けた			★レシピ帳・ラタトゥイユ
	GF_MP1201_TBOX04,		//漂着物用（確保）▼第二部⑪ディナを助けた				食材セット
	GF_MP1201_TBOX05,		//漂着物用（確保）▼第三部①ラクシャの元へ向かう		状態異常回復薬セット
	GF_MP1201_TBOX06,		//漂着物用（確保）▼第四部①島北部に足を踏み入れた		★苗３：キャベツの苗
	GF_MP1201_TBOX07,		//漂着物用（確保）▼第五部②バハの塔に向かう			果物セット
	GF_MP1201_TBOX08,		//漂着物用（確保）▼第五部④大空洞へ向かう				マルクス物語・下巻（プレゼント・リコッタ）
	GF_MP1201_TBOX09,		//漂着物用（確保）▼第六部②ジャンダルム頂上へ向かう	妙薬＋霊薬セット
	GF_MP1201_TBOX10,		//漂着物用（確保）未使用
	GF_MP1201_TBOX11,		//漂着物用（確保）未使用
	GF_MP1201_TBOX12,		//漂着物用（確保）未使用
	GF_MP1201_TBOX13,		//漂着物用（確保）未使用
	GF_MP1201_TBOX14,		//漂着物用（確保）未使用
	GF_MP1201_TBOX15,		//漂着物用（確保）未使用
	GF_MP1201_TBOX16,		//漂着物用（確保）未使用

	//骸骨からアイテム
	GF_MP7303_SKELETON01,	//水音の洞窟
	GF_MP0402_SKELETON01,	//幽霊船

	GF_MP4301_SKELETON01,	//浸食谷		海賊のメモ①
	GF_MP4305_SKELETON01,	//浸食谷		海賊のメモ②
	GF_MP4308_SKELETON01,	//浸食谷		海賊のメモ③
	GF_MP2303_SKELETON01,	//密林			海賊のメモ④
	GF_MP1115_SKELETON01,	//霧の海岸		海賊のメモ⑤
	GF_MP0408_SKELETON01,	//幽霊船		海賊のメモ⑥

	//キラキラ落とし物からアイテム
	GF_MP1116_KIRAKIRA01,	//望郷岬・浜辺
	GF_MP7461_KIRAKIRA01,	//水源地
	GF_MP1122_KIRAKIRA01,	//離れ島
	GF_MP6370_KIRAKIRA01,	//大穴：船名プレート

	//漂流物・初回必ず出現フラグ
	GF_MP1110_RANDBOX01,
	GF_MP1111_RANDBOX01,
	GF_MP1112_RANDBOX01,

//◆◆◆◆PS4追加分◆◆◆◆
	// 珊瑚の森・夜
	GF_MP1301t2_TBOX01,
	GF_MP1301t2_TBOX02,
	GF_MP1301t2_TBOX03,
	
	GF_MP1302t2_TBOX01,
	GF_MP1302t2_TBOX02,
	GF_MP1302t2_TBOX03,
	GF_MP1302t2_TBOX04,
	GF_MP1303t2_TBOX01,
//	GF_MP1303t2_TBOX02,			//★後から追加したので別の所に定義してある
	GF_MP1304t2_TBOX01,
	GF_MP1304t2_TBOX02,
	GF_MP1304t2_TBOX03,
	GF_MP1306t2_TBOX01,
	GF_MP1307t2_TBOX01,

	// ジャンダルム・夜
	GF_MP4331t2_TBOX01,
	GF_MP4333t2_TBOX01,
	GF_MP4333t2_TBOX02,
	GF_MP4333t2_TBOX03,
	GF_MP4334t2_TBOX01,
	GF_MP4334t2_TBOX02,
	GF_MP4336t2_TBOX01,
	GF_MP4337t2_TBOX01,
	GF_MP4338t2_TBOX01,
	GF_MP4339t2_TBOX01,

	GF_MP6111t2_TBOX01,
	GF_MP6112t2_TBOX01,
	GF_MP6116t2_TBOX01,

	// 過去編・地下聖堂１層
	GF_MP6511m_TBOX01,
	GF_MP6514m_TBOX01,
	GF_MP6514m_TBOX02,

	// 過去編・地下聖堂２層
	GF_MP6523m_TBOX01,
	GF_MP6524m_TBOX01,

	// 過去編・地下聖堂３層
	GF_MP6531m_TBOX01,
	GF_MP6531m_TBOX02,
	GF_MP6531m_TBOX03,
	GF_MP6531m_TBOX04,
	GF_MP6531m_TBOX05,
	GF_MP6531m_TBOX06,
	GF_MP6531m_TBOX07,
	GF_MP6531m_TBOX08,
	GF_MP6531m_TBOX09,
	GF_MP6531m_TBOX10,
	GF_MP6532m_TBOX01,
	GF_MP6532m_TBOX02,
	GF_MP6532m_TBOX03,
	GF_MP6532m_TBOX04,
	GF_MP6532m_TBOX05,
	GF_MP6532m_TBOX06,

	// 過去編・地下聖堂４層
	GF_MP6541m_TBOX01,
	GF_MP6541m_TBOX02,
	GF_MP6542m_TBOX01,
	GF_MP6542m_TBOX02,
	GF_MP6542m_TBOX03,

	// 過去編・地下聖堂５層
	GF_MP6551m_TBOX01,
	GF_MP6551m_TBOX02,
	GF_MP6552m_TBOX01,
	GF_MP6552m_TBOX02,
	GF_MP6552m_TBOX03,
	GF_MP6553m_TBOX01,
	GF_MP6553m_TBOX02,
	GF_MP6554m_TBOX01,
	GF_MP6554m_TBOX02,
	GF_MP6554m_TBOX03,
	GF_MP6554m_TBOX04,

	// 過去編・地下聖堂６層
	GF_MP6561m_TBOX01,
	GF_MP6561m_TBOX02,
	GF_MP6561m_TBOX03,
	GF_MP6561m_TBOX04,


	GF_TBOX_MAX2,				//トロフィーに計算されない宝箱フラグ終端


	///////////////////////////////////////////////
	// 予備フラグ
	///////////////////////////////////////////////
	GF_RESERVE_START = 4000,	// 予備フラグスタート

	///////////////////////////////////////////////
	// クエストフラグ
	///////////////////////////////////////////////
	// クエストフラグは、
	// QUEST_NOTHING=「未登録」
	// QUEST_END=「達成済み」
	// QUEST_START=「進行中」とします。
	// 手帳では、QUEST_NOTHINGのときは項目を「？？？？？」で、表示して未登録扱いとします。
	// QUEST_ENDのときは達成済みのマーク★付きで表示します。★
	// それ以外はグレー表示にして、まだ進行中扱いとします。

	// scr_inc.h

//	enum {
//		QUEST_NOTHING = 0,		// 00:クエストまだ未登録
//		QUEST_BBS,				// 01:掲示板を見た
//		QUEST_START,			// 02:依頼を開始した
//		QUEST_FALSE,			// 03:失敗した
//
//		QUEST_SUCCESS = 98,		// 98:クエスト達成した
//		QUEST_END = 99,			// 99:クエスト報告した
//	};
//
//
//	手帳仕様メモ
//		スクリプトに専用コマンドを用意して、現在時刻をフラグに代入できるようにする。
//		メッセージログはフラグが０か否かで判定し、フラグに値が入っている場合、
//		フラグにセットされている値を小さい順にソートした順でメッセージを表示する。
//
//		例）以下のようにフラグとメッセージが対応している場合
//				GF_MAIN_01			アドルは記憶を失った
//				GF_MAIN_02			デュレンが仲間になった
//				GF_MAIN_03			キャスナンを出発
//				GF_MAIN_04			キャンプを張った
//				GF_MAIN_05			コモドに到着した
//
//			以上の状態の時に、それぞれフラグの中身が以下となっている場合、
//
//				GF_MAIN_01			50
//				GF_MAIN_02			100
//				GF_MAIN_03			75
//				GF_MAIN_04			60
//				GF_MAIN_05			0
//
//			手帳には以下のように表示される
//
//				アドルは記憶を失った				// GF_MAIN_01	値  50
//				キャンプを張った					// GF_MAIN_04	値  60
//				キャスナンを出発					// GF_MAIN_03	値  75
//				デュレンが仲間になった				// GF_MAIN_02	値 100
//
//			※GF_MAIN_05は0なので表示されない
//			※メッセージテーブルは、フラグとメッセージを登録し、
//			　フラグ名はスクリプターが好きな名前で登録できるようにしておく。
//

	GF_QUEST_START,				// クエストフラグ定義開始（これがないとプログラムに異常を来す）

	//-- 手帳・クエストイベント判定用 ----------------------------------------------------------
	GF_QUEST_200,				// 寝床の作成
	GF_QUEST_201,				// 備蓄用の素材

	GF_QUEST_210,				// カーテンの仕立て

	GF_QUEST_220,				// 見張り台の作成
	GF_QUEST_221,				// 小船の作成
	GF_QUEST_222,				// 仕立ての練習
	GF_QUEST_223,				// 凶獣の討伐依頼①

	GF_QUEST_230,				// 海賊のお宝探し
	GF_QUEST_231,				// 美味なる食事

	GF_QUEST_300,				// 願いの木
	GF_QUEST_301,				// 新しい薬のテスト
	GF_QUEST_302,				// 凶獣の討伐依頼②

	GF_QUEST_310,				// 工芸品のテスト
	GF_QUEST_311,				// 神に祈りを

	GF_QUEST_400,				// ししょーへの献上
	GF_QUEST_401,				// 新入りの捕獲
	GF_QUEST_402,				// 栄養満点の肉料理

	GF_QUEST_500,				// 脱出船の材料集め
	GF_QUEST_501,				// 卵の配達
	GF_QUEST_502,				// 船長へのお供え
	GF_QUEST_503,				// 凶獣の討伐依頼③

	GF_QUEST_510,				// 故郷の香り

	GF_QUEST_520,				// 最高の名前
	GF_QUEST_521,				// 巨大な怨敵
	GF_QUEST_522,				// エタニアの調べ

	GF_QUEST_530,				// 凶獣の討伐依頼④

	GF_QUEST_600,				// 最強防具の作成
	GF_QUEST_601,				// 冒険家への依頼
	GF_QUEST_602,				// 白酒の調達

	GF_QUEST_610,				// オルガの髪飾り
	GF_QUEST_611,				// 老兵との手合わせ
	GF_QUEST_612,				// 欠けたモノリス

	//★PS4追加分
	GF_QUEST_232,				// 闇夜の怪
	GF_QUEST_303,				// 制圧せよ！密林地帯
	GF_QUEST_504,				// 解放せよ！浸食谷
	GF_QUEST_505,				// 月光草の採取
	GF_QUEST_603,				// 撃滅せよ！王家の谷
	GF_QUEST_613,				// 卵の奪還

	GF_QUEST_END,

//-- クエスト用ワーク+各種クエスト用ＧＦ ------------------------------------------------
// 160個くらいは使える

	//頭アイコン用
	GF_QSHEADICON_START = 4050,	// 頭上アイコン用スタート

	GF_QS200_END = GF_QSHEADICON_START,		// 寝床の作成
	GF_QS201_END,				// 備蓄用の素材

	GF_QS210_END,				// カーテンの仕立て

	GF_QS220_END,				// 見張り台の作成
	GF_QS221_END,				// 小船の作成
	GF_QS222_END,				// 仕立ての練習
	GF_QS223_END,				// 凶獣の討伐依頼①

	GF_QS230_END,				// 海賊のお宝探し
	GF_QS231_END,				// 美味なる食事

	GF_QS300_END,				// 願いの木
	GF_QS301_END,				// 新しい薬のテスト
	GF_QS302_END,				// 凶獣の討伐依頼②

	GF_QS310_END,				// 工芸品のテスト
	GF_QS311_END,				// 神に祈りを

	GF_QS400_END,				// ししょーへの献上
	GF_QS401_END,				// 新入りの捕獲
	GF_QS402_END,				// 栄養満点の肉料理

	GF_QS500_END,				// 脱出船の材料集め
	GF_QS501_END,				// 卵の配達
	GF_QS502_END,				// 船長へのお供え
	GF_QS503_END,				// 凶獣の討伐依頼③

	GF_QS510_END,				// 故郷の香り

	GF_QS520_END,				// 最高の名前
	GF_QS521_END,				// 巨大な怨敵
	GF_QS522_END,				// エタニアの調べ

	GF_QS530_END,				// 凶獣の討伐依頼④

	GF_QS600_END,				// 最強防具の作成
	GF_QS601_END,				// 冒険家への依頼
	GF_QS602_END,				// 白酒の調達

	GF_QS610_END,				// オルガの髪飾り
	GF_QS611_END,				// 老兵との手合わせ
	GF_QS612_END,				// 欠けたモノリス

	GF_QS101_END,				// ※セルセタのクエスト（削除予定）
	GF_QS102_END,				// ※セルセタのクエスト（削除予定）
	GF_QS103_END,				// ※セルセタのクエスト（削除予定）
	GF_QS104_END,				// ※セルセタのクエスト（削除予定）
	GF_QS105_END,				// ※セルセタのクエスト（削除予定）
	GF_QS106_END,				// ※セルセタのクエスト（削除予定）
	GF_QS107_END,				// ※セルセタのクエスト（削除予定）
	GF_QS108_END,				// ※セルセタのクエスト（削除予定）
	GF_QS109_END,				// ※セルセタのクエスト（削除予定）

	GF_QS202_END,				// ※セルセタのクエスト（削除予定）
	GF_QS203_END,				// ※セルセタのクエスト（削除予定）
	GF_QS204_END,				// ※セルセタのクエスト（削除予定）
	GF_QS205_END,				// ※セルセタのクエスト（削除予定）
	GF_QS206_END,				// ※セルセタのクエスト（削除予定）
	GF_QS207_END,				// ※セルセタのクエスト（削除予定）
	GF_QS208_END,				// ※セルセタのクエスト（削除予定）
	GF_QS209_END,				// ※セルセタのクエスト（削除予定）

	GF_QS303_END,				// ※セルセタのクエスト（削除予定）
	GF_QS304_END,				// ※セルセタのクエスト（削除予定）
	GF_QS305_END,				// ※セルセタのクエスト（削除予定）
	GF_QS306_END,				// ※セルセタのクエスト（削除予定）
	GF_QS307_END,				// ※セルセタのクエスト（削除予定）
	GF_QS308_END,				// ※セルセタのクエスト（削除予定）
	GF_QS309_END,				// ※セルセタのクエスト（削除予定）

	GF_QS403_END,				// ※セルセタのクエスト（削除予定）
	GF_QS404_END,				// ※セルセタのクエスト（削除予定）
	GF_QS405_END,				// ※セルセタのクエスト（削除予定）

	GF_QS504_END,				// ※セルセタのクエスト（削除予定）
	GF_QS505_END,				// ※セルセタのクエスト（削除予定）


	GF_QSHEADICON_MAX,	// 頭上アイコン用終端

	//開始＆期限切れ専用
	GF_QSLIMIT_START = 4120,	// 開始＆期限切れ専用スタート

	GF_QS101_FALSE = GF_QSLIMIT_START,		// 期限切れ（quest.csv用）
	GF_QS102_FALSE,				// 期限切れ（quest.csv用）

	GF_QS401_STARTOK,			// 開始時期になった（頭アイコン用）
	GF_QS403_STARTOK,			// 開始時期になった（頭アイコン用）
	GF_QS204_STARTOK,			// 開始時期になった（頭アイコン用）
	GF_QS207_STARTOK,			// 開始時期になった（頭アイコン用）
	GF_QS208_STARTOK,			// 開始時期になった（頭アイコン用）

	GF_QS201_FALSE,				// 期限切れ（quest.csv用）
	GF_QS301_FALSE,				// 期限切れ（quest.csv用）


	GF_QSLIMIT_MAX,	// 開始＆期限切れ専用終端

	//各クエスト用サブフラグ
	GF_QSSUB_START = 4150,		// 各クエスト用サブフラグスタート

	GF_QS_EVENT_TMP = GF_QSSUB_START,		//クエストイベント発生時に、一般メッセージの選択肢ループを抜けるためのテンポラリ
	GF_QS200_1STTALK,			//【QS200】ＧＦ初回
	GF_QS220_CHECK_A,			//【QS220】▼ＬＰ発見イベントＡ を見た
	GF_QS220_CHECK_B,			//【QS220】▼ＬＰ発見イベントＢ を見た
	GF_QS220_CHECK_C,			//【QS220】▼ＬＰ発見イベントＣ を見た
	GF_QS223_KILL_CT,			//【QS223】ヒュッパーの掃討 倒したモンスターのカウンタ
	GF_QS223_KILL_MONS,			//【QS223】ヒュッパーの掃討 モンスターを討伐した
//	GF_QS223_SET_MARKER,		//【QS223】ヒュッパーの掃討 マーカーをセットした	後ろに追加
	GF_QS230_GET_TREASURE,		//【QS230】▼お宝発見イベント を見た
	GF_QS300_GET_TREE,			//【QS300】▼木を入手する を見た
	GF_QS302_KILL_MONS,			//【QS302】アギアギラの討伐 モンスターを討伐した
//	GF_QS302_SET_MARKER,		//【QS302】アギアギラの討伐 マーカーをセットした	後ろに追加
	GF_QS310_KILL_ANCIENT_1,	//【QS310】ジャンダルムにいる古代種を倒した１
	GF_QS310_KILL_ANCIENT_2,	//【QS310】ジャンダルムにいる古代種を倒した２
	GF_QS311_ESCORT_START,		//【QS311】▼護衛開始イベント を見た
	GF_QS311_LOOK_EVENT,		//【QS311】▼クエストイベント を見た
	GF_QS400_CHECK_EVENT,		//【QS400】▼クエストイベント を見た
	GF_QS400_QUEST_BATTLE,		//【QS400】1:クエスト戦闘中
	GF_QS400_KONG_LV,			//【QS400】マスターコングのモード指定(0=リコッタ,1=サハド,2=ダーナ,3=ラクシャ,4=ヒュンメル,5=アドル)
	GF_QS401_LOOK_PICARD_1,		//【QS401】▼ピッカード捕獲イベント（浜辺） を見た
	GF_QS401_LOOK_PICARD_2,		//【QS401】▼ピッカード捕獲イベント（集会所） を見た
	GF_QS401_LOOK_PICARD_A,		//【QS401】▼ピッカード捕獲イベント（屋内Ａ） を見た
	GF_QS401_LOOK_PICARD_B,		//【QS401】▼ピッカード捕獲イベント（屋内Ｂ） を見た
	GF_QS503_KILL_CT,			//【QS503】グラドングゥの掃討 倒したモンスターのカウンタ
	GF_QS503_KILL_MONS,			//【QS503】グラドングゥの掃討 モンスターを討伐した
//	GF_QS503_SET_MARKER,		//【QS503】グラドングゥの掃討 マーカーをセットした	後ろに追加
	GF_QS510_LOOK_SUBEV,		//【QS510】▼サブイベント・アリスンが倒れる を見た
	GF_QS520_BABY_NAME_HOPE,	//【QS520】赤ちゃんの名前に『ホープ』を選んだ（0もしくはイベントスキップなら『ウィル』,1『ホープ』,2『ルーク』）
	GF_QS521_GET_FISH,			//【QS521】▼巨大ピラルクを釣った時のイベント を見た
	GF_QS522_TALK_SERACH1,		//【QS522】▼楽譜探しイベント① を見た
	GF_QS522_TALK_SERACH2,		//【QS522】▼楽譜探しイベント② を見た
	GF_QS522_TALK_SERACH3,		//【QS522】▼楽譜探しイベント③ を見た
	GF_QS522_TALK_SERACH4,		//【QS522】▼楽譜探しイベント③ （３）を見た
	GF_QS530_KILL_CT,			//【QS530】アルシャコウの討伐 倒したモンスターのカウンタ（フラグ）
	GF_QS530_KILL_MONS,			//【QS530】アルシャコウの討伐 モンスターを討伐した
//	GF_QS530_SET_MARKER,		//【QS530】アルシャコウの討伐 マーカーをセットした	後ろに追加
	GF_QS600_1STTALK,			//【QS600】ＧＦ初回
	GF_QS600_ARMOR_WOMEN,		//【QS600】女性用の鎧を造ってもらう を選んだ
	GF_QS602_PRESENT_KASHU,		//カシュー：▼プレゼントイベント を見た
	GF_QS602_SAP_A,				//【QS602】▼発酵樹液を入手する を見た
	GF_QS602_SAP_B,				//【QS602】▼発酵樹液を入手する を見た
	GF_QS602_SAP_C,				//【QS602】▼発酵樹液を入手する を見た
	GF_QS610_LOOK_DESK,			//【QS610】▼中央書架の机を調べる を見た
	GF_QS610_LOOK_STELE,		//【QS610】▼バハの塔の石碑を調べる を見た
	GF_QS611_QUEST_BATTLE,		//【QS611】1:クエスト戦闘中
	GF_QS611_LOSE,				//【QS611】▼敗北イベント を見た
	GF_QS310_GET_ITEM,			//【QS310】報酬をもらった。ショップ更新用

	//◆◆◆◆追加分◆◆◆◆
	GF_QS223_SET_MARKER,		//【QS223】ヒュッパーの掃討 マーカーをセットした
	GF_QS302_SET_MARKER,		//【QS302】アギアギラの討伐 マーカーをセットした
	GF_QS503_SET_MARKER,		//【QS503】グラドングゥの掃討 マーカーをセットした
	GF_QS530_SET_MARKER,		//【QS530】アルシャコウの討伐 マーカーをセットした

	GF_QS311_START_READY,		//【QS311】開始条件を満たす
	GF_QS400_SEE_KONG_VISUAL,	//【QS400】マスターコングビジュアル名を見ました
	GF_QS611_SEE_SILVIA_VISUAL,	//【QS611】シルヴィアビジュアル名を見ました
	GF_QS201_SHOP_ADD,			//【QS201】「備蓄用の素材」クリア後ショップに追加
	GF_QS610_TALK_DANA,			//【QS610】ダーナーの話を聞く
	GF_QS222_SHOP_ADD,			//【QS222】「仕立ての練習」クリア後ショップに追加
	GF_QS600_SHOP_ADD,			//【QS600】「輝ける鎧」クリア後ショップに追加
	GF_QS310_GET_ITEM2,			//【QS310】ショップ更新用・暴竜の守護石専用フラグ				大穴に向かう
	//クエストではないものもあるけどここに入れます。
	GF_SHOP_ADD_RECIPE05,		//【一般 】リコッタの一般を逃したら掘り出し物に並ぶ
	GF_SHOP_ADD_RECIPE06,		//【QS402】ミラルダのクエストを逃したら掘り出し物に並ぶ
	GF_SHOP_ADD_RECIPE10,		//【一般 】シスター・ニアの一般を逃したら掘り出し物に並ぶ
	GF_QS310_GET_ITEM3,			//【QS310】ショップ更新用・暴竜の護符専用フラグ　0519			バハに向かう

	//クエスト
	GF_QS311_QUEST_CANCEL,		//【QS311】クエスト途中でキャンセル

	GF_QS510_FIND_ED,			// 【QS510】自力でエドを見つけた（故郷の花を達成した）

	//PS4追加分_クエストサブフラグ
	GF_QS303_QUESTEVENT,		//【QS311】制圧せよ！　密林地帯　強制イベントを見た
	GF_QS303_QUESTCLEAR,		//【QS311】制圧せよ！　密林地帯　クエストをクリアした

	//PS4追加分_夜ダンジョンクエスト
	GF_QS232_EVENT_1,			//【QS232】クエストイベント１を見た
	GF_QS232_EVENT_2,			//【QS232】クエストイベント２を見た
	GF_QS232_EVENT_3,			//【QS232】クエストイベント３を見た
	GF_QS232_EVENT_4,			//【QS232】クエストイベント４を見た
	GF_QS232_EVENT_5,			//【QS232】クエストイベント５を見た

	GF_QS505_EVENT_1,				//【QS505】クエストイベント１を見た
	GF_QS505_GET_HERB_1,			//【QS505】月光草１を手に入れた
	GF_QS505_GET_HERB_2,			//【QS505】月光草２を手に入れた
	GF_QS505_GET_HERB_3,			//【QS505】月光草３を手に入れた
	GF_QS505_GET_HERB_4,			//【QS505】月光草４を手に入れた
	GF_QS505_GET_HERB_5,			//【QS505】月光草５を手に入れた
	GF_QS505_GET_HERB_ALL,			//【QS505】月光草を全て手に入れた
	GF_QS505_EVENT_2,				//【QS505】クエストイベント２を見た
	GF_QS505_QUESTCLEAR,			//【QS505】クエストをクリアした

	GF_QS613_EVENT_1,				//【QS613】クエストイベント１を見た
	GF_QS613_EVENT_2,				//【QS613】クエストイベント２を見た
	GF_QS613_QUESTCLEAR,			//【QS613】クエストをクリアした

	//PS4追加分_制圧戦（残り）
	GF_QS504_QUESTEVENT,		//【QS504】解放せよ！　浸食谷　ドギの開始イベントを見た	
	GF_QS504_QUESTCLEAR,		//【QS504】解放せよ！　浸食谷　クエストをクリアした

	GF_QS603_QUESTEVENT,		//【QS603】撃滅せよ！　王家の谷　ドギの開始イベントを見た
	GF_QS603_QUESTCLEAR,		//【QS603】撃滅せよ！　王家の谷　クエストをクリアした

	//PS4追加分　期限切れの掘り出し物フォロー
	GF_ADD_DRUG_RECIPE02,		//【QS230】ディナのクエストを逃したらショップに並ぶ
	GF_ADD_AR_028,				//【QS500】漂流村（ドギ）のクエストを逃したら掘り出し物に並ぶ
	GF_DRUG_RECIPE13,			//【QS505】漂流村（リヒト）のクエストを逃したら６部で調合可能になる

	//制圧戦チュートリアルを見た
	GF_QS303_TUTORIAL,			//【QS311】制圧せよ！　密林地帯　チュートリアルを見た


	GF_QSSUB_MAX,			// 各クエスト用サブフラグ終端

//--------------------------------------------------------------------
//-- ■クエスト手帳用 ------------------------------------------------
//--------------------------------------------------------------------
	DF_QS_START = 4400,		// クエスト手帳用スタート

	//【QS200】ベッドの作成（バルバロス）
	DF_QS200_START = DF_QS_START,		//【QS200】★バルバロス船長に素材を渡し、依頼を達成した！

	//【QS201】備蓄用の素材（ドギ）
	DF_QS201_START,				//【QS201】★ドギから話を聞いた。以下の素材を集めよう。
	DF_QS201_END,				//【QS201】★ドギに素材を渡し、依頼を達成。

	//【QS210】カーテンの作成（ラクシャ）
	DF_QS210_START,				//【QS210】★ラクシャから話を聞いた。以下の素材を集めよう。
	DF_QS210_END,				//【QS210】★ラクシャに素材を渡して作業を手伝った！

	//【QS220】見張り台の建設（バルバロス）
	DF_QS220_START,				//【QS220】★名知らず海岸の北に広がっているという
	DF_QS220_001A,				//【QS220】★キメの細かい石を見つけた。
	DF_QS220_001B,				//【QS220】★漂流物が溜まっている場所を見つけた。
	DF_QS220_001C,				//【QS220】★立派な木を見つけた。
	DF_QS220_END,				//【QS220】★材料の場所をバルバロス船長に報告。

	//【QS221】小舟の作成（ドギ）
	DF_QS221_END_1ST,			//【QS221】★ドギに素材を渡し、小船作りを手伝った。
	DF_QS221_END_2ND,			//【QS221】★ドギに素材を渡し、小船作りを手伝った。

	//【QS222】仕立ての練習（アリスン）
	DF_QS222_END,				//【QS222】★アリスンに素材を渡し、依頼を達成。

	//【QS223】ヒュッパーの掃討
	DF_QS223_001,				//【QS223】★ヒュッパーの群れを掃討した！　漂流村に戻って報告しよう。
	DF_QS223_END,				//【QS223】★獣討伐の報告を行った！

	//【QS230】海賊のお宝探し（ディナ）
	DF_QS230_START,				//【QS230】★ディナから海賊の物と思しき
	DF_QS230_001,				//【QS230】★宝を発見、折を見てディナに報告しよう。
	DF_QS230_END,				//【QS230】★ディナと一緒に宝箱の中身を確認。

	//【QS231】美味なる食事（カーラン卿）
	DF_QS231_START,				//【QS231】★カーラン卿に料理を渡し、依頼を達成。

	//【QS300】祈願の木（サハド）
	DF_QS300_START,				//【QS300】★サハドから話を聞いた。
	DF_QS300_001,				//【QS300】★ジャンダルムで良さそうな木を見つけた。
	DF_QS300_END,				//【QS300】漂流村に祈願の木を設置し、

	//【QS301】新しい薬の調合（リヒト）
	DF_QS301_END,				//【QS301】★リヒトに素材を渡し、依頼を達成。

	//【QS302】アギアギラの討伐
	DF_QS302_001,				//【QS302】★アギアギラを討伐した！　漂流村に戻って報告しよう。
	DF_QS302_END,				//【QS302】★獣討伐の報告を行った！

	//【QS310】試作品の性能テスト（エアラン）
	DF_QS310_START,				//【QS310】★エアランから試作品の
	DF_QS310_001,				//【QS310】★試作品のテストを済ませた。
	DF_QS310_END,				//【QS310】★エアランに報告し、依頼を達成した！

	//【QS311】神に祈りを（シスター・ニア）
	DF_QS311_START,				//【QS311】★シスター・ニアから話を聞いた。
	DF_QS311_END,				//【QS311】★シスターを風見丘陵の頂上まで無事に送り届け

	//【QS400】ししょーへの献上（リコッタ）
	DF_QS400_START,				//【QS400】★リコッタから話を聞いた。
	DF_QS400_END,				//【QS400】★リコッタがししょーに稽古をつけてもらった！

	//【QS401】新入りはいずこ（レーヤ）
	DF_QS401_START,				//【QS401】★レーヤから話を聞いた。
	DF_QS401_001,				//【QS401】★見張り台でピッカードを発見するが
	DF_QS401_002,				//【QS401】★男性用の休息所でピッカードを発見……
	DF_QS401_003,				//【QS401】★女性用の休息所でピッカードを発見……
	DF_QS401_END,				//【QS401】★休息所の共有スペースでピッカードを発見。

	//【QS402】栄養満点の肉料理（ミラルダ）
	DF_QS402_END,				//【QS402】★ミラルダさんに食材を渡し、依頼を達成した！

	//【QS500】脱出船の資材集め（ドギ）
	DF_QS500_END,				//【QS500】★ドギに素材を渡し、依頼を達成した！

	//【QS501】卵の配達（ヒュンメル）
	DF_QS501_START,				//【QS501】★ヒュンメルから話を聞いた。
	DF_QS501_END,				//【QS501】★古代種の卵を無事、巣に送り届けた！

	//【QS502】航海のお守り（クイナ）
	DF_QS502_START,				//【QS502】★クイナから話を聞いた。以下の素材を集めよう。
	DF_QS502_END,				//【QS502】★クイナに素材を渡して依頼を達成した！

	//【QS503】グラドングゥの掃討
	DF_QS503_001,				//【QS503】★グラドングゥの群れを掃討した！　漂流村に戻って報告しよう。
	DF_QS503_END,				//【QS503】★獣討伐の報告を行った！

	//【QS510】故郷の花
	DF_QS510_END,				//【QS510】★望郷岬にて紫鈴草を見つけると同時に

	//【QS520】真紅の産衣（エド）
	DF_QS520_END_A,				//【QS520】★エドに素材を渡して依頼を達成。
	DF_QS520_END_B,				//【QS520】★エドに素材を渡して依頼を達成。

	//【QS521】巨大な怨敵（タナトス）
	DF_QS521_START,				//【QS521】★タナトスさんから話を聞いた。
	DF_QS521_001,				//【QS521】★魚を釣った。
	DF_QS521_END,				//【QS521】★タナトスさんに魚を渡し、皆で食べた！

	//【QS522】奮起の演奏会（オースティン）
	DF_QS522_START,				//【QS522】★オースティンから話を聞いた。
	DF_QS522_END,				//【QS522】★オースティンに『蒼き豊穣の楽譜』を渡し、

	//【QS530】アルシャコウの討伐
	DF_QS530_001,				//【QS530】★アルシャコウを討伐した！　漂流村に戻って報告しよう。
	DF_QS530_END,				//【QS530】★獣討伐の報告を行った！

	//【QS600】輝ける鎧（カトリーン）
	DF_QS600_END,				//【QS600】★カトリーンさんにヒイロカネの原石を渡し、

	//【QS601】冒険家への依頼（フランツ）
	DF_QS601_START,				//【QS601】★フランツさんと話した。
	DF_QS601_END,				//【QS601】★思った以上の数と対峙することになったものの

	//【QS602】白酒の調達（カシュー）
	DF_QS602_START,				//【QS602】★カシューと話した。以下の物を探そう。
	DF_QS602_END,				//【QS602】★カシューに醗酵樹液を渡し、

	//【QS610】親友の遺言（ダーナ）
	DF_QS610_START,				//【QS610】★オルガが託すと語ったらしい
	DF_QS610_001,				//【QS610】★『青き鳥』についての伝承を確認したが
	DF_QS610_002,				//【QS610】★王都アイギアスの大聖堂に並ぶレリーフは
	DF_QS610_END,				//【QS610】★オルガの形見の品とともに、

	//【QS611】老いらくの剣
	DF_QS611_START,				//【QS611】★シルヴィアさんと話した。
	DF_QS611_END,				//【QS611】★シルヴィアさんに何とか勝つことができた！

	//【QS612】色褪せたモノリス（グリゼルダ）
	DF_QS612_START,				//【QS612】★グリゼルダさんと話した。
	DF_QS612_END,				//【QS612】★モノリスの欠片を渡し、依頼を達成。

	//【QS232】闇夜の怪
	DF_QS232_START,				//【QS232】　　★ドギから話を聞いた。
	DF_QS232_001,				//【QS232】　　★漂流村に出没していたと思われる
	DF_QS232_END,				//【QS232】　　★調査の間、漂流村でも聞き込みが進み

	//【QS505】月光草の採取
	DF_QS505_START,				//【QS505】
	DF_QS505_001,				//【QS505】
	DF_QS505_002,				//【QS505】
	DF_QS505_END,				//【QS505】

	//【QS613】卵の奪還
	DF_QS613_START,				//【QS613】
	DF_QS613_001,				//【QS613】
	DF_QS613_END,				//【QS613】

	//【QS303】制圧せよ！　密林地帯
	DF_QS303_START,				//【QS303】
	DF_QS303_END,				//【QS303】　　★密林地帯を制圧し、獣の大量発生を沈静化した！

	//【QS504】解放せよ！　浸食谷
	DF_QS504_START,				//【QS504】
	DF_QS504_END,				//【QS504】　　★浸食谷を制圧し、獣の大量発生を沈静化した！

	//【QS303】撃滅せよ！　王家の谷
	DF_QS603_START,				//【QS603】
	DF_QS603_END,				//【QS603】　　★王家の谷を制圧し、獣の大量発生を沈静化した！

	DF_QS_MAX,		// クエスト手帳用終端

//--------------------------------------------------------------------
//-- ■メイン手帳用 --------------------------------------------------
//--------------------------------------------------------------------

	//漂流者合流
	DF_JOIN_START = 4600,		// 漂流者合流スタート

	DF_JOIN_LAXIA = DF_JOIN_START,			// ★ラクシャが仲間に加わった。
	DF_JOIN_BARBAROSS,				// ★バルバロス船長と再会した。
	DF_JOIN_DOGI,					// ★ドギと再会した。
	DF_JOIN_SAHAD,					// ★サハドが仲間に加わった。
	DF_JOIN_ALISON,					// ★アリスンを救出した。
	DF_JOIN_CURRAN,					// ★カーラン卿を救出した。
	DF_JOIN_KIERGAARD,				// ★キルゴールを救出した。
	DF_JOIN_KATRIN,					// ★カトリーンを救出した。
	DF_JOIN_NIA,					// ★シスター・ニアを救出した。
	DF_JOIN_HUMMEL,					// ★ヒュンメルが仲間に加わった。
	DF_JOIN_DINA,					// ★ディナを救出した。
	DF_JOIN_REJA,					// ★レーヤを救出した。
	DF_JOIN_MIRALDA,				// ★ミラルダを救出した。
	DF_JOIN_AARON,					// ★エアランが漂流村に加わった。
	DF_JOIN_LICHT,					// ★リヒトを救出した。
	DF_JOIN_KUINA,					// ★クイナを救出した。
	DF_JOIN_RICOTTA,				// ★リコッタが仲間に加わった。
	DF_JOIN_AUSTEN,					// ★オースティンを救出した。
	DF_JOIN_SILVIA,					// ★シルヴィアが漂流村に加わった。
	DF_JOIN_THANATOS,				// ★タナトスが漂流村に加わった。
	DF_JOIN_DANA,					// ★ダーナが仲間に加わった。
	DF_JOIN_KASHU,					// ★カシューを救出した。
	DF_JOIN_ED,						// ★エドを救出した。
	DF_JOIN_FRANZ,					// ★フランツが漂流村に加わった。
	DF_JOIN_CURRAN2,				// ★カーラン卿が改めて漂流村に加わった。
	DF_JOIN_GRISELDA,				// ★グリゼルダが漂流村に加わった。


	DF_JOIN_MAX,		// 漂流者合流終端

	//支援イベント
	DF_SUBEV_START = 4650,		// 支援イベントスタート

	DF_SUBEV_1110_REMOVE_WOOD = DF_SUBEV_START,// ★名知らず海岸にあった巨大な倒木を撤去した。				◆入力済み
	DF_SUBEV_1111_REMOVE_ROCK,		// ★名知らず海岸浜辺の大岩を撤去した。						◆入力済み
	DF_SUBEV_2101_REMOVE_ROCK,		// ★名知らず海岸の森にあった土砂崩れを撤去した。			◆入力済み
	DF_SUBEV_1120_REMOVE_ROCK,		// ★大峡谷流域にあった大岩を撤去した。						◆入力済み
	DF_SUBEV_1131_REMOVE_ROCK,		// ★名知らず海岸の西にあった大岩を撤去した。				◆入力済み
	DF_SUBEV_2105_REMOVE_WOOD,		// ★水と森の丘にあった巨大な倒木を撤去した。				◆入力済み
	DF_SUBEV_1117_REMOVE_ROCK,		// ★遠鳴り浜にあった大岩を撤去した。						◆入力済み
	DF_SUBEV_1107_REPAIR_BRIDGE,	// ★大峡谷流域奥の壊れた吊り橋を修理した。					◆入力済み
	DF_SUBEV_1109_REPAIR_CLIFF,		// ★獣たちの丘にあった崩れた崖を補強した。					◆入力済み
	DF_SUBEV_1116_REMOVE_ROCK,		// ★望郷岬にあった土砂を撤去した。							◆入力済み
	DF_SUBEV_6102_REMOVE_PILLAR,	// ★パンガイア大平原にあった大きな石柱を撤去した。			◆入力済み
	DF_SUBEV_1132_REMOVE_SAND,		// ★白浜岬にあった泥砂を撤去した。							◆入力済み
	DF_SUBEV_4110_SET_LADDER,		// ★見晴らし峠にあった崖に縄梯子を設置した。				◆入力済み
	DF_SUBEV_6107_REMOVE_SAND,		// ★ロディニア湖沼地帯にあった土砂を撤去した。				◆入力済み
	DF_SUBEV_6362_REMOVE_PILLAR,	// ★始生代の大穴にあった大きな石柱を撤去した。				◆入力済み
	DF_SUBEV_2104_REMOVE_SAND,		// ★水と森の丘奥にあった土砂を撤去した。					◆入力済み


	DF_SUBEV_MAX,		// 支援イベント終端

//-- ■アクティブボイス用 --------------------------------------------
	GF_AVOICE_START = 5100,

	GF_AVOICE_0000 = GF_AVOICE_START,
	GF_AVOICE_0001,
	GF_AVOICE_0002,

	GF_AVOICE_0100,
	GF_AVOICE_0101,
	GF_AVOICE_0102,
	GF_AVOICE_0103,

	GF_AVOICE_0200,
	GF_AVOICE_0201,
	GF_AVOICE_0202,
	GF_AVOICE_0203,
	GF_AVOICE_0204,
	GF_AVOICE_0205,
	GF_AVOICE_0206,
	GF_AVOICE_0207,
	GF_AVOICE_0208,
	GF_AVOICE_0209,
	GF_AVOICE_0210,
	GF_AVOICE_0211,
	GF_AVOICE_0212,		//霧の中で古代種に見つかったフラグ・メインで判定
	GF_AVOICE_0213,
	GF_AVOICE_0214,
	GF_AVOICE_0215,
	GF_AVOICE_0216,
	GF_AVOICE_0217,
	GF_AVOICE_0218,
	GF_AVOICE_0219,
	GF_AVOICE_0220,
	GF_AVOICE_0221,
	GF_AVOICE_0222,
	GF_AVOICE_0223,
	GF_AVOICE_0224,
	GF_AVOICE_0225,
	GF_AVOICE_0226,
	GF_AVOICE_0227,
	GF_AVOICE_0228,
	GF_AVOICE_0229,

	GF_AVOICE_0300,
	GF_AVOICE_0301,
	GF_AVOICE_0302,
	GF_AVOICE_0303,
	GF_AVOICE_0304,
	GF_AVOICE_0305,
	GF_AVOICE_0306,
	GF_AVOICE_0307,
	GF_AVOICE_0308,
	GF_AVOICE_0309,
	GF_AVOICE_0310,
	GF_AVOICE_0311,
	GF_AVOICE_0312,
	GF_AVOICE_0313,
	GF_AVOICE_0314,

	GF_AVOICE_0400,
	GF_AVOICE_0401,
	GF_AVOICE_0402,
	GF_AVOICE_0403,
	GF_AVOICE_0404,
	GF_AVOICE_0405,
	GF_AVOICE_0406,
	GF_AVOICE_0407,
	GF_AVOICE_0408,
	GF_AVOICE_0409,
	GF_AVOICE_0410,
	GF_AVOICE_0411,
	GF_AVOICE_0412,
	GF_AVOICE_0413,
	GF_AVOICE_0414,
	GF_AVOICE_0415,

	GF_AVOICE_0500,
	GF_AVOICE_0501,
	GF_AVOICE_0502,
	GF_AVOICE_0503,
	GF_AVOICE_0504,
	GF_AVOICE_0505,
	GF_AVOICE_0506,
	GF_AVOICE_0507,
	GF_AVOICE_0508,
	GF_AVOICE_0509,
	GF_AVOICE_0510,
	GF_AVOICE_0511,
	GF_AVOICE_0512,
	GF_AVOICE_0513,
	GF_AVOICE_0514,
	GF_AVOICE_0515,
	GF_AVOICE_0516,
	GF_AVOICE_0517,
	GF_AVOICE_0518,
	GF_AVOICE_0519,
	GF_AVOICE_0520,
	GF_AVOICE_0521,
	GF_AVOICE_0522,
	GF_AVOICE_0523,
	GF_AVOICE_0524,
	GF_AVOICE_0525,
	GF_AVOICE_0526,
	GF_AVOICE_0527,
	GF_AVOICE_0528,
	GF_AVOICE_0529,
	GF_AVOICE_0530,
	GF_AVOICE_0531,

	GF_AVOICE_0600,
	GF_AVOICE_0601,
	GF_AVOICE_0602,
	GF_AVOICE_0603,
	GF_AVOICE_0604,
	GF_AVOICE_0605,
	GF_AVOICE_0606,
	GF_AVOICE_0607,
	GF_AVOICE_0608,
	GF_AVOICE_0609,
	GF_AVOICE_0610,
	GF_AVOICE_0611,

	GF_AVOICE_0700,

	GF_AVOICE_0800,
	GF_AVOICE_0801,
	GF_AVOICE_0802,
	GF_AVOICE_0803,
	GF_AVOICE_0804,
	GF_AVOICE_0805,
	GF_AVOICE_0806,
	GF_AVOICE_0807,
	GF_AVOICE_0808,
	GF_AVOICE_0809,
	GF_AVOICE_0810,
	GF_AVOICE_0811,
	GF_AVOICE_0812,
	GF_AVOICE_0813,

	GF_AVOICE_0900,
	GF_AVOICE_0901,
	GF_AVOICE_0902,
	GF_AVOICE_0903,
	GF_AVOICE_0904,
	GF_AVOICE_0905,
	GF_AVOICE_0906,
	GF_AVOICE_0907,
	GF_AVOICE_0908,
	GF_AVOICE_0909,
	GF_AVOICE_0910,

	//リトルパロの迎撃戦伝令
	GF_AVOICE_INTBTL002,
	GF_AVOICE_INTBTL003,
	GF_AVOICE_INTBTL005,
	GF_AVOICE_INTBTL007,
	GF_AVOICE_INTBTL012,

//■追加分
	GF_AVOICE_P_MARK01,
	GF_AVOICE_P_MARK02,
	GF_AVOICE_P_MARK03,

	GF_AVOICE_0219B,		//カエルを怒らせて退却した（※第二部中のみ）//ラクシャ版
	GF_AVOICE_0510B,		//初めてエリアに入ったら
	GF_AVOICE_0801B,		//下に落下したら　明るい版

	GF_AVOICE_0230,			//キルゴールの追跡、3101に入った

//■PS4追加分
	GF_AVOICE_1401,			//	精霊を救出するイベント後
	GF_AVOICE_1402,			//	はじめてギミックエリアに入ったら（B1灯火エリアのチュートリアル後）
	GF_AVOICE_1403,			//	地下聖堂の途中で
	GF_AVOICE_1404,			//	地下聖堂で精霊救出ポイント手前にきたら
	GF_AVOICE_1405,			//	ボス撃破後、最奥の扉が開いたのを見て

	GF_AVOICE_1501,			//	Ｔ字路を少し北に入ったあたりで
	GF_AVOICE_1502,			//	精霊がいるマップに入ると
	GF_AVOICE_1503,			//	地下聖堂フロア２に到達イベント後
	GF_AVOICE_1504,			//	大僧院の扉を修復するエタニアクエストを完了したら
	GF_AVOICE_1505,			//	扉を開く予知を見たら
	GF_AVOICE_1506,			//	ボス戦後、モノリスに近づくと
	GF_AVOICE_1507,			//	霧の中で不可視の敵から何度かダメージを受けると
	GF_AVOICE_1508,			//	霧の中で光る渦に近づくと
	GF_AVOICE_1509,			//	扉が開く予知を見たら
	GF_AVOICE_1510,			//	王家の私有地の門番が見えたら

	GF_AVOICE_1601,			//	扉が開く予知を見たら
	GF_AVOICE_1602,			//	ボス戦後、モノリスに近づくと
	GF_AVOICE_1603,			//	禁忌域へ向かう道中で
	GF_AVOICE_1604,			//	王宮の状況を知るイベント後、オルガのいる玉座に到達する前に
	GF_AVOICE_1605,			//	陰鬱な王宮内の様々な場所で・市民（竜人Ｈ（男性・中年））
	GF_AVOICE_1606,			//	陰鬱な王宮内の様々な場所で・市民（竜人Ｉ（女性・娘））
	GF_AVOICE_1607,			//	陰鬱な王宮内の様々な場所で・市民（竜人Ｊ（女性・中年））
	GF_AVOICE_1608,			//	陰鬱な王宮内の様々な場所で・市民（竜人Ｋ（男性・中年））
	GF_AVOICE_1609,			//	陰鬱な王宮内の様々な場所で・市民（竜人Ｌ（男性・青年））
	GF_AVOICE_1610,			//	陰鬱な王宮内の様々な場所で・市民（竜人Ｍ（男性・青年））
	GF_AVOICE_1611,			//	イオに会った後、中央区に入ると
	GF_AVOICE_1612,			//	西街区を歩いていると

	GF_AVOICE_1801,			//	はじめての灯火エリアで、火の鳥に灯火を再点灯されたら
	GF_AVOICE_1802,			//	はじめてブロック・パズルエリアに入ったら
	GF_AVOICE_1803,			//	はじめて風エリアで押し戻された
	GF_AVOICE_1804,			//	はじめて4層に入ったら
	GF_AVOICE_1805,			//	風を発生させる敵に近づいたら
	GF_AVOICE_1806,			//	盾を持っている敵に近づいたら
	GF_AVOICE_1807,			//	第五層の溶岩ゾーンに入ったら

	GF_AVOICE_1901,			//	戦闘開始直後
	GF_AVOICE_1902,			//	イオのHPを60％まで減らした
	GF_AVOICE_1903,			//	イオのHPを30％まで減らした
	GF_AVOICE_1904,			//	大技に見せかけたフェイク攻撃をしたら
	GF_AVOICE_1905,			//	イオが地スタイルに変化した（初回のみ）
	GF_AVOICE_1906,			//	イオが光スタイルに変化した（初回のみ）

//■追加するときはここから




	GF_AVOICE_MAX,		// アクティブボイス終端

//-- ■ヘルプ画像用 --------------------------------------------
	GF_HELP_START = 5300,	// ヘルプ画像用スタート

	GF_HELP_A01 = GF_HELP_START,	// 基本操作
	GF_HELP_A02,			// セーブ／ロード
	GF_HELP_A03,			// ミニマップ
	GF_HELP_A04,			// ボタン操作一覧
	GF_HELP_A05,			// 冒険日誌
	GF_HELP_A06,			// 水晶石とリトライ
	GF_HELP_A07,			// 漂着物
	GF_HELP_A08,			// 素材の採取
	GF_HELP_A09,			// アイテムの使用
	GF_HELP_A10,			// 装備
	GF_HELP_A11,			// 回復薬の調合
	GF_HELP_A12,			// 地図メニュー
	GF_HELP_A13,			// 地図の評価
	GF_HELP_A14,			// 地図を使った移動
	GF_HELP_A15,			// 衣装変更
	GF_HELP_A16,			// 釣り①
	GF_HELP_A17,			// 釣り②
	GF_HELP_A18,			// 釣り図鑑
	GF_HELP_A19,			// 釣りの評価
	GF_HELP_A20,			// 料理
	GF_HELP_A21,			// アイテム交換
	GF_HELP_A22,			// 武器の強化
	GF_HELP_A23,			// クエスト
	GF_HELP_A24,			// 支援イベント
	GF_HELP_A25,			// ロケーションポイント
	GF_HELP_A26,			// 漂流者の救出
	GF_HELP_A27,			// 野営地
	GF_HELP_A28,			// 冒険具
	GF_HELP_A29,			// グリップグローブの効果
	GF_HELP_A30,			// 夜光石の効果
	GF_HELP_A31,			// 浮き靴の効果
	GF_HELP_A32,			// 始祖鳥の指環の効果
	GF_HELP_A33,			// アンピビアの指環の効果
	GF_HELP_A34,			// 銀の鈴の効果
	GF_HELP_A35,			// 武器の進化
	GF_HELP_A36,			// 防具の作成
	GF_HELP_A37,			// パーティ編成
	GF_HELP_A38,			// 交易所／売却
	GF_HELP_A39,			// 虫駆除剤の使い方
	GF_HELP_A40,			// 農場
	GF_HELP_A41,			// プレゼントイベント
	GF_HELP_A42,			// 好感度
	GF_HELP_A43,			// 道具屋
	GF_HELP_A44,			// 意識共有
	GF_HELP_A45,			// 漂流村の強化

	GF_HELP_B01,			// 攻撃とターゲットロック
	GF_HELP_B02,			// 回避／ダッシュ
	GF_HELP_B03,			// ジャンプ／ジャンプ攻撃
	GF_HELP_B04,			// スキルの修得とセット
	GF_HELP_B05,			// スキルの使い方
	GF_HELP_B06,			// 攻撃属性
	GF_HELP_B07,			// ブレイク
	GF_HELP_B08,			// 戦闘ボーナス
	GF_HELP_B09,			// ドロップアイテムと図鑑
	GF_HELP_B10,			// ブレイクオブジェ
	GF_HELP_B11,			// ＥＸＴＲＡスキル
	GF_HELP_B12,			// 戦闘のコツ
	GF_HELP_B13,			// 上級テクニック
	GF_HELP_B13_B,			// ダッシュ
	GF_HELP_B14,			// フィールドでの休息
	GF_HELP_B15,			// 状態異常
	GF_HELP_B16,			// 迎撃戦①
	GF_HELP_B17,			// 迎撃戦②（戦況ゲージ）
	GF_HELP_B18,			// 迎撃戦③（サポートスキル）
	GF_HELP_B19,			// 迎撃戦④（リザルト評価）
	GF_HELP_B20,			// 迎撃戦⑤（発生／再戦について）

//0512追加
	GF_HELP_A46,			// 地図アイコン一覧
	GF_HELP_A47,			// 破裂の胞子

//PS4版ヘルプ
	GF_HELP_A48,			// ヌシ釣り
	GF_HELP_A49,			// 閃光を放つ石（浸食谷）
	GF_HELP_A50,			// 精霊の救出
	GF_HELP_A51,			// ダーナの徳
	GF_HELP_A52,			// エイミーのショップ
	GF_HELP_A53,			// 地下聖堂内の転位
	GF_HELP_A54,			// 行動メンバー数の変更
	GF_HELP_A55,			// 夜間探索
	GF_HELP_A56,			// お宝発見
	GF_HELP_A57,			// 宝石の交換

	GF_HELP_B21,			// ダーナのスタイルチェンジ
	GF_HELP_B22,			// 地下聖堂『灯火台』
	GF_HELP_B23,			// グラティカの能力
	GF_HELP_B24,			// イクルシアンの能力
	GF_HELP_B25,			// ルミナスの能力
	GF_HELP_B26,			// イクルシアンのスタイル強化
	GF_HELP_B27,			// グラティカのスタイル強化
	GF_HELP_B28,			// ルミナスのスタイル強化
	GF_HELP_B29,			// 制圧戦の画面
	GF_HELP_B30,			// 制圧戦のフロー
	GF_HELP_B31,			// 仲間の行動を指示

//ヘルプ追加分
	GF_HELP_A58,			// ダウンロードコンテンツ
	GF_HELP_A59,			// アクセサリの作成
	GF_HELP_A44_B,			// 意識交代

	GF_HELP_MAX,			//ヘルプ数チェック（終端）

	///////////////////////////////////////////////
	// 採集ポイントフラグ
	///////////////////////////////////////////////
	GF_ITEMPOINT_START = 5500,	// アイテムポイントスタート
	// ※未使用ＩＤは必ず消してください。回収率の計算が出来なくなります。
	// 拠点

	// 水音の洞窟
	GF_MP7302_ATKIP_01,
	GF_MP7302_ATKIP_02,
	GF_MP7303_ATKIP_01,

	// 名も無き海岸
	GF_MP1102_ATKIP_01,
	GF_MP1102_ATKIP_02,
	GF_MP1102_ATKIP_03,
	GF_MP1102_ATKIP_04,

	GF_MP1131_ATKIP_01,
	GF_MP1131_ATKIP_02,
	GF_MP1131_ATKIP_03,
	GF_MP1131_ATKIP_04,
	GF_MP1131_ATKIP_05,

	GF_MP1111_ATKIP_01,
	GF_MP1111_ATKIP_02,
	GF_MP1111_ATKIP_03,
	GF_MP1111_ATKIP_04,
	GF_MP1111_ATKIP_05,
	GF_MP1111_ATKIP_06,

	GF_MP1104_ATKIP_01,
	GF_MP1104_ATKIP_02,
	GF_MP1104_ATKIP_03,
	GF_MP1104_ATKIP_04,
	GF_MP1104_ATKIP_05,
	GF_MP1104_ATKIP_06,

	GF_MP1112_ATKIP_01,
	GF_MP1112_ATKIP_02,
	GF_MP1112_ATKIP_03,
	GF_MP1112_ATKIP_04,
	GF_MP1112_ATKIP_05,
	GF_MP1112_ATKIP_06,
	GF_MP1112_ATKIP_07,
	GF_MP1112_ATKIP_08,
	GF_MP1112_ATKIP_09,
//	GF_MP1112_ATKIP_10,
//	GF_MP1112_ATKIP_11,

	GF_MP2101_ATKIP_01,
	GF_MP2101_ATKIP_02,
	GF_MP2101_ATKIP_03,
	GF_MP2101_ATKIP_04,
	GF_MP2101_ATKIP_05,

	GF_MP1105_ATKIP_01,
	GF_MP1105_ATKIP_02,

	GF_MP1106_ATKIP_01,
	GF_MP1106_ATKIP_02,
	GF_MP1106_ATKIP_03,

	// 珊瑚礁
	GF_MP1113_ATKIP_01,
	GF_MP1113_ATKIP_02,
	GF_MP1113_ATKIP_03,
	GF_MP1113_ATKIP_04,

	GF_MP1132_ATKIP_01,
	GF_MP1132_ATKIP_02,
	GF_MP1132_ATKIP_03,
	GF_MP1132_ATKIP_04,
//	GF_MP1132_ATKIP_05,
//	GF_MP1132_ATKIP_06,

	GF_MP1133_ATKIP_01,
	GF_MP1133_ATKIP_02,
	GF_MP1133_ATKIP_03,

	GF_MP1134_ATKIP_01,
	GF_MP1134_ATKIP_02,

	// 珊瑚の森
	GF_MP1301_ATKIP_01,
	GF_MP1301_ATKIP_02,
	GF_MP1301_ATKIP_03,

	GF_MP1302_ATKIP_01,
	GF_MP1302_ATKIP_02,
	GF_MP1302_ATKIP_03,
	GF_MP1302_ATKIP_04,
	GF_MP1302_ATKIP_05,
	GF_MP1302_ATKIP_06,
//	GF_MP1302_ATKIP_07,		後ろに追加

	GF_MP1303_ATKIP_01,
	GF_MP1303_ATKIP_02,
	GF_MP1303_ATKIP_03,
	GF_MP1303_ATKIP_04,
	GF_MP1303_ATKIP_05,
	GF_MP1303_ATKIP_06,

	GF_MP1304_ATKIP_01,
	GF_MP1304_ATKIP_02,
	GF_MP1304_ATKIP_03,
	GF_MP1304_ATKIP_04,
	GF_MP1304_ATKIP_05,
	GF_MP1304_ATKIP_06,
	GF_MP1304_ATKIP_07,
	GF_MP1304_ATKIP_08,

	GF_MP1305_ATKIP_01,
	GF_MP1305_ATKIP_02,

	GF_MP1307_ATKIP_01,
	GF_MP1307_ATKIP_02,
//	GF_MP1307_ATKIP_03,
//	GF_MP1307_ATKIP_04,

	// 西の浜辺
	GF_MP1117_ATKIP_01,
	GF_MP1117_ATKIP_02,
	GF_MP1117_ATKIP_03,
	GF_MP1117_ATKIP_04,

	GF_MP1135_ATKIP_01,
	GF_MP1135_ATKIP_02,
	GF_MP1135_ATKIP_03,
	GF_MP1135_ATKIP_04,
	GF_MP1135_ATKIP_05,
	GF_MP1135_ATKIP_06,
	GF_MP1135_ATKIP_07,
	GF_MP1135_ATKIP_08,
	GF_MP1135_ATKIP_09,
	GF_MP1135_ATKIP_10,
	GF_MP1135_ATKIP_11,
	GF_MP1135_ATKIP_12,
	GF_MP1135_ATKIP_13,

	// 島中央部
	GF_MP2102_ATKIP_01,
	GF_MP2102_ATKIP_02,
	GF_MP2102_ATKIP_03,
	GF_MP2102_ATKIP_04,
	GF_MP2102_ATKIP_05,
	GF_MP2102_ATKIP_06,
	GF_MP2102_ATKIP_07,
	GF_MP2102_ATKIP_08,
	GF_MP2102_ATKIP_09,
//	GF_MP2102_ATKIP_10,		//後ろに追加

	GF_MP1107_ATKIP_01,
	GF_MP1107_ATKIP_02,
	GF_MP1107_ATKIP_03,
	GF_MP1107_ATKIP_04,
	GF_MP1107_ATKIP_05,
	GF_MP1107_ATKIP_06,

	GF_MP1120_ATKIP_01,
	GF_MP1120_ATKIP_02,
	GF_MP1120_ATKIP_03,
	GF_MP1120_ATKIP_04,
	GF_MP1120_ATKIP_05,
	GF_MP1120_ATKIP_06,
	GF_MP1120_ATKIP_07,

	GF_MP3103_ATKIP_01,
	GF_MP3103_ATKIP_02,
	GF_MP3103_ATKIP_03,

	GF_MP3104_ATKIP_01,
	GF_MP3104_ATKIP_02,
	GF_MP3104_ATKIP_03,
	GF_MP3104_ATKIP_04,
//	GF_MP3104_ATKIP_05,
//	GF_MP3104_ATKIP_06,
//	GF_MP3104_ATKIP_07,
//	GF_MP3104_ATKIP_08,

	//鍾乳洞
	GF_MP7471_ATKIP_01,
	GF_MP7471_ATKIP_02,
	GF_MP7471_ATKIP_03,
	GF_MP7471_ATKIP_04,
	GF_MP7471_ATKIP_05,
	GF_MP7471_ATKIP_06,
	GF_MP7471_ATKIP_07,
	GF_MP7471_ATKIP_08,
	GF_MP7471_ATKIP_09,
	GF_MP7471_ATKIP_10,
	GF_MP7471_ATKIP_11,
	GF_MP7471_ATKIP_12,
	GF_MP7471_ATKIP_13,
	GF_MP7471_ATKIP_14,
	GF_MP7471_ATKIP_15,

	// 島東部
	GF_MP1108_ATKIP_01,
	GF_MP1108_ATKIP_02,
	GF_MP1108_ATKIP_03,
	GF_MP1108_ATKIP_04,
	GF_MP1108_ATKIP_05,
	GF_MP1108_ATKIP_06,
	GF_MP1108_ATKIP_07,
	GF_MP1108_ATKIP_08,

	GF_MP4102_ATKIP_01,
	GF_MP4102_ATKIP_02,

	GF_MP2103_ATKIP_01,

	GF_MP1109_ATKIP_01,
	GF_MP1109_ATKIP_02,
	GF_MP1109_ATKIP_03,
	GF_MP1109_ATKIP_04,
	GF_MP1109_ATKIP_05,

	// 浸食谷
	GF_MP4301_ATKIP_01,
	GF_MP4301_ATKIP_02,
	GF_MP4301_ATKIP_03,
	GF_MP4301_ATKIP_04,
	GF_MP4301_ATKIP_05,
	GF_MP4301_ATKIP_06,
	GF_MP4301_ATKIP_07,
	GF_MP4301_ATKIP_08,
	GF_MP4301_ATKIP_09,

	GF_MP4302_ATKIP_01,
	GF_MP4302_ATKIP_02,
	GF_MP4302_ATKIP_03,
	GF_MP4302_ATKIP_04,
	GF_MP4302_ATKIP_05,
	GF_MP4302_ATKIP_06,

	GF_MP4303_ATKIP_01,
	GF_MP4303_ATKIP_02,
	GF_MP4303_ATKIP_03,
	GF_MP4303_ATKIP_04,
	GF_MP4303_ATKIP_05,
	GF_MP4303_ATKIP_06,
	GF_MP4303_ATKIP_07,
	GF_MP4303_ATKIP_08,

	GF_MP4304_ATKIP_01,
	GF_MP4304_ATKIP_02,

	GF_MP4305_ATKIP_01,
	GF_MP4305_ATKIP_02,
	GF_MP4305_ATKIP_03,
	GF_MP4305_ATKIP_04,
	GF_MP4305_ATKIP_05,

	GF_MP4307_ATKIP_01,
	GF_MP4307_ATKIP_02,
	GF_MP4307_ATKIP_03,
	GF_MP4307_ATKIP_04,
	GF_MP4307_ATKIP_05,
	GF_MP4307_ATKIP_06,
	GF_MP4307_ATKIP_07,
	GF_MP4307_ATKIP_08,
	GF_MP4307_ATKIP_09,
	GF_MP4307_ATKIP_10,

	GF_MP4308_ATKIP_01,
	GF_MP4308_ATKIP_02,
	GF_MP4308_ATKIP_03,

	// 北東の浜辺
	GF_MP1119_ATKIP_01,
	GF_MP1119_ATKIP_02,
	GF_MP1119_ATKIP_03,
	GF_MP1119_ATKIP_04,

	//風見の高原
	GF_MP3101_ATKIP_01,
	GF_MP3101_ATKIP_02,
	GF_MP3101_ATKIP_03,
	GF_MP3102_ATKIP_01,
	GF_MP3102_ATKIP_02,
	GF_MP3102_ATKIP_03,
	GF_MP3102_ATKIP_04,

	//水源地
	GF_MP7451_ATKIP_01,
	GF_MP7451_ATKIP_02,
	GF_MP7451_ATKIP_03,
	GF_MP7451_ATKIP_04,
	GF_MP7451_ATKIP_05,
//	GF_MP7451_ATKIP_06,	//追加分は後ろに
//	GF_MP7451_ATKIP_07,
//	GF_MP7451_ATKIP_08,
//	GF_MP7451_ATKIP_09,
//	GF_MP7451_ATKIP_10,
//	GF_MP7451_ATKIP_11,
//	GF_MP7451_ATKIP_12,

	GF_MP7461_ATKIP_01,
	GF_MP7461_ATKIP_02,
	GF_MP7461_ATKIP_03,
	GF_MP7461_ATKIP_04,
	GF_MP7461_ATKIP_05,
	GF_MP7461_ATKIP_06,
	GF_MP7461_ATKIP_07,
	GF_MP7461_ATKIP_08,
	GF_MP7461_ATKIP_09,
	GF_MP7461_ATKIP_10,

	GF_MP7462_ATKIP_01,
	GF_MP7462_ATKIP_02,
	GF_MP7462_ATKIP_03,
	GF_MP7462_ATKIP_04,
	GF_MP7462_ATKIP_05,
	GF_MP7462_ATKIP_06,
	GF_MP7462_ATKIP_07,
	GF_MP7462_ATKIP_08,
	GF_MP7462_ATKIP_09,
	GF_MP7462_ATKIP_10,

	// 密林
	GF_MP2301_ATKIP_01,
	GF_MP2301_ATKIP_02,
	GF_MP2301_ATKIP_03,
	GF_MP2301_ATKIP_04,
	GF_MP2301_ATKIP_05,
	GF_MP2301_ATKIP_06,

	GF_MP2302_ATKIP_01,
	GF_MP2302_ATKIP_02,
	GF_MP2302_ATKIP_03,
	GF_MP2302_ATKIP_04,
	GF_MP2302_ATKIP_05,
	GF_MP2302_ATKIP_06,

	GF_MP2303_ATKIP_01,
	GF_MP2303_ATKIP_02,
	GF_MP2303_ATKIP_03,

	GF_MP2304_ATKIP_01,

	GF_MP2305_ATKIP_01,
	GF_MP2305_ATKIP_02,
	GF_MP2305_ATKIP_03,

	GF_MP2306_ATKIP_01,
	GF_MP2306_ATKIP_02,
	GF_MP2306_ATKIP_03,
	GF_MP2306_ATKIP_04,
	GF_MP2306_ATKIP_05,
	GF_MP2306_ATKIP_06,
	GF_MP2306_ATKIP_07,
	GF_MP2306_ATKIP_08,
//	GF_MP2306_ATKIP_09,
//	GF_MP2306_ATKIP_10,
//	GF_MP2306_ATKIP_11,
//	GF_MP2306_ATKIP_12,
//	GF_MP2306_ATKIP_13,
//	GF_MP2306_ATKIP_14,
//	GF_MP2306_ATKIP_15,

	GF_MP2307_ATKIP_01,
	GF_MP2307_ATKIP_02,

	//奇岩浜
	GF_MP1118_ATKIP_01,
	GF_MP1118_ATKIP_02,

	//濃霧の森
	GF_MP2105_ATKIP_01,
	GF_MP2105_ATKIP_02,
	GF_MP2105_ATKIP_03,
	GF_MP2105_ATKIP_04,
	GF_MP2105_ATKIP_05,
	GF_MP2105_ATKIP_06,

	//霧の海岸
	GF_MP1114_ATKIP_01,
	GF_MP1114_ATKIP_02,
	GF_MP1114_ATKIP_03,
	GF_MP1114_ATKIP_04,
	GF_MP1114_ATKIP_05,
	GF_MP1114_ATKIP_06,
	GF_MP1114_ATKIP_07,
	GF_MP1114_ATKIP_08,
	GF_MP1114_ATKIP_09,

	GF_MP1115_ATKIP_01,
	GF_MP1115_ATKIP_02,
	GF_MP1115_ATKIP_03,
	GF_MP1115_ATKIP_04,
//	GF_MP1115_ATKIP_05,
//	GF_MP1115_ATKIP_06,
//	GF_MP1115_ATKIP_07,

	//高原
	GF_MP3109_ATKIP_01,
	GF_MP3109_ATKIP_02,
	GF_MP3109_ATKIP_03,
	GF_MP3109_ATKIP_04,
	GF_MP3109_ATKIP_05,
	GF_MP3109_ATKIP_06,
//	GF_MP3109_ATKIP_07,
//	GF_MP3109_ATKIP_08,
//	GF_MP3109_ATKIP_09,

	//ジャンダルム
	GF_MP4331_ATKIP_01,
	GF_MP4331_ATKIP_02,
	GF_MP4331_ATKIP_03,
	GF_MP4331_ATKIP_04,
	GF_MP4331_ATKIP_05,

	GF_MP4332_ATKIP_01,
	GF_MP4332_ATKIP_02,
	GF_MP4332_ATKIP_03,
	GF_MP4332_ATKIP_04,

	GF_MP4333_ATKIP_01,
	GF_MP4333_ATKIP_02,
	GF_MP4333_ATKIP_03,
	GF_MP4333_ATKIP_04,
	GF_MP4333_ATKIP_05,
	GF_MP4333_ATKIP_06,

	GF_MP4334_ATKIP_01,
	GF_MP4334_ATKIP_02,
	GF_MP4334_ATKIP_03,
	GF_MP4334_ATKIP_04,
	GF_MP4334_ATKIP_05,
	GF_MP4334_ATKIP_06,
	GF_MP4334_ATKIP_07,
	GF_MP4334_ATKIP_08,
	GF_MP4334_ATKIP_09,

	//高原
	GF_MP3108_ATKIP_01,
	GF_MP3108_ATKIP_02,
	GF_MP3108_ATKIP_03,

	GF_MP3106_ATKIP_01,
	GF_MP3106_ATKIP_02,
	GF_MP3106_ATKIP_03,
//	GF_MP3106_ATKIP_04,
//	GF_MP3106_ATKIP_05,

	GF_MP3107_ATKIP_01,
	GF_MP3107_ATKIP_02,
	GF_MP3107_ATKIP_03,
	GF_MP3107_ATKIP_04,
	GF_MP3107_ATKIP_05,
	GF_MP3107_ATKIP_06,
	GF_MP3107_ATKIP_07,
	GF_MP3107_ATKIP_08,
	GF_MP3107_ATKIP_09,
	GF_MP3107_ATKIP_10,

	//古代の洞窟
	GF_MP7401_ATKIP_01,
	GF_MP7401_ATKIP_02,
	GF_MP7401_ATKIP_03,

	//ジャンダルム
	GF_MP4336_ATKIP_01,
	GF_MP4336_ATKIP_02,
	GF_MP4336_ATKIP_03,
	GF_MP4336_ATKIP_04,
	GF_MP4336_ATKIP_05,
	GF_MP4336_ATKIP_06,

	GF_MP4338_ATKIP_01,
	GF_MP4338_ATKIP_02,
	GF_MP4338_ATKIP_03,
	GF_MP4338_ATKIP_04,

	GF_MP4339_ATKIP_01,
	GF_MP4339_ATKIP_02,

	GF_MP4340_ATKIP_01,
	GF_MP4340_ATKIP_02,
	GF_MP4340_ATKIP_03,
	GF_MP4340_ATKIP_04,
	GF_MP4340_ATKIP_05,

//風雲山道
	GF_MP4103_ATKIP_01,
	GF_MP4103_ATKIP_02,
	GF_MP4103_ATKIP_03,
	GF_MP4103_ATKIP_04,
	GF_MP4103_ATKIP_05,
	GF_MP4103_ATKIP_06,
	GF_MP4103_ATKIP_07,
	GF_MP4103_ATKIP_08,

	GF_MP7101_ATKIP_01,
	GF_MP7101_ATKIP_02,
	GF_MP7101_ATKIP_03,
	GF_MP7101_ATKIP_04,

	GF_MP4104_ATKIP_01,
	GF_MP4104_ATKIP_02,
	GF_MP4104_ATKIP_03,
	GF_MP4104_ATKIP_04,

	GF_MP4106_ATKIP_01,
	GF_MP4106_ATKIP_02,
	GF_MP4106_ATKIP_03,
	GF_MP4106_ATKIP_04,
	GF_MP4106_ATKIP_05,
	GF_MP4106_ATKIP_06,
	GF_MP4106_ATKIP_07,

	GF_MP4108_ATKIP_01,
	GF_MP4108_ATKIP_02,
	GF_MP4108_ATKIP_03,
	GF_MP4108_ATKIP_04,
	GF_MP4108_ATKIP_05,

	GF_MP7102_ATKIP_01,
	GF_MP7102_ATKIP_02,
	GF_MP7102_ATKIP_03,
	GF_MP7102_ATKIP_04,
	GF_MP7102_ATKIP_05,
	GF_MP7102_ATKIP_06,
	GF_MP7102_ATKIP_07,

	//聖域への参道
	GF_MP4109_ATKIP_01,
	GF_MP4109_ATKIP_02,

	//原生林
	GF_MP5103_ATKIP_01,
	GF_MP5103_ATKIP_02,
	GF_MP5103_ATKIP_03,
//	GF_MP5103_ATKIP_04,
	GF_MP5102_ATKIP_01,
	GF_MP5102_ATKIP_02,
	GF_MP5102_ATKIP_03,
	GF_MP5102_ATKIP_04,
	GF_MP5102_ATKIP_05,
	GF_MP5102_ATKIP_06,
//	GF_MP5102_ATKIP_07,
//	GF_MP5102_ATKIP_08,
//	GF_MP5102_ATKIP_09,
	GF_MP5101_ATKIP_01,
	GF_MP5101_ATKIP_02,
	GF_MP5101_ATKIP_03,
	GF_MP5101_ATKIP_04,

// 太古の大平原
	GF_MP6102_ATKIP_01,
	GF_MP6102_ATKIP_02,
	GF_MP6102_ATKIP_03,
	GF_MP6102_ATKIP_04,
	GF_MP6102_ATKIP_05,
	GF_MP6102_ATKIP_06,

	GF_MP6116_ATKIP_01,
	GF_MP6116_ATKIP_02,
	GF_MP6116_ATKIP_03,
	GF_MP6116_ATKIP_04,
	GF_MP6116_ATKIP_05,
	GF_MP6116_ATKIP_06,
	GF_MP6116_ATKIP_07,
	GF_MP6116_ATKIP_08,

	GF_MP6111_ATKIP_01,
	GF_MP6111_ATKIP_02,
	GF_MP6111_ATKIP_03,
	GF_MP6111_ATKIP_04,
	GF_MP6111_ATKIP_05,
	GF_MP6111_ATKIP_06,

	GF_MP6112_ATKIP_01,
	GF_MP6112_ATKIP_02,
	GF_MP6112_ATKIP_03,
	GF_MP6112_ATKIP_04,
	GF_MP6112_ATKIP_05,
	GF_MP6112_ATKIP_06,
	GF_MP6112_ATKIP_07,
	GF_MP6112_ATKIP_08,
	GF_MP6112_ATKIP_09,

//過去編・東

	GF_MP5103m_ATKIP_01,
	GF_MP5103m_ATKIP_02,
	GF_MP5103m_ATKIP_03,
	GF_MP5103m_ATKIP_04,
	GF_MP5103m_ATKIP_05,
	GF_MP5103m_ATKIP_06,
	GF_MP5103m_ATKIP_07,

	GF_MP6112m_ATKIP_01,
	GF_MP6112m_ATKIP_02,

//トワル街道

	GF_MP6103_ATKIP_01,
	GF_MP6103_ATKIP_02,
	GF_MP6103_ATKIP_03,
	GF_MP6103_ATKIP_04,
	GF_MP6103_ATKIP_05,
	GF_MP6103_ATKIP_06,
	GF_MP6103_ATKIP_07,
//	GF_MP6103_ATKIP_08,

	GF_MP6115_ATKIP_01,
	GF_MP6115_ATKIP_02,

	GF_MP6104_ATKIP_01,
	GF_MP6104_ATKIP_02,
	GF_MP6104_ATKIP_03,
	GF_MP6104_ATKIP_04,
	GF_MP6104_ATKIP_05,
	GF_MP6104_ATKIP_06,
	GF_MP6104_ATKIP_07,
	GF_MP6104_ATKIP_08,
	GF_MP6104_ATKIP_09,
//	GF_MP6104_ATKIP_10,

//過去編・東・トワル街道
	GF_MP6103m_ATKIP_01,
	GF_MP6103m_ATKIP_02,
	GF_MP6103m_ATKIP_03,
	GF_MP6103m_ATKIP_04,
	GF_MP6103m_ATKIP_05,
	GF_MP6103m_ATKIP_06,
	GF_MP6103m_ATKIP_07,
	GF_MP6103m_ATKIP_08,

//バハの斜塔
	GF_MP6322_ATKIP_01,
	GF_MP6322_ATKIP_02,
	GF_MP6322_ATKIP_03,
	GF_MP6322_ATKIP_04,
	GF_MP6322_ATKIP_05,

	GF_MP6323_ATKIP_01,
	GF_MP6323_ATKIP_02,
	GF_MP6323_ATKIP_03,
	GF_MP6323_ATKIP_04,

	GF_MP6324_ATKIP_01,
	GF_MP6324_ATKIP_02,
	GF_MP6324_ATKIP_03,
	GF_MP6324_ATKIP_04,
	GF_MP6324_ATKIP_05,

	GF_MP6326_ATKIP_01,
	GF_MP6326_ATKIP_02,
	GF_MP6326_ATKIP_03,

	GF_MP6328_ATKIP_01,
	GF_MP6328_ATKIP_02,
	GF_MP6328_ATKIP_03,
	GF_MP6328_ATKIP_04,

//喜望峰
	GF_MP1116_ATKIP_01,
	GF_MP1116_ATKIP_02,
	GF_MP1116_ATKIP_03,
	GF_MP1116_ATKIP_04,
//	GF_MP1116_ATKIP_05,
//	GF_MP1116_ATKIP_06,

// 海岸洞窟_mp741x
	GF_MP7411_ATKIP_01,
	GF_MP7411_ATKIP_02,
	GF_MP7411_ATKIP_03,
	GF_MP7411_ATKIP_04,
	GF_MP7411_ATKIP_05,

//幽霊船

//始生代の大穴
	GF_MP6362_ATKIP_01,
	GF_MP6362_ATKIP_02,
	GF_MP6362_ATKIP_03,
	GF_MP6362_ATKIP_04,

	GF_MP6363_ATKIP_01,
	GF_MP6363_ATKIP_02,
	GF_MP6363_ATKIP_03,
	GF_MP6363_ATKIP_04,

	GF_MP6364_ATKIP_01,
	GF_MP6364_ATKIP_02,
	GF_MP6364_ATKIP_03,
	GF_MP6364_ATKIP_04,

	GF_MP6365_ATKIP_01,
	GF_MP6365_ATKIP_02,
	GF_MP6365_ATKIP_03,
	GF_MP6365_ATKIP_04,
	GF_MP6365_ATKIP_05,
	GF_MP6365_ATKIP_06,
	GF_MP6365_ATKIP_07,
	GF_MP6365_ATKIP_08,
	GF_MP6365_ATKIP_09,
	GF_MP6365_ATKIP_10,
	GF_MP6365_ATKIP_11,
	GF_MP6365_ATKIP_12,

	GF_MP6367_ATKIP_01,
	GF_MP6367_ATKIP_02,
	GF_MP6367_ATKIP_03,
	GF_MP6367_ATKIP_04,
	GF_MP6367_ATKIP_05,
	GF_MP6367_ATKIP_06,
	GF_MP6367_ATKIP_07,
	GF_MP6367_ATKIP_08,
	GF_MP6367_ATKIP_09,
	GF_MP6367_ATKIP_10,

	GF_MP6369_ATKIP_01,
	GF_MP6369_ATKIP_02,
	GF_MP6369_ATKIP_03,

//天崖丘陵
	GF_MP4110_ATKIP_01,
	GF_MP4110_ATKIP_02,
	GF_MP4110_ATKIP_03,
	GF_MP4110_ATKIP_04,
	GF_MP4110_ATKIP_05,

	GF_MP5104_ATKIP_01,
	GF_MP5104_ATKIP_02,
	GF_MP5104_ATKIP_03,
	GF_MP5104_ATKIP_04,
	GF_MP5104_ATKIP_05,
	GF_MP5104_ATKIP_06,

//湿原地帯
	GF_MP6106_ATKIP_01,
	GF_MP6106_ATKIP_02,
	GF_MP6106_ATKIP_03,
	GF_MP6106_ATKIP_04,
	GF_MP6106_ATKIP_05,
	GF_MP6106_ATKIP_06,

	GF_MP6113_ATKIP_01,
	GF_MP6113_ATKIP_02,
	GF_MP6113_ATKIP_03,
	GF_MP6113_ATKIP_04,
	GF_MP6113_ATKIP_05,
	GF_MP6113_ATKIP_06,
	GF_MP6113_ATKIP_07,
//	GF_MP6113_ATKIP_08,		後ろに追加

	GF_MP6107_ATKIP_01,
	GF_MP6107_ATKIP_02,
	GF_MP6107_ATKIP_03,
	GF_MP6107_ATKIP_04,
	GF_MP6107_ATKIP_05,
	GF_MP6107_ATKIP_06,
	GF_MP6107_ATKIP_07,
	GF_MP6107_ATKIP_08,
	GF_MP6107_ATKIP_09,

	GF_MP6114_ATKIP_01,
	GF_MP6114_ATKIP_02,
	GF_MP6114_ATKIP_03,
	GF_MP6114_ATKIP_04,
	GF_MP6114_ATKIP_05,
	GF_MP6114_ATKIP_06,
	GF_MP6114_ATKIP_07,

//過去編・西
	GF_MP6113m_ATKIP_01,
	GF_MP6113m_ATKIP_02,
	GF_MP6113m_ATKIP_03,
	GF_MP6113m_ATKIP_04,
	GF_MP6113m_ATKIP_05,

	GF_MP6106m_ATKIP_01,
	GF_MP6106m_ATKIP_02,
	GF_MP6106m_ATKIP_03,
	GF_MP6106m_ATKIP_04,
	GF_MP6106m_ATKIP_05,
	GF_MP6106m_ATKIP_06,

	GF_MP6107m_ATKIP_01,
	GF_MP6107m_ATKIP_02,
	GF_MP6107m_ATKIP_03,
	GF_MP6107m_ATKIP_04,
	GF_MP6107m_ATKIP_05,
	GF_MP6107m_ATKIP_06,
	GF_MP6107m_ATKIP_07,
	GF_MP6107m_ATKIP_08,

	GF_MP6114m_ATKIP_01,
	GF_MP6114m_ATKIP_02,
	GF_MP6114m_ATKIP_03,
	GF_MP6114m_ATKIP_04,
	GF_MP6114m_ATKIP_05,

	GF_MP5104m_ATKIP_01,
	GF_MP5104m_ATKIP_02,
	GF_MP5104m_ATKIP_03,
	GF_MP5104m_ATKIP_04,

	GF_MP6108m_ATKIP_01,
	GF_MP6108m_ATKIP_02,
	GF_MP6108m_ATKIP_03,
	GF_MP6108m_ATKIP_04,
	GF_MP6108m_ATKIP_05,

//悠久の丘
	GF_MP6109_ATKIP_01,
	GF_MP6109_ATKIP_02,
	GF_MP6109_ATKIP_03,
	GF_MP6109_ATKIP_04,
	GF_MP6109_ATKIP_05,
	GF_MP6109_ATKIP_06,
	GF_MP6109_ATKIP_07,
//	GF_MP6109_ATKIP_08,		//後ろに追加
//	GF_MP6109_ATKIP_09,
//	GF_MP6109_ATKIP_10,

// 埋没した塔_mp641x
	GF_MP6411_ATKIP_01,
	GF_MP6411_ATKIP_02,
	GF_MP6411_ATKIP_03,
	GF_MP6411_ATKIP_04,

	GF_MP6412_ATKIP_01,
	GF_MP6412_ATKIP_02,
	GF_MP6412_ATKIP_03,
	GF_MP6412_ATKIP_04,

	GF_MP6413_ATKIP_01,
	GF_MP6413_ATKIP_02,
	GF_MP6413_ATKIP_03,
	GF_MP6413_ATKIP_04,

//オクトゥス・氷の回廊
	GF_MP6306_ATKIP_01,
	GF_MP6306_ATKIP_02,
	GF_MP6306_ATKIP_03,

//オクトゥス・蟲の回廊
	GF_MP6307_ATKIP_01,
	GF_MP6307_ATKIP_02,
	GF_MP6307_ATKIP_03,

//オクトゥス・天の回廊
	GF_MP6308_ATKIP_01,
	GF_MP6308_ATKIP_02,
	GF_MP6308_ATKIP_03,

// 大石柱の風穴_mp749x
	GF_MP7491_ATKIP_01,
	GF_MP7491_ATKIP_02,
	GF_MP7491_ATKIP_03,
	GF_MP7491_ATKIP_04,
	GF_MP7491_ATKIP_05,
	GF_MP7491_ATKIP_06,
	GF_MP7491_ATKIP_07,
	GF_MP7491_ATKIP_08,
	GF_MP7491_ATKIP_09,
	GF_MP7491_ATKIP_10,
	GF_MP7491_ATKIP_11,
	GF_MP7491_ATKIP_12,
	GF_MP7491_ATKIP_13,

//追加

	//水源地
	GF_MP7451_ATKIP_06,
	GF_MP7451_ATKIP_07,
	GF_MP7451_ATKIP_08,
	GF_MP7451_ATKIP_09,
	GF_MP7451_ATKIP_10,
	GF_MP7451_ATKIP_11,
	GF_MP7451_ATKIP_12,

//過去編ダーナ①・大峡谷
	GF_MP3109m_ATKIP_01,
	GF_MP3110m_ATKIP_01,

//過去編Ⅰ・
	GF_MP5103m_ATKIP_08,
	GF_MP6101m_ATKIP_01,
//過去編Ⅲ・
	GF_MP6103m_ATKIP_09,
	GF_MP6103m_ATKIP_10,
//過去編Ⅴ・
	GF_MP6106m_ATKIP_07,
	GF_MP6106m_ATKIP_08,
//追加
	GF_MP5101_ATKIP_05,	//後ろに追加
	GF_MP6113_ATKIP_08,		//後ろに追加
	GF_MP6109_ATKIP_08,		//後ろに追加
	GF_MP6109_ATKIP_09,
	GF_MP6109_ATKIP_10,
	GF_MP1302_ATKIP_07,		//後ろに追加
	GF_MP2102_ATKIP_10,		//後ろに追加
	GF_MP2306_ATKIP_09,
	GF_MP2306_ATKIP_10,
	GF_MP2306_ATKIP_11,
	GF_MP2306_ATKIP_12,
	GF_MP2306_ATKIP_13,
	GF_MP2306_ATKIP_14,
	GF_MP2306_ATKIP_15,
	GF_MP1115_ATKIP_05,
	GF_MP1115_ATKIP_06,
	GF_MP1115_ATKIP_07,
	GF_MP3109_ATKIP_07,
	GF_MP3109_ATKIP_08,
	GF_MP3109_ATKIP_09,
	GF_MP3106_ATKIP_04,
	GF_MP3106_ATKIP_05,
	GF_MP1307_ATKIP_03,
	GF_MP1307_ATKIP_04,
	GF_MP3104_ATKIP_05,
	GF_MP3104_ATKIP_06,
	GF_MP3104_ATKIP_07,
	GF_MP3104_ATKIP_08,
	GF_MP5103_ATKIP_04,
	GF_MP5102_ATKIP_07,
	GF_MP5102_ATKIP_08,
	GF_MP5102_ATKIP_09,
	GF_MP6103_ATKIP_08,
	GF_MP6104_ATKIP_10,
	GF_MP1116_ATKIP_05,
	GF_MP1116_ATKIP_06,
	GF_MP1132_ATKIP_05,
	GF_MP1132_ATKIP_06,
	GF_MP1112_ATKIP_10,
	GF_MP1112_ATKIP_11,
	GF_MP1131_ATKIP_06,

// PS4追加分
	GF_MP1301t2_ATKIP_01,
	GF_MP1301t2_ATKIP_02,
	GF_MP1301t2_ATKIP_03,
	GF_MP1301t2_ATKIP_04,
	GF_MP1301t2_ATKIP_05,
	GF_MP1301t2_ATKIP_06,
	GF_MP1301t2_ATKIP_07,
	GF_MP1302t2_ATKIP_01,
	GF_MP1302t2_ATKIP_02,
	GF_MP1302t2_ATKIP_03,
	GF_MP1302t2_ATKIP_04,
	GF_MP1302t2_ATKIP_05,
	GF_MP1302t2_ATKIP_06,
	GF_MP1302t2_ATKIP_07,
	GF_MP1302t2_ATKIP_08,
	GF_MP1302t2_ATKIP_09,
	GF_MP1302t2_ATKIP_10,
	GF_MP1302t2_ATKIP_11,
	GF_MP1302t2_ATKIP_12,
	GF_MP1303t2_ATKIP_01,
	GF_MP1303t2_ATKIP_02,
	GF_MP1303t2_ATKIP_03,
	GF_MP1303t2_ATKIP_04,
	GF_MP1303t2_ATKIP_05,
	GF_MP1303t2_ATKIP_06,
	GF_MP1303t2_ATKIP_07,
	GF_MP1304t2_ATKIP_01,
	GF_MP1304t2_ATKIP_02,
	GF_MP1304t2_ATKIP_03,
	GF_MP1304t2_ATKIP_04,
	GF_MP1304t2_ATKIP_05,
	GF_MP1304t2_ATKIP_06,
	GF_MP1304t2_ATKIP_07,
	GF_MP1304t2_ATKIP_08,
	GF_MP1304t2_ATKIP_09,
	GF_MP1304t2_ATKIP_10,
	GF_MP1304t2_ATKIP_11,
	GF_MP1305t2_ATKIP_01,
	GF_MP1305t2_ATKIP_02,
	GF_MP1305t2_ATKIP_03,
	GF_MP1305t2_ATKIP_04,
	GF_MP1305t2_ATKIP_05,
	GF_MP1306t2_ATKIP_01,
	GF_MP1306t2_ATKIP_02,
	GF_MP1307t2_ATKIP_01,
	GF_MP1307t2_ATKIP_02,
	GF_MP1307t2_ATKIP_03,
	GF_MP1307t2_ATKIP_04,
	GF_MP4331t2_ATKIP_01,
	GF_MP4331t2_ATKIP_02,
	GF_MP4331t2_ATKIP_03,
	GF_MP4331t2_ATKIP_04,
	GF_MP4331t2_ATKIP_05,
	GF_MP4331t2_ATKIP_06,
	GF_MP4332t2_ATKIP_01,
	GF_MP4332t2_ATKIP_02,
	GF_MP4332t2_ATKIP_03,
	GF_MP4332t2_ATKIP_04,
	GF_MP4333t2_ATKIP_01,
	GF_MP4333t2_ATKIP_02,
	GF_MP4333t2_ATKIP_03,
	GF_MP4333t2_ATKIP_04,
	GF_MP4333t2_ATKIP_05,
	GF_MP4334t2_ATKIP_01,
	GF_MP4334t2_ATKIP_02,
	GF_MP4334t2_ATKIP_03,
	GF_MP4334t2_ATKIP_04,
	GF_MP4334t2_ATKIP_05,
	GF_MP4334t2_ATKIP_06,
	GF_MP4334t2_ATKIP_07,
	GF_MP4334t2_ATKIP_08,
	GF_MP4334t2_ATKIP_09,
	GF_MP4334t2_ATKIP_10,
	GF_MP4334t2_ATKIP_11,
	GF_MP4335t2_ATKIP_01,
	GF_MP4336t2_ATKIP_01,
	GF_MP4336t2_ATKIP_02,
	GF_MP4336t2_ATKIP_03,
	GF_MP4336t2_ATKIP_04,
	GF_MP4336t2_ATKIP_05,
	GF_MP4336t2_ATKIP_06,
	GF_MP4336t2_ATKIP_07,
	GF_MP4336t2_ATKIP_08,
	GF_MP4337t2_ATKIP_01,
	GF_MP4337t2_ATKIP_02,
	GF_MP4338t2_ATKIP_01,
	GF_MP4338t2_ATKIP_02,
	GF_MP4338t2_ATKIP_03,
	GF_MP4338t2_ATKIP_04,
	GF_MP4338t2_ATKIP_05,
	GF_MP4338t2_ATKIP_06,
	GF_MP4338t2_ATKIP_07,
	GF_MP4339t2_ATKIP_01,
	GF_MP4339t2_ATKIP_02,
	GF_MP4339t2_ATKIP_03,
	GF_MP4339t2_ATKIP_04,
	GF_MP4339t2_ATKIP_05,
	GF_MP4340t2_ATKIP_01,
	GF_MP4340t2_ATKIP_02,
	GF_MP4340t2_ATKIP_03,
	GF_MP4340t2_ATKIP_04,
	GF_MP4341t2_ATKIP_01,
	GF_MP4341t2_ATKIP_02,
	GF_MP6111t2_ATKIP_01,
	GF_MP6111t2_ATKIP_02,
	GF_MP6111t2_ATKIP_03,
	GF_MP6111t2_ATKIP_04,
	GF_MP6111t2_ATKIP_05,
	GF_MP6111t2_ATKIP_06,
	GF_MP6112t2_ATKIP_01,
	GF_MP6112t2_ATKIP_02,
	GF_MP6112t2_ATKIP_03,
	GF_MP6112t2_ATKIP_04,
	GF_MP6112t2_ATKIP_05,
	GF_MP6112t2_ATKIP_06,
	GF_MP6112t2_ATKIP_07,
	GF_MP6112t2_ATKIP_08,
	GF_MP6112t2_ATKIP_09,
	GF_MP6116t2_ATKIP_01,
	GF_MP6116t2_ATKIP_02,
	GF_MP6116t2_ATKIP_03,
	GF_MP6116t2_ATKIP_04,
	GF_MP6116t2_ATKIP_05,
	GF_MP6116t2_ATKIP_06,
	GF_MP6116t2_ATKIP_07,
	GF_MP6116t2_ATKIP_08,
	// 地下聖堂
	GF_MP6531m_ATKIP_01,
	GF_MP6531m_ATKIP_02,
	GF_MP6531m_ATKIP_03,
	GF_MP6531m_ATKIP_04,
	GF_MP6531m_ATKIP_05,
	GF_MP6551m_ATKIP_01,
	GF_MP6551m_ATKIP_02,
	GF_MP6551m_ATKIP_03,
	GF_MP6553m_ATKIP_01,
	GF_MP6553m_ATKIP_02,
	GF_MP6553m_ATKIP_03,
	GF_MP6553m_ATKIP_04,
	GF_MP6553m_ATKIP_05,
	// 旧地下聖堂
	GF_MP6512_ATKIP_01,
	GF_MP6512_ATKIP_02,
	GF_MP6512_ATKIP_03,
	GF_MP6531_ATKIP_01,
	GF_MP6531_ATKIP_02,
	GF_MP6531_ATKIP_03,
	GF_MP6531_ATKIP_04,
	GF_MP6531_ATKIP_05,
	GF_MP6531_ATKIP_06,
	GF_MP6531_ATKIP_07,
	GF_MP6531_ATKIP_08,
	GF_MP6531_ATKIP_09,
	GF_MP6531_ATKIP_10,
	GF_MP6531_ATKIP_11,
	GF_MP6531_ATKIP_12,
	GF_MP6531_ATKIP_13,
	GF_MP6542_ATKIP_01,
	GF_MP6542_ATKIP_02,
	GF_MP6551_ATKIP_01,
	GF_MP6551_ATKIP_02,
	GF_MP6551_ATKIP_03,
	GF_MP6551_ATKIP_04,
	GF_MP6551_ATKIP_05,
	GF_MP6551_ATKIP_06,
	GF_MP6551_ATKIP_07,
	GF_MP6551_ATKIP_08,
	GF_MP6552_ATKIP_01,
	GF_MP6552_ATKIP_02,
	GF_MP6553_ATKIP_01,
	GF_MP6553_ATKIP_02,
	GF_MP6553_ATKIP_03,
	GF_MP6553_ATKIP_04,
	GF_MP6553_ATKIP_05,
	GF_MP6554_ATKIP_01,
	GF_MP6554_ATKIP_02,
	GF_MP6554_ATKIP_03,
	GF_MP6554_ATKIP_04,
	GF_MP6554_ATKIP_05,

	// さらに追加分
	GF_MP1302t2_ATKIP_13,
	GF_MP1302t2_ATKIP_14,

	GF_ITEMPOINT_MAX,			// アイテムポイントここまで（フラグ数チェック用なので、GF_RESERVE_START直前に置くように）

//■ギャラリーモード用------------------------------------------------------------------
	GF_GALL_START = 6535,	// 現在使用数=108

	GF_GALL_CLEAR_ED3 = GF_GALL_START,		//真EDクリア キャラ・エクストライラスト、ムービー開放

	GF_GALL_EV_PL_01,			// M00S001:アドル＆ドギ登場
	GF_GALL_EV_PL_02,			// M00S010:バルバロス登場
	GF_GALL_EV_PL_03,			// M00S050:巨大な触手と戦闘する
	GF_GALL_EV_PL_04,			// M00S060:ロンバルディアが沈没する
	GF_GALL_EV_01_01,			// M01S000:セイレン島に漂着する
	GF_GALL_EV_01_02,			// M01S030:ラクシャに遭遇する
	GF_GALL_EV_01_03,			// M01S180:古代種と遭遇
	GF_GALL_EV_01_04,			// M01S181:サハド抱きつく
	GF_GALL_EV_02_01,			// M02S101:はじめて野営をする２
	GF_GALL_EV_02_02,			// M02S260:ヒュンメルと出会う
	GF_GALL_EV_02_03,			// M02S271:mp1121で野営する２
	GF_GALL_EV_02_04,			// M02S320:ヒュンメルが合流する
	GF_GALL_EV_02_05,			// M02S331:侵蝕谷前の野営２
	GF_GALL_EV_02_06,			// M02S361:密林前の野営２
	GF_GALL_EV_02_07,			// M02S490:ラクシャと二人きりで話す
	GF_GALL_EV_02_08,			// M02S560:カーラン卿が死亡する
	GF_GALL_EV_02_09,			// M02S650:バルバロスが致命傷を負う
	GF_GALL_EV_02_10,			// M02S670:キルゴールが死亡
	GF_GALL_EV_02_11,			// M02S680:バルバロスが命を落とす
	GF_GALL_EV_03_01,			// M03S010:ダーナ① 植樹祭の説明を受ける
	GF_GALL_EV_03_02,			// M03S031:ダーナ① 植樹の儀２
	GF_GALL_EV_03_03,			// M03S111:ダーナ② サライとの別れ２
	GF_GALL_EV_03_04,			// M03S150:ジャンダルムで大型古代種に遭遇
	GF_GALL_EV_03_05,			// M03S151:リコッタが助太刀に入る
	GF_GALL_EV_03_06,			// M03S160:リコッタの話を聞く
	GF_GALL_EV_03_07,			// M03S250:初めて古代種を打倒する
	GF_GALL_EV_03_08,			// M03S270:翼竜型古代種登場
	GF_GALL_EV_03_09,			// M03S290:ジャンダルムの頂上に到着する
	GF_GALL_EV_04_01,			// M04S060:ダーナ③ 新女王サライへの謁見
	GF_GALL_EV_04_02,			// M04S080:リコッタが行方不明になる
	GF_GALL_EV_04_03,			// M04S121:王都前で野営する
	GF_GALL_EV_04_04,			// M04S132:過去Ⅰ 初めて水晶石前に植樹
	GF_GALL_EV_04_05,			// M04S170:橋の上でタナトスに出会う
	GF_GALL_EV_04_06,			// M04S260:ダーナを発見する
	GF_GALL_EV_05_01,			// M05S010:ダーナが迎撃戦に参加する
	GF_GALL_EV_05_02,			// M05S130:ダーナがモノリスを起動する
	GF_GALL_EV_05_03,			// M05S147:エレフセリア号が出航する
	GF_GALL_EV_05_04,			// M05S171:キャプテン・リードと別れる
	GF_GALL_EV_05_05,			// M05S230:消滅した王宮が復活する
	GF_GALL_EV_05_06,			// M05S280:オケアノス討伐戦を開始する
	GF_GALL_EV_05_07,			// M05S293:オケアノスに勝利する
	GF_GALL_EV_05_08,			// M05S310:高台でダーナと話す
	GF_GALL_EV_05_09,			// M05S320:過去Ⅳ－２　星の落下を予知する
	GF_GALL_EV_05_10,			// M05S341:過去Ⅳ－２　謎の竜種との戦闘後
	GF_GALL_EV_05_11,			// M05S381:ダーナに追いつく２
	GF_GALL_EV_05_12,			// M05S421:墓所前で野営する
	GF_GALL_EV_05_13,			// M05S460:壁画の間にたどり着く
	GF_GALL_EV_06_01,			// M06S044:山門前で護り人たちに遭遇する２
	GF_GALL_EV_06_02,			// M06S070:過去Ⅵ　ダーナが自分を封印する
	GF_GALL_EV_06_03,			// M06S203:サライが想念を取り戻す
	GF_GALL_EV_06_04,			// M06S210:想剣ミストルティンを入手する
	GF_GALL_EV_06_05,			// M06S230:《選択の間》への扉を開く
	GF_GALL_EV_06_06,			// M06S240:ﾃｵｽ･ﾃﾞ･ｴﾝﾄﾞﾛｸﾞﾗﾑとの戦い
	GF_GALL_EV_06_07,			// M06S241:ﾃｵｽ･ﾃﾞ･ｴﾝﾄﾞﾛｸﾞﾗﾑとの戦い２
	GF_GALL_EV_EL_01,			// M07S000:漂流村でアドルが目を覚ます
	GF_GALL_EV_EL_02,			// M07S010:ＥＤⅠ 寺院跡を訪れる＆脱出
	GF_GALL_EV_EL_03,			// M07S040:ＥＤⅡ 大地神マイアとの邂逅
	GF_GALL_EV_EL_04,			// M07S040:ＥＤⅢ 大地神マイアとの邂逅
	GF_GALL_EV_EL_05,			// M07S100:ＥＤⅢ 《はじまりの深淵》突破
	GF_GALL_EV_EL_06,			// M07S121:ＥＤⅢ セイレン島を脱出する

	GF_GALL_EV_LIKE_01,			// Sinai_Dogi
	GF_GALL_EV_LIKE_02,			// Sinai_Hummel
	GF_GALL_EV_LIKE_03,			// Sinai_Miralda
	GF_GALL_EV_LIKE_04,			// Sinai_Paro
	GF_GALL_EV_LIKE_05,			// Sinai_Licht
	GF_GALL_EV_LIKE_06,			// Sinai_Alison
	GF_GALL_EV_LIKE_07,			// Sinai_Curran
	GF_GALL_EV_LIKE_08,			// Sinai_Thanatos
	GF_GALL_EV_LIKE_09,			// Sinai_Ricotta
	GF_GALL_EV_LIKE_10,			// Sinai_Laxia
	GF_GALL_EV_LIKE_11,			// Sinai_Silvia
	GF_GALL_EV_LIKE_12,			// Sinai_Franz
	GF_GALL_EV_LIKE_13,			// Sinai_Kashu
	GF_GALL_EV_LIKE_14,			// Sinai_Sahad
	GF_GALL_EV_LIKE_15,			// Sinai_Nia
	GF_GALL_EV_LIKE_16,			// Sinai_Reja
	GF_GALL_EV_LIKE_17,			// Sinai_Aaron
	GF_GALL_EV_LIKE_18,			// Sinai_Ed
	GF_GALL_EV_LIKE_19,			// Sinai_Austen
	GF_GALL_EV_LIKE_20,			// Sinai_Katrin
	GF_GALL_EV_LIKE_21,			// Sinai_Kuina
	GF_GALL_EV_LIKE_22,			// Sinai_Griselda
	GF_GALL_EV_LIKE_23,			// Sinai_Dana
	GF_GALL_EV_LIKE_24,			// Sinai_Dina
	
	GF_GALL_EVIMG_01,			// p_10000 アドルの夢Ⅰ[牧童の少女]：空を見上げるダーナ
	GF_GALL_EVIMG_02,			// p_10001 アドルの夢Ⅰ[牧童の少女]：振り返るダーナ
	GF_GALL_EVIMG_03,			// p_10010 アドルの夢Ⅰ[寺院の使者たち]
	GF_GALL_EVIMG_04,			// p_10020 アドルの夢Ⅱ[巫女の候補者たち]
	GF_GALL_EVIMG_05,			// p_10030 アドルの夢Ⅱ[ダーナと巫女]
	GF_GALL_EVIMG_06,			// p_10031 アドルの夢Ⅱ[ダーナと巫女]（巫女なし差分）
	GF_GALL_EVIMG_07,			// p_10032 アドルの夢Ⅱ[灰色の予知] マイアの姿
	GF_GALL_EVIMG_08,			// p_10040 アドルの夢Ⅱ[三人の候補者]
	GF_GALL_EVIMG_09,			// p_10050 アドルの夢Ⅲ[瞑想しているダーナ]：瞑目
	GF_GALL_EVIMG_10,			// p_10051 アドルの夢Ⅲ[瞑想しているダーナ]：開眼
	GF_GALL_EVIMG_11,			// p_10070 アドルの夢Ⅳ[巫女の計らい]
	GF_GALL_EVIMG_12,			// p_10080 アドルの夢Ⅴ[森を駆けるダーナたち]
	GF_GALL_EVIMG_13,			// p_10090 アドルの夢Ⅴ[聖域に立つダーナたち]
	GF_GALL_EVIMG_14,			// p_10120 アドルの夢Ⅵ[巫女選定の儀]
	GF_GALL_EVIMG_15,			// p_10130 アドルの夢Ⅵ[サライとオルガ]
	GF_GALL_EVIMG_16,			// p_10100 ラクシャ回想[父への想い]
	GF_GALL_EVIMG_17,			// p_10113 ラクシャ回想[ロズウェル家の苦難]：領地剥奪の令状
	GF_GALL_EVIMG_18,			// p_10140 ダーナ回想[苦悩する幼少ダーナ]
	GF_GALL_EVIMG_19,			// p_10150 ダーナ回想[ダーナと母]
	GF_GALL_EVIMG_20,			// p_10160 ダーナ回想[母の死]
	GF_GALL_EVIMG_21,			// p_10190 ダーナフラッシュバック[母の死]：焼け落ちる家
	GF_GALL_EVIMG_22,			// p_10170 ヒュンメル回想「出奔」
	GF_GALL_EVIMG_23,			// p_10180 ヒュンメル回想「親子の再会」
	GF_GALL_EVIMG_24,			//p_10200 ダーナ編モノリスポートレート
	GF_GALL_EVIMG_25,			//p_10220 ダーナ編モノリスポートレート
	GF_GALL_EVIMG_26,			//p_10230 ダーナ編モノリスポートレート
	GF_GALL_EVIMG_27,			//p_10240 ダーナ編モノリスポートレート
	GF_GALL_EVIMG_28,			//p_10250 ダーナ編モノリスポートレート
	GF_GALL_EVIMG_29,			//p_10260,p_10261 ダーナ編モノリスポートレート

	//追加分（ムービー順次開放）
	GF_GALL_MOVIE_01,				//	オープニング		※最初から開放されるので欠番
	GF_GALL_MOVIE_02,				//	植樹祭の予知
	GF_GALL_MOVIE_03,				//	灰色の予知
	GF_GALL_MOVIE_04,				//	王都理力障壁展開
	GF_GALL_MOVIE_05,				//	隕石群の飛来
	GF_GALL_MOVIE_06,				//	理力障壁決壊
	GF_GALL_MOVIE_07,				//	ラクリモサの消滅
	GF_GALL_MOVIE_08,				//	通常エンディングロール
	GF_GALL_MOVIE_09,				//	真エンディングロール

	//追加分（過去編ポートレートの追加）
	GF_GALL_EVIMG_30,			//モノリスポートレート小窓
	GF_GALL_EVIMG_31,			//モノリスポートレート小窓
	GF_GALL_EVIMG_32,			//モノリスポートレート小窓
	GF_GALL_EVIMG_33,			//モノリスポートレート小窓

	GF_GALL_CLEAR_ED1,			//バッドエンド・ノーマルエンド
	GF_GALL_CLEAR_ED4,			//真ＥＤ＋エタニアクエスト全クリア

	GF_GALL_END,
	// ※GF_GALL_END - GF_GALL_START < SYSTEMSAVE_GALLERY_FLAG_MAX(256) である必要がある。

//■ サブシステム用------------------------------------------------------------------
	GF_MENUSAVE_PAST_START = 6845,	// 

	GF_MENUSAVE_PAST_TAB1 = GF_MENUSAVE_PAST_START,			// 過去編メニュー保存用
	GF_MENUSAVE_PAST_ITEM_ITEM,
	GF_MENUSAVE_PAST_SCR_ITEM,

	GF_MENUSAVE_PAST_MAX,
	GF_SHOP_VOICE_INTERCEPT,				// 迎撃戦のショップボイスを鳴らす

	GF_SHOP_GETONCE_START = 6850,			// 一品物取得管理スタート（プログラムでビット制御。最大96個想定）
	GF_SHOP_GETONCE_00 = GF_SHOP_GETONCE_START,
	GF_SHOP_GETONCE_01,
	GF_SHOP_GETONCE_02,
	GF_DIARY_SHOP_INFO = 6853,				// 素材手帳に載せるショップ（プログラムでビット制御）
	
	GF_VIRTURE_POINT,						// 徳ポイント
	
	GF_DR_CHARA_START = 6855,				// 人物メモフラグスタート（プログラムでビット制御。最大60人）
	GF_DR_CHARA_01 = GF_DR_CHARA_START,
	GF_DR_CHARA_02,
	GF_DR_CHARA_03,
	GF_DR_CHARA_04,
	GF_DR_CHARA_05,
	GF_DR_CHARA_06,
	GF_DR_CHARA_07,
	GF_DR_CHARA_08,
	GF_DR_CHARA_09,
	GF_DR_CHARA_10,
	GF_DR_CHARA_11,

	GF_SHOP_VOICE_ALISON,					// アリスンのショップボイスを鳴らす
	GF_SHOP_VOICE_USED1,					// 重複使用チェック１
	GF_SHOP_VOICE_USED2,					// 重複使用チェック２

	GF_GALLERY_EVENT_RETURN,				// ギャラリーイベントから戻ったぞ


	GF_DR_CHARA_MAX,					// GF_DR_CHARA_STARTに対する終端（GF_LIKELV_STARTの数を超えていないか判定用）

	GF_LIKELV_START = 6870,					// 好感度レベルスタート（ここの並びはNPC_～と同じにすべし）	（0～3：表示上ではLV1～LV4になる）
		// NPC
	GF_LIKELV_BARBAROSS = GF_LIKELV_START,	// バルバロス船長
	GF_LIKELV_DOGI,							// ドギ
	GF_LIKELV_ALISON,						// アリスン
	GF_LIKELV_KIERGAARD,					// キルゴール
	GF_LIKELV_CURRAN,						// カーラン卿
	GF_LIKELV_KATRIN,						// カトリーン
	GF_LIKELV_DINA,							// ディナ
	GF_LIKELV_AARON,						// エアラン
	GF_LIKELV_LICHT,						// リヒト
	GF_LIKELV_REJA,							// レーヤ
	GF_LIKELV_MIRALDA,						// ミラルダ
	GF_LIKELV_KUINA,						// クイナ
	GF_LIKELV_NIA,							// シスターニア
	GF_LIKELV_KASHU,						// カシュー
	GF_LIKELV_FRANZ,						// フランツ
	GF_LIKELV_THANATOS,						// タナトス
	GF_LIKELV_ED,							// エド				// ※綴り不明
	GF_LIKELV_GRISELDA,						// グリゼルダ
	GF_LIKELV_AUSTEN,						// オースティン		// ※綴り不明
	GF_LIKELV_SILVIA,						// シルビア			// ※綴り不明
		// 非人
	GF_LIKELV_PARO,							// リトル・パロ
	GF_LIKELV_SKILLMONKY,					// スキルザル
	GF_LIKELV_BALAENICEPS_REX,				// ハシビロコウ
		// プレイヤー
	GF_LIKELV_ADOL,							// アドル			// 他の処理と合わせる為に入れてある。
	GF_LIKELV_LAXIA,						// ラクシャ
	GF_LIKELV_SAHAD,						// サハド
	GF_LIKELV_HUMMEL,						// ヒュンメル
	GF_LIKELV_RICOTTA,						// リコッタ
	GF_LIKELV_DANA,							// ダーナ
	GF_LIKELV_DANACOPY,						// ダーナバックアップコピー
	GF_LIKELV_DANA2,						// ダーナ２
	GF_LIKELV_DANA3,						// ダーナ３
	GF_LIKELV_DANAOLD,						// 過去編ダーナバックアップコピー

	GF_LIKELV_RESERVE10,					// リザーブ10
	GF_LIKELV_RESERVE11,					// リザーブ11
	GF_LIKELV_RESERVE12,					// リザーブ12
	GF_LIKELV_RESERVE13,					// リザーブ13
	GF_LIKELV_RESERVE14,					// リザーブ14
	GF_LIKELV_RESERVE15,					// リザーブ15
	GF_LIKELV_RESERVE16,					// リザーブ16
	GF_LIKELV_RESERVE17,					// リザーブ17
	GF_LIKELV_RESERVE18,					// リザーブ18
	GF_LIKELV_RESERVE19,					// リザーブ19

	GF_LIKELV_MAX,	// 44人

	GF_SHOP_START = 6915,		//ショップ持ちNPCのアイコン用　ゲーム開始直後に立てる
	GF_SHOP_END,				//ショップ持ちNPCのアイコン用　ゲーム中、絶対に立てない

	GF_FAME_POINT,				//名声値

	GF_INTERCEPT_STAGEID,		// 迎撃戦ステージＩＤ（迎撃戦準備中以外は無効）
	GF_INTERCEPT_LEFTTIME,		// 迎撃戦開始までの残り時間
	GF_INTERCEPT_LASTSTAGEID,	// 最後に行った迎撃戦ステージＩＤ（INTERCEPT_STAGE01等）	※迎撃戦終了時に設定する以外では、プログラムでは一切触らないので適宜 INTERCEPT_STAGE_NONE に設定する等して下さい。
	GF_INTERCEPT_LASTRESULT,	// 最後に行った迎撃戦の結果（0:敗北	1:勝利）

	// 
	GF_INTERCEPT_MAX,

	// 迎撃戦、強化情報
	GF_INTERCEPT_BUILDUP_START = 6923,
	// この間のフラグは迎撃戦強化情報に使うので、それ以外で使ってはいけない
	GF_INTERCEPT_BUILDUP_END = 6924,

	GF_MENUSAVE_START = 6925,	// メニューの項目位置保持関連のセーブ用
	GF_MENUSAVE_TAB1 = GF_MENUSAVE_START,// [タブindex]アイテム・日誌／ストーリーのテキスト位置
	GF_MENUSAVE_ITEM_ITEM,		// [項目ID]使用アイテム・所持アイテム
	GF_MENUSAVE_ITEM_DIARY1,	// [項目ID]ストーリー・クエスト
	GF_MENUSAVE_ITEM_DIARY2,	// [項目ID]人物・Aボイス
	GF_MENUSAVE_ITEM_DIARY3,	// [項目ID]料理・釣り
	GF_MENUSAVE_ITEM_DIARY4,	// [項目ID]モンスター・素材
	GF_MENUSAVE_ITEM_DIARY5,	// [項目ID]ヘルプ・最新ストーリーフラグ
	GF_MENUSAVE_SCR_DIARY1,		// [項目位置]ストーリー・クエスト
	GF_MENUSAVE_SCR_DIARY2,		// [項目位置]人物・Aボイス
	GF_MENUSAVE_SCR_DIARY3,		// [項目位置]料理・釣り
	GF_MENUSAVE_SCR_DIARY4,		// [項目位置]モンスター・素材
	GF_MENUSAVE_SCR_DIARY5,		// [項目位置]ヘルプ・(予備)
	GF_MENUSAVE_SCR_ITEM,		// [項目位置]消費・一覧
	GF_MENUSAVE_RESERVE01,

		
	GF_MENUSAVE_END,		// メニューの項目位置保持関連のセーブ用ここまで

	GF_NLTIPS_START = 6940,		// NowLoading時のチップス見たことある保存用
	// この間のフラグはチップス管理に使うので、それ以外では使ってはいけない
	GF_NLTIPS_END = 6949,

	// 旧タイムアタックフラグ（セルセタ時代の物。Ys8では難易度別で補完したいので、ここだとフラグ数が少なすぎたので、ここは使わない。ただし、セーブデータ維持の為、リザーブとして置いてある）
	__GF_TIMEATK_START = 6950,	// タイムアタック用フラグ

	__GF_TIMEATK_B900,			// アダマンティス
	__GF_TIMEATK_B901,			// ドスブレイビー
	__GF_TIMEATK_B000,			// シャコツムリ
	__GF_TIMEATK_B050,			// ヘビドリラー
	__GF_TIMEATK_B001,			// ＬＥＤアンコウ２
	__GF_TIMEATK_B002,			// ダビッドソン
	__GF_TIMEATK_B003,			// ガーディアン１
	__GF_TIMEATK_B0033,			// ガーディアン３
	__GF_TIMEATK_B0042,			// ソル＝ガルヴァ１
	__GF_TIMEATK_B052,			// ゲロコキング
	__GF_TIMEATK_B054,			// ガディス
	__GF_TIMEATK_B053,			// バミー
	__GF_TIMEATK_B004,			// ソル＝ガルヴァ２
	__GF_TIMEATK_B005,			// 心臓ボス
	__GF_TIMEATK_B006,			// 黒エルディール
	__GF_TIMEATK_B055,			// 青銅の中ボス
	__GF_TIMEATK_B056,			// 白銀の中ボス
	__GF_TIMEATK_B057,			// 黄金の中ボス

	GF_TIMEATK_MENUCONTROL,		// タイムアタックメニュー制御用
	GF_TIMEATK_CTFLAG,			// 現在のベストスコアを保存すべきフラグ番号
	GF_TIMEATK_GAMERANK,		// 現在選択中の難易度 (ETIMEATK_GAMERANK)
	GF_TIMEATK_STAGENO,			// 現在選択中のステージＩＤ

	GF_TIMEATK_RETRY,			// ボスラッシュリトライ回数
	GF_TIMEATK_GAMEMODE,		// 現在選択中のタイムアタックモード (ETIMEATK_GAMEMODE)

	// 以下、レコード、トロフィー用
	GF_LASTMAXMONEY,			// 過去最大所持ＧＯＬＤ
	GF_TOTALMOVE,				// 総移動距離
	GF_FLASHGUARDCT,			// フラッシュガード回数
	GF_FLASHMOVECT,				// フラッシュムーブ回数
	GF_BREAKCT,					// ブレイク回数
	GF_SKILLFINISHCT,			// スキルフィニッシュ回数
	GF_EXTRASKILLCT,			// エクストラスキル使用回数

	GF_ADOLPLAYTIME,			// アドルプレイ時間
	GF_LAXIAPLAYTIME,			// ラクシャプレイ時間
	GF_SAHADPLAYTIME,			// サハドプレイ時間
	GF_HUMMELPLAYTIME,			// ヒュンメルプレイ時間
	GF_RICOTTAPLAYTIME,			// リコッタプレイ時間
	GF_DANAPLAYTIME,			// ダーナプレイ時間
	GF_DANACOPYPLAYTIME,		// （使わない）ダーナバックアップコピープレイ時間
	GF_DANA2PLAYTIME,			// （使わない）ダーナ２プレイ時間
	GF_DANA3PLAYTIME,			// （使わない）ダーナ３プレイ時間
	GF_DANAOLDPLAYTIME,			// （使わない）過去編ダーナバックアップコピープレイ時間

	GF_RESERVE10PLAYTIME,		// 
	GF_RESERVE11PLAYTIME,		// 
	GF_RESERVE12PLAYTIME,		// 
	GF_RESERVE13PLAYTIME,		// 
	GF_RESERVE14PLAYTIME,		// 
	GF_RESERVE15PLAYTIME,		// 
	GF_RESERVE16PLAYTIME,		// 
	GF_RESERVE17PLAYTIME,		// 
	GF_RESERVE18PLAYTIME,		// 
	GF_RESERVE19PLAYTIME,		// 

	GF_TIMEATK_NODMG,			// タイムアタックノーダメージチェック

//-------------------------------------------------------------------------------
//■ Tips 手帳で表示して良いかフラグ
	GF_TIPS_NOTE_START	= 7100,
	GF_TIPS_NOTE_S00_01	= GF_TIPS_NOTE_START,
	GF_TIPS_NOTE_S00_02,
	GF_TIPS_NOTE_S00_03,
	GF_TIPS_NOTE_S00_04,
	GF_TIPS_NOTE_S01_01,
	GF_TIPS_NOTE_S01_02,
	GF_TIPS_NOTE_S01_03,
	GF_TIPS_NOTE_S01_04,
	GF_TIPS_NOTE_S01_05,
	GF_TIPS_NOTE_S01_06,
	GF_TIPS_NOTE_S01_07,
	GF_TIPS_NOTE_S01_08,
	GF_TIPS_NOTE_S01_09,
	GF_TIPS_NOTE_S02_01,
	GF_TIPS_NOTE_S02_02,
	GF_TIPS_NOTE_S02_03,
	GF_TIPS_NOTE_S02_04,
	GF_TIPS_NOTE_S02_05,
	GF_TIPS_NOTE_S02_06,
	GF_TIPS_NOTE_S02_07,
	GF_TIPS_NOTE_S02_08,
	GF_TIPS_NOTE_S02_09,
	GF_TIPS_NOTE_S02_10,
	GF_TIPS_NOTE_S02_11,
	GF_TIPS_NOTE_S02_12,
	GF_TIPS_NOTE_S02_13,
	GF_TIPS_NOTE_S02_14,
	GF_TIPS_NOTE_S02_15,
	GF_TIPS_NOTE_S02_16,
	GF_TIPS_NOTE_S02_17,
	GF_TIPS_NOTE_S02_18,
	GF_TIPS_NOTE_S02_19,
	GF_TIPS_NOTE_S02_20,
	GF_TIPS_NOTE_S02_21,
	GF_TIPS_NOTE_S03_01,
	GF_TIPS_NOTE_S03_02,
	GF_TIPS_NOTE_S03_03,
	GF_TIPS_NOTE_S03_04,
	GF_TIPS_NOTE_S03_05,
	GF_TIPS_NOTE_S03_06,
	GF_TIPS_NOTE_S03_07,
	GF_TIPS_NOTE_S03_08,
	GF_TIPS_NOTE_S03_09,
	GF_TIPS_NOTE_S03_10,
	GF_TIPS_NOTE_S03_11,
	GF_TIPS_NOTE_S03_12,
	GF_TIPS_NOTE_S03_13,
	GF_TIPS_NOTE_S04_01,
	GF_TIPS_NOTE_S04_02,
	GF_TIPS_NOTE_S04_03,
	GF_TIPS_NOTE_S04_04,
	GF_TIPS_NOTE_S04_05,
	GF_TIPS_NOTE_S04_06,
	GF_TIPS_NOTE_S04_07,
	GF_TIPS_NOTE_S04_08,
	GF_TIPS_NOTE_S04_09,
	GF_TIPS_NOTE_S04_10,
	GF_TIPS_NOTE_S04_11,
	GF_TIPS_NOTE_S04_12,
	GF_TIPS_NOTE_S04_13,
	GF_TIPS_NOTE_S04_14,
	GF_TIPS_NOTE_S04_15,
	GF_TIPS_NOTE_S04_16,
	GF_TIPS_NOTE_S05_01,
	GF_TIPS_NOTE_S05_02,
	GF_TIPS_NOTE_S05_03,
	GF_TIPS_NOTE_S05_04,
	GF_TIPS_NOTE_S05_05,
	GF_TIPS_NOTE_S05_06,
	GF_TIPS_NOTE_S05_07,
	GF_TIPS_NOTE_S05_08,
	GF_TIPS_NOTE_S05_09,
	GF_TIPS_NOTE_S05_10,
	GF_TIPS_NOTE_S05_11,
	GF_TIPS_NOTE_S05_12,
	GF_TIPS_NOTE_S05_13,
	GF_TIPS_NOTE_S05_14,
	GF_TIPS_NOTE_S05_15,
	GF_TIPS_NOTE_S05_16,
	GF_TIPS_NOTE_S05_17,
	GF_TIPS_NOTE_S05_18,
	GF_TIPS_NOTE_S05_19,
	GF_TIPS_NOTE_S05_20,
	GF_TIPS_NOTE_S05_21,
	GF_TIPS_NOTE_S05_22,
	GF_TIPS_NOTE_S05_23,
	GF_TIPS_NOTE_S05_24,
	GF_TIPS_NOTE_S05_25,
	GF_TIPS_NOTE_S05_26,
	GF_TIPS_NOTE_S05_27,
	GF_TIPS_NOTE_S05_28,
	GF_TIPS_NOTE_S05_29,
	GF_TIPS_NOTE_S05_30,
	GF_TIPS_NOTE_S05_31,
	GF_TIPS_NOTE_S05_32,
	GF_TIPS_NOTE_S05_33,
	GF_TIPS_NOTE_S05_34,
	GF_TIPS_NOTE_S05_35,
	GF_TIPS_NOTE_S06_01,
	GF_TIPS_NOTE_S06_02,
	GF_TIPS_NOTE_S06_03,
	GF_TIPS_NOTE_S06_04,
	GF_TIPS_NOTE_S06_05,
	GF_TIPS_NOTE_S06_06,
	GF_TIPS_NOTE_S06_07,
	GF_TIPS_NOTE_S06_08,
	GF_TIPS_NOTE_S06_09,
	GF_TIPS_NOTE_S06_10,
	GF_TIPS_NOTE_S06_11,
	GF_TIPS_NOTE_S06_12,
	GF_TIPS_NOTE_S06_13,
	GF_TIPS_NOTE_S06_14,
	GF_TIPS_NOTE_S06_15,
	GF_TIPS_NOTE_S06_16,
	GF_TIPS_NOTE_S06_17,
	GF_TIPS_NOTE_S06_18,
	GF_TIPS_NOTE_S06_19,
	GF_TIPS_NOTE_S06_20,
	GF_TIPS_NOTE_S06_21,
	GF_TIPS_NOTE_S06_22,
	GF_TIPS_NOTE_S06_23,
	GF_TIPS_NOTE_S06_24,
	GF_TIPS_NOTE_S06_25,
	GF_TIPS_NOTE_S06_26,
	GF_TIPS_NOTE_S06_27,
	GF_TIPS_NOTE_S06_28,
	GF_TIPS_NOTE_S07_01,
	GF_TIPS_NOTE_S07_02,
	GF_TIPS_NOTE_S07_03,
	GF_TIPS_NOTE_S07_04,
	GF_TIPS_NOTE_S07_05,
	GF_TIPS_NOTE_S07_06,
	GF_TIPS_NOTE_S07_07,
	GF_TIPS_NOTE_S07_08,
	GF_TIPS_NOTE_S07_09,
	GF_TIPS_NOTE_S07_10,
	GF_TIPS_NOTE_S07_11,
	GF_TIPS_NOTE_S07_12,
	GF_TIPS_NOTE_S07_13,

	GF_TIPS_NOTE_H00_01,
	GF_TIPS_NOTE_H00_02,
	GF_TIPS_NOTE_H01_01,
	GF_TIPS_NOTE_H01_02,
	GF_TIPS_NOTE_H01_03,
	GF_TIPS_NOTE_H01_04,
	GF_TIPS_NOTE_H01_05,
	GF_TIPS_NOTE_H01_06,
	GF_TIPS_NOTE_H01_07,
	GF_TIPS_NOTE_H01_08,
	GF_TIPS_NOTE_H01_09,
	GF_TIPS_NOTE_H01_10,
	GF_TIPS_NOTE_H02_01,
	GF_TIPS_NOTE_H02_02,
	GF_TIPS_NOTE_H02_03,
	GF_TIPS_NOTE_H02_04,
	GF_TIPS_NOTE_H02_05,
	GF_TIPS_NOTE_H02_06,
	GF_TIPS_NOTE_H02_07,
	GF_TIPS_NOTE_H02_08,
	GF_TIPS_NOTE_H02_09,
	GF_TIPS_NOTE_H02_10,
	GF_TIPS_NOTE_H02_11,
	GF_TIPS_NOTE_H02_12,
	GF_TIPS_NOTE_H02_13,
	GF_TIPS_NOTE_H02_14,
	GF_TIPS_NOTE_H02_15,
	GF_TIPS_NOTE_H02_16,
	GF_TIPS_NOTE_H02_17,
	GF_TIPS_NOTE_H04_01,
	GF_TIPS_NOTE_H09_01,
	GF_TIPS_NOTE_H09_02,
	GF_TIPS_NOTE_H09_03,
	GF_TIPS_NOTE_H09_04,
	GF_TIPS_NOTE_H09_05,
	GF_TIPS_NOTE_H09_06,

	GF_TIPS_NOTE_H02_18,
	GF_TIPS_NOTE_H02_19,
	GF_TIPS_NOTE_H02_20,
	GF_TIPS_NOTE_H02_21,
	GF_TIPS_NOTE_H04_02,
	GF_TIPS_NOTE_H01_11,
	GF_TIPS_NOTE_H02_22,
	GF_TIPS_NOTE_H01_12,
	GF_TIPS_NOTE_H02_23,

	GF_TIPS_NOTE_H05_01,
	GF_TIPS_NOTE_H02_24,
	GF_TIPS_NOTE_H02_25,
	GF_TIPS_NOTE_H01_13,
	GF_TIPS_NOTE_H02_26,

	GF_TIPS_NOTE_END	= 7400,

//-------------------------------------------------------------------------------
//■ トロフィー関連フラグ

	// 過去編ダンジョン踏破率
	GF_TROPHY_ETERNIADUNGEON_START,
	GF_TROPHY_ETERNIADUNGEON_01,
	GF_TROPHY_ETERNIADUNGEON_02,
	GF_TROPHY_ETERNIADUNGEON_03,
	GF_TROPHY_ETERNIADUNGEON_04,
	GF_TROPHY_ETERNIADUNGEON_05,
	GF_TROPHY_ETERNIADUNGEON_06,
	GF_TROPHY_ETERNIADUNGEON_END,

	// 過去編精霊救出率
	GF_TROPHY_ETERNIASPIRIT_START,
	GF_TROPHY_ETERNIASPIRIT_01,
	GF_TROPHY_ETERNIASPIRIT_02,
	GF_TROPHY_ETERNIASPIRIT_03,
	GF_TROPHY_ETERNIASPIRIT_04,
	GF_TROPHY_ETERNIASPIRIT_05,
	GF_TROPHY_ETERNIASPIRIT_06,
	GF_TROPHY_ETERNIASPIRIT_07,
	GF_TROPHY_ETERNIASPIRIT_08,
	GF_TROPHY_ETERNIASPIRIT_09,
	GF_TROPHY_ETERNIASPIRIT_10,
	GF_TROPHY_ETERNIASPIRIT_END,

//-------------------------------------------------------------------------------
	GF_DUMMY_ZERO = 8099,		// ダミー判定用フラグ（必ず０が入っている事が保証されているフラグとして利用）
//■ タイムアタック用------------------------------------------------------------------
	GF_TIMEATK_START = 8100,	// 250個予約	（人数別×ボス数×難易度）
								//	▼通常
								//		人数	　３	（１人／２人／３人）
								//		ボス数	４０	（３３種＋ボスラッシュ＋リザーブｘ６）
								//		難易度	　５
								//	------------------
								//		合計	 600
								//
								//	▼ダーナ編
								//		人数	　１	（ダーナのみ）
								//		ボス数	１０	（７種＋ボスラッシュ＋リザーブｘ２）
								//		難易度	　５
								//	------------------
								//		合計	  50
								//
								//	▼現代編ボス別タイムアタックメンバー保存用（5bitで管理。３人モード15bit	２人モード10bit １人モード5bit 計30bit）
								//		ボス数	４０
								//		難易度	　５
								//	------------------
								//		合計	 200
			
								//	フラグ850は必要

	// ＊最上位ビットが立っていると、更新した表示になる
	// ＊メニュー閉じる時に最上位ビットは全て降りる。

	// 現代編3人

		// EASY3人用
	GF_TIMEATK_EASY_ST = GF_TIMEATK_START,
	GF_TIMEATK_EASY_M0111 = GF_TIMEATK_EASY_ST,	// イージー00、１部、ビフテリザ
	GF_TIMEATK_EASY_B150,	// イージー01、１部、アヴァロドラギル
	GF_TIMEATK_EASY_B100,	// イージー02、２部、セルペンタス
	GF_TIMEATK_EASY_B000,	// イージー03、２部、クラリオン
	GF_TIMEATK_EASY_B101B,	// イージー04、２部、ロンブリゲウス
	GF_TIMEATK_EASY_B001,	// イージー05、２部、グルガンチュラ
	GF_TIMEATK_EASY_B102,	// イージー06、２部、マガマンドラ
	GF_TIMEATK_EASY_B002,	// イージー07、２部、ラスピスース
	GF_TIMEATK_EASY_B152,	// イージー08、２部、キルゴール
	GF_TIMEATK_EASY_B154,	// イージー09、３部、アヴァロドラギル
	GF_TIMEATK_EASY_B003,	// イージー10、３部、ギアスバーン
	GF_TIMEATK_EASY_B006,	// イージー11、４部、ブラキオン
	GF_TIMEATK_EASY_B104,	// イージー12、５部、エクスメーテル
	GF_TIMEATK_EASY_B004,	// イージー13、５部、カルヴェロス
	GF_TIMEATK_EASY_B103,	// イージー14、５部、ピラティスアニマ
	GF_TIMEATK_EASY_B106,	// イージー15、５部、シエラカントゥス
	GF_TIMEATK_EASY_B007,	// イージー16、５部、オケアノス
	GF_TIMEATK_EASY_B105,	// イージー17、５部、ドクサ・グリエル
	GF_TIMEATK_EASY_B005,	// イージー18、５部、バシレウス
	GF_TIMEATK_EASY_B012,	// イージー19、６部、レ・エリュトロン
	GF_TIMEATK_EASY_B112,	// イージー20、６部、アニムス・ヒドゥラ
	GF_TIMEATK_EASY_B110,	// イージー21、６部、アニムス・ミノス
	GF_TIMEATK_EASY_B111,	// イージー22、６部、アニムス・ネストール
	GF_TIMEATK_EASY_B008,	// イージー23、６部、アニムス・ウーラ
	GF_TIMEATK_EASY_B021_1,	// イージー24、６部、テオス・デ・エンドログラム１
	GF_TIMEATK_EASY_B021_2,	// イージー25、６部、テオス・デ・エンドログラム２
	GF_TIMEATK_EASY_B021_3,	// イージー26、６部、テオス・デ・エンドログラム３
	GF_TIMEATK_EASY_B009,	// イージー28、７部、はじまりの命・子
	GF_TIMEATK_EASY_B010,	// イージー28、７部、はじまりの命・親
	GF_TIMEATK_EASY_B155,	// イージー29、シルヴィア
	GF_TIMEATK_EASY_B151,	// イージー30、マスターコング
	GF_TIMEATK_EASY_B153,	// イージー31、６部、メフォラシュム
	GF_TIMEATK_EASY_B170,	// イージー32、６部、◆仮名：２週目ダンジョンボス
	__GF_TIMEATK_EASY_RSV33,// イージー34、リザーブ33
	__GF_TIMEATK_EASY_RSV34,// イージー34、リザーブ34
	__GF_TIMEATK_EASY_RSV35,// イージー35、リザーブ35
	__GF_TIMEATK_EASY_RSV36,// イージー36、リザーブ36
	__GF_TIMEATK_EASY_RSV37,// イージー37、リザーブ37
	__GF_TIMEATK_EASY_RSV38,// イージー38、リザーブ38
	GF_TIMEATK_EASY_RUSH,	// イージー39、ボスラッシュ

	GF_TIMEATK_EASY_ED,

		// NORMAL3人用
	GF_TIMEATK_NORMAL_ST = GF_TIMEATK_EASY_ED,
	GF_TIMEATK_NORMAL_M0111 = GF_TIMEATK_NORMAL_ST,	// ノーマル00、１部、ビフテリザ
	GF_TIMEATK_NORMAL_B150,		// ノーマル01、１部、アヴァロドラギル
	GF_TIMEATK_NORMAL_B100,		// ノーマル02、２部、セルペンタス
	GF_TIMEATK_NORMAL_B000,		// ノーマル03、２部、クラリオン
	GF_TIMEATK_NORMAL_B101B,	// ノーマル04、２部、ロンブリゲウス
	GF_TIMEATK_NORMAL_B001,		// ノーマル05、２部、グルガンチュラ
	GF_TIMEATK_NORMAL_B102,		// ノーマル06、２部、マガマンドラ
	GF_TIMEATK_NORMAL_B002,		// ノーマル07、２部、ラスピスース
	GF_TIMEATK_NORMAL_B152,		// ノーマル08、２部、キルゴール
	GF_TIMEATK_NORMAL_B154,		// ノーマル09、３部、アヴァロドラギル
	GF_TIMEATK_NORMAL_B003,		// ノーマル10、３部、ギアスバーン
	GF_TIMEATK_NORMAL_B006,		// ノーマル11、４部、ブラキオン
	GF_TIMEATK_NORMAL_B104,		// ノーマル12、５部、エクスメーテル
	GF_TIMEATK_NORMAL_B004,		// ノーマル13、５部、カルヴェロス
	GF_TIMEATK_NORMAL_B103,		// ノーマル14、５部、ピラティスアニマ
	GF_TIMEATK_NORMAL_B106,		// ノーマル15、５部、シエラカントゥス
	GF_TIMEATK_NORMAL_B007,		// ノーマル16、５部、オケアノス
	GF_TIMEATK_NORMAL_B105,		// ノーマル17、５部、ドクサ・グリエル
	GF_TIMEATK_NORMAL_B005,		// ノーマル18、５部、バシレウス
	GF_TIMEATK_NORMAL_B012,		// ノーマル19、６部、レ・エリュトロン
	GF_TIMEATK_NORMAL_B112,		// ノーマル20、６部、アニムス・ヒドゥラ
	GF_TIMEATK_NORMAL_B110,		// ノーマル21、６部、アニムス・ミノス
	GF_TIMEATK_NORMAL_B111,		// ノーマル22、６部、アニムス・ネストール
	GF_TIMEATK_NORMAL_B008,		// ノーマル23、６部、アニムス・ウーラ
	GF_TIMEATK_NORMAL_B021_1,	// ノーマル24、６部、テオス・デ・エンドログラム１
	GF_TIMEATK_NORMAL_B021_2,	// ノーマル25、６部、テオス・デ・エンドログラム２
	GF_TIMEATK_NORMAL_B021_3,	// ノーマル26、６部、テオス・デ・エンドログラム３
	GF_TIMEATK_NORMAL_B009,		// ノーマル27、７部、はじまりの命・子
	GF_TIMEATK_NORMAL_B010,		// ノーマル28、７部、はじまりの命・親
	GF_TIMEATK_NORMAL_B155,		// ノーマル29、シルヴィア
	GF_TIMEATK_NORMAL_B151,		// ノーマル30、マスターコング
	GF_TIMEATK_NORMAL_B153,		// ノーマル31、６部、メフォラシュム
	GF_TIMEATK_NORMAL_B170,	// ノーマル32、６部、◆仮名：２週目ダンジョンボス
	__GF_TIMEATK_NORMAL_RSV33,	// ノーマル34、リザーブ33
	__GF_TIMEATK_NORMAL_RSV34,	// ノーマル34、リザーブ34
	__GF_TIMEATK_NORMAL_RSV35,	// ノーマル35、リザーブ35
	__GF_TIMEATK_NORMAL_RSV36,	// ノーマル36、リザーブ36
	__GF_TIMEATK_NORMAL_RSV37,	// ノーマル37、リザーブ37
	__GF_TIMEATK_NORMAL_RSV38,	// ノーマル38、リザーブ38
	GF_TIMEATK_NORMAL_RUSH,		// ノーマル39、ボスラッシュ

	GF_TIMEATK_NORMAL_ED,

		// HARD3人用
	GF_TIMEATK_HARD_ST = GF_TIMEATK_NORMAL_ED,
	GF_TIMEATK_HARD_M0111 = GF_TIMEATK_HARD_ST,		// ハード00、１部、ビフテリザ
	GF_TIMEATK_HARD_B150,		// ハード01、１部、アヴァロドラギル
	GF_TIMEATK_HARD_B100,		// ハード02、２部、セルペンタス
	GF_TIMEATK_HARD_B000,		// ハード03、２部、クラリオン
	GF_TIMEATK_HARD_B101B,		// ハード04、２部、ロンブリゲウス
	GF_TIMEATK_HARD_B001,		// ハード05、２部、グルガンチュラ
	GF_TIMEATK_HARD_B102,		// ハード06、２部、マガマンドラ
	GF_TIMEATK_HARD_B002,		// ハード07、２部、ラスピスース
	GF_TIMEATK_HARD_B152,		// ハード08、２部、キルゴール
	GF_TIMEATK_HARD_B154,		// ハード09、３部、アヴァロドラギル
	GF_TIMEATK_HARD_B003,		// ハード10、３部、ギアスバーン
	GF_TIMEATK_HARD_B006,		// ハード11、４部、ブラキオン
	GF_TIMEATK_HARD_B104,		// ハード12、５部、エクスメーテル
	GF_TIMEATK_HARD_B004,		// ハード13、５部、カルヴェロス
	GF_TIMEATK_HARD_B103,		// ハード14、５部、ピラティスアニマ
	GF_TIMEATK_HARD_B106,		// ハード15、５部、シエラカントゥス
	GF_TIMEATK_HARD_B007,		// ハード16、５部、オケアノス
	GF_TIMEATK_HARD_B105,		// ハード17、５部、ドクサ・グリエル
	GF_TIMEATK_HARD_B005,		// ハード18、５部、バシレウス
	GF_TIMEATK_HARD_B012,		// ハード19、６部、レ・エリュトロン
	GF_TIMEATK_HARD_B112,		// ハード20、６部、アニムス・ヒドゥラ
	GF_TIMEATK_HARD_B110,		// ハード21、６部、アニムス・ミノス
	GF_TIMEATK_HARD_B111,		// ハード22、６部、アニムス・ネストール
	GF_TIMEATK_HARD_B008,		// ハード23、６部、アニムス・ウーラ
	GF_TIMEATK_HARD_B021_1,		// ハード24、６部、テオス・デ・エンドログラム１
	GF_TIMEATK_HARD_B021_2,		// ハード25、６部、テオス・デ・エンドログラム２
	GF_TIMEATK_HARD_B021_3,		// ハード26、６部、テオス・デ・エンドログラム３
	GF_TIMEATK_HARD_B009,		// ハード27、７部、はじまりの命・子
	GF_TIMEATK_HARD_B010,		// ハード28、７部、はじまりの命・親
	GF_TIMEATK_HARD_B155,		// ハード29、シルヴィア
	GF_TIMEATK_HARD_B151,		// ハード30、マスターコング
	GF_TIMEATK_HARD_B153,		// ハード31、６部、メフォラシュム
	GF_TIMEATK_HARD_B170,		// ハード32、６部、◆仮名：２週目ダンジョンボス
	__GF_TIMEATK_HARD_RSV33,	// ハード33、リザーブ33
	__GF_TIMEATK_HARD_RSV34,	// ハード34、リザーブ34
	__GF_TIMEATK_HARD_RSV35,	// ハード35、リザーブ35
	__GF_TIMEATK_HARD_RSV36,	// ハード36、リザーブ36
	__GF_TIMEATK_HARD_RSV37,	// ハード37、リザーブ37
	__GF_TIMEATK_HARD_RSV38,	// ハード38、リザーブ38
	GF_TIMEATK_HARD_RUSH,		// ハード39、ボスラッシュ

	GF_TIMEATK_HARD_ED,

		// NIGHTMARE3人用
	GF_TIMEATK_NIGHTMARE_ST = GF_TIMEATK_HARD_ED,
	GF_TIMEATK_NIGHTMARE_M0111 = GF_TIMEATK_NIGHTMARE_ST,	// ナイトメア00、１部、ビフテリザ
	GF_TIMEATK_NIGHTMARE_B150,		// ナイトメア01、１部、アヴァロドラギル
	GF_TIMEATK_NIGHTMARE_B100,		// ナイトメア02、２部、セルペンタス
	GF_TIMEATK_NIGHTMARE_B000,		// ナイトメア03、２部、クラリオン
	GF_TIMEATK_NIGHTMARE_B101B,		// ナイトメア04、２部、ロンブリゲウス
	GF_TIMEATK_NIGHTMARE_B001,		// ナイトメア05、２部、グルガンチュラ
	GF_TIMEATK_NIGHTMARE_B102,		// ナイトメア06、２部、マガマンドラ
	GF_TIMEATK_NIGHTMARE_B002,		// ナイトメア07、２部、ラスピスース
	GF_TIMEATK_NIGHTMARE_B152,		// ナイトメア08、２部、キルゴール
	GF_TIMEATK_NIGHTMARE_B154,		// ナイトメア09、３部、アヴァロドラギル
	GF_TIMEATK_NIGHTMARE_B003,		// ナイトメア10、３部、ギアスバーン
	GF_TIMEATK_NIGHTMARE_B006,		// ナイトメア11、４部、ブラキオン
	GF_TIMEATK_NIGHTMARE_B104,		// ナイトメア12、５部、エクスメーテル
	GF_TIMEATK_NIGHTMARE_B004,		// ナイトメア13、５部、カルヴェロス
	GF_TIMEATK_NIGHTMARE_B103,		// ナイトメア14、５部、ピラティスアニマ
	GF_TIMEATK_NIGHTMARE_B106,		// ナイトメア15、５部、シエラカントゥス
	GF_TIMEATK_NIGHTMARE_B007,		// ナイトメア16、５部、オケアノス
	GF_TIMEATK_NIGHTMARE_B105,		// ナイトメア17、５部、ドクサ・グリエル
	GF_TIMEATK_NIGHTMARE_B005,		// ナイトメア18、５部、バシレウス
	GF_TIMEATK_NIGHTMARE_B012,		// ナイトメア19、６部、レ・エリュトロン
	GF_TIMEATK_NIGHTMARE_B112,		// ナイトメア20、６部、アニムス・ヒドゥラ
	GF_TIMEATK_NIGHTMARE_B110,		// ナイトメア21、６部、アニムス・ミノス
	GF_TIMEATK_NIGHTMARE_B111,		// ナイトメア22、６部、アニムス・ネストール
	GF_TIMEATK_NIGHTMARE_B008,		// ナイトメア23、６部、アニムス・ウーラ
	GF_TIMEATK_NIGHTMARE_B021_1,	// ナイトメア24、６部、テオス・デ・エンドログラム１
	GF_TIMEATK_NIGHTMARE_B021_2,	// ナイトメア25、６部、テオス・デ・エンドログラム２
	GF_TIMEATK_NIGHTMARE_B021_3,	// ナイトメア26、６部、テオス・デ・エンドログラム３
	GF_TIMEATK_NIGHTMARE_B009,		// ナイトメア27、７部、はじまりの命・子
	GF_TIMEATK_NIGHTMARE_B010,		// ナイトメア28、７部、はじまりの命・親
	GF_TIMEATK_NIGHTMARE_B155,		// ナイトメア29、シルヴィア
	GF_TIMEATK_NIGHTMARE_B151,		// ナイトメア30、マスターコング
	GF_TIMEATK_NIGHTMARE_B153,		// ナイトメア31、６部、メフォラシュム
	GF_TIMEATK_NIGHTMARE_B170,		// ナイトメア32、６部、◆仮名：２週目ダンジョンボス
	__GF_TIMEATK_NIGHTMARE_RSV33,	// ナイトメア33、リザーブ33
	__GF_TIMEATK_NIGHTMARE_RSV34,	// ナイトメア34、リザーブ34
	__GF_TIMEATK_NIGHTMARE_RSV35,	// ナイトメア35、リザーブ35
	__GF_TIMEATK_NIGHTMARE_RSV36,	// ナイトメア36、リザーブ36
	__GF_TIMEATK_NIGHTMARE_RSV37,	// ナイトメア37、リザーブ37
	__GF_TIMEATK_NIGHTMARE_RSV38,	// ナイトメア38、リザーブ38
	GF_TIMEATK_NIGHTMARE_RUSH,		// ナイトメア39、ボスラッシュ

	GF_TIMEATK_NIGHTMARE_ED,

		// INFERNO3人用
	GF_TIMEATK_INFERNO_ST = GF_TIMEATK_NIGHTMARE_ED,
	GF_TIMEATK_INFERNO_M0111 = GF_TIMEATK_INFERNO_ST,	// インフェルノ00、１部、ビフテリザ
	GF_TIMEATK_INFERNO_B150,		// インフェルノ01、１部、アヴァロドラギル
	GF_TIMEATK_INFERNO_B100,		// インフェルノ02、２部、セルペンタス
	GF_TIMEATK_INFERNO_B000,		// インフェルノ03、２部、クラリオン
	GF_TIMEATK_INFERNO_B101B,		// インフェルノ04、２部、ロンブリゲウス
	GF_TIMEATK_INFERNO_B001,		// インフェルノ05、２部、グルガンチュラ
	GF_TIMEATK_INFERNO_B102,		// インフェルノ06、２部、マガマンドラ
	GF_TIMEATK_INFERNO_B002,		// インフェルノ07、２部、ラスピスース
	GF_TIMEATK_INFERNO_B152,		// インフェルノ08、２部、キルゴール
	GF_TIMEATK_INFERNO_B154,		// インフェルノ09、３部、アヴァロドラギル
	GF_TIMEATK_INFERNO_B003,		// インフェルノ10、３部、ギアスバーン
	GF_TIMEATK_INFERNO_B006,		// インフェルノ11、４部、ブラキオン
	GF_TIMEATK_INFERNO_B104,		// インフェルノ12、５部、エクスメーテル
	GF_TIMEATK_INFERNO_B004,		// インフェルノ13、５部、カルヴェロス
	GF_TIMEATK_INFERNO_B103,		// インフェルノ14、５部、ピラティスアニマ
	GF_TIMEATK_INFERNO_B106,		// インフェルノ15、５部、シエラカントゥス
	GF_TIMEATK_INFERNO_B007,		// インフェルノ16、５部、オケアノス
	GF_TIMEATK_INFERNO_B105,		// インフェルノ17、５部、ドクサ・グリエル
	GF_TIMEATK_INFERNO_B005,		// インフェルノ18、５部、バシレウス
	GF_TIMEATK_INFERNO_B012,		// インフェルノ19、６部、レ・エリュトロン
	GF_TIMEATK_INFERNO_B112,		// インフェルノ20、６部、アニムス・ヒドゥラ
	GF_TIMEATK_INFERNO_B110,		// インフェルノ21、６部、アニムス・ミノス
	GF_TIMEATK_INFERNO_B111,		// インフェルノ22、６部、アニムス・ネストール
	GF_TIMEATK_INFERNO_B008,		// インフェルノ23、６部、アニムス・ウーラ
	GF_TIMEATK_INFERNO_B021_1,		// インフェルノ24、６部、テオス・デ・エンドログラム１
	GF_TIMEATK_INFERNO_B021_2,		// インフェルノ25、６部、テオス・デ・エンドログラム２
	GF_TIMEATK_INFERNO_B021_3,		// インフェルノ26、６部、テオス・デ・エンドログラム３
	GF_TIMEATK_INFERNO_B009,		// インフェルノ27、７部、はじまりの命・子
	GF_TIMEATK_INFERNO_B010,		// インフェルノ28、７部、はじまりの命・親
	GF_TIMEATK_INFERNO_B155,		// インフェルノ29、シルヴィア
	GF_TIMEATK_INFERNO_B151,		// インフェルノ30、マスターコング
	GF_TIMEATK_INFERNO_B153,		// インフェルノ31、６部、メフォラシュム
	GF_TIMEATK_INFERNO_B170,		// インフェルノ32、６部、◆仮名：２週目ダンジョンボス
	__GF_TIMEATK_INFERNO_RSV33,		// インフェルノ33、リザーブ33
	__GF_TIMEATK_INFERNO_RSV34,		// インフェルノ34、リザーブ34
	__GF_TIMEATK_INFERNO_RSV35,		// インフェルノ35、リザーブ35
	__GF_TIMEATK_INFERNO_RSV36,		// インフェルノ36、リザーブ36
	__GF_TIMEATK_INFERNO_RSV37,		// インフェルノ37、リザーブ37
	__GF_TIMEATK_INFERNO_RSV38,		// インフェルノ38、リザーブ38
	GF_TIMEATK_INFERNO_RUSH,		// インフェルノ39、ボスラッシュ

	GF_TIMEATK_INFERNO_ED,

	// 現代編2人

		// EASY2人用
	GF_TIMEATK_2_EASY_ST = GF_TIMEATK_INFERNO_ED,
	GF_TIMEATK_2_EASY_M0111 = GF_TIMEATK_2_EASY_ST,	// イージー00、１部、ビフテリザ
	GF_TIMEATK_2_EASY_B150,	// イージー01、１部、アヴァロドラギル
	GF_TIMEATK_2_EASY_B100,	// イージー02、２部、セルペンタス
	GF_TIMEATK_2_EASY_B000,	// イージー03、２部、クラリオン
	GF_TIMEATK_2_EASY_B101B,	// イージー04、２部、ロンブリゲウス
	GF_TIMEATK_2_EASY_B001,	// イージー05、２部、グルガンチュラ
	GF_TIMEATK_2_EASY_B102,	// イージー06、２部、マガマンドラ
	GF_TIMEATK_2_EASY_B002,	// イージー07、２部、ラスピスース
	GF_TIMEATK_2_EASY_B152,	// イージー08、２部、キルゴール
	GF_TIMEATK_2_EASY_B154,	// イージー09、３部、アヴァロドラギル
	GF_TIMEATK_2_EASY_B003,	// イージー10、３部、ギアスバーン
	GF_TIMEATK_2_EASY_B006,	// イージー11、４部、ブラキオン
	GF_TIMEATK_2_EASY_B104,	// イージー12、５部、エクスメーテル
	GF_TIMEATK_2_EASY_B004,	// イージー13、５部、カルヴェロス
	GF_TIMEATK_2_EASY_B103,	// イージー14、５部、ピラティスアニマ
	GF_TIMEATK_2_EASY_B106,	// イージー15、５部、シエラカントゥス
	GF_TIMEATK_2_EASY_B007,	// イージー16、５部、オケアノス
	GF_TIMEATK_2_EASY_B105,	// イージー17、５部、ドクサ・グリエル
	GF_TIMEATK_2_EASY_B005,	// イージー18、５部、バシレウス
	GF_TIMEATK_2_EASY_B012,	// イージー19、６部、レ・エリュトロン
	GF_TIMEATK_2_EASY_B112,	// イージー20、６部、アニムス・ヒドゥラ
	GF_TIMEATK_2_EASY_B110,	// イージー21、６部、アニムス・ミノス
	GF_TIMEATK_2_EASY_B111,	// イージー22、６部、アニムス・ネストール
	GF_TIMEATK_2_EASY_B008,	// イージー23、６部、アニムス・ウーラ
	GF_TIMEATK_2_EASY_B021_1,	// イージー24、６部、テオス・デ・エンドログラム１
	GF_TIMEATK_2_EASY_B021_2,	// イージー25、６部、テオス・デ・エンドログラム２
	GF_TIMEATK_2_EASY_B021_3,	// イージー26、６部、テオス・デ・エンドログラム３
	GF_TIMEATK_2_EASY_B009,	// イージー28、７部、はじまりの命・子
	GF_TIMEATK_2_EASY_B010,	// イージー28、７部、はじまりの命・親
	GF_TIMEATK_2_EASY_B155,	// イージー29、シルヴィア
	GF_TIMEATK_2_EASY_B151,	// イージー30、マスターコング
	GF_TIMEATK_2_EASY_B153,	// イージー31、６部、メフォラシュム
	GF_TIMEATK_2_EASY_B170,	// イージー32、６部、◆仮名：２週目ダンジョンボス
	__GF_TIMEATK_2_EASY_RSV33,// イージー34、リザーブ33
	__GF_TIMEATK_2_EASY_RSV34,// イージー34、リザーブ34
	__GF_TIMEATK_2_EASY_RSV35,// イージー35、リザーブ35
	__GF_TIMEATK_2_EASY_RSV36,// イージー36、リザーブ36
	__GF_TIMEATK_2_EASY_RSV37,// イージー37、リザーブ37
	__GF_TIMEATK_2_EASY_RSV38,// イージー38、リザーブ38
	GF_TIMEATK_2_EASY_RUSH,	// イージー39、ボスラッシュ

	GF_TIMEATK_2_EASY_ED,

		// NORMAL2人用
	GF_TIMEATK_2_NORMAL_ST = GF_TIMEATK_2_EASY_ED,
	GF_TIMEATK_2_NORMAL_M0111 = GF_TIMEATK_2_NORMAL_ST,	// ノーマル00、１部、ビフテリザ
	GF_TIMEATK_2_NORMAL_B150,		// ノーマル01、１部、アヴァロドラギル
	GF_TIMEATK_2_NORMAL_B100,		// ノーマル02、２部、セルペンタス
	GF_TIMEATK_2_NORMAL_B000,		// ノーマル03、２部、クラリオン
	GF_TIMEATK_2_NORMAL_B101B,	// ノーマル04、２部、ロンブリゲウス
	GF_TIMEATK_2_NORMAL_B001,		// ノーマル05、２部、グルガンチュラ
	GF_TIMEATK_2_NORMAL_B102,		// ノーマル06、２部、マガマンドラ
	GF_TIMEATK_2_NORMAL_B002,		// ノーマル07、２部、ラスピスース
	GF_TIMEATK_2_NORMAL_B152,		// ノーマル08、２部、キルゴール
	GF_TIMEATK_2_NORMAL_B154,		// ノーマル09、３部、アヴァロドラギル
	GF_TIMEATK_2_NORMAL_B003,		// ノーマル10、３部、ギアスバーン
	GF_TIMEATK_2_NORMAL_B006,		// ノーマル11、４部、ブラキオン
	GF_TIMEATK_2_NORMAL_B104,		// ノーマル12、５部、エクスメーテル
	GF_TIMEATK_2_NORMAL_B004,		// ノーマル13、５部、カルヴェロス
	GF_TIMEATK_2_NORMAL_B103,		// ノーマル14、５部、ピラティスアニマ
	GF_TIMEATK_2_NORMAL_B106,		// ノーマル15、５部、シエラカントゥス
	GF_TIMEATK_2_NORMAL_B007,		// ノーマル16、５部、オケアノス
	GF_TIMEATK_2_NORMAL_B105,		// ノーマル17、５部、ドクサ・グリエル
	GF_TIMEATK_2_NORMAL_B005,		// ノーマル18、５部、バシレウス
	GF_TIMEATK_2_NORMAL_B012,		// ノーマル19、６部、レ・エリュトロン
	GF_TIMEATK_2_NORMAL_B112,		// ノーマル20、６部、アニムス・ヒドゥラ
	GF_TIMEATK_2_NORMAL_B110,		// ノーマル21、６部、アニムス・ミノス
	GF_TIMEATK_2_NORMAL_B111,		// ノーマル22、６部、アニムス・ネストール
	GF_TIMEATK_2_NORMAL_B008,		// ノーマル23、６部、アニムス・ウーラ
	GF_TIMEATK_2_NORMAL_B021_1,	// ノーマル24、６部、テオス・デ・エンドログラム１
	GF_TIMEATK_2_NORMAL_B021_2,	// ノーマル25、６部、テオス・デ・エンドログラム２
	GF_TIMEATK_2_NORMAL_B021_3,	// ノーマル26、６部、テオス・デ・エンドログラム３
	GF_TIMEATK_2_NORMAL_B009,		// ノーマル27、７部、はじまりの命・子
	GF_TIMEATK_2_NORMAL_B010,		// ノーマル28、７部、はじまりの命・親
	GF_TIMEATK_2_NORMAL_B155,	// ノーマル29、シルヴィア
	GF_TIMEATK_2_NORMAL_B151,	// ノーマル30、マスターコング
	GF_TIMEATK_2_NORMAL_B153,		// ノーマル31、６部、メフォラシュム
	GF_TIMEATK_2_NORMAL_B170,	// ノーマル32、６部、◆仮名：２週目ダンジョンボス
	__GF_TIMEATK_2_NORMAL_RSV33,	// ノーマル34、リザーブ33
	__GF_TIMEATK_2_NORMAL_RSV34,	// ノーマル34、リザーブ34
	__GF_TIMEATK_2_NORMAL_RSV35,	// ノーマル35、リザーブ35
	__GF_TIMEATK_2_NORMAL_RSV36,	// ノーマル36、リザーブ36
	__GF_TIMEATK_2_NORMAL_RSV37,	// ノーマル37、リザーブ37
	__GF_TIMEATK_2_NORMAL_RSV38,	// ノーマル38、リザーブ38
	GF_TIMEATK_2_NORMAL_RUSH,		// ノーマル39、ボスラッシュ

	GF_TIMEATK_2_NORMAL_ED,

		// HARD2人用
	GF_TIMEATK_2_HARD_ST = GF_TIMEATK_2_NORMAL_ED,
	GF_TIMEATK_2_HARD_M0111 = GF_TIMEATK_2_HARD_ST,		// ハード00、１部、ビフテリザ
	GF_TIMEATK_2_HARD_B150,		// ハード01、１部、アヴァロドラギル
	GF_TIMEATK_2_HARD_B100,		// ハード02、２部、セルペンタス
	GF_TIMEATK_2_HARD_B000,		// ハード03、２部、クラリオン
	GF_TIMEATK_2_HARD_B101B,		// ハード04、２部、ロンブリゲウス
	GF_TIMEATK_2_HARD_B001,		// ハード05、２部、グルガンチュラ
	GF_TIMEATK_2_HARD_B102,		// ハード06、２部、マガマンドラ
	GF_TIMEATK_2_HARD_B002,		// ハード07、２部、ラスピスース
	GF_TIMEATK_2_HARD_B152,		// ハード08、２部、キルゴール
	GF_TIMEATK_2_HARD_B154,		// ハード09、３部、アヴァロドラギル
	GF_TIMEATK_2_HARD_B003,		// ハード10、３部、ギアスバーン
	GF_TIMEATK_2_HARD_B006,		// ハード11、４部、ブラキオン
	GF_TIMEATK_2_HARD_B104,		// ハード12、５部、エクスメーテル
	GF_TIMEATK_2_HARD_B004,		// ハード13、５部、カルヴェロス
	GF_TIMEATK_2_HARD_B103,		// ハード14、５部、ピラティスアニマ
	GF_TIMEATK_2_HARD_B106,		// ハード15、５部、シエラカントゥス
	GF_TIMEATK_2_HARD_B007,		// ハード16、５部、オケアノス
	GF_TIMEATK_2_HARD_B105,		// ハード17、５部、ドクサ・グリエル
	GF_TIMEATK_2_HARD_B005,		// ハード18、５部、バシレウス
	GF_TIMEATK_2_HARD_B012,		// ハード19、６部、レ・エリュトロン
	GF_TIMEATK_2_HARD_B112,		// ハード20、６部、アニムス・ヒドゥラ
	GF_TIMEATK_2_HARD_B110,		// ハード21、６部、アニムス・ミノス
	GF_TIMEATK_2_HARD_B111,		// ハード22、６部、アニムス・ネストール
	GF_TIMEATK_2_HARD_B008,		// ハード23、６部、アニムス・ウーラ
	GF_TIMEATK_2_HARD_B021_1,		// ハード24、６部、テオス・デ・エンドログラム１
	GF_TIMEATK_2_HARD_B021_2,		// ハード25、６部、テオス・デ・エンドログラム２
	GF_TIMEATK_2_HARD_B021_3,		// ハード26、６部、テオス・デ・エンドログラム３
	GF_TIMEATK_2_HARD_B009,		// ハード27、７部、はじまりの命・子
	GF_TIMEATK_2_HARD_B010,		// ハード28、７部、はじまりの命・親
	GF_TIMEATK_2_HARD_B155,		// ハード29、シルヴィア
	GF_TIMEATK_2_HARD_B151,		// ハード30、マスターコング
	GF_TIMEATK_2_HARD_B153,		// ハード31、６部、メフォラシュム
	GF_TIMEATK_2_HARD_B170,		// ハード32、６部、◆仮名：２週目ダンジョンボス
	__GF_TIMEATK_2_HARD_RSV33,	// ハード33、リザーブ33
	__GF_TIMEATK_2_HARD_RSV34,	// ハード34、リザーブ34
	__GF_TIMEATK_2_HARD_RSV35,	// ハード35、リザーブ35
	__GF_TIMEATK_2_HARD_RSV36,	// ハード36、リザーブ36
	__GF_TIMEATK_2_HARD_RSV37,	// ハード37、リザーブ37
	__GF_TIMEATK_2_HARD_RSV38,	// ハード38、リザーブ38
	GF_TIMEATK_2_HARD_RUSH,		// ハード39、ボスラッシュ

	GF_TIMEATK_2_HARD_ED,

		// NIGHTMARE2人用
	GF_TIMEATK_2_NIGHTMARE_ST = GF_TIMEATK_2_HARD_ED,
	GF_TIMEATK_2_NIGHTMARE_M0111 = GF_TIMEATK_2_NIGHTMARE_ST,	// ナイトメア00、１部、ビフテリザ
	GF_TIMEATK_2_NIGHTMARE_B150,		// ナイトメア01、１部、アヴァロドラギル
	GF_TIMEATK_2_NIGHTMARE_B100,		// ナイトメア02、２部、セルペンタス
	GF_TIMEATK_2_NIGHTMARE_B000,		// ナイトメア03、２部、クラリオン
	GF_TIMEATK_2_NIGHTMARE_B101B,		// ナイトメア04、２部、ロンブリゲウス
	GF_TIMEATK_2_NIGHTMARE_B001,		// ナイトメア05、２部、グルガンチュラ
	GF_TIMEATK_2_NIGHTMARE_B102,		// ナイトメア06、２部、マガマンドラ
	GF_TIMEATK_2_NIGHTMARE_B002,		// ナイトメア07、２部、ラスピスース
	GF_TIMEATK_2_NIGHTMARE_B152,		// ナイトメア08、２部、キルゴール
	GF_TIMEATK_2_NIGHTMARE_B154,		// ナイトメア09、３部、アヴァロドラギル
	GF_TIMEATK_2_NIGHTMARE_B003,		// ナイトメア10、３部、ギアスバーン
	GF_TIMEATK_2_NIGHTMARE_B006,		// ナイトメア11、４部、ブラキオン
	GF_TIMEATK_2_NIGHTMARE_B104,		// ナイトメア12、５部、エクスメーテル
	GF_TIMEATK_2_NIGHTMARE_B004,		// ナイトメア13、５部、カルヴェロス
	GF_TIMEATK_2_NIGHTMARE_B103,		// ナイトメア14、５部、ピラティスアニマ
	GF_TIMEATK_2_NIGHTMARE_B106,		// ナイトメア15、５部、シエラカントゥス
	GF_TIMEATK_2_NIGHTMARE_B007,		// ナイトメア16、５部、オケアノス
	GF_TIMEATK_2_NIGHTMARE_B105,		// ナイトメア17、５部、ドクサ・グリエル
	GF_TIMEATK_2_NIGHTMARE_B005,		// ナイトメア18、５部、バシレウス
	GF_TIMEATK_2_NIGHTMARE_B012,		// ナイトメア19、６部、レ・エリュトロン
	GF_TIMEATK_2_NIGHTMARE_B112,		// ナイトメア20、６部、アニムス・ヒドゥラ
	GF_TIMEATK_2_NIGHTMARE_B110,		// ナイトメア21、６部、アニムス・ミノス
	GF_TIMEATK_2_NIGHTMARE_B111,		// ナイトメア22、６部、アニムス・ネストール
	GF_TIMEATK_2_NIGHTMARE_B008,		// ナイトメア23、６部、アニムス・ウーラ
	GF_TIMEATK_2_NIGHTMARE_B021_1,	// ナイトメア24、６部、テオス・デ・エンドログラム１
	GF_TIMEATK_2_NIGHTMARE_B021_2,	// ナイトメア25、６部、テオス・デ・エンドログラム２
	GF_TIMEATK_2_NIGHTMARE_B021_3,	// ナイトメア26、６部、テオス・デ・エンドログラム３
	GF_TIMEATK_2_NIGHTMARE_B009,		// ナイトメア27、７部、はじまりの命・子
	GF_TIMEATK_2_NIGHTMARE_B010,		// ナイトメア28、７部、はじまりの命・親
	GF_TIMEATK_2_NIGHTMARE_B155,		// ナイトメア29、シルヴィア
	GF_TIMEATK_2_NIGHTMARE_B151,		// ナイトメア30、マスターコング
	GF_TIMEATK_2_NIGHTMARE_B153,		// ナイトメア31、６部、メフォラシュム
	GF_TIMEATK_2_NIGHTMARE_B170,		// ナイトメア32、６部、◆仮名：２週目ダンジョンボス
	__GF_TIMEATK_2_NIGHTMARE_RSV33,	// ナイトメア33、リザーブ33
	__GF_TIMEATK_2_NIGHTMARE_RSV34,	// ナイトメア34、リザーブ34
	__GF_TIMEATK_2_NIGHTMARE_RSV35,	// ナイトメア35、リザーブ35
	__GF_TIMEATK_2_NIGHTMARE_RSV36,	// ナイトメア36、リザーブ36
	__GF_TIMEATK_2_NIGHTMARE_RSV37,	// ナイトメア37、リザーブ37
	__GF_TIMEATK_2_NIGHTMARE_RSV38,	// ナイトメア38、リザーブ38
	GF_TIMEATK_2_NIGHTMARE_RUSH,		// ナイトメア39、ボスラッシュ

	GF_TIMEATK_2_NIGHTMARE_ED,

		// INFERNO2人用
	GF_TIMEATK_2_INFERNO_ST = GF_TIMEATK_2_NIGHTMARE_ED,
	GF_TIMEATK_2_INFERNO_M0111 = GF_TIMEATK_2_INFERNO_ST,	// インフェルノ00、１部、ビフテリザ
	GF_TIMEATK_2_INFERNO_B150,		// インフェルノ01、１部、アヴァロドラギル
	GF_TIMEATK_2_INFERNO_B100,		// インフェルノ02、２部、セルペンタス
	GF_TIMEATK_2_INFERNO_B000,		// インフェルノ03、２部、クラリオン
	GF_TIMEATK_2_INFERNO_B101B,		// インフェルノ04、２部、ロンブリゲウス
	GF_TIMEATK_2_INFERNO_B001,		// インフェルノ05、２部、グルガンチュラ
	GF_TIMEATK_2_INFERNO_B102,		// インフェルノ06、２部、マガマンドラ
	GF_TIMEATK_2_INFERNO_B002,		// インフェルノ07、２部、ラスピスース
	GF_TIMEATK_2_INFERNO_B152,		// インフェルノ08、２部、キルゴール
	GF_TIMEATK_2_INFERNO_B154,		// インフェルノ09、３部、アヴァロドラギル
	GF_TIMEATK_2_INFERNO_B003,		// インフェルノ10、３部、ギアスバーン
	GF_TIMEATK_2_INFERNO_B006,		// インフェルノ11、４部、ブラキオン
	GF_TIMEATK_2_INFERNO_B104,		// インフェルノ12、５部、エクスメーテル
	GF_TIMEATK_2_INFERNO_B004,		// インフェルノ13、５部、カルヴェロス
	GF_TIMEATK_2_INFERNO_B103,		// インフェルノ14、５部、ピラティスアニマ
	GF_TIMEATK_2_INFERNO_B106,		// インフェルノ15、５部、シエラカントゥス
	GF_TIMEATK_2_INFERNO_B007,		// インフェルノ16、５部、オケアノス
	GF_TIMEATK_2_INFERNO_B105,		// インフェルノ17、５部、ドクサ・グリエル
	GF_TIMEATK_2_INFERNO_B005,		// インフェルノ18、５部、バシレウス
	GF_TIMEATK_2_INFERNO_B012,		// インフェルノ19、６部、レ・エリュトロン
	GF_TIMEATK_2_INFERNO_B112,		// インフェルノ20、６部、アニムス・ヒドゥラ
	GF_TIMEATK_2_INFERNO_B110,		// インフェルノ21、６部、アニムス・ミノス
	GF_TIMEATK_2_INFERNO_B111,		// インフェルノ22、６部、アニムス・ネストール
	GF_TIMEATK_2_INFERNO_B008,		// インフェルノ23、６部、アニムス・ウーラ
	GF_TIMEATK_2_INFERNO_B021_1,		// インフェルノ24、６部、テオス・デ・エンドログラム１
	GF_TIMEATK_2_INFERNO_B021_2,		// インフェルノ25、６部、テオス・デ・エンドログラム２
	GF_TIMEATK_2_INFERNO_B021_3,		// インフェルノ26、６部、テオス・デ・エンドログラム３
	GF_TIMEATK_2_INFERNO_B009,		// インフェルノ27、７部、はじまりの命・子
	GF_TIMEATK_2_INFERNO_B010,		// インフェルノ28、７部、はじまりの命・親
	GF_TIMEATK_2_INFERNO_B155,		// インフェルノ29、シルヴィア
	GF_TIMEATK_2_INFERNO_B151,		// インフェルノ30、マスターコング
	GF_TIMEATK_2_INFERNO_B153,		// インフェルノ31、６部、メフォラシュム
	GF_TIMEATK_2_INFERNO_B170,		// インフェルノ32、６部、◆仮名：２週目ダンジョンボス
	__GF_TIMEATK_2_INFERNO_RSV33,		// インフェルノ33、リザーブ33
	__GF_TIMEATK_2_INFERNO_RSV34,		// インフェルノ34、リザーブ34
	__GF_TIMEATK_2_INFERNO_RSV35,		// インフェルノ35、リザーブ35
	__GF_TIMEATK_2_INFERNO_RSV36,		// インフェルノ36、リザーブ36
	__GF_TIMEATK_2_INFERNO_RSV37,		// インフェルノ37、リザーブ37
	__GF_TIMEATK_2_INFERNO_RSV38,		// インフェルノ38、リザーブ38
	GF_TIMEATK_2_INFERNO_RUSH,		// インフェルノ39、ボスラッシュ

	GF_TIMEATK_2_INFERNO_ED,

	// 現代編1人

		// EASY1人用
	GF_TIMEATK_1_EASY_ST = GF_TIMEATK_2_INFERNO_ED,
	GF_TIMEATK_1_EASY_M0111 = GF_TIMEATK_1_EASY_ST,	// イージー00、１部、ビフテリザ
	GF_TIMEATK_1_EASY_B150,	// イージー01、１部、アヴァロドラギル
	GF_TIMEATK_1_EASY_B100,	// イージー02、２部、セルペンタス
	GF_TIMEATK_1_EASY_B000,	// イージー03、２部、クラリオン
	GF_TIMEATK_1_EASY_B101B,	// イージー04、２部、ロンブリゲウス
	GF_TIMEATK_1_EASY_B001,	// イージー05、２部、グルガンチュラ
	GF_TIMEATK_1_EASY_B102,	// イージー06、２部、マガマンドラ
	GF_TIMEATK_1_EASY_B002,	// イージー07、２部、ラスピスース
	GF_TIMEATK_1_EASY_B152,	// イージー08、２部、キルゴール
	GF_TIMEATK_1_EASY_B154,	// イージー09、３部、アヴァロドラギル
	GF_TIMEATK_1_EASY_B003,	// イージー10、３部、ギアスバーン
	GF_TIMEATK_1_EASY_B006,	// イージー11、４部、ブラキオン
	GF_TIMEATK_1_EASY_B104,	// イージー12、５部、エクスメーテル
	GF_TIMEATK_1_EASY_B004,	// イージー13、５部、カルヴェロス
	GF_TIMEATK_1_EASY_B103,	// イージー14、５部、ピラティスアニマ
	GF_TIMEATK_1_EASY_B106,	// イージー15、５部、シエラカントゥス
	GF_TIMEATK_1_EASY_B007,	// イージー16、５部、オケアノス
	GF_TIMEATK_1_EASY_B105,	// イージー17、５部、ドクサ・グリエル
	GF_TIMEATK_1_EASY_B005,	// イージー18、５部、バシレウス
	GF_TIMEATK_1_EASY_B012,	// イージー19、６部、レ・エリュトロン
	GF_TIMEATK_1_EASY_B112,	// イージー20、６部、アニムス・ヒドゥラ
	GF_TIMEATK_1_EASY_B110,	// イージー21、６部、アニムス・ミノス
	GF_TIMEATK_1_EASY_B111,	// イージー22、６部、アニムス・ネストール
	GF_TIMEATK_1_EASY_B008,	// イージー23、６部、アニムス・ウーラ
	GF_TIMEATK_1_EASY_B021_1,	// イージー24、６部、テオス・デ・エンドログラム１
	GF_TIMEATK_1_EASY_B021_2,	// イージー25、６部、テオス・デ・エンドログラム２
	GF_TIMEATK_1_EASY_B021_3,	// イージー26、６部、テオス・デ・エンドログラム３
	GF_TIMEATK_1_EASY_B009,	// イージー28、７部、はじまりの命・子
	GF_TIMEATK_1_EASY_B010,	// イージー28、７部、はじまりの命・親
	GF_TIMEATK_1_EASY_B155,	// イージー29、シルヴィア
	GF_TIMEATK_1_EASY_B151,	// イージー30、マスターコング
	GF_TIMEATK_1_EASY_B153,	// イージー31、６部、メフォラシュム
	GF_TIMEATK_1_EASY_B170,	// イージー32、６部、◆仮名：２週目ダンジョンボス
	__GF_TIMEATK_1_EASY_RSV33,// イージー34、リザーブ33
	__GF_TIMEATK_1_EASY_RSV34,// イージー34、リザーブ34
	__GF_TIMEATK_1_EASY_RSV35,// イージー35、リザーブ35
	__GF_TIMEATK_1_EASY_RSV36,// イージー36、リザーブ36
	__GF_TIMEATK_1_EASY_RSV37,// イージー37、リザーブ37
	__GF_TIMEATK_1_EASY_RSV38,// イージー38、リザーブ38
	GF_TIMEATK_1_EASY_RUSH,	// イージー39、ボスラッシュ

	GF_TIMEATK_1_EASY_ED,

		// NORMAL1人用
	GF_TIMEATK_1_NORMAL_ST = GF_TIMEATK_1_EASY_ED,
	GF_TIMEATK_1_NORMAL_M0111 = GF_TIMEATK_1_NORMAL_ST,	// ノーマル00、１部、ビフテリザ
	GF_TIMEATK_1_NORMAL_B150,		// ノーマル01、１部、アヴァロドラギル
	GF_TIMEATK_1_NORMAL_B100,		// ノーマル02、２部、セルペンタス
	GF_TIMEATK_1_NORMAL_B000,		// ノーマル03、２部、クラリオン
	GF_TIMEATK_1_NORMAL_B101B,	// ノーマル04、２部、ロンブリゲウス
	GF_TIMEATK_1_NORMAL_B001,		// ノーマル05、２部、グルガンチュラ
	GF_TIMEATK_1_NORMAL_B102,		// ノーマル06、２部、マガマンドラ
	GF_TIMEATK_1_NORMAL_B002,		// ノーマル07、２部、ラスピスース
	GF_TIMEATK_1_NORMAL_B152,		// ノーマル08、２部、キルゴール
	GF_TIMEATK_1_NORMAL_B154,		// ノーマル09、３部、アヴァロドラギル
	GF_TIMEATK_1_NORMAL_B003,		// ノーマル10、３部、ギアスバーン
	GF_TIMEATK_1_NORMAL_B006,		// ノーマル11、４部、ブラキオン
	GF_TIMEATK_1_NORMAL_B104,		// ノーマル12、５部、エクスメーテル
	GF_TIMEATK_1_NORMAL_B004,		// ノーマル13、５部、カルヴェロス
	GF_TIMEATK_1_NORMAL_B103,		// ノーマル14、５部、ピラティスアニマ
	GF_TIMEATK_1_NORMAL_B106,		// ノーマル15、５部、シエラカントゥス
	GF_TIMEATK_1_NORMAL_B007,		// ノーマル16、５部、オケアノス
	GF_TIMEATK_1_NORMAL_B105,		// ノーマル17、５部、ドクサ・グリエル
	GF_TIMEATK_1_NORMAL_B005,		// ノーマル18、５部、バシレウス
	GF_TIMEATK_1_NORMAL_B012,		// ノーマル19、６部、レ・エリュトロン
	GF_TIMEATK_1_NORMAL_B112,		// ノーマル20、６部、アニムス・ヒドゥラ
	GF_TIMEATK_1_NORMAL_B110,		// ノーマル21、６部、アニムス・ミノス
	GF_TIMEATK_1_NORMAL_B111,		// ノーマル22、６部、アニムス・ネストール
	GF_TIMEATK_1_NORMAL_B008,		// ノーマル23、６部、アニムス・ウーラ
	GF_TIMEATK_1_NORMAL_B021_1,	// ノーマル24、６部、テオス・デ・エンドログラム１
	GF_TIMEATK_1_NORMAL_B021_2,	// ノーマル25、６部、テオス・デ・エンドログラム２
	GF_TIMEATK_1_NORMAL_B021_3,	// ノーマル26、６部、テオス・デ・エンドログラム３
	GF_TIMEATK_1_NORMAL_B009,		// ノーマル27、７部、はじまりの命・子
	GF_TIMEATK_1_NORMAL_B010,		// ノーマル28、７部、はじまりの命・親
	GF_TIMEATK_1_NORMAL_B155,	// ノーマル29、シルヴィア
	GF_TIMEATK_1_NORMAL_B151,	// ノーマル30、マスターコング
	GF_TIMEATK_1_NORMAL_B153,		// ノーマル31、６部、メフォラシュム
	GF_TIMEATK_1_NORMAL_B170,	// ノーマル32、６部、◆仮名：２週目ダンジョンボス
	__GF_TIMEATK_1_NORMAL_RSV33,	// ノーマル34、リザーブ33
	__GF_TIMEATK_1_NORMAL_RSV34,	// ノーマル34、リザーブ34
	__GF_TIMEATK_1_NORMAL_RSV35,	// ノーマル35、リザーブ35
	__GF_TIMEATK_1_NORMAL_RSV36,	// ノーマル36、リザーブ36
	__GF_TIMEATK_1_NORMAL_RSV37,	// ノーマル37、リザーブ37
	__GF_TIMEATK_1_NORMAL_RSV38,	// ノーマル38、リザーブ38
	GF_TIMEATK_1_NORMAL_RUSH,		// ノーマル39、ボスラッシュ

	GF_TIMEATK_1_NORMAL_ED,

		// HARD1人用
	GF_TIMEATK_1_HARD_ST = GF_TIMEATK_1_NORMAL_ED,
	GF_TIMEATK_1_HARD_M0111 = GF_TIMEATK_1_HARD_ST,		// ハード00、１部、ビフテリザ
	GF_TIMEATK_1_HARD_B150,		// ハード01、１部、アヴァロドラギル
	GF_TIMEATK_1_HARD_B100,		// ハード02、２部、セルペンタス
	GF_TIMEATK_1_HARD_B000,		// ハード03、２部、クラリオン
	GF_TIMEATK_1_HARD_B101B,		// ハード04、２部、ロンブリゲウス
	GF_TIMEATK_1_HARD_B001,		// ハード05、２部、グルガンチュラ
	GF_TIMEATK_1_HARD_B102,		// ハード06、２部、マガマンドラ
	GF_TIMEATK_1_HARD_B002,		// ハード07、２部、ラスピスース
	GF_TIMEATK_1_HARD_B152,		// ハード08、２部、キルゴール
	GF_TIMEATK_1_HARD_B154,		// ハード09、３部、アヴァロドラギル
	GF_TIMEATK_1_HARD_B003,		// ハード10、３部、ギアスバーン
	GF_TIMEATK_1_HARD_B006,		// ハード11、４部、ブラキオン
	GF_TIMEATK_1_HARD_B104,		// ハード12、５部、エクスメーテル
	GF_TIMEATK_1_HARD_B004,		// ハード13、５部、カルヴェロス
	GF_TIMEATK_1_HARD_B103,		// ハード14、５部、ピラティスアニマ
	GF_TIMEATK_1_HARD_B106,		// ハード15、５部、シエラカントゥス
	GF_TIMEATK_1_HARD_B007,		// ハード16、５部、オケアノス
	GF_TIMEATK_1_HARD_B105,		// ハード17、５部、ドクサ・グリエル
	GF_TIMEATK_1_HARD_B005,		// ハード18、５部、バシレウス
	GF_TIMEATK_1_HARD_B012,		// ハード19、６部、レ・エリュトロン
	GF_TIMEATK_1_HARD_B112,		// ハード20、６部、アニムス・ヒドゥラ
	GF_TIMEATK_1_HARD_B110,		// ハード21、６部、アニムス・ミノス
	GF_TIMEATK_1_HARD_B111,		// ハード22、６部、アニムス・ネストール
	GF_TIMEATK_1_HARD_B008,		// ハード23、６部、アニムス・ウーラ
	GF_TIMEATK_1_HARD_B021_1,		// ハード24、６部、テオス・デ・エンドログラム１
	GF_TIMEATK_1_HARD_B021_2,		// ハード25、６部、テオス・デ・エンドログラム２
	GF_TIMEATK_1_HARD_B021_3,		// ハード26、６部、テオス・デ・エンドログラム３
	GF_TIMEATK_1_HARD_B009,		// ハード27、７部、はじまりの命・子
	GF_TIMEATK_1_HARD_B010,		// ハード28、７部、はじまりの命・親
	GF_TIMEATK_1_HARD_B155,		// ハード29、シルヴィア
	GF_TIMEATK_1_HARD_B151,		// ハード30、マスターコング
	GF_TIMEATK_1_HARD_B153,		// ハード31、６部、メフォラシュム
	GF_TIMEATK_1_HARD_B170,		// ハード32、６部、◆仮名：２週目ダンジョンボス
	__GF_TIMEATK_1_HARD_RSV33,	// ハード33、リザーブ33
	__GF_TIMEATK_1_HARD_RSV34,	// ハード34、リザーブ34
	__GF_TIMEATK_1_HARD_RSV35,	// ハード35、リザーブ35
	__GF_TIMEATK_1_HARD_RSV36,	// ハード36、リザーブ36
	__GF_TIMEATK_1_HARD_RSV37,	// ハード37、リザーブ37
	__GF_TIMEATK_1_HARD_RSV38,	// ハード38、リザーブ38
	GF_TIMEATK_1_HARD_RUSH,		// ハード39、ボスラッシュ

	GF_TIMEATK_1_HARD_ED,

		// NIGHTMARE1人用
	GF_TIMEATK_1_NIGHTMARE_ST = GF_TIMEATK_1_HARD_ED,
	GF_TIMEATK_1_NIGHTMARE_M0111 = GF_TIMEATK_1_NIGHTMARE_ST,	// ナイトメア00、１部、ビフテリザ
	GF_TIMEATK_1_NIGHTMARE_B150,		// ナイトメア01、１部、アヴァロドラギル
	GF_TIMEATK_1_NIGHTMARE_B100,		// ナイトメア02、２部、セルペンタス
	GF_TIMEATK_1_NIGHTMARE_B000,		// ナイトメア03、２部、クラリオン
	GF_TIMEATK_1_NIGHTMARE_B101B,		// ナイトメア04、２部、ロンブリゲウス
	GF_TIMEATK_1_NIGHTMARE_B001,		// ナイトメア05、２部、グルガンチュラ
	GF_TIMEATK_1_NIGHTMARE_B102,		// ナイトメア06、２部、マガマンドラ
	GF_TIMEATK_1_NIGHTMARE_B002,		// ナイトメア07、２部、ラスピスース
	GF_TIMEATK_1_NIGHTMARE_B152,		// ナイトメア08、２部、キルゴール
	GF_TIMEATK_1_NIGHTMARE_B154,		// ナイトメア09、３部、アヴァロドラギル
	GF_TIMEATK_1_NIGHTMARE_B003,		// ナイトメア10、３部、ギアスバーン
	GF_TIMEATK_1_NIGHTMARE_B006,		// ナイトメア11、４部、ブラキオン
	GF_TIMEATK_1_NIGHTMARE_B104,		// ナイトメア12、５部、エクスメーテル
	GF_TIMEATK_1_NIGHTMARE_B004,		// ナイトメア13、５部、カルヴェロス
	GF_TIMEATK_1_NIGHTMARE_B103,		// ナイトメア14、５部、ピラティスアニマ
	GF_TIMEATK_1_NIGHTMARE_B106,		// ナイトメア15、５部、シエラカントゥス
	GF_TIMEATK_1_NIGHTMARE_B007,		// ナイトメア16、５部、オケアノス
	GF_TIMEATK_1_NIGHTMARE_B105,		// ナイトメア17、５部、ドクサ・グリエル
	GF_TIMEATK_1_NIGHTMARE_B005,		// ナイトメア18、５部、バシレウス
	GF_TIMEATK_1_NIGHTMARE_B012,		// ナイトメア19、６部、レ・エリュトロン
	GF_TIMEATK_1_NIGHTMARE_B112,		// ナイトメア20、６部、アニムス・ヒドゥラ
	GF_TIMEATK_1_NIGHTMARE_B110,		// ナイトメア21、６部、アニムス・ミノス
	GF_TIMEATK_1_NIGHTMARE_B111,		// ナイトメア22、６部、アニムス・ネストール
	GF_TIMEATK_1_NIGHTMARE_B008,		// ナイトメア23、６部、アニムス・ウーラ
	GF_TIMEATK_1_NIGHTMARE_B021_1,	// ナイトメア24、６部、テオス・デ・エンドログラム１
	GF_TIMEATK_1_NIGHTMARE_B021_2,	// ナイトメア25、６部、テオス・デ・エンドログラム２
	GF_TIMEATK_1_NIGHTMARE_B021_3,	// ナイトメア26、６部、テオス・デ・エンドログラム３
	GF_TIMEATK_1_NIGHTMARE_B009,		// ナイトメア27、７部、はじまりの命・子
	GF_TIMEATK_1_NIGHTMARE_B010,		// ナイトメア28、７部、はじまりの命・親
	GF_TIMEATK_1_NIGHTMARE_B155,		// ナイトメア29、シルヴィア
	GF_TIMEATK_1_NIGHTMARE_B151,		// ナイトメア30、マスターコング
	GF_TIMEATK_1_NIGHTMARE_B153,		// ナイトメア31、６部、メフォラシュム
	GF_TIMEATK_1_NIGHTMARE_B170,		// ナイトメア32、６部、◆仮名：２週目ダンジョンボス
	__GF_TIMEATK_1_NIGHTMARE_RSV33,	// ナイトメア33、リザーブ33
	__GF_TIMEATK_1_NIGHTMARE_RSV34,	// ナイトメア34、リザーブ34
	__GF_TIMEATK_1_NIGHTMARE_RSV35,	// ナイトメア35、リザーブ35
	__GF_TIMEATK_1_NIGHTMARE_RSV36,	// ナイトメア36、リザーブ36
	__GF_TIMEATK_1_NIGHTMARE_RSV37,	// ナイトメア37、リザーブ37
	__GF_TIMEATK_1_NIGHTMARE_RSV38,	// ナイトメア38、リザーブ38
	GF_TIMEATK_1_NIGHTMARE_RUSH,		// ナイトメア39、ボスラッシュ

	GF_TIMEATK_1_NIGHTMARE_ED,

		// INFERNO1人用
	GF_TIMEATK_1_INFERNO_ST = GF_TIMEATK_1_NIGHTMARE_ED,
	GF_TIMEATK_1_INFERNO_M0111 = GF_TIMEATK_1_INFERNO_ST,	// インフェルノ00、１部、ビフテリザ
	GF_TIMEATK_1_INFERNO_B150,		// インフェルノ01、１部、アヴァロドラギル
	GF_TIMEATK_1_INFERNO_B100,		// インフェルノ02、２部、セルペンタス
	GF_TIMEATK_1_INFERNO_B000,		// インフェルノ03、２部、クラリオン
	GF_TIMEATK_1_INFERNO_B101B,		// インフェルノ04、２部、ロンブリゲウス
	GF_TIMEATK_1_INFERNO_B001,		// インフェルノ05、２部、グルガンチュラ
	GF_TIMEATK_1_INFERNO_B102,		// インフェルノ06、２部、マガマンドラ
	GF_TIMEATK_1_INFERNO_B002,		// インフェルノ07、２部、ラスピスース
	GF_TIMEATK_1_INFERNO_B152,		// インフェルノ08、２部、キルゴール
	GF_TIMEATK_1_INFERNO_B154,		// インフェルノ09、３部、アヴァロドラギル
	GF_TIMEATK_1_INFERNO_B003,		// インフェルノ10、３部、ギアスバーン
	GF_TIMEATK_1_INFERNO_B006,		// インフェルノ11、４部、ブラキオン
	GF_TIMEATK_1_INFERNO_B104,		// インフェルノ12、５部、エクスメーテル
	GF_TIMEATK_1_INFERNO_B004,		// インフェルノ13、５部、カルヴェロス
	GF_TIMEATK_1_INFERNO_B103,		// インフェルノ14、５部、ピラティスアニマ
	GF_TIMEATK_1_INFERNO_B106,		// インフェルノ15、５部、シエラカントゥス
	GF_TIMEATK_1_INFERNO_B007,		// インフェルノ16、５部、オケアノス
	GF_TIMEATK_1_INFERNO_B105,		// インフェルノ17、５部、ドクサ・グリエル
	GF_TIMEATK_1_INFERNO_B005,		// インフェルノ18、５部、バシレウス
	GF_TIMEATK_1_INFERNO_B012,		// インフェルノ19、６部、レ・エリュトロン
	GF_TIMEATK_1_INFERNO_B112,		// インフェルノ20、６部、アニムス・ヒドゥラ
	GF_TIMEATK_1_INFERNO_B110,		// インフェルノ21、６部、アニムス・ミノス
	GF_TIMEATK_1_INFERNO_B111,		// インフェルノ22、６部、アニムス・ネストール
	GF_TIMEATK_1_INFERNO_B008,		// インフェルノ23、６部、アニムス・ウーラ
	GF_TIMEATK_1_INFERNO_B021_1,		// インフェルノ24、６部、テオス・デ・エンドログラム１
	GF_TIMEATK_1_INFERNO_B021_2,		// インフェルノ25、６部、テオス・デ・エンドログラム２
	GF_TIMEATK_1_INFERNO_B021_3,		// インフェルノ26、６部、テオス・デ・エンドログラム３
	GF_TIMEATK_1_INFERNO_B009,		// インフェルノ27、７部、はじまりの命・子
	GF_TIMEATK_1_INFERNO_B010,		// インフェルノ28、７部、はじまりの命・親
	GF_TIMEATK_1_INFERNO_B155,		// インフェルノ29、シルヴィア
	GF_TIMEATK_1_INFERNO_B151,		// インフェルノ30、マスターコング
	GF_TIMEATK_1_INFERNO_B153,		// インフェルノ31、６部、メフォラシュム
	GF_TIMEATK_1_INFERNO_B170,		// インフェルノ32、６部、◆仮名：２週目ダンジョンボス
	__GF_TIMEATK_1_INFERNO_RSV33,		// インフェルノ33、リザーブ33
	__GF_TIMEATK_1_INFERNO_RSV34,		// インフェルノ34、リザーブ34
	__GF_TIMEATK_1_INFERNO_RSV35,		// インフェルノ35、リザーブ35
	__GF_TIMEATK_1_INFERNO_RSV36,		// インフェルノ36、リザーブ36
	__GF_TIMEATK_1_INFERNO_RSV37,		// インフェルノ37、リザーブ37
	__GF_TIMEATK_1_INFERNO_RSV38,		// インフェルノ38、リザーブ38
	GF_TIMEATK_1_INFERNO_RUSH,		// インフェルノ39、ボスラッシュ

	GF_TIMEATK_1_INFERNO_ED,

	// 現代編パーティメンバー

		// EASY現代編パーティメンバー用
	GF_TIMEATK_M_EASY_ST = GF_TIMEATK_1_INFERNO_ED,
	GF_TIMEATK_M_EASY_M0111 = GF_TIMEATK_M_EASY_ST,	// イージー00、１部、ビフテリザ
	GF_TIMEATK_M_EASY_B150,	// イージー01、１部、アヴァロドラギル
	GF_TIMEATK_M_EASY_B100,	// イージー02、２部、セルペンタス
	GF_TIMEATK_M_EASY_B000,	// イージー03、２部、クラリオン
	GF_TIMEATK_M_EASY_B101B,	// イージー04、２部、ロンブリゲウス
	GF_TIMEATK_M_EASY_B001,	// イージー05、２部、グルガンチュラ
	GF_TIMEATK_M_EASY_B102,	// イージー06、２部、マガマンドラ
	GF_TIMEATK_M_EASY_B002,	// イージー07、２部、ラスピスース
	GF_TIMEATK_M_EASY_B152,	// イージー08、２部、キルゴール
	GF_TIMEATK_M_EASY_B154,	// イージー09、３部、アヴァロドラギル
	GF_TIMEATK_M_EASY_B003,	// イージー10、３部、ギアスバーン
	GF_TIMEATK_M_EASY_B006,	// イージー11、４部、ブラキオン
	GF_TIMEATK_M_EASY_B104,	// イージー12、５部、エクスメーテル
	GF_TIMEATK_M_EASY_B004,	// イージー13、５部、カルヴェロス
	GF_TIMEATK_M_EASY_B103,	// イージー14、５部、ピラティスアニマ
	GF_TIMEATK_M_EASY_B106,	// イージー15、５部、シエラカントゥス
	GF_TIMEATK_M_EASY_B007,	// イージー16、５部、オケアノス
	GF_TIMEATK_M_EASY_B105,	// イージー17、５部、ドクサ・グリエル
	GF_TIMEATK_M_EASY_B005,	// イージー18、５部、バシレウス
	GF_TIMEATK_M_EASY_B012,	// イージー19、６部、レ・エリュトロン
	GF_TIMEATK_M_EASY_B112,	// イージー20、６部、アニムス・ヒドゥラ
	GF_TIMEATK_M_EASY_B110,	// イージー21、６部、アニムス・ミノス
	GF_TIMEATK_M_EASY_B111,	// イージー22、６部、アニムス・ネストール
	GF_TIMEATK_M_EASY_B008,	// イージー23、６部、アニムス・ウーラ
	GF_TIMEATK_M_EASY_B021_1,	// イージー24、６部、テオス・デ・エンドログラム１
	GF_TIMEATK_M_EASY_B021_2,	// イージー25、６部、テオス・デ・エンドログラム２
	GF_TIMEATK_M_EASY_B021_3,	// イージー26、６部、テオス・デ・エンドログラム３
	GF_TIMEATK_M_EASY_B009,	// イージー28、７部、はじまりの命・子
	GF_TIMEATK_M_EASY_B010,	// イージー28、７部、はじまりの命・親
	GF_TIMEATK_M_EASY_B155,	// イージー29、シルヴィア
	GF_TIMEATK_M_EASY_B151,	// イージー30、マスターコング
	GF_TIMEATK_M_EASY_B153,	// イージー31、６部、メフォラシュム
	GF_TIMEATK_M_EASY_B170,	// イージー32、６部、◆仮名：２週目ダンジョンボス
	__GF_TIMEATK_M_EASY_RSV33,// イージー34、リザーブ33
	__GF_TIMEATK_M_EASY_RSV34,// イージー34、リザーブ34
	__GF_TIMEATK_M_EASY_RSV35,// イージー35、リザーブ35
	__GF_TIMEATK_M_EASY_RSV36,// イージー36、リザーブ36
	__GF_TIMEATK_M_EASY_RSV37,// イージー37、リザーブ37
	__GF_TIMEATK_M_EASY_RSV38,// イージー38、リザーブ38
	GF_TIMEATK_M_EASY_RUSH,	// イージー39、ボスラッシュ

	GF_TIMEATK_M_EASY_ED,

		// NORMAL現代編パーティメンバー用
	GF_TIMEATK_M_NORMAL_ST = GF_TIMEATK_M_EASY_ED,
	GF_TIMEATK_M_NORMAL_M0111 = GF_TIMEATK_M_NORMAL_ST,	// ノーマル00、１部、ビフテリザ
	GF_TIMEATK_M_NORMAL_B150,		// ノーマル01、１部、アヴァロドラギル
	GF_TIMEATK_M_NORMAL_B100,		// ノーマル02、２部、セルペンタス
	GF_TIMEATK_M_NORMAL_B000,		// ノーマル03、２部、クラリオン
	GF_TIMEATK_M_NORMAL_B101B,	// ノーマル04、２部、ロンブリゲウス
	GF_TIMEATK_M_NORMAL_B001,		// ノーマル05、２部、グルガンチュラ
	GF_TIMEATK_M_NORMAL_B102,		// ノーマル06、２部、マガマンドラ
	GF_TIMEATK_M_NORMAL_B002,		// ノーマル07、２部、ラスピスース
	GF_TIMEATK_M_NORMAL_B152,		// ノーマル08、２部、キルゴール
	GF_TIMEATK_M_NORMAL_B154,		// ノーマル09、３部、アヴァロドラギル
	GF_TIMEATK_M_NORMAL_B003,		// ノーマル10、３部、ギアスバーン
	GF_TIMEATK_M_NORMAL_B006,		// ノーマル11、４部、ブラキオン
	GF_TIMEATK_M_NORMAL_B104,		// ノーマル12、５部、エクスメーテル
	GF_TIMEATK_M_NORMAL_B004,		// ノーマル13、５部、カルヴェロス
	GF_TIMEATK_M_NORMAL_B103,		// ノーマル14、５部、ピラティスアニマ
	GF_TIMEATK_M_NORMAL_B106,		// ノーマル15、５部、シエラカントゥス
	GF_TIMEATK_M_NORMAL_B007,		// ノーマル16、５部、オケアノス
	GF_TIMEATK_M_NORMAL_B105,		// ノーマル17、５部、ドクサ・グリエル
	GF_TIMEATK_M_NORMAL_B005,		// ノーマル18、５部、バシレウス
	GF_TIMEATK_M_NORMAL_B012,		// ノーマル19、６部、レ・エリュトロン
	GF_TIMEATK_M_NORMAL_B112,		// ノーマル20、６部、アニムス・ヒドゥラ
	GF_TIMEATK_M_NORMAL_B110,		// ノーマル21、６部、アニムス・ミノス
	GF_TIMEATK_M_NORMAL_B111,		// ノーマル22、６部、アニムス・ネストール
	GF_TIMEATK_M_NORMAL_B008,		// ノーマル23、６部、アニムス・ウーラ
	GF_TIMEATK_M_NORMAL_B021_1,	// ノーマル24、６部、テオス・デ・エンドログラム１
	GF_TIMEATK_M_NORMAL_B021_2,	// ノーマル25、６部、テオス・デ・エンドログラム２
	GF_TIMEATK_M_NORMAL_B021_3,	// ノーマル26、６部、テオス・デ・エンドログラム３
	GF_TIMEATK_M_NORMAL_B009,		// ノーマル27、７部、はじまりの命・子
	GF_TIMEATK_M_NORMAL_B010,		// ノーマル28、７部、はじまりの命・親
	GF_TIMEATK_M_NORMAL_B155,	// ノーマル29、シルヴィア
	GF_TIMEATK_M_NORMAL_B151,	// ノーマル30、マスターコング
	GF_TIMEATK_M_NORMAL_B153,		// ノーマル31、６部、メフォラシュム
	GF_TIMEATK_M_NORMAL_B170,	// ノーマル32、６部、◆仮名：２週目ダンジョンボス
	__GF_TIMEATK_M_NORMAL_RSV33,	// ノーマル34、リザーブ33
	__GF_TIMEATK_M_NORMAL_RSV34,	// ノーマル34、リザーブ34
	__GF_TIMEATK_M_NORMAL_RSV35,	// ノーマル35、リザーブ35
	__GF_TIMEATK_M_NORMAL_RSV36,	// ノーマル36、リザーブ36
	__GF_TIMEATK_M_NORMAL_RSV37,	// ノーマル37、リザーブ37
	__GF_TIMEATK_M_NORMAL_RSV38,	// ノーマル38、リザーブ38
	GF_TIMEATK_M_NORMAL_RUSH,		// ノーマル39、ボスラッシュ

	GF_TIMEATK_M_NORMAL_ED,

		// HARD現代編パーティメンバー用
	GF_TIMEATK_M_HARD_ST = GF_TIMEATK_M_NORMAL_ED,
	GF_TIMEATK_M_HARD_M0111 = GF_TIMEATK_M_HARD_ST,		// ハード00、１部、ビフテリザ
	GF_TIMEATK_M_HARD_B150,		// ハード01、１部、アヴァロドラギル
	GF_TIMEATK_M_HARD_B100,		// ハード02、２部、セルペンタス
	GF_TIMEATK_M_HARD_B000,		// ハード03、２部、クラリオン
	GF_TIMEATK_M_HARD_B101B,		// ハード04、２部、ロンブリゲウス
	GF_TIMEATK_M_HARD_B001,		// ハード05、２部、グルガンチュラ
	GF_TIMEATK_M_HARD_B102,		// ハード06、２部、マガマンドラ
	GF_TIMEATK_M_HARD_B002,		// ハード07、２部、ラスピスース
	GF_TIMEATK_M_HARD_B152,		// ハード08、２部、キルゴール
	GF_TIMEATK_M_HARD_B154,		// ハード09、３部、アヴァロドラギル
	GF_TIMEATK_M_HARD_B003,		// ハード10、３部、ギアスバーン
	GF_TIMEATK_M_HARD_B006,		// ハード11、４部、ブラキオン
	GF_TIMEATK_M_HARD_B104,		// ハード12、５部、エクスメーテル
	GF_TIMEATK_M_HARD_B004,		// ハード13、５部、カルヴェロス
	GF_TIMEATK_M_HARD_B103,		// ハード14、５部、ピラティスアニマ
	GF_TIMEATK_M_HARD_B106,		// ハード15、５部、シエラカントゥス
	GF_TIMEATK_M_HARD_B007,		// ハード16、５部、オケアノス
	GF_TIMEATK_M_HARD_B105,		// ハード17、５部、ドクサ・グリエル
	GF_TIMEATK_M_HARD_B005,		// ハード18、５部、バシレウス
	GF_TIMEATK_M_HARD_B012,		// ハード19、６部、レ・エリュトロン
	GF_TIMEATK_M_HARD_B112,		// ハード20、６部、アニムス・ヒドゥラ
	GF_TIMEATK_M_HARD_B110,		// ハード21、６部、アニムス・ミノス
	GF_TIMEATK_M_HARD_B111,		// ハード22、６部、アニムス・ネストール
	GF_TIMEATK_M_HARD_B008,		// ハード23、６部、アニムス・ウーラ
	GF_TIMEATK_M_HARD_B021_1,		// ハード24、６部、テオス・デ・エンドログラム１
	GF_TIMEATK_M_HARD_B021_2,		// ハード25、６部、テオス・デ・エンドログラム２
	GF_TIMEATK_M_HARD_B021_3,		// ハード26、６部、テオス・デ・エンドログラム３
	GF_TIMEATK_M_HARD_B009,		// ハード27、７部、はじまりの命・子
	GF_TIMEATK_M_HARD_B010,		// ハード28、７部、はじまりの命・親
	GF_TIMEATK_M_HARD_B155,		// ハード29、シルヴィア
	GF_TIMEATK_M_HARD_B151,		// ハード30、マスターコング
	GF_TIMEATK_M_HARD_B153,		// ハード31、６部、メフォラシュム
	GF_TIMEATK_M_HARD_B170,		// ハード32、６部、◆仮名：２週目ダンジョンボス
	__GF_TIMEATK_M_HARD_RSV33,	// ハード33、リザーブ33
	__GF_TIMEATK_M_HARD_RSV34,	// ハード34、リザーブ34
	__GF_TIMEATK_M_HARD_RSV35,	// ハード35、リザーブ35
	__GF_TIMEATK_M_HARD_RSV36,	// ハード36、リザーブ36
	__GF_TIMEATK_M_HARD_RSV37,	// ハード37、リザーブ37
	__GF_TIMEATK_M_HARD_RSV38,	// ハード38、リザーブ38
	GF_TIMEATK_M_HARD_RUSH,		// ハード39、ボスラッシュ

	GF_TIMEATK_M_HARD_ED,

		// NIGHTMARE現代編パーティメンバー用
	GF_TIMEATK_M_NIGHTMARE_ST = GF_TIMEATK_M_HARD_ED,
	GF_TIMEATK_M_NIGHTMARE_M0111 = GF_TIMEATK_M_NIGHTMARE_ST,	// ナイトメア00、１部、ビフテリザ
	GF_TIMEATK_M_NIGHTMARE_B150,		// ナイトメア01、１部、アヴァロドラギル
	GF_TIMEATK_M_NIGHTMARE_B100,		// ナイトメア02、２部、セルペンタス
	GF_TIMEATK_M_NIGHTMARE_B000,		// ナイトメア03、２部、クラリオン
	GF_TIMEATK_M_NIGHTMARE_B101B,		// ナイトメア04、２部、ロンブリゲウス
	GF_TIMEATK_M_NIGHTMARE_B001,		// ナイトメア05、２部、グルガンチュラ
	GF_TIMEATK_M_NIGHTMARE_B102,		// ナイトメア06、２部、マガマンドラ
	GF_TIMEATK_M_NIGHTMARE_B002,		// ナイトメア07、２部、ラスピスース
	GF_TIMEATK_M_NIGHTMARE_B152,		// ナイトメア08、２部、キルゴール
	GF_TIMEATK_M_NIGHTMARE_B154,		// ナイトメア09、３部、アヴァロドラギル
	GF_TIMEATK_M_NIGHTMARE_B003,		// ナイトメア10、３部、ギアスバーン
	GF_TIMEATK_M_NIGHTMARE_B006,		// ナイトメア11、４部、ブラキオン
	GF_TIMEATK_M_NIGHTMARE_B104,		// ナイトメア12、５部、エクスメーテル
	GF_TIMEATK_M_NIGHTMARE_B004,		// ナイトメア13、５部、カルヴェロス
	GF_TIMEATK_M_NIGHTMARE_B103,		// ナイトメア14、５部、ピラティスアニマ
	GF_TIMEATK_M_NIGHTMARE_B106,		// ナイトメア15、５部、シエラカントゥス
	GF_TIMEATK_M_NIGHTMARE_B007,		// ナイトメア16、５部、オケアノス
	GF_TIMEATK_M_NIGHTMARE_B105,		// ナイトメア17、５部、ドクサ・グリエル
	GF_TIMEATK_M_NIGHTMARE_B005,		// ナイトメア18、５部、バシレウス
	GF_TIMEATK_M_NIGHTMARE_B012,		// ナイトメア19、６部、レ・エリュトロン
	GF_TIMEATK_M_NIGHTMARE_B112,		// ナイトメア20、６部、アニムス・ヒドゥラ
	GF_TIMEATK_M_NIGHTMARE_B110,		// ナイトメア21、６部、アニムス・ミノス
	GF_TIMEATK_M_NIGHTMARE_B111,		// ナイトメア22、６部、アニムス・ネストール
	GF_TIMEATK_M_NIGHTMARE_B008,		// ナイトメア23、６部、アニムス・ウーラ
	GF_TIMEATK_M_NIGHTMARE_B021_1,	// ナイトメア24、６部、テオス・デ・エンドログラム１
	GF_TIMEATK_M_NIGHTMARE_B021_2,	// ナイトメア25、６部、テオス・デ・エンドログラム２
	GF_TIMEATK_M_NIGHTMARE_B021_3,	// ナイトメア26、６部、テオス・デ・エンドログラム３
	GF_TIMEATK_M_NIGHTMARE_B009,		// ナイトメア27、７部、はじまりの命・子
	GF_TIMEATK_M_NIGHTMARE_B010,		// ナイトメア28、７部、はじまりの命・親
	GF_TIMEATK_M_NIGHTMARE_B155,		// ナイトメア29、シルヴィア
	GF_TIMEATK_M_NIGHTMARE_B151,		// ナイトメア30、マスターコング
	GF_TIMEATK_M_NIGHTMARE_B153,		// ナイトメア31、６部、メフォラシュム
	GF_TIMEATK_M_NIGHTMARE_B170,		// ナイトメア32、６部、◆仮名：２週目ダンジョンボス
	__GF_TIMEATK_M_NIGHTMARE_RSV33,	// ナイトメア33、リザーブ33
	__GF_TIMEATK_M_NIGHTMARE_RSV34,	// ナイトメア34、リザーブ34
	__GF_TIMEATK_M_NIGHTMARE_RSV35,	// ナイトメア35、リザーブ35
	__GF_TIMEATK_M_NIGHTMARE_RSV36,	// ナイトメア36、リザーブ36
	__GF_TIMEATK_M_NIGHTMARE_RSV37,	// ナイトメア37、リザーブ37
	__GF_TIMEATK_M_NIGHTMARE_RSV38,	// ナイトメア38、リザーブ38
	GF_TIMEATK_M_NIGHTMARE_RUSH,		// ナイトメア39、ボスラッシュ

	GF_TIMEATK_M_NIGHTMARE_ED,

		// INFERNO現代編パーティメンバー用
	GF_TIMEATK_M_INFERNO_ST = GF_TIMEATK_M_NIGHTMARE_ED,
	GF_TIMEATK_M_INFERNO_M0111 = GF_TIMEATK_M_INFERNO_ST,	// インフェルノ00、１部、ビフテリザ
	GF_TIMEATK_M_INFERNO_B150,		// インフェルノ01、１部、アヴァロドラギル
	GF_TIMEATK_M_INFERNO_B100,		// インフェルノ02、２部、セルペンタス
	GF_TIMEATK_M_INFERNO_B000,		// インフェルノ03、２部、クラリオン
	GF_TIMEATK_M_INFERNO_B101B,		// インフェルノ04、２部、ロンブリゲウス
	GF_TIMEATK_M_INFERNO_B001,		// インフェルノ05、２部、グルガンチュラ
	GF_TIMEATK_M_INFERNO_B102,		// インフェルノ06、２部、マガマンドラ
	GF_TIMEATK_M_INFERNO_B002,		// インフェルノ07、２部、ラスピスース
	GF_TIMEATK_M_INFERNO_B152,		// インフェルノ08、２部、キルゴール
	GF_TIMEATK_M_INFERNO_B154,		// インフェルノ09、３部、アヴァロドラギル
	GF_TIMEATK_M_INFERNO_B003,		// インフェルノ10、３部、ギアスバーン
	GF_TIMEATK_M_INFERNO_B006,		// インフェルノ11、４部、ブラキオン
	GF_TIMEATK_M_INFERNO_B104,		// インフェルノ12、５部、エクスメーテル
	GF_TIMEATK_M_INFERNO_B004,		// インフェルノ13、５部、カルヴェロス
	GF_TIMEATK_M_INFERNO_B103,		// インフェルノ14、５部、ピラティスアニマ
	GF_TIMEATK_M_INFERNO_B106,		// インフェルノ15、５部、シエラカントゥス
	GF_TIMEATK_M_INFERNO_B007,		// インフェルノ16、５部、オケアノス
	GF_TIMEATK_M_INFERNO_B105,		// インフェルノ17、５部、ドクサ・グリエル
	GF_TIMEATK_M_INFERNO_B005,		// インフェルノ18、５部、バシレウス
	GF_TIMEATK_M_INFERNO_B012,		// インフェルノ19、６部、レ・エリュトロン
	GF_TIMEATK_M_INFERNO_B112,		// インフェルノ20、６部、アニムス・ヒドゥラ
	GF_TIMEATK_M_INFERNO_B110,		// インフェルノ21、６部、アニムス・ミノス
	GF_TIMEATK_M_INFERNO_B111,		// インフェルノ22、６部、アニムス・ネストール
	GF_TIMEATK_M_INFERNO_B008,		// インフェルノ23、６部、アニムス・ウーラ
	GF_TIMEATK_M_INFERNO_B021_1,		// インフェルノ24、６部、テオス・デ・エンドログラム１
	GF_TIMEATK_M_INFERNO_B021_2,		// インフェルノ25、６部、テオス・デ・エンドログラム２
	GF_TIMEATK_M_INFERNO_B021_3,		// インフェルノ26、６部、テオス・デ・エンドログラム３
	GF_TIMEATK_M_INFERNO_B009,		// インフェルノ27、７部、はじまりの命・子
	GF_TIMEATK_M_INFERNO_B010,		// インフェルノ28、７部、はじまりの命・親
	GF_TIMEATK_M_INFERNO_B155,		// インフェルノ29、シルヴィア
	GF_TIMEATK_M_INFERNO_B151,		// インフェルノ30、マスターコング
	GF_TIMEATK_M_INFERNO_B153,		// インフェルノ31、６部、メフォラシュム
	GF_TIMEATK_M_INFERNO_B170,		// インフェルノ32、６部、◆仮名：２週目ダンジョンボス
	__GF_TIMEATK_M_INFERNO_RSV33,		// インフェルノ33、リザーブ33
	__GF_TIMEATK_M_INFERNO_RSV34,		// インフェルノ34、リザーブ34
	__GF_TIMEATK_M_INFERNO_RSV35,		// インフェルノ35、リザーブ35
	__GF_TIMEATK_M_INFERNO_RSV36,		// インフェルノ36、リザーブ36
	__GF_TIMEATK_M_INFERNO_RSV37,		// インフェルノ37、リザーブ37
	__GF_TIMEATK_M_INFERNO_RSV38,		// インフェルノ38、リザーブ38
	GF_TIMEATK_M_INFERNO_RUSH,		// インフェルノ39、ボスラッシュ

	GF_TIMEATK_M_INFERNO_ED,

	// ダーナ編

		// ダーナ編EASY用
	GF_TIMEATK_D_EASY_ST = GF_TIMEATK_M_INFERNO_ED,

	GF_TIMEATK_D_EASY_B161 = GF_TIMEATK_D_EASY_ST,		// ダーナ編イージー00、◆仮名：第１層、中ボス
	GF_TIMEATK_D_EASY_B162,			// ダーナ編イージー01、◆仮名：第２層、中ボス
	GF_TIMEATK_D_EASY_B163,			// ダーナ編イージー02、◆仮名：第３層、中ボス
	GF_TIMEATK_D_EASY_B011,			// ダーナ編イージー03、６部、レ・キュアノス
	GF_TIMEATK_D_EASY_B164,			// ダーナ編イージー04、◆仮名：第４層、中ボス
	GF_TIMEATK_D_EASY_B165,			// ダーナ編イージー05、◆仮名：第５層、中ボス
	GF_TIMEATK_D_EASY_B030,			// ダーナ編イージー06、◆仮名：イオ
	__GF_TIMEATK_D_EASY_RSV07,		// ダーナ編イージー07、リザーブ07
	__GF_TIMEATK_D_EASY_RSV08,		// ダーナ編イージー08、リザーブ08
	GF_TIMEATK_D_EASY_RUSH,			// ダーナ編イージー09、ボスラッシュ

	GF_TIMEATK_D_EASY_ED,

		// ダーナ編NORMAL用
	GF_TIMEATK_D_NORMAL_ST = GF_TIMEATK_D_EASY_ED,

	GF_TIMEATK_D_NORMAL_B161 = GF_TIMEATK_D_NORMAL_ST,		// ダーナ編ノーマル00、◆仮名：第１層、中ボス
	GF_TIMEATK_D_NORMAL_B162,		// ダーナ編ノーマル01、◆仮名：第２層、中ボス
	GF_TIMEATK_D_NORMAL_B163,		// ダーナ編ノーマル02、◆仮名：第３層、中ボス
	GF_TIMEATK_D_NORMAL_B011,		// ダーナ編ノーマル03、６部、レ・キュアノス
	GF_TIMEATK_D_NORMAL_B164,		// ダーナ編ノーマル04、◆仮名：第４層、中ボス
	GF_TIMEATK_D_NORMAL_B165,		// ダーナ編ノーマル05、◆仮名：第５層、中ボス
	GF_TIMEATK_D_NORMAL_B030,		// ダーナ編ノーマル06、◆仮名：イオ
	__GF_TIMEATK_D_NORMAL_RSV07,	// ダーナ編ノーマル07、リザーブ07
	__GF_TIMEATK_D_NORMAL_RSV08,	// ダーナ編ノーマル08、リザーブ08
	GF_TIMEATK_D_NORMAL_RUSH,		// ダーナ編ノーマル09、ボスラッシュ

	GF_TIMEATK_D_NORMAL_ED,

		// ダーナ編HARD用
	GF_TIMEATK_D_HARD_ST = GF_TIMEATK_D_NORMAL_ED,

	GF_TIMEATK_D_HARD_B161 = GF_TIMEATK_D_HARD_ST,		// ダーナ編ハード00、◆仮名：第１層、中ボス
	GF_TIMEATK_D_HARD_B162,			// ダーナ編ハード01、◆仮名：第２層、中ボス
	GF_TIMEATK_D_HARD_B163,			// ダーナ編ハード02、◆仮名：第３層、中ボス
	GF_TIMEATK_D_HARD_B011,			// ダーナ編ハード03、６部、レ・キュアノス
	GF_TIMEATK_D_HARD_B164,			// ダーナ編ハード04、◆仮名：第４層、中ボス
	GF_TIMEATK_D_HARD_B165,			// ダーナ編ハード05、◆仮名：第５層、中ボス
	GF_TIMEATK_D_HARD_B030,			// ダーナ編ハード06、◆仮名：イオ
	__GF_TIMEATK_D_HARD_RSV07,		// ダーナ編ハード07、リザーブ07
	__GF_TIMEATK_D_HARD_RSV08,		// ダーナ編ハード08、リザーブ08
	GF_TIMEATK_D_HARD_RUSH,			// ダーナ編ハード09、ボスラッシュ

	GF_TIMEATK_D_HARD_ED,

		// ダーナ編NIGHTMARE用
	GF_TIMEATK_D_NIGHTMARE_ST = GF_TIMEATK_D_HARD_ED,

	GF_TIMEATK_D_NIGHTMARE_B161 = GF_TIMEATK_D_NIGHTMARE_ST,		// ダーナ編ナイトメア00、◆仮名：第１層、中ボス
	GF_TIMEATK_D_NIGHTMARE_B162,	// ダーナ編ナイトメア01、◆仮名：第２層、中ボス
	GF_TIMEATK_D_NIGHTMARE_B163,	// ダーナ編ナイトメア02、◆仮名：第３層、中ボス
	GF_TIMEATK_D_NIGHTMARE_B011,	// ダーナ編ナイトメア03、６部、レ・キュアノス
	GF_TIMEATK_D_NIGHTMARE_B164,	// ダーナ編ナイトメア04、◆仮名：第４層、中ボス
	GF_TIMEATK_D_NIGHTMARE_B165,	// ダーナ編ナイトメア05、◆仮名：第５層、中ボス
	GF_TIMEATK_D_NIGHTMARE_B030,	// ダーナ編ナイトメア06、◆仮名：イオ
	__GF_TIMEATK_D_NIGHTMARE_RSV07,	// ダーナ編ナイトメア07、リザーブ07
	__GF_TIMEATK_D_NIGHTMARE_RSV08,	// ダーナ編ナイトメア08、リザーブ08
	GF_TIMEATK_D_NIGHTMARE_RUSH,	// ダーナ編ナイトメア09、ボスラッシュ

	GF_TIMEATK_D_NIGHTMARE_ED,

		// ダーナ編INFERNO用
	GF_TIMEATK_D_INFERNO_ST = GF_TIMEATK_D_NIGHTMARE_ED,

	GF_TIMEATK_D_INFERNO_B161 = GF_TIMEATK_D_INFERNO_ST,		// ダーナ編インフェルノ00、◆仮名：第１層、中ボス
	GF_TIMEATK_D_INFERNO_B162,		// ダーナ編インフェルノ01、◆仮名：第２層、中ボス
	GF_TIMEATK_D_INFERNO_B163,		// ダーナ編インフェルノ02、◆仮名：第３層、中ボス
	GF_TIMEATK_D_INFERNO_B011,		// ダーナ編インフェルノ03、６部、レ・キュアノス
	GF_TIMEATK_D_INFERNO_B164,		// ダーナ編インフェルノ04、◆仮名：第４層、中ボス
	GF_TIMEATK_D_INFERNO_B165,		// ダーナ編インフェルノ05、◆仮名：第５層、中ボス
	GF_TIMEATK_D_INFERNO_B030,		// ダーナ編インフェルノ06、◆仮名：イオ
	__GF_TIMEATK_D_INFERNO_RSV07,	// ダーナ編インフェルノ07、リザーブ07
	__GF_TIMEATK_D_INFERNO_RSV08,	// ダーナ編インフェルノ08、リザーブ08
	GF_TIMEATK_D_INFERNO_RUSH,		// ダーナ編インフェルノ09、ボスラッシュ

	GF_TIMEATK_D_INFERNO_ED,

	GF_TIMEATK_END = GF_TIMEATK_D_INFERNO_ED,

	// タイムアタックここまで
	//--------------------------------------------------------------------

	GF_MENUSAVE2_START = 8950,	// 過去メニューの項目位置保持関連のセーブ用
	GF_MENUSAVE2_ITEM_DIARY1=GF_MENUSAVE2_START,	// 過去[項目ID]ストーリー・クエスト
	GF_MENUSAVE2_ITEM_DIARY2,	// 過去[項目ID]人物・Aボイス
	GF_MENUSAVE2_ITEM_DIARY3,	// 過去[項目ID]料理・釣り
	GF_MENUSAVE2_ITEM_DIARY4,	// 過去[項目ID]モンスター・素材
	GF_MENUSAVE2_ITEM_DIARY5,	// 過去[項目ID]ヘルプ・最新ストーリーフラグ
	GF_MENUSAVE2_SCR_DIARY1,	// 過去[項目位置]ストーリー・クエスト
	GF_MENUSAVE2_SCR_DIARY2,	// 過去[項目位置]人物・Aボイス
	GF_MENUSAVE2_SCR_DIARY3,	// 過去[項目位置]料理・釣り
	GF_MENUSAVE2_SCR_DIARY4,	// 過去[項目位置]モンスター・素材
	GF_MENUSAVE2_SCR_DIARY5,	// 過去[項目位置]ヘルプ・(予備)
	GF_MENUSAVE2_END,			// 過去メニューの項目位置保持関連のセーブ用ここまで

	GF_RESERVE_MAX,				// 予備フラグここまで（フラグ数チェック用なので、GLOBAL_FLAG_MAX直前に置くように）

	GLOBAL_FLAG_MAX,			// グローバルフラグ　ここまで


	FLAG_MAX = 9000,			// フラグ全部でここまで


	FLAG_RESERVE_MAX = 9000,	// フラグマックスのリザーブ
};
#define SYSTEMSAVE_GALLERY_FLAG_MAX		256
#define SYSTEMSAVE_TIMEATK_FLAG_MAX		1000

// 迎撃戦シーンボイス、ランダム再生時にキャラが喋れないようにする為のテンポラリフラグ（vo_scene.csvで使っている）
enum
{
	// 迎撃戦しゃべる許可フラグ　NPC
	TF_VOICEOK_ST = 150,

	TF_VOICEOK_BARBAROSS = TF_VOICEOK_ST,		// 00:バルバロス船長
	TF_VOICEOK_DOGI,							// 01:ドギ
	TF_VOICEOK_ALISON,							// 02:アリスン
	TF_VOICEOK_KIERGAARD,						// 03:キルゴール
	TF_VOICEOK_CURRAN,							// 04:カーラン卿
	TF_VOICEOK_KATRIN,							// 05:カトリーン
	TF_VOICEOK_AARON,							// 06:エアラン
	TF_VOICEOK_DINA,							// 07:ディナ
	TF_VOICEOK_LICHT,							// 08:リヒト
	TF_VOICEOK_REJA,							// 09:レーヤ
	TF_VOICEOK_MIRALDA,							// 10:ミラルダ
	TF_VOICEOK_KUINA,							// 11:クイナ
	TF_VOICEOK_NIA,								// 12:シスターニア
	TF_VOICEOK_KASHU,							// 13:カシュー
	TF_VOICEOK_FRANZ,							// 14:フランツ
	TF_VOICEOK_THANATOS,						// 15:タナトス
	TF_VOICEOK_ED,								// 16:エド				// ※綴り不明
	TF_VOICEOK_GRISELDA,						// 17:グリゼルダ
	TF_VOICEOK_AUSTEN,							// 18:オースティン		// ※綴り不明
	TF_VOICEOK_SILVIA,							// 19:シルビア			// ※綴り不明
	TF_VOICEOK_CURRAN_B,						// 20:カーラン卿2（後半用）
	TF_VOICEOK_AUSTEN2,							// 21:オースティン２
	TF_VOICEOK_PARO,							// 22:リトル・パロ
	TF_VOICEOK_SKILLMONKY,						// 23:スキルザル
	TF_VOICEOK_BALAENICEPS_REX,					// 24:ハシビロコウ

	// 迎撃戦しゃべる許可フラグ　PC
	TF_VOICEOK_ADOL,							// アドル
	TF_VOICEOK_LAXIA,							// ラクシャ
	TF_VOICEOK_SAHAD,							// サハド
	TF_VOICEOK_HUMMEL,							// ヒュンメル
	TF_VOICEOK_RICOTTA,							// リコッタ
	TF_VOICEOK_DANA,							// ダーナ

	// 特殊分岐
	TF_VOICEOK_KUINA_A,							// クイナ（マップ海側）
	TF_VOICEOK_KUINA_B,							// クイナ（マップ山側）
	TF_VOICEOK_NIA_A,							// シスター・ニア（前半専用）
	TF_VOICEOK_NIA_B,							// シスター・ニア（後半専用）
	TF_VOICEOK_AUSTEN_A,						// オースティン（前半戦用）		// ※綴り不明
	TF_VOICEOK_AUSTEN_B,						// オースティン（後半戦用）		// ※綴り不明
	TF_VOICEOK_PARO_A,							// リトル・パロ（スキル・与ダメージアップ）
	TF_VOICEOK_PARO_B,							// リトル・パロ（スキル・被ダメージダウン）
	TF_VOICEOK_PARO_C,							// リトル・パロ（スキル・クリティカルアップ）
	TF_VOICEOK_PARO_D,							// リトル・パロ（スキル・戦況ゲージＭＡＸ）

	TF_VOICEOK_FINISH,
};

// システムフラグとして扱うGF
#define SF_MAP_NAME_NO_DRAW		GF_MPxxxx_MAP_NAME_NO_DRAW

	// ボイス分岐用フラグの別名定義（フラグが決まったら０を入れ替える必要あり）
#define SF_CHANGEVOICE_CURRAN	GF_SUBEV_JOIN_CURRAN2	// カーラン卿のボイスを切り替える
#define SF_CHNAGEVOICE_NIA		DF_QS311_END			// シスター・ニアのボイスを切り替える
#define SF_CHANGEVOICE_AUSTEN	DF_QS522_END			// オースティンのボイスを切り替える
#define SF_VOICE_LAXIA_2ND		GF_02MP1201_LOST_CURRAN	// リコッタ後半
#define SF_VOICE_RICOTTA_2ND	GF_04MP6101_MAKE_CAMP	// リコッタ後半

// 互換性の為に残してある
#define	SF_DOGI_JOINOK		SF_SAHAD_JOINOK				// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）
#define	SF_AISHA_JOINOK		SF_LAXIA_JOINOK			// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）
#define	SF_GEIS_JOINOK		SF_HUMMEL_JOINOK				// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）
#define SF_KRSHE_JOINOK		SF_RICOTTA_JOINOK			// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）
#define SF_MISHERA_JOINOK	SF_DANA_JOINOK				// パーティー加入可能！（０－加入不可　１－入れ替え自由　２－強制）

#define SF_WING_LIMIT		SF_WARP_DISABLED			// ウィング制限

// 廃止したフラグ、互換性の為に残してある
#define SF_TAME_SPEED_UP		0	// 無効なフラグ番号を設定
#define SF_WING_LIMIT_SEGRAM	0	// 無効なフラグ番号を設定

// 難易度フラグの中身用
#define DIFFICULT_NORMAL		0x000		// ノーマル
#define DIFFICULT_HARD			0x001		// HARDフラグ
#define DIFFICULT_NIGHTMARE		0x002		// NIGHTMAREフラグ
#define DIFFICULT_EASY			0x004		// EASYフラグ


// クエスト場所定義
enum
{
	QUEST_NOBOARD = 0,			// 掲示板じゃないよ
	QUEST_CASNAN,				// キャスナン
	QUEST_COMODO,				// コモド
	QUEST_SELRAY,				// セルレイ
	QUEST_HIGHLAND,				// ハイランド
	QUEST_DANAN,				// ダナン
	QUEST_ELDUKE,				// エルドゥーク
	QUEST_OTHERS,				// その他
};


// マップ名定義ファイルの定義用
enum{
	MN_NONE = 0,				// 未登録用に置いてある

	// F001：セイレン島・西部
	MN_F_SOUTHWEST_PLANE_MP1101,	// 南西部
	MN_F_SOUTHWEST_PLANE_MP1102,	// 南西部
	MN_F_SOUTHWEST_PLANE_MP1103,	// 南西部
	MN_F_SOUTHWEST_PLANE_MP1104,	// 南西部
	MN_F_SOUTHWEST_PLANE_MP1110,	// 南西部
	MN_F_SOUTHWEST_PLANE_MP1111,	// 南西部
	MN_F_SOUTHWEST_PLANE_MP1131,	// 南西部
	MN_F_SOUTHWEST_PLANE_MP1112,	// 南西部
	MN_F_SOUTHWEST_PLANE_MP2101,	// 南西部
	MN_F_SOUTHWEST_PLANE_MP1105,	// 南西部
	MN_F_SOUTHWEST_PLANE_MP1106,	// 南西部

	// MP120x：漂流村
	MN_T_VILLAGE_MP1201,			// 拠点
	MN_T_VILLAGE_MP1202,			// 拠点
	MN_T_VILLAGE_MP1201_2,			// 拠点（名前変更後）
	MN_T_VILLAGE_MP1202_2,			// 拠点（名前変更後）

	// MP730x：朽ちた穴倉
	MN_D_CELLAR_MP7301,				// 穴倉１
	MN_D_CELLAR_MP7302,				// 穴倉２
	MN_D_CELLAR_MP7303,				// 穴倉３
	MN_D_CELLAR_MP7304,				// 穴倉４
	MN_D_CELLAR_MP7305,				// 穴倉・嘆きの断崖

	//MP130x：珊瑚の森
	MN_D_MP1301,		// 珊瑚の森
	MN_D_MP1302,		// 珊瑚の森
	MN_D_MP1303,		// 珊瑚の森
	MN_D_MP1304,		// 珊瑚の森
	MN_D_MP1305,		// 珊瑚の森
	MN_D_MP1306,		// 珊瑚の森
	MN_D_MP1307,		// 珊瑚の森
	MN_D_MP1308,		// 珊瑚の森
	MN_D_MP1309,		// 珊瑚の森

	//MP230x：密林
	MN_D_MP2301,		// 密林 
	MN_D_MP2302,		// 密林 
	MN_D_MP2303,		// 密林 
	MN_D_MP2304,		// 密林 
	MN_D_MP2305,		// 密林 
	MN_D_MP2306,		// 密林 
	MN_D_MP2307,		// 密林 
	MN_D_MP2308,		// 密林 

	//MP430x：浸食谷
	MN_D_MP4301,		// 浸食谷
	MN_D_MP4302,		// 浸食谷
	MN_D_MP4303,		// 浸食谷
	MN_D_MP4304,		// 浸食谷
	MN_D_MP4305,		// 浸食谷
	MN_D_MP4306,		// 浸食谷
	MN_D_MP4307,		// 浸食谷
	MN_D_MP4308,		// 浸食谷

	// ◆F002：中央部
	MN_F_MP1120,
	MN_F_MP1121,
	MN_F_MP1107,		// 吊り橋　※スクリプトで使用済み。変更するときは一緒に変更。
	MN_F_MP3103,
	MN_F_MP3104,
	MN_F_MP2102,
	
	// ◆F003：東部
	MN_F_MP1108,
	MN_F_MP1109,
	MN_F_MP4102,
	MN_F_MP2103,
	
	// ◆F004：喜望峰
	MN_F_MP1116,
	
	// ◆F005：西部・南端（珊瑚礁）
	MN_F_MP1113,
	MN_F_MP1132,
	MN_F_MP1133,
	MN_F_MP1134,
	
	// F006：西部高原・(風見の高原)
	MN_F_MP3101,
	MN_F_MP3102,
	
	// F007：中央高原
	MN_F_MP3105,
	MN_F_MP3106,
	MN_F_MP3107,
	MN_F_MP3108,
	MN_F_MP3109,
	MN_F_MP4101,

	// 大峡谷(植樹祭)
	MN_F_MP3109m,
	MN_F_MP3110m,
	MN_F_MP3111m,

	// ◆F008：遠鳴り浜
	MN_F_MP1117,
	MN_F_MP1135,
	
	// ◆F009：漂流浜
	MN_F_MP1118,
	
	// ◆F010：漂流浜
	MN_F_MP1119,

	// ◆F011：濃霧の森
	MN_F_MP2104,
	MN_F_MP2105,
	MN_F_MP2106,
	
	// ◆F012：霞の海岸
	MN_F_MP1114,
	MN_F_MP1115,

	// ◆F013：離れ島
	MN_F_MP1122,
	MN_F_MP1123,

	// ◆F031：風雲山道
	MN_F_MP4103,
	MN_F_MP4104,
	MN_F_MP4106,
	MN_F_MP4108,
	MN_F_MP7101,
	MN_F_MP7102,

	// ◆F032：王都
	MN_F_MP6201,
	MN_F_MP6202,
	MN_F_MP6203,
	MN_F_MP6204,
	MN_F_MP6211,
	MN_F_MP6212,
	MN_F_MP6213,
	MN_F_MP6214,
	MN_F_MP6215,


	// ◆F033：原生林
	MN_F_MP5101,
	MN_F_MP5102,
	MN_F_MP5103,

	// ◆F034：太古の大平原
	MN_F_MP6101,
	MN_F_MP6102,
	MN_F_MP6111,
	MN_F_MP6112,
	MN_F_MP6116,

	// ◆F035：トワル街道
	MN_F_MP6103,
	MN_F_MP6104,
	MN_F_MP6110,
	MN_F_MP6115,

	// ◆F036：天涯丘陵
	MN_F_MP4110,
	MN_F_MP5104,

	// ◆F037：湿原地帯
	MN_F_MP6105,
	MN_F_MP6106,
	MN_F_MP6107,
	MN_F_MP6108,
	MN_F_MP6113,
	MN_F_MP6114,
	
	// ◆F038：悠久の丘
	MN_F_MP6109,

	// ◆F039：聖域への山道
	MN_F_MP4105,
	MN_F_MP4109,
	MN_F_MP4111,

	//MP433x：ジャンダルム
	MN_D_MP4331,
	MN_D_MP4332,
	MN_D_MP4333,
	MN_D_MP4334,
	MN_D_MP4335,
	MN_D_MP4336,
	MN_D_MP4337,
	MN_D_MP4338,
	MN_D_MP4339,
	MN_D_MP4340,
	MN_D_MP4341,
	MN_F_MP4107,
	MN_D_MP4342,
	
	MN_F_MP4202,	//小屋

	// ◆FXXXM：過去編フィールド
	MN_F_MPXXXM,


	// ◆大樹寺院(過去）
	MN_F_MP6401m,
	MN_F_MP6402m,
	MN_F_MP6408m,
	MN_F_MP6409m,
	MN_F_MP6410m,


	// ◆大樹寺院(現在）
	MN_D_MP6401,
	MN_D_MP6402,
	MN_D_MP6408,
	MN_D_MP6409,
	MN_D_MP6410,


	// ◆大樹寺院(過去）
	MN_F_MP6409v2,
	
	
	// ◆王都室内(現在）
	MN_D_MP6211,
	MN_D_MP6214,

	// ◆王都室内(過去）
	MN_F_MP6211m,
	MN_F_MP6212m,
	MN_F_MP6213m,
	MN_F_MP6214m,
	MN_F_MP6215m,
	MN_F_MP6216m,
	MN_F_MP6222m,
	MN_F_MP6222m2,
	MN_F_MP6231m,

	// ◆ロンバルディア号
	MN_F_MP0011,
	MN_F_MP0012,
	MN_F_MP0013,
	MN_F_MP0014,
	MN_F_MP0015,
	MN_F_MP0016,
	MN_F_MP0017,
	MN_F_MP0018,

	// ◆幽霊船
	MN_D_MP0401,
	MN_D_MP0402,
	MN_D_MP0403,
	MN_D_MP0404,
	MN_D_MP0405,
	MN_D_MP0406,
	MN_D_MP0407,
	MN_D_MP0408,
	
	// ◆王家の谷
	MN_D_MP6341,		// 王家の谷・複層広間
	MN_D_MP6342,		// 王家の谷・小部屋１
	MN_D_MP6343,		// 王家の谷・小部屋２
	MN_D_MP6344,		// 王家の谷・小部屋３
	MN_D_MP6345,		// 王家の谷・中ボス部屋
	MN_D_MP6346,		// 王家の谷・後半大部屋１
	MN_D_MP6347,		// 王家の谷・後半大部屋２
	MN_D_MP6349,		// 王家の谷・大ボス部屋
	MN_D_MP6350,		// 王家の谷・剣安置部屋・復活前
	MN_D_MP6350m,		// 王家の谷・剣安置部屋・過去
	MN_D_MP6350v1,		// 王家の谷・剣安置部屋・復活後
	MN_D_MP6351,		// 王家の谷・壁画部屋

	// ◆ラスダン・共通部分
	MN_D_MP6301,		// ラスダン・大空間（天ｴﾘｱ）
	MN_D_MP6302,		// ラスダン・大空間（海ｴﾘｱ）
	MN_D_MP6303,		// ラスダン・大空間（氷ｴﾘｱ）
	MN_D_MP6304,		// ラスダン・大空間（蟲ｴﾘｱ）

	// ◆ラスダン・海エリア
	MN_D_MP6305,		// 海エリア・攻略
	MN_D_MP6305b,		// 海エリア・ボス

	// ◆ラスダン・氷エリア
	MN_D_MP6306,		// 氷エリア・攻略
	MN_D_MP6306b,		// 氷エリア・ボス

	// ◆ラスダン・蟲エリア
	MN_D_MP6307,		// 蟲エリア・攻略
	MN_D_MP6307b,		// 蟲エリア・ボス

	// ◆ラスダン・天エリア
	MN_D_MP6308,		// 天エリア・攻略
	MN_D_MP6308b,		// 天エリア・ボス

	// ◆ラスダン・ラスボスエリア
	MN_D_MP6310,		// ラスボスエリア・攻略
	MN_D_MP6310b,		// ラスボスエリア・ボス

	// ◆バハの斜塔
	MN_D_MP6321,		// バハの斜塔・下層１
	MN_D_MP6322,		// バハの斜塔・下層２
	MN_D_MP6323,		// バハの斜塔・下層３
	MN_D_MP6324,		// バハの斜塔・回廊１
	MN_D_MP6325,		// バハの斜塔・中ボス部屋
	MN_D_MP6326,		// バハの斜塔・上層１
	MN_D_MP6327,		// バハの斜塔・回廊２
	MN_D_MP6328,		// バハの斜塔・上層２
	MN_D_MP6329,		// バハの斜塔・ボス部屋
	MN_D_MP6330,		// バハの斜塔・最上階

	// ◆始生代の大穴
	MN_D_MP6361,		// 始生代の大穴・王宮跡１
	MN_D_MP6362,		// 始生代の大穴・外観
	MN_D_MP6363,		// 始生代の大穴・洞窟１
	MN_D_MP6364,		// 始生代の大穴・洞窟２
	MN_D_MP6365,		// 始生代の大穴・洞窟３
	MN_D_MP6366,		// 始生代の大穴・中ボスマップ
	MN_D_MP6367,		// 始生代の大穴・洞窟４
	MN_D_MP6368,		// 始生代の大穴・王宮跡２
	MN_D_MP6369,		// 始生代の大穴・王宮跡３
	MN_D_MP6370,		// 始生代の大穴・ボスマップ

	// ◆浸食谷
	MN_D_EROSIONVALLEY_MP4301,		// 浸食谷
	MN_D_EROSIONVALLEY_MP4302,		// 浸食谷
	MN_D_EROSIONVALLEY_MP4303,		// 浸食谷
	MN_D_EROSIONVALLEY_MP4304,		// 浸食谷
	MN_D_EROSIONVALLEY_MP4305,		// 浸食谷
	MN_D_EROSIONVALLEY_MP4306,		// 浸食谷
	MN_D_EROSIONVALLEY_MP4307,		// 浸食谷
	MN_D_EROSIONVALLEY_MP4308,		// 浸食谷
	MN_D_EROSIONVALLEY_MP4309,		// 浸食谷
		
	// ◆埋没した塔
	MN_D_MP6411,					// 埋没した塔
	MN_D_MP6412,					// 埋没した塔
	MN_D_MP6413,					// 埋没した塔
	
	// ◆MP832x：はじまりの深淵
	MN_D_MP8321,					// はじまりの深淵入口
	MN_D_MP8322,					// はじまりの深淵通路
	MN_D_MP8323,					// はじまりの深淵ボスマップ

	// ◆大僧院
	MN_D_MP6421,
	MN_D_MP6422,

	// ◆古代種の住処
	MN_D_MP5401,	

	// ◆古代の洞窟
	MN_D_MP7401,	

	// ◆沖の洞窟
	MN_D_MP7411,

	// ◆水源地
	MN_D_MP7451,
	MN_D_MP7452,

	// ◆地下水脈
	MN_D_MP7461,
	MN_D_MP7462,

	// ◆鍾乳洞
	MN_D_MP7471,
	MN_D_MP7472,

	// ◆水没墓地
	MN_D_MP7481,
	MN_D_MP7482,

	// ◆大石柱の風穴
	MN_D_MP7491,
	MN_D_MP7492,

	// ◆脱出船
	MN_F_MP0021,


	// ◆過去編フィールド
	MN_F_MP4105M,
	MN_F_MP5103M,
	MN_F_MP5104M,
	MN_F_MP6101M,
	MN_F_MP6103M,
	MN_F_MP6104M,
	MN_F_MP6106M,
	MN_F_MP6107M,
	MN_F_MP6108M,
	MN_F_MP6110M,
	MN_F_MP6112M,
	MN_F_MP6113M,
	MN_F_MP6114M,
	MN_F_MP6201M,
	MN_F_MP6202M,
	MN_F_MP6203M,
	MN_F_MP6204M,

	MN_DIARY_OTHER,		// 植樹祭			過去編・ダーナ①
	MN_DIARY_OTHER2,	// 謁見と再会と		過去編・ダーナ③
	MN_DIARY_OTHER3,	// 赤毛の剣士		過去編Ⅰ
	MN_DIARY_OTHER4,	// 導きの苗木		過去編Ⅱ
	MN_DIARY_OTHER5,	// お転婆巫女の一日	過去編Ⅲ
	MN_DIARY_OTHER6,	// 冥暗				過去編Ⅳ
	MN_DIARY_OTHER7,	// 運命の日			過去編Ⅳ－２
	MN_DIARY_OTHER8,	// 昏き空の下で		過去編Ⅴ
	MN_DIARY_OTHER9,	// 悲壮なる決意		過去編Ⅵ

//追加分
	MN_D_MP6409B,

// ◆過去編追加ダンジョン
	MN_D_MP6511M,
	MN_D_MP6512M,
	MN_D_MP6513M,
	MN_D_MP6514M,
	MN_D_MP6515M,
	MN_D_MP6519M,
	MN_D_MP6521M,
	MN_D_MP6522M,
	MN_D_MP6523M,
	MN_D_MP6524M,
	MN_D_MP6529M,
	MN_D_MP6531M,
	MN_D_MP6532M,
	MN_D_MP6539M,
	MN_D_MP6541M,
	MN_D_MP6542M,
	MN_D_MP6549M,
	MN_D_MP6551M,
	MN_D_MP6552M,
	MN_D_MP6553M,
	MN_D_MP6554M,
	MN_D_MP6559M,
	MN_D_MP6561M,
	MN_D_MP6569M,

	MN_D_MP6511,
	MN_D_MP6512,
	MN_D_MP6513,
	MN_D_MP6519,
	MN_D_MP6521,
	MN_D_MP6522,
	MN_D_MP6529,
	MN_D_MP6531,
	MN_D_MP6532,
	MN_D_MP6539,
	MN_D_MP6541,
	MN_D_MP6542,
	MN_D_MP6549,
	MN_D_MP6551,
	MN_D_MP6552,
	MN_D_MP6553,
	MN_D_MP6554,
	MN_D_MP6555,
	MN_D_MP6559,
	MN_D_MP6561,
	MN_D_MP6569,
	
// ◆夜ダンジョン
	//MP130x：珊瑚の森
	MN_D_MP1301T2,		// 珊瑚の森
	MN_D_MP1302T2,		// 珊瑚の森
	MN_D_MP1303T2,		// 珊瑚の森
	MN_D_MP1304T2,		// 珊瑚の森
	MN_D_MP1305T2,		// 珊瑚の森
	MN_D_MP1306T2,		// 珊瑚の森
	MN_D_MP1307T2,		// 珊瑚の森
	MN_D_MP1308T2,		// 珊瑚の森
	MN_D_MP1309T2,		// 珊瑚の森

	//MP433x：ジャンダルム
	MN_D_MP4331T2,
	MN_D_MP4332T2,
	MN_D_MP4333T2,
	MN_D_MP4334T2,
	MN_D_MP4335T2,
	MN_D_MP4336T2,
	MN_D_MP4337T2,
	MN_D_MP4338T2,
	MN_D_MP4339T2,
	MN_D_MP4340T2,
	MN_D_MP4341T2,
	MN_D_MP4342T2,

	// ◆F034：太古の大平原
	MN_F_MP6101T2,
	MN_F_MP6102T2,
	MN_F_MP6111T2,
	MN_F_MP6112T2,
	MN_F_MP6116T2,

	//過去編アクティブボイスでっちあげ定義：過去編Ⅶ用
	MN_DIARY_OTHER10,			//過去編Ⅶ用
	MN_DIARY_OTHER11,			//過去編・地下聖堂用



	//// ▼ys8 マップ名ＩＤ定義はここまで ////
	//////////////////////////////////////////







	MN_MAX,							// マップ名定義、最大値
};


// レコード用定義ＩＤ
enum{
	// 総合
	RD_PLAYTIME = 0,			// プレイ時間
	RD_TOTALMOVE,				// 総移動距離
	RD_MAPRATIO,				// 総合探索率
	RD_NPCNUM,					// 漂流村人数（支援可能人数）
	RD_TBOXRATIO,				// 宝箱発見率
	RD_MATRATIO,				// 採取ポイント発見率
	RD_LOCATIONRATIO,			// ロケーションポイント発見率
	RD_VILLAGELV_RATIO,			// 漂流村強化率
	RD_LIKE_RATIO,				// 好感度達成率
	RD_COOP_RATIO,				// 支援イベント達成率
	RD_FAME_RATIO,				// 名声値
	RD_VIRTURE_RATIO,			// ダーナの徳
	RD_FAME_RATIO2,				// 名声値
	RD_VIRTURE_RATIO2,			// ダーナの徳
	//RD_PASTDUNGEON,				// 地下聖堂踏破率

	// エリア探索率
	RD_AREA_TITLE,				// 
	RD_AREA_S,					// ↓エリアここから
	RD_AREA01=RD_AREA_S,		// 漂流村
	RD_AREA02,					// 名知らず海岸
	RD_AREA03,					// 水音の洞窟
	RD_AREA04,					// 白浜岬
	RD_AREA05,					// 隆起珊瑚の森
	RD_AREA06,					// 遠鳴り浜
	RD_AREA07,					// 大峡谷流域
	RD_AREA08,					// 滝裏の鍾乳洞
	RD_AREA09,					// 獣たちの丘
	RD_AREA10,					// 浸食谷
	RD_AREA11,					// 日の出ヶ浜
	RD_AREA12,					// 風見丘陵
	RD_AREA13,					// 水源の滝
	RD_AREA14,					// ◆地下水脈
	RD_AREA15,					// ロングフォーン海岸
	RD_AREA16,					// 水と森の丘
	RD_AREA17,					// シュラム密林地帯
	RD_AREA18,					// 奇岩海岸
	RD_AREA19,					// 古代種の抜け道
	RD_AREA20,					// ジャンダルム
	RD_AREA21,					// 西麓高原
	RD_AREA22,					// 古王の巌窟
	RD_AREA23,					// 天崖山道
	RD_AREA24,					// テンペル参道
	RD_AREA25,					// ティティス原始林
	RD_AREA26,					// 古代種の住処
	RD_AREA27,					// パンガイア大平原
	RD_AREA28,					// エタニア王都遺跡
	RD_AREA29,					// 大樹の寺院
	RD_AREA30,					// 大石柱の風穴
	RD_AREA31,					// トワル街道
	RD_AREA32,					// バハの斜塔
	RD_AREA33,					// 望郷岬
	RD_AREA34,					// 東の海岸洞窟
	RD_AREA35,					// 海賊船エレフセリア号
	RD_AREA36,					// 始生代の大穴
	RD_AREA37,					// 見晴らし峠
	RD_AREA38,					// ロディニア湖沼地帯
	RD_AREA39,					// ボラド大僧院
	RD_AREA40,					// 水没墓地
	RD_AREA41,					// 王家の谷
	RD_AREA42,					// 悠久の丘
	RD_AREA43,					// ひとり島
	RD_AREA44,					// 沈黙の塔
	RD_AREA45,					// 見届けの丘
	RD_AREA46,					// 海の道
	RD_AREA47,					// 氷の道
	RD_AREA48,					// 蟲の道
	RD_AREA49,					// 天の道
	RD_AREA50,					// 選択の間
	RD_AREA51,					// ◆大樹の寺院・裏庭

	RD_AREA_E,					// ↑エリアここまで

	// 戦闘
	RD_NUMKILLEDMONS=RD_AREA_E,	// モンスター撃破数
	RD_NUMKILLEDDRAGON,			// 竜型古代種撃破数
	RD_NUMSKILLFINISH,			// スキルフィニッシュ発動回数
	RD_NUMBRAKE,				// ブレイク発動回数
	RD_NUMFLASHGUARD,			// フラッシュガード発動回数
	RD_NUMFLASHMOVE,			// フラッシュムーブ発動回数
	RD_NUMEXSKILL,				// エクストラスキル発動回数
	RD_SPACE01,					// 空白
	RD_INTERCEPT,				// 迎撃戦評価
	RD_INTERCEPT_BAT01,			// INTERCEPT_STAGE01
	RD_INTERCEPT_BAT02,			// INTERCEPT_STAGE02
	RD_INTERCEPT_BAT03,			// INTERCEPT_STAGE03
	RD_INTERCEPT_BAT04,			// INTERCEPT_STAGE04
	RD_INTERCEPT_BAT05,			// INTERCEPT_STAGE05
	RD_INTERCEPT_BAT06,			// INTERCEPT_STAGE06
	RD_INTERCEPT_BAT07,			// INTERCEPT_STAGE07
	RD_INTERCEPT_BAT08,			// INTERCEPT_STAGE08
	RD_INTERCEPT_BAT09,			// INTERCEPT_STAGE09
	RD_INTERCEPT_BAT11,			// INTERCEPT_STAGE11
	RD_INTERCEPT_BAT12,			// INTERCEPT_STAGE12
	RD_INTERCEPT_BAT21,			// INTERCEPT_STAGE21
	RD_INTERCEPT_BAT22,			// INTERCEPT_STAGE22
	RD_INTERCEPT_BAT23,			// INTERCEPT_STAGE23
	RD_INTERCEPT_BAT24,			// INTERCEPT_STAGE24
	RD_INTERCEPT_BAT25,			// INTERCEPT_STAGE25
	RD_INTERCEPT_BAT26,			// INTERCEPT_STAGE26
	RD_INTERCEPT_BAT27,			// INTERCEPT_STAGE27
	RD_SPACE01B,				// 空白
	RD_INTERCEPT_C,				// 迎撃戦評価
	RD_INTERCEPT_C_BAT01,		// INTERCEPT_STAGE31
	RD_INTERCEPT_C_BAT02,		// INTERCEPT_STAGE32
	RD_INTERCEPT_C_BAT03,		// INTERCEPT_STAGE33
	RD_INTERCEPT_C_BAT04,		// INTERCEPT_STAGE34
	RD_INTERCEPT_C_BAT05,		// INTERCEPT_STAGE35
	RD_INTERCEPT_C_BAT06,		// INTERCEPT_STAGE36
	RD_INTERCEPT_C_BAT07,		// INTERCEPT_STAGE37
	RD_INTERCEPT_C_BAT08,		// INTERCEPT_STAGE38
	RD_INTERCEPT_C_BAT09,		// INTERCEPT_STAGE39

	// コレクション
	RD_DIARY_CHARA,				// 冒険日誌「人物」開封率
	RD_DIARY_COOK,				// 冒険日誌「料理」開封率
	RD_DIARY_FISH,				// 冒険日誌「釣り」開封率
	RD_DIARY_MONSTER,			// 冒険日誌「モンスター」開封率（暴魚以外）
	RD_DIARY_MATERIAL,			// 冒険日誌「素材・食材」開封率
	RD_SPACE02,					// 空白
	RD_QUEST_RATIO,				// クエスト達成率
	RD_PASTQUEST_RATIO,			// エタニアクエスト達成率
	RD_PASTQUEST_01,			// 　忘れ去られた水路
	RD_PASTQUEST_02,			// 　双子のかくれんぼ
	RD_PASTQUEST_03,			// 　水底に消えた鍵
	RD_PASTQUEST_04,			// 　竜種討伐①
	RD_PASTQUEST_05,			// 　巫女の施し
	RD_PASTQUEST_06,			// 　古き祝福の大扉
	RD_PASTQUEST_07,			// 　はぐれた避難民
	RD_PASTQUEST_08,			// 　竜種討伐②
	RD_PASTQUEST_09,			// 　竜種討伐③
	RD_PASTQUEST_10,			// 　枯れゆく大地に恵みを
	RD_PASTQUEST_11,			// 　◆追加エタニアクエスト
	RD_PASTSPIRIT_RATIO,		// エタニア精霊救出率
	RD_PASTSPIRIT_01,			// 　◆精霊01
	RD_PASTSPIRIT_02,			// 　◆精霊02
	RD_PASTSPIRIT_03,			// 　◆精霊03
	RD_PASTSPIRIT_04,			// 　◆精霊04
	RD_PASTSPIRIT_05,			// 　◆精霊05
	RD_PASTSPIRIT_06,			// 　◆精霊06
	RD_PASTSPIRIT_07,			// 　◆精霊07
	RD_PASTSPIRIT_08,			// 　◆精霊08
	RD_PASTSPIRIT_09,			// 　◆精霊09
	RD_PASTSPIRIT_10,			// 　◆精霊10

	//追加分
	RD_PASTDUNGEON_00,			//地下聖堂
	RD_PASTDUNGEON_01,			//地下聖堂１層
	RD_PASTDUNGEON_02,			//地下聖堂２層
	RD_PASTDUNGEON_03,			//地下聖堂３層
	RD_PASTDUNGEON_04,			//地下聖堂４層
	RD_PASTDUNGEON_05,			//地下聖堂５層
	RD_PASTDUNGEON_06,			//地下聖堂６層

	RD_SPACE03,					// 空白
	RD_ITEMALLRATIO,			// アイテム収集率（◆※ＤＬＣは含めない）
	RD_ITEM_MATRATIO,			// 汎用素材
	RD_ITEM_RMATRATIO,			// レア素材
	RD_ITEM_DRUGBTLRATIO,		// 瓶薬
	RD_ITEM_DRUGRATIO,			// 固形薬
	RD_ITEM_FOODRATIO,			// 果物
	RD_ITEM_COOKRATIO,			// 料理
	RD_ITEM_COOKSTUFFRATIO,		// 食材
	RD_ITEM_FISHRATIO,			// 魚
	RD_ITEM_MAGICRATIO,			// 冒険具
	RD_ITEM_WEAPONRATIO,		// 武器
	RD_ITEM_ARMORRATIO,			// 体防具
	RD_ITEM_RINGRATIO,			// 腕防具
	RD_ITEM_ACCESSORYRATIO,		// アクセサリ
	RD_ITEM_DRESSRATIO,			// 衣装(コスチューム)
	RD_ITEM_ATTACHRATIO,		// アタッチ(コスチューム)
	RD_ITEM_BOOKRATIO,			// 書物
	RD_ITEM_INVRATIO,			// 大事な物
	//RD_SPACE01,					// スペース

	RD_MAX
};
// レコード表示定義用
enum{
	// 総合
	RD_SHOW_FLAG= 0,			// フラグ
	RD_SHOW_MINIMAP,			// ミニマップID
	RD_SHOW_INTERCEPT,			// 迎撃戦闘ID
	RD_SHOW_KIND_MAX,
};

// 日誌ストーリー、定義ＩＤ
enum{
	DIARY_STORY = 0,		// 冒険の記録
	DIARY_TIPS,				// 発見した紙片
	DIARY_VOYAGE,			// 航海日誌
	DIARY2_STORY,			// 行動の記録
	DIARY2_MONOLITH,		// 発見したモノリス
};

// アイテムポイント用定義ＩＤ
enum{

	// 水音の洞窟_mp730x
	IP_MP7302_01 = 0,
	IP_MP7302_02,
	IP_MP7303_01,

	// 名も無き海岸
	IP_MP1102_01,
	IP_MP1102_02,
	IP_MP1102_03,
	IP_MP1102_04,

	IP_MP1131_01,
	IP_MP1131_02,
	IP_MP1131_03,
	IP_MP1131_04,
	IP_MP1131_05,

	IP_MP1111_01,
	IP_MP1111_02,
	IP_MP1111_03,
	IP_MP1111_04,
	IP_MP1111_05,
	IP_MP1111_06,

	IP_MP1104_01,
	IP_MP1104_02,
	IP_MP1104_03,
	IP_MP1104_04,
	IP_MP1104_05,
	IP_MP1104_06,

	IP_MP1112_01,
	IP_MP1112_02,
	IP_MP1112_03,
	IP_MP1112_04,
	IP_MP1112_05,
	IP_MP1112_06,
	IP_MP1112_07,
	IP_MP1112_08,
	IP_MP1112_09,
//	IP_MP1112_10,
//	IP_MP1112_11,

	IP_MP2101_01,
	IP_MP2101_02,
	IP_MP2101_03,
	IP_MP2101_04,
	IP_MP2101_05,

	IP_MP1105_01,
	IP_MP1105_02,

	IP_MP1106_01,
	IP_MP1106_02,
	IP_MP1106_03,

	// 珊瑚礁
	IP_MP1113_01,
	IP_MP1113_02,
	IP_MP1113_03,
	IP_MP1113_04,

	IP_MP1132_01,
	IP_MP1132_02,
	IP_MP1132_03,
	IP_MP1132_04,
//	IP_MP1132_05,
//	IP_MP1132_06,

	IP_MP1133_01,
	IP_MP1133_02,
	IP_MP1133_03,

	IP_MP1134_01,
	IP_MP1134_02,

	// 珊瑚の森
	IP_MP1301_01,
	IP_MP1301_02,
	IP_MP1301_03,

	IP_MP1302_01,
	IP_MP1302_02,
	IP_MP1302_03,
	IP_MP1302_04,
	IP_MP1302_05,
	IP_MP1302_06,
//	IP_MP1302_07,

	IP_MP1303_01,
	IP_MP1303_02,
	IP_MP1303_03,
	IP_MP1303_04,
	IP_MP1303_05,
	IP_MP1303_06,

	IP_MP1304_01,
	IP_MP1304_02,
	IP_MP1304_03,
	IP_MP1304_04,
	IP_MP1304_05,
	IP_MP1304_06,
	IP_MP1304_07,
	IP_MP1304_08,

	IP_MP1305_01,
	IP_MP1305_02,

	IP_MP1307_01,
	IP_MP1307_02,
//	IP_MP1307_03,
//	IP_MP1307_04,

	// 西の浜辺
	IP_MP1117_01,
	IP_MP1117_02,
	IP_MP1117_03,
	IP_MP1117_04,
	
	IP_MP1135_01,
	IP_MP1135_02,
	IP_MP1135_03,
	IP_MP1135_04,
	IP_MP1135_05,
	IP_MP1135_06,
	IP_MP1135_07,
	IP_MP1135_08,
	IP_MP1135_09,
	IP_MP1135_10,
	IP_MP1135_11,
	IP_MP1135_12,
	IP_MP1135_13,
	
	// 島中央部
	IP_MP2102_01,
	IP_MP2102_02,
	IP_MP2102_03,
	IP_MP2102_04,
	IP_MP2102_05,
	IP_MP2102_06,
	IP_MP2102_07,
	IP_MP2102_08,
	IP_MP2102_09,
//	IP_MP2102_10,
	
	IP_MP1107_01,
	IP_MP1107_02,
	IP_MP1107_03,
	IP_MP1107_04,
	IP_MP1107_05,
	IP_MP1107_06,

	IP_MP1120_01,
	IP_MP1120_02,
	IP_MP1120_03,
	IP_MP1120_04,
	IP_MP1120_05,
	IP_MP1120_06,
	IP_MP1120_07,

	IP_MP3103_01,
	IP_MP3103_02,
	IP_MP3103_03,

	IP_MP3104_01,
	IP_MP3104_02,
	IP_MP3104_03,
	IP_MP3104_04,
//	IP_MP3104_05,
//	IP_MP3104_06,
//	IP_MP3104_07,
//	IP_MP3104_08,

	// 島東部
	IP_MP1108_01,
	IP_MP1108_02,
	IP_MP1108_03,
	IP_MP1108_04,
	IP_MP1108_05,
	IP_MP1108_06,
	IP_MP1108_07,
	IP_MP1108_08,

	IP_MP4102_01,
	IP_MP4102_02,

	IP_MP2103_01,

	IP_MP1109_01,
	IP_MP1109_02,
	IP_MP1109_03,
	IP_MP1109_04,
	IP_MP1109_05,

	// 浸食谷
	IP_MP4301_01,
	IP_MP4301_02,
	IP_MP4301_03,
	IP_MP4301_04,
	IP_MP4301_05,
	IP_MP4301_06,
	IP_MP4301_07,
	IP_MP4301_08,
	IP_MP4301_09,

	IP_MP4302_01,
	IP_MP4302_02,
	IP_MP4302_03,
	IP_MP4302_04,
	IP_MP4302_05,
	IP_MP4302_06,

	IP_MP4303_01,
	IP_MP4303_02,
	IP_MP4303_03,
	IP_MP4303_04,
	IP_MP4303_05,
	IP_MP4303_06,
	IP_MP4303_07,
	IP_MP4303_08,

	IP_MP4304_01,
	IP_MP4304_02,

	IP_MP4305_01,
	IP_MP4305_02,
	IP_MP4305_03,
	IP_MP4305_04,
	IP_MP4305_05,

	IP_MP4307_01,
	IP_MP4307_02,
	IP_MP4307_03,
	IP_MP4307_04,
	IP_MP4307_05,
	IP_MP4307_06,
	IP_MP4307_07,
	IP_MP4307_08,
	IP_MP4307_09,
	IP_MP4307_10,

	IP_MP4308_01,
	IP_MP4308_02,
	IP_MP4308_03,

	// 北東の浜辺
	IP_MP1119_01,
	IP_MP1119_02,
	IP_MP1119_03,
	IP_MP1119_04,

	//風見の高原
	IP_MP3101_01,
	IP_MP3101_02,
	IP_MP3101_03,

	IP_MP3102_01,
	IP_MP3102_02,
	IP_MP3102_03,
	IP_MP3102_04,

	// 水源地_mp745x
	IP_MP7451_01,
	IP_MP7451_02,
	IP_MP7451_03,
	IP_MP7451_04,
	IP_MP7451_05,
//	IP_MP7451_06,	追加分は後ろに
//	IP_MP7451_07,
//	IP_MP7451_08,
//	IP_MP7451_09,
//	IP_MP7451_10,
//	IP_MP7451_11,
//	IP_MP7451_12,
	// 地下水脈_mp746x		オケアノス後
	IP_MP7461_01,
	IP_MP7461_02,
	IP_MP7461_03,
	IP_MP7461_04,
	IP_MP7461_05,
	IP_MP7461_06,
	IP_MP7461_07,
	IP_MP7461_08,
	IP_MP7461_09,
	IP_MP7461_10,

	IP_MP7462_01,
	IP_MP7462_02,
	IP_MP7462_03,
	IP_MP7462_04,
	IP_MP7462_05,
	IP_MP7462_06,
	IP_MP7462_07,
	IP_MP7462_08,
	IP_MP7462_09,
	IP_MP7462_10,

	// 霧の海岸
	IP_MP1114_01,
	IP_MP1114_02,
	IP_MP1114_03,
	IP_MP1114_04,
	IP_MP1114_05,
	IP_MP1114_06,
	IP_MP1114_07,
	IP_MP1114_08,
	IP_MP1114_09,

	IP_MP1115_01,
	IP_MP1115_02,
	IP_MP1115_03,
	IP_MP1115_04,
//	IP_MP1115_05,
//	IP_MP1115_06,
//	IP_MP1115_07,

	// 濃霧の森
	IP_MP2105_01,
	IP_MP2105_02,
	IP_MP2105_03,
	IP_MP2105_04,
	IP_MP2105_05,
	IP_MP2105_06,

	// 密林
	IP_MP2301_01,
	IP_MP2301_02,
	IP_MP2301_03,
	IP_MP2301_04,
	IP_MP2301_05,
	IP_MP2301_06,

	IP_MP2302_01,
	IP_MP2302_02,
	IP_MP2302_03,
	IP_MP2302_04,
	IP_MP2302_05,
	IP_MP2302_06,
	IP_MP2302_07,

	IP_MP2303_01,
	IP_MP2303_02,
	IP_MP2303_03,

	IP_MP2304_01,

	IP_MP2305_01,
	IP_MP2305_02,
	IP_MP2305_03,

	IP_MP2306_01,
	IP_MP2306_02,
	IP_MP2306_03,
	IP_MP2306_04,
	IP_MP2306_05,
	IP_MP2306_06,
	IP_MP2306_07,
	IP_MP2306_08,
//	IP_MP2306_09,	//後ろに追加
//	IP_MP2306_10,
//	IP_MP2306_11,
//	IP_MP2306_12,
//	IP_MP2306_13,
//	IP_MP2306_14,
//	IP_MP2306_15,

	IP_MP2307_01,
	IP_MP2307_02,

	// 奇岩浜
	IP_MP1118_01,
	IP_MP1118_02,

// 高原エリア_mp31xx
	IP_MP3109_01,
	IP_MP3109_02,
	IP_MP3109_03,
	IP_MP3109_04,
	IP_MP3109_05,
	IP_MP3109_06,
//	IP_MP3109_07,
//	IP_MP3109_08,
//	IP_MP3109_09,

// ジャンダルム_mp433x
	IP_MP4331_01,
	IP_MP4331_02,
	IP_MP4331_03,
	IP_MP4331_04,
	IP_MP4331_05,

	IP_MP4332_01,
	IP_MP4332_02,
	IP_MP4332_03,
	IP_MP4332_04,

	IP_MP4333_01,
	IP_MP4333_02,
	IP_MP4333_03,
	IP_MP4333_04,
	IP_MP4333_05,
	IP_MP4333_06,

	IP_MP4334_01,
	IP_MP4334_02,
	IP_MP4334_03,
	IP_MP4334_04,
	IP_MP4334_05,
	IP_MP4334_06,
	IP_MP4334_07,
	IP_MP4334_08,
	IP_MP4334_09,

// 高原エリア_mp31xx
	IP_MP3108_01,
	IP_MP3108_02,
	IP_MP3108_03,

	IP_MP3106_01,
	IP_MP3106_02,
	IP_MP3106_03,
//	IP_MP3106_04,
//	IP_MP3106_05,

	IP_MP3107_01,
	IP_MP3107_02,
	IP_MP3107_03,
	IP_MP3107_04,
	IP_MP3107_05,
	IP_MP3107_06,
	IP_MP3107_07,
	IP_MP3107_08,
	IP_MP3107_09,
	IP_MP3107_10,
// 古代の洞窟
	IP_MP7401_01,
	IP_MP7401_02,
	IP_MP7401_03,

// ジャンダルム_mp433x
	IP_MP4336_01,
	IP_MP4336_02,
	IP_MP4336_03,
	IP_MP4336_04,
	IP_MP4336_05,
	IP_MP4336_06,

	IP_MP4338_01,
	IP_MP4338_02,
	IP_MP4338_03,
	IP_MP4338_04,

	IP_MP4339_01,
	IP_MP4339_02,

	IP_MP4340_01,
	IP_MP4340_02,
	IP_MP4340_03,
	IP_MP4340_04,
	IP_MP4340_05,

// 山岳エリア_mp41xx
	IP_MP4103_01,
	IP_MP4103_02,
	IP_MP4103_03,
	IP_MP4103_04,
	IP_MP4103_05,
	IP_MP4103_06,
	IP_MP4103_07,
	IP_MP4103_08,

	IP_MP7101_01,
	IP_MP7101_02,
	IP_MP7101_03,
	IP_MP7101_04,

	IP_MP4104_01,
	IP_MP4104_02,
	IP_MP4104_03,
	IP_MP4104_04,

	IP_MP4106_01,
	IP_MP4106_02,
	IP_MP4106_03,
	IP_MP4106_04,
	IP_MP4106_05,
	IP_MP4106_06,
	IP_MP4106_07,

	IP_MP4108_01,
	IP_MP4108_02,
	IP_MP4108_03,
	IP_MP4108_04,
	IP_MP4108_05,

	IP_MP7102_01,
	IP_MP7102_02,
	IP_MP7102_03,
	IP_MP7102_04,
	IP_MP7102_05,
	IP_MP7102_06,
	IP_MP7102_07,

//聖域への参道
	IP_MP4109_01,
	IP_MP4109_02,

// 幽霊船_mp04xx

// 古代原生林エリア_mp510x
	IP_MP5103_01,
	IP_MP5103_02,
	IP_MP5103_03,
//	IP_MP5103_04,
	IP_MP5102_01,
	IP_MP5102_02,
	IP_MP5102_03,
	IP_MP5102_04,
	IP_MP5102_05,
	IP_MP5102_06,
//	IP_MP5102_07,
//	IP_MP5102_08,
//	IP_MP5102_09,
	IP_MP5101_01,
	IP_MP5101_02,
	IP_MP5101_03,
	IP_MP5101_04,
//	IP_MP5101_05,	//後ろに追加

// 古代種の住処_mp540x

// 古代平原_mp61xx

	IP_MP6102_01,
	IP_MP6102_02,
	IP_MP6102_03,
	IP_MP6102_04,
	IP_MP6102_05,
	IP_MP6102_06,

	IP_MP6116_01,
	IP_MP6116_02,
	IP_MP6116_03,
	IP_MP6116_04,
	IP_MP6116_05,
	IP_MP6116_06,
	IP_MP6116_07,
	IP_MP6116_08,

	IP_MP6111_01,
	IP_MP6111_02,
	IP_MP6111_03,
	IP_MP6111_04,
	IP_MP6111_05,
	IP_MP6111_06,

	IP_MP6112_01,
	IP_MP6112_02,
	IP_MP6112_03,
	IP_MP6112_04,
	IP_MP6112_05,
	IP_MP6112_06,
	IP_MP6112_07,
	IP_MP6112_08,
	IP_MP6112_09,

//過去編・東
	IP_MP5103m_01,
	IP_MP5103m_02,
	IP_MP5103m_03,
	IP_MP5103m_04,
	IP_MP5103m_05,
	IP_MP5103m_06,
	IP_MP5103m_07,

	IP_MP6112m_01,
	IP_MP6112m_02,

// エタニア_mp62xx

// 大樹の寺院_mp640x		break_object

//トワル街道

	IP_MP6103_01,
	IP_MP6103_02,
	IP_MP6103_03,
	IP_MP6103_04,
	IP_MP6103_05,
	IP_MP6103_06,
	IP_MP6103_07,
//	IP_MP6103_08,

	IP_MP6115_01,
	IP_MP6115_02,

	IP_MP6104_01,
	IP_MP6104_02,
	IP_MP6104_03,
	IP_MP6104_04,
	IP_MP6104_05,
	IP_MP6104_06,
	IP_MP6104_07,
	IP_MP6104_08,
	IP_MP6104_09,
//	IP_MP6104_10,

//過去編・東・トワル街道
	IP_MP6103m_01,
	IP_MP6103m_02,
	IP_MP6103m_03,
	IP_MP6103m_04,
	IP_MP6103m_05,
	IP_MP6103m_06,
	IP_MP6103m_07,
	IP_MP6103m_08,

// 斜塔_mp632x
	IP_MP6322_01,
	IP_MP6322_02,
	IP_MP6322_03,
	IP_MP6322_04,
	IP_MP6322_05,

	IP_MP6323_01,
	IP_MP6323_02,
	IP_MP6323_03,
	IP_MP6323_04,

	IP_MP6324_01,
	IP_MP6324_02,
	IP_MP6324_03,
	IP_MP6324_04,
	IP_MP6324_05,

	IP_MP6326_01,
	IP_MP6326_02,
	IP_MP6326_03,

	IP_MP6328_01,
	IP_MP6328_02,
	IP_MP6328_03,
	IP_MP6328_04,

//喜望峰
	IP_MP1116_01,
	IP_MP1116_02,
	IP_MP1116_03,
	IP_MP1116_04,
//	IP_MP1116_05,
//	IP_MP1116_06,

// 海岸洞窟_mp741x
	IP_MP7411_01,
	IP_MP7411_02,
	IP_MP7411_03,
	IP_MP7411_04,
	IP_MP7411_05,

//幽霊船

// 王家の谷_mp634x
	IP_MP6341_01,
	IP_MP6341_02,
	IP_MP6341_03,
	IP_MP6341_04,
	IP_MP6341_05,
	IP_MP6341_06,
	
	IP_MP6342_01,
	IP_MP6342_02,

	IP_MP6343_01,
	IP_MP6343_02,

	IP_MP6344_01,

	IP_MP6346_01,
	IP_MP6346_02,
	IP_MP6346_03,
	IP_MP6346_04,
	IP_MP6346_05,
	IP_MP6346_06,

	IP_MP6347_01,
	IP_MP6347_02,
	IP_MP6347_03,
	IP_MP6347_04,
	IP_MP6347_05,
	IP_MP6347_06,

// 大空洞_mp636x
	IP_MP6362_01,
	IP_MP6362_02,
	IP_MP6362_03,
	IP_MP6362_04,

	IP_MP6363_01,
	IP_MP6363_02,
	IP_MP6363_03,
	IP_MP6363_04,

	IP_MP6364_01,
	IP_MP6364_02,
	IP_MP6364_03,
	IP_MP6364_04,

	IP_MP6365_01,
	IP_MP6365_02,
	IP_MP6365_03,
	IP_MP6365_04,
	IP_MP6365_05,
	IP_MP6365_06,
	IP_MP6365_07,
	IP_MP6365_08,
	IP_MP6365_09,
	IP_MP6365_10,
	IP_MP6365_11,
	IP_MP6365_12,

	IP_MP6367_01,
	IP_MP6367_02,
	IP_MP6367_03,
	IP_MP6367_04,
	IP_MP6367_05,
	IP_MP6367_06,
	IP_MP6367_07,
	IP_MP6367_08,
	IP_MP6367_09,
	IP_MP6367_10,

	IP_MP6369_01,
	IP_MP6369_02,
	IP_MP6369_03,

//天崖丘陵
	IP_MP4110_01,
	IP_MP4110_02,
	IP_MP4110_03,
	IP_MP4110_04,
	IP_MP4110_05,

	IP_MP5104_01,
	IP_MP5104_02,
	IP_MP5104_03,
	IP_MP5104_04,
	IP_MP5104_05,
	IP_MP5104_06,

//湿原地帯
	IP_MP6106_01,
	IP_MP6106_02,
	IP_MP6106_03,
	IP_MP6106_04,
	IP_MP6106_05,
	IP_MP6106_06,

	IP_MP6113_01,
	IP_MP6113_02,
	IP_MP6113_03,
	IP_MP6113_04,
	IP_MP6113_05,
	IP_MP6113_06,
	IP_MP6113_07,
//	IP_MP6113_08,		//後ろに追加

	IP_MP6107_01,
	IP_MP6107_02,
	IP_MP6107_03,
	IP_MP6107_04,
	IP_MP6107_05,
	IP_MP6107_06,
	IP_MP6107_07,
	IP_MP6107_08,
	IP_MP6107_09,

	IP_MP6114_01,
	IP_MP6114_02,
	IP_MP6114_03,
	IP_MP6114_04,
	IP_MP6114_05,
	IP_MP6114_06,
	IP_MP6114_07,

//過去編・西
	IP_MP6113m_01,
	IP_MP6113m_02,
	IP_MP6113m_03,
	IP_MP6113m_04,
	IP_MP6113m_05,

	IP_MP6106m_01,
	IP_MP6106m_02,
	IP_MP6106m_03,
	IP_MP6106m_04,
	IP_MP6106m_05,
	IP_MP6106m_06,
//	IP_MP6106m_07,
//	IP_MP6106m_08,

	IP_MP6107m_01,
	IP_MP6107m_02,
	IP_MP6107m_03,
	IP_MP6107m_04,
	IP_MP6107m_05,
	IP_MP6107m_06,
	IP_MP6107m_07,
	IP_MP6107m_08,

	IP_MP6114m_01,
	IP_MP6114m_02,
	IP_MP6114m_03,
	IP_MP6114m_04,
	IP_MP6114m_05,

	IP_MP5104m_01,
	IP_MP5104m_02,
	IP_MP5104m_03,
	IP_MP5104m_04,

	IP_MP6108m_01,
	IP_MP6108m_02,
	IP_MP6108m_03,
	IP_MP6108m_04,
	IP_MP6108m_05,

//王家の谷


//悠久の丘
	IP_MP6109_01,
	IP_MP6109_02,
	IP_MP6109_03,
	IP_MP6109_04,
	IP_MP6109_05,
	IP_MP6109_06,
	IP_MP6109_07,
//	IP_MP6109_08,	後ろに追加
//	IP_MP6109_09,
//	IP_MP6109_10,

//オクトゥス・海の回廊

//オクトゥス・氷の回廊
	IP_MP6306_01,
	IP_MP6306_02,
	IP_MP6306_03,

//オクトゥス・蟲の回廊
	IP_MP6307_01,
	IP_MP6307_02,
	IP_MP6307_03,

//オクトゥス・天の回廊
	IP_MP6308_01,
	IP_MP6308_02,
	IP_MP6308_03,

//オクトゥス・選択の間





// 埋没した塔_mp641x
	IP_MP6411_01,
	IP_MP6411_02,
	IP_MP6411_03,
	IP_MP6411_04,

	IP_MP6412_01,
	IP_MP6412_02,
	IP_MP6412_03,
	IP_MP6412_04,

	IP_MP6413_01,
	IP_MP6413_02,
	IP_MP6413_03,
	IP_MP6413_04,

// 大僧院_mp642x
// はじまりの大樹_mp630x
// 滝裏の鍾乳洞_mp747x
	IP_MP7471_01,
	IP_MP7471_02,
	IP_MP7471_03,
	IP_MP7471_04,
	IP_MP7471_05,
	IP_MP7471_06,
	IP_MP7471_07,
	IP_MP7471_08,
	IP_MP7471_09,
	IP_MP7471_10,

	IP_MP7471_11,
	IP_MP7471_12,
	IP_MP7471_13,
	IP_MP7471_14,
	IP_MP7471_15,

// 水没墓地_mp748x

// 大石柱の風穴_mp749x
	IP_MP7491_01,
	IP_MP7491_02,
	IP_MP7491_03,
	IP_MP7491_04,
	IP_MP7491_05,
	IP_MP7491_06,
	IP_MP7491_07,
	IP_MP7491_08,
	IP_MP7491_09,
	IP_MP7491_10,
	IP_MP7491_11,
	IP_MP7491_12,
	IP_MP7491_13,

// はじまりの深淵_mp832x

//水源地・追加分
	IP_MP7451_06,
	IP_MP7451_07,
	IP_MP7451_08,
	IP_MP7451_09,
	IP_MP7451_10,
	IP_MP7451_11,
	IP_MP7451_12,

//過去編ダーナ①・大峡谷
	IP_MP3109m_01,
	IP_MP3110m_01,

//過去編Ⅰ・
	IP_MP5103m_08,
	IP_MP6101m_01,
//過去編Ⅲ・
	IP_MP6103m_09,
	IP_MP6103m_10,
//過去編Ⅴ・
	IP_MP6106m_07,
	IP_MP6106m_08,

//追加
	IP_MP5101_05,	//後ろに追加
	IP_MP6113_08,		//後ろに追加
	IP_MP6109_08,	//後ろに追加
	IP_MP6109_09,
	IP_MP6109_10,
	IP_MP1302_07,
	IP_MP2102_10,
	IP_MP2306_09,	//後ろに追加
	IP_MP2306_10,
	IP_MP2306_11,
	IP_MP2306_12,
	IP_MP2306_13,
	IP_MP2306_14,
	IP_MP2306_15,
	IP_MP1115_05,
	IP_MP1115_06,
	IP_MP1115_07,
	IP_MP3109_07,
	IP_MP3109_08,
	IP_MP3109_09,
	IP_MP3106_04,
	IP_MP3106_05,
	IP_MP1307_03,
	IP_MP1307_04,
	IP_MP3104_05,
	IP_MP3104_06,
	IP_MP3104_07,
	IP_MP3104_08,
	IP_MP5103_04,
	IP_MP5102_07,
	IP_MP5102_08,
	IP_MP5102_09,
	IP_MP6103_08,
	IP_MP6104_10,
	IP_MP1116_05,
	IP_MP1116_06,
	IP_MP1132_05,
	IP_MP1132_06,
	IP_MP1112_10,
	IP_MP1112_11,
	IP_MP1131_06,



//--------------------------------------------------------------------
// PS4追加分
	IP_MP1301t2_01,
	IP_MP1301t2_02,
	IP_MP1301t2_03,
	IP_MP1301t2_04,
	IP_MP1301t2_05,
	IP_MP1301t2_06,
	IP_MP1301t2_07,
	IP_MP1302t2_01,
	IP_MP1302t2_02,
	IP_MP1302t2_03,
	IP_MP1302t2_04,
	IP_MP1302t2_05,
	IP_MP1302t2_06,
	IP_MP1302t2_07,
	IP_MP1302t2_08,
	IP_MP1302t2_09,
	IP_MP1302t2_10,
	IP_MP1302t2_11,
	IP_MP1302t2_12,
	IP_MP1303t2_01,
	IP_MP1303t2_02,
	IP_MP1303t2_03,
	IP_MP1303t2_04,
	IP_MP1303t2_05,
	IP_MP1303t2_06,
	IP_MP1303t2_07,
	IP_MP1304t2_01,
	IP_MP1304t2_02,
	IP_MP1304t2_03,
	IP_MP1304t2_04,
	IP_MP1304t2_05,
	IP_MP1304t2_06,
	IP_MP1304t2_07,
	IP_MP1304t2_08,
	IP_MP1304t2_09,
	IP_MP1304t2_10,
	IP_MP1304t2_11,
	IP_MP1305t2_01,
	IP_MP1305t2_02,
	IP_MP1305t2_03,
	IP_MP1305t2_04,
	IP_MP1305t2_05,
	IP_MP1306t2_01,
	IP_MP1306t2_02,
	IP_MP1307t2_01,
	IP_MP1307t2_02,
	IP_MP1307t2_03,
	IP_MP1307t2_04,

	IP_MP4331t2_01,
	IP_MP4331t2_02,
	IP_MP4331t2_03,
	IP_MP4331t2_04,
	IP_MP4331t2_05,
	IP_MP4331t2_06,
	IP_MP4332t2_01,
	IP_MP4332t2_02,
	IP_MP4332t2_03,
	IP_MP4332t2_04,
	IP_MP4333t2_01,
	IP_MP4333t2_02,
	IP_MP4333t2_03,
	IP_MP4333t2_04,
	IP_MP4333t2_05,
	IP_MP4334t2_01,
	IP_MP4334t2_02,
	IP_MP4334t2_03,
	IP_MP4334t2_04,
	IP_MP4334t2_05,
	IP_MP4334t2_06,
	IP_MP4334t2_07,
	IP_MP4334t2_08,
	IP_MP4334t2_09,
	IP_MP4334t2_10,
	IP_MP4334t2_11,
	IP_MP4335t2_01,
	IP_MP4336t2_01,
	IP_MP4336t2_02,
	IP_MP4336t2_03,
	IP_MP4336t2_04,
	IP_MP4336t2_05,
	IP_MP4336t2_06,
	IP_MP4336t2_07,
	IP_MP4336t2_08,
	IP_MP4337t2_01,
	IP_MP4337t2_02,
	IP_MP4338t2_01,
	IP_MP4338t2_02,
	IP_MP4338t2_03,
	IP_MP4338t2_04,
	IP_MP4338t2_05,
	IP_MP4338t2_06,
	IP_MP4338t2_07,
	IP_MP4339t2_01,
	IP_MP4339t2_02,
	IP_MP4339t2_03,
	IP_MP4339t2_04,
	IP_MP4339t2_05,
	IP_MP4340t2_01,
	IP_MP4340t2_02,
	IP_MP4340t2_03,
	IP_MP4340t2_04,
	IP_MP4341t2_01,
	IP_MP4341t2_02,

	IP_MP6111t2_01,
	IP_MP6111t2_02,
	IP_MP6111t2_03,
	IP_MP6111t2_04,
	IP_MP6111t2_05,
	IP_MP6111t2_06,
	IP_MP6112t2_01,
	IP_MP6112t2_02,
	IP_MP6112t2_03,
	IP_MP6112t2_04,
	IP_MP6112t2_05,
	IP_MP6112t2_06,
	IP_MP6112t2_07,
	IP_MP6112t2_08,
	IP_MP6112t2_09,
	IP_MP6116t2_01,
	IP_MP6116t2_02,
	IP_MP6116t2_03,
	IP_MP6116t2_04,
	IP_MP6116t2_05,
	IP_MP6116t2_06,
	IP_MP6116t2_07,
	IP_MP6116t2_08,

	IP_MP6531m_01,
	IP_MP6531m_02,
	IP_MP6531m_03,
	IP_MP6531m_04,
	IP_MP6531m_05,
	IP_MP6551m_01,
	IP_MP6551m_02,
	IP_MP6551m_03,

	IP_MP6553m_01,
	IP_MP6553m_02,
	IP_MP6553m_03,
	IP_MP6553m_04,
	IP_MP6553m_05,

	IP_MP6512_01,
	IP_MP6512_02,
	IP_MP6512_03,
	IP_MP6531_01,
	IP_MP6531_02,
	IP_MP6531_03,
	IP_MP6531_04,
	IP_MP6531_05,
	IP_MP6531_06,
	IP_MP6531_07,
	IP_MP6531_08,
	IP_MP6531_09,
	IP_MP6531_10,
	IP_MP6531_11,
	IP_MP6531_12,
	IP_MP6531_13,
	IP_MP6542_01,
	IP_MP6542_02,
	IP_MP6551_01,
	IP_MP6551_02,
	IP_MP6551_03,
	IP_MP6551_04,
	IP_MP6551_05,
	IP_MP6551_06,
	IP_MP6551_07,
	IP_MP6551_08,
	IP_MP6552_01,
	IP_MP6552_02,
	IP_MP6553_01,
	IP_MP6553_02,
	IP_MP6553_03,
	IP_MP6553_04,
	IP_MP6553_05,
	IP_MP6554_01,
	IP_MP6554_02,
	IP_MP6554_03,
	IP_MP6554_04,
	IP_MP6554_05,

	// さらに追加分
	IP_MP1302t2_13,
	IP_MP1302t2_14,
	IP_MP1303t2_08,

	IP_RES_181,
	IP_RES_182,
	IP_RES_183,
	IP_RES_184,

	IP_RES_185,
	IP_RES_186,
	IP_RES_187,
	IP_RES_188,
	IP_RES_189,

	IP_RES_190,
	IP_RES_191,
	IP_RES_192,
	IP_RES_193,

	IP_RES_194,
	IP_RES_195,
	IP_RES_196,
	IP_RES_197,

	IP_RES_198,
	IP_RES_199,
	IP_RES_200,
	IP_RES_201,
	IP_RES_202,
	IP_RES_203,
	IP_RES_204,

	IP_RES_205,
	IP_RES_206,
	IP_RES_207,
	IP_RES_208,
	IP_RES_209,

	IP_RES_210,
	IP_RES_211,
	IP_RES_212,
	IP_RES_213,
	IP_RES_214,
	IP_RES_215,
	IP_RES_216,

	IP_RES_217,


	// 以下はデバッグ用
	IP_T0001_01,
	IP_T0001_02,
	IP_T0001_03,
	IP_T0001_04,
	IP_T0001_05,
	IP_T0001_06,
	IP_T0001_07,
	IP_T0001_08,
	IP_T0001_09,
	IP_T0001_10,
	IP_T0001_11,
	IP_T0001_12,
	IP_T0001_13,
	IP_T0001_14,
	IP_T0001_15,


	IP_RELEASE_MAX,
	
	IP_MAX

};

