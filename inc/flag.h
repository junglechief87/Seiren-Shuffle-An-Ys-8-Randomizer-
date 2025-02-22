// �t���O�w�b�_
//
//	TEMP_FLAG_MAX �܂ł��e���|�����t���O�i���[�J���t���O�j�@�}�b�v�؂�ւ��܂ŗL��
//	GLOBAL_FLAG_MAX �܂ł��O���[�o���t���O�@�Q�[���I���A�������̓Z�[�u�f�[�^�̃��[�h�܂ŗL��
//

enum {
	// �e���|�����t���O�Q
	TF_START = 0,

	TF_0001_4EV,			// TalkMes�̏����w��u#?X�v�p�Ɋm�ۂ��Ă���̈�B���ڔԍ��w��p�B
	TF_0002_4EV,			// TalkMes�̏����w��u#?X�v�p�Ɋm�ۂ��Ă���̈�B���ڔԍ��w��p�B
	TF_0003_4EV,			// TalkMes�̏����w��u#?X�v�p�Ɋm�ۂ��Ă���̈�B���ڔԍ��w��p�B
	TF_0004_4EV,			// TalkMes�̏����w��u#?X�v�p�Ɋm�ۂ��Ă���̈�B���ڔԍ��w��p�B
	TF_0005_4EV,			// TalkMes�̏����w��u#?X�v�p�Ɋm�ۂ��Ă���̈�B���ڔԍ��w��p�B
	TF_0006_4EV,			// TalkMes�̏����w��u#?X�v�p�Ɋm�ۂ��Ă���̈�B���ڔԍ��w��p�B
	TF_0007_4EV,			// TalkMes�̏����w��u#?X�v�p�Ɋm�ۂ��Ă���̈�B���ڔԍ��w��p�B
	TF_0008_4EV,			// TalkMes�̏����w��u#?X�v�p�Ɋm�ۂ��Ă���̈�B���ڔԍ��w��p�B
	TF_0009_4EV,			// TalkMes�̏����w��u#?X�v�p�Ɋm�ۂ��Ă���̈�B���ڔԍ��w��p�B
	TF_0010_4EV,			// TalkMes�̏����w��u#?X�v�p�Ɋm�ۂ��Ă���̈�B���ڔԍ��w��p�B

	TF_GAMEOVER_SEL,		// �Q�[���I�[�o�[���̃Z���N�g
	TF_OLDMMINIMAP_LAYER,	// �~�j�}�b�v�S��ʎ��Ɋo���Ă������C���[�ԍ�
	TF_TEMPROTATE_CAMERA,	// �~�j�}�b�v�S��ʎ��̃e���|������]
	TF_TEMPROTATE_CAMERA2,	// �~�j�}�b�v�S��ʎ��̃e���|������]�A�ڕW�l

	// ���Â��̌��Ńt���O�iTF_TRIAL�`�j�͊댯�Ȃ̂ō폜���܂����B�i�R�j
	//
	// ���̏����̃e���|�����͊�{�I�Ƀ}�b�v�e���|�����ō쐬���ĉ������B
	// �}�b�v�e���|������ /bin/inc/maptmp/mp_xxxx.inc �Œ�`���鎖�B
	// �}�b�v�e���|�����ɂ͈ȉ��̂悤�ȕ����`���܂��B
	//	�E�ꎞ�I�ȃM�~�b�N�󋵃t���O
	//	�E��ʉ�b���ŏ��񂩂ǂ����𔻒肷��t���O
	//	�E�Ƃɂ����}�b�v����̃e���|�����t���O
	//
	// �ėp�I�ȃe���|�������K�v�ȏꍇ�͐�p�̖��O�ō쐬���ĉ������B
	//	��jTF_MENU_SELECT		// ���j���[�Z���N�g�p�B�S�}�b�v�Ŏg�p�B

	// �M�~�b�N�p�i�����ăe���|�����t���O�ɂ��Ă����悤�ȋC������j
	TF_TALK_ZOOMCAMERA,			// STOPFLAG_TALKING���A�J�������񂹂�BSTOPFLAG_TALKING���~���Ɠ����Ɏ����ŉ��������
	TF_TALK_ZOOMRATIO,			// TF_TALK_ZOOMCAMERA�̎��̃Y�[�����ݒ�B0�`100��100��TF_TALK_ZOOMCAMERA���g���Ă��Ȃ����Ɠ����B�O�̓V�X�e�����ݒ肵���l�i2015/01/16���݂�40�j�ɂȂ�BTF_TALK_ZOOMCAMERA�����Z�b�g�����̂Ɠ����^�C�~���O�Ŏ����I�ɂO�ɍĐݒ肳���B
	TF_TALK_ZOOMNOINTERPOLATE,	// �P��ݒ肷���TF_TALK_ZOOMCAMERA�Ɋւ����ԏ�������u�ŏI��点��B������ɂ͂O���ݒ肳���B
	TF_TALK_NOTURNANIME,		// STOPFLAG_TALK�ŉ�b�J�n�E�I������ۂɁA�L������]�ɍ��킹�ăL�������[�V���������Ȃ��ꍇ�ɗ��Ă�

	// �A�N�V�����p
	TF_MENU_SELECT,				// ���j���[�Z���N�g�p�e���|����
	TF_MENU_SELECT2,			// ���j���[�Z���N�g�p�e���|����
	TF_TORCHLIGHT,				// �����܂g�p�ς݁i�v���O�����p�j
	
	TF_VOICEPLY_CHR,			// WK_RANDBTLMB/WK_RANDJOINMB�Ńs�b�N�A�b�v�����L�������x���̒u���ꏊ

	TF_TRORHY_COUNT,			// �g���t�B�[�p�e���|����

	TF_KILLENEMY_CNT,			// ���j���J�E���g�i�e���|�����j
	TF_NO_RETRY,				// ���g���C�O����p�i�e���|�����j
	TF_CHECK_DISTANCE,			// PLAYER1��PLAYER2�̋�������p�i�e���|�����j
	TF_CHECK_DISTANCE2,			// PLAYER1��PLAYER3�̋�������p�i�e���|�����j

	TF_LOADING_TIPS_OFF,		// NowLoading ���� Tips �\�����J�b�g
	TF_MAPNAME_SHOWN,			// �n���\�������i�e���|�����j

	TF_EVSKIP,					// �C�x���g�X�L�b�v����

	TF_TALK_TYPE,				// ��ʉ�b�̏�������p

	TF_BREAK_RND,				// �u���C�N�I�u�W�F�N�g�̃h���b�v���胉���_���p

	TF_ENDROGRAM_STATE,			// �e�I�X�E�f�E�G���h���O�����󋵔���p
	TF_NPC_NOLOAD,				// �����Ă����NPCPosition���Ăяo���Ȃ��i�Y�����h���}�b�v����j

	TF_SIENEVENT,				//�x���C�x���g�̍Đ��p�^�[���𔻒肷��t���O

	//*****************************************************************
	// 100�`349 �}�b�v�M�~�b�N�e���|����
	// �Ⴄ�}�b�v�ɍs�����瓯���ԍ��ł��S���Ⴄ�t���O�Ǝv���ׂ�
	// ���l���w������肦��̂Œ���
	// ��`�������Ȃ�Əd���Ȃ�̂ŁA�}�b�v�ʂ�.h��p�ӂ�����@�ɕύX�B
	// �Ȃ̂�100�`349�͐�΂Ɏg���Ă͂����Ȃ�
	//
	// DUNGEON_START�`DUNGEON_END�̊Ԃ́A�_���W�����e���|�����ŁA
	// arg��[MAP_SET]�Z�N�V�����Ŏw�肵�Ă���PAGE_NO�P�ʂŋ��L����e���|�����t���O�ł��B
	// inc/mp23xx.h���ŁA���ʂ̃t���O���g���悤�ɂ��Ă��������B
	TF_MAP_START = 100,			// �}�b�v�e���|�����J�n�i�}�b�v�ؑւłO�ɖ߂�t���O�j
	TF_DUNGEON_START = 200,		// �_���W�����e���|�����J�n�iPAGE_NO���؂�ւ��ƂO�ɖ߂�t���O�j
	TF_DUNGEON_END = 350,		// �_���W�����e���|���������܂�

	//*****************************************************************
	// 350�Ԉȍ~ ��������͏d�����Ȃ��悤�ɁI�I
	// �U�R�`�h�`�����l���p
	TF_AI_CHANNEL0 = TF_DUNGEON_END,
	TF_AI_CHANNEL1,
	TF_AI_CHANNEL2,
	TF_AI_CHANNEL3,
	TF_AI_CHANNEL4,
	TF_AI_CHANNEL5,
	TF_AI_CHANNEL6,
	TF_AI_CHANNEL7,

	TEMP_FLAG_MAX,				// �e���|�����t���O�@�����܂�

	TEMP_FLAG_RESERVE_MAX = 400,// �e���|�����t���O�̃��U�[�u�}�b�N�X

	// �ړ��ς݃}�b�v�`�F�b�N�t���O�B�r�b�g�Ŏ��B�t���O��int�^�Ȃ̂ŁA�O�ׂ̈R�P�܂łƂ��Ă����B	SF_MAP_CHECK_POINT03/04�����邪�A���̏ꏊ�ɎU��΂��Ă���
	SF_MAP_CHECK_POINT01,		// �}�b�v�`�F�b�N�|�C���g�i�o�b�t�@�P�j
	SF_MAP_CHECK_POINT02,		// �}�b�v�`�F�b�N�|�C���g�i�o�b�t�@�Q�j

	// �V�X�e���t���O�n
	SF_SAVEMENU,				// �Z�[�u�n���j���[�N����
	SF_DIFFICULT,				// ��Փx
	SF_LOADING,					// ���[�h�������t���O	// 1�`100 �ʏ탍�[�h	200 RAM���[�h
	SF_ENTRY,					// �G���g���[������
	SF_ALLMUTEKI,				// �G���������S�����G�t���O
	SF_MINIGAME,				// �~�j�Q�[�����[�h�t���O
	SF_TOWNMODE,				// �X��																									// �}�b�v�؂�ւ����ɖ��񃊃Z�b�g�����Barg�̃G���A�t���O�ŃZ�b�g���ׂ�
	SF_HEALAREA,				// �񕜉\�G���A�i���u���ɕ����������邩�ǂ����̔���ɂ������Ă���B�j								// �}�b�v�؂�ւ����ɖ��񃊃Z�b�g�����Barg�̃G���A�t���O�ŃZ�b�g���ׂ�
	SF_DEFEAT_ANCIENT,			// �Ñ�b��|����
	SF_CANTSAVE,				// �Z�[�u�s�\�I�i�{�X�퓙�A���j���[���J���Ȃ��悤�ɂȂ�j												// �}�b�v�؂�ւ����ɖ��񃊃Z�b�g�����Barg�̃G���A�t���O�ŃZ�b�g���ׂ�

		//�L����
	SF_ADOL_JOINOK,				// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j
	SF_LAXIA_JOINOK,			// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j
	SF_SAHAD_JOINOK,			// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j
	SF_HUMMEL_JOINOK,			// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j
	SF_RICOTTA_JOINOK,			// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j
	SF_DANA_JOINOK,				// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j

	SF_DANACOPY_JOINOK,			// �_�[�i�T���p�̈�Ȃ̂ŐG���Ă͂����Ȃ�

	SF_DANA2_JOINOK,			// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j
	SF_DANA3_JOINOK,			// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j
	
	SF_DANAOLD_JOINOK,			// �ߋ��҃_�[�i�T���p�̈�Ȃ̂ŐG���Ă͂����Ȃ�

	SF_RESERVE10_JOINOK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j
	SF_RESERVE11_JOINOK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j
	SF_RESERVE12_JOINOK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j
	SF_RESERVE13_JOINOK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j
	SF_RESERVE14_JOINOK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j
	SF_RESERVE15_JOINOK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j
	SF_RESERVE16_JOINOK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j
	SF_RESERVE17_JOINOK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j
	SF_RESERVE18_JOINOK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j
	SF_RESERVE19_JOINOK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j

	SF_MINIMAP_VIEWMODE,		// �~�j�}�b�v�r���[���[�h�B�O�|�ʃ}�b�v�̓O���[		�P�|�ʃ}�b�v�͔�\��	�Q�|�ʃ}�b�v�����ʂɕ\��
	SF_DARKAREA,				// �Èň����ɂ���}�b�v�B�^�[�Q�b�g�\�͈͂��k�ށB	// �}�b�v�؂�ւ����ɖ��񃊃Z�b�g�����Barg�̃G���A�t���O�ŃZ�b�g���ׂ��BSF_TORCHPOWER, SF_TORCHRANGE�Ń}�b�v���ɖ���΂̋����Ɣ͈͂�ύX�ł���
	SF_MINIMAP_LAYER,			// �~�j�}�b�v���C���[�ԍ��B�G���A�؂�ւ����Ɏ����I�ɂO�ɂȂ�B
	
	SF_CAMP_CANT_SYSTEM,		// �V�X�e�����j���[�֎~�i�`���[�g���A������p�Ȃǁj
	SF_CAMP_CANT_ITEM,			// �A�C�e�����j���[�֎~�i�`���[�g���A������p�Ȃǁj

	__SF_TORCHTIMER,			// ����΂̎c�莞�ԃJ�E���g�p�iSF_DARKAREA�ł͌�������j
	__SF_TORCHPOWER,			// ����΂̋����ݒ�i0�`100�B�f�t�H���g��100�B�}�b�v�؂�ւ����Ƀ��Z�b�g�����j
	__SF_TORCHRANGE,			// ����΂͈̔́��ݒ�i0�`100�B�f�t�H���g��100�B�}�b�v�؂�ւ����Ƀ��Z�b�g�����j

		// ���̑�
	SF_REDENTRYLINE,			// �G���g���[����ԐF�\���ɂ���	// �}�b�v�؂�ւ����ɖ��񃊃Z�b�g�����B���g���C�X�N���v�g���ł̎w��Y�꒍��
	SF_LASTENTRY_NO,			// �Ō�ɒʂ����G���g���[�̔ԍ��B�X�N���v�g�Ń��[�v�������́|�P�������Ă���B
	SF_LOADMAP,					// �}�b�v�ǂ񂾒���
	SF_MINIMAP_MODE,			// �~�j�}�b�v�̕\�����[�h
	SF_EXPOWER,					// ���K�E�Q�[�W�l
	SF_DONTSTOPSEALL,			// �r�d�S��~���������Ȃ��ꍇ�ɗ��Ă�B���}�b�v�؂�ւ���init�X�N���v�g��Ƀ��Z�b�g�����B

	SF_SETRAMSAVE,				// �v���C���[���s���ł���悤�ɂȂ�����RAM�Z�[�u���
	SF_RAMSAVED,				// ����RAM�Z�[�u�������Ă��邩�ǂ���

		// �V�d�l�p�A�`���[�g���A���Ƃ��V�i���I�Ƃ��̒ǉ���ύX�ŕK�v�ɂȂ�����
	SF_ITEMSLOT_NUM,			// �`����X���b�g���i-1�F�X���b�g��\��	1�ȏ�F�g����X���b�g��	��1�����͑����ł���X���b�g����1�����B�j
	SF_CAN_EXSKILL,				// EX�X�L�����g����悤�ɂȂ�iEX���[�^�[�����܂�悤�ɂȂ�j
	SF_SPMAX,					// SP�ő�l�i100�`200�B����ȊO��100�����j
	SF_STAMMINA_LV,				// �X�^�~�i���x���i�O�`�j
	SF_CHARANORECVSHADOW,		// �L�����͉e�󂯂Ȃ�	// �}�b�v�؂�ւ����ɖ��񃊃Z�b�g�����Barg�̃G���A�t���O�ŃZ�b�g���ׂ��B

		// �`���[�g���A���m�F�p
	SF_USE_TAMEATK,				// ���ߍU���œG�Ƀ_���[�W��^����ƂP������
	SF_USE_SKILLATK,			// �X�L���U���œG�Ƀ_���[�W��^����ƂP������

		// �^�C���A�^�b�N�n
	SF_TIMEATK,					// �^�C���A�^�b�N���t���O�i���̃t���O�������Ă��鎞�̓��j���[����̃Z�[�u���s�\�ɂȂ�\��j
	SF_TIMEATKCT,				// �^�C���A�^�b�N�v�����ԁi�v���O�����p�j


	SF_CHRSWITCH_MODE,			// ���Ԃ͌��ɂ��Ă���̂ł͂Ȃ��A�g�o�������L���Đ؂�ւ���iZWEI���j�B

		// ���̑�����ǉ��n
	SF_MAP_CHECK_POINT03,		// �}�b�v�`�F�b�N�|�C���g�i�o�b�t�@�R�j
	SF_MAP_CHECK_POINT04,		// �}�b�v�`�F�b�N�|�C���g�i�o�b�t�@�S�j

	SF_NOCHANGEBGM,				// �}�b�v�؂�ւ����ɂa�f�l��؂�ւ��Ȃ�	���}�b�v�؂�ւ���init�X�N���v�g��Ƀ��Z�b�g�����B

	SF_TEAR_CANT_HEAL,			// �P���w�肷��ƃe�B�A���񕜍s�������Ă���Ȃ��Ȃ�B

	SF_LOADINIT,				// ���[�h�Ŕ��ł����B������}�b�v�؂�ւ���init�X�N���v�g�O�Ƀ��Z�b�g�����B

	SF_BESTIARYPOTION,			// �x�X�e�B�A���[�|�[�V�������g������������i�V�X�e���Z�[�u�Ɉȍ~���邩���j
	SF_ITEMSLOT_NUMBK,			// �`����X���b�g���o�b�N�A�b�v

	SF_2ND_TAKEOVER_LV,			// ���x�������p����
	SF_2ND_TAKEOVER_SKILL,		// �X�L�������p����
	SF_2ND_TAKEOVER_EQUIP,		// �i����������j�����i�������p����
	SF_2ND_TAKEOVER_USEITEM,	// ���Օi�������p����
	SF_2ND_TAKEOVER_MATERIAL,	// �f�ށE�H�ނ������p����
	SF_2ND_TAKEOVER_MAPRATIO,	// �n�}�J�����������p����
	SF_2ND_GET_MATERIAL,		// ������T�u�e��z�΁v��I��
	SF_2ND_GET_BOTTLE,			// ������T�u�󂫕r�v��I��
	SF_2ND_TAKEOVER_MAPMARKER,	// �n�}�}�[�J�[�������p����

	SF_CANTUSE_SKILL,			// �X�L���g�p�֎~�iSP�����܂�Ȃ��j

	SF_VOICE_LAXIA_1ST,			// ���N�V���{�C�X�O��
	SF_VOICE_RICOTTA_1ST,		// ���R�b�^�{�C�X�O��

	SF_EPILOGUE_MODE,			// �G�s���[�O���[�h�i�֎~�ݒ�̐����΃}�[�J�[���\���ɂ��A�����΂ƃ��C���}�[�J�[�ȊO�̃}�[�J�[����\���ɂ���B�I�����o���Ȃ�����B�j
	SF_CANTUSE_MAP,				// �n�}�g�p�֎~
	SF_WEAKENEMY_COUNT,			// �G��̉��J�E���g
	SF_WEAKENEMY_UPDATE,		// �G��̉��J�E���g�A�b�v�f�[�g������i����������Ȃ��Łj
	SF_CANTUSE_TOOL,			// �`����g�p�֎~�i�`����X���b�g�̔�\�����Ƌ@�\���֎~����j

	SF_GALLERY_EVENT,			// �C�x���g�M�������[����Ăяo���Ă���
	SF_GALLERY_AUTOMODE,		// �M�������[�������Đ����[�h

	SF_DANA_WATERSTYLE_LV,		// �_�[�i�҃X�^�C�����x���i��2016/10/24���݂͌���҂ł��L���j	0-�f�t�H���g
	SF_DANA_EARTHSTYLE_LV,		// �_�[�i�҃X�^�C�����x���i��2016/10/24���݂͌���҂ł��L���j	0-�f�t�H���g
	SF_DANA_LIGHTSTYLE_LV,		// �_�[�i�҃X�^�C�����x���i��2016/10/24���݂͌���҂ł��L���j	0-�f�t�H���g

	SF_INFERNO,					// �C���t�F���m���[�h�i�i�C�g���A�ł��C���t�F���m�̎��̂݃C���t�F���m�ɂȂ�j

	SF_SYS_CLEARED,				// �i�V�X�e���Z�[�u�E���[�h�����j�N���A�ς�
	SF_SYS_TRUECLEARED,			// �i�V�X�e���Z�[�u�E���[�h�����j�g�D���[�G���h�ς�
	SF_SYS_GALLERYMODE,			// �M�������[���[�h���i�V�X�e���Z�[�u�̃��[�h�E�Z�[�u���M�������[���[�h�p�ɂȂ�j
	SF_SYS_TIMEATKMODE,			// �^�C���A�^�b�N���[�h���i�V�X�e���Z�[�u�̃��[�h�E�Z�[�u���^�C���A�^�b�N���[�h�p�ɂȂ�j
	SF_AUTOSAVING,				// �I�[�g�Z�[�u��
	SF_CANTLOAD,				// ���[�h�s�\�I											// �}�b�v�؂�ւ����ɖ��񃊃Z�b�g�����Barg�̃G���A�t���O�ŃZ�b�g���ׂ�
	SF_MAPDATAID,				// �n�}���J���ۂɓǂݍ��ރf�[�^�����߂�f�[�^�Z�b�g�̂h�c����Bscr_inc.h��EMAPDATA_ID_�`���Q�ƁB
	SF_INFINITY,				// �C���t�B�j�e�B���[�h�iLV1�̓G��LV70�ɂȂ�BLV99�̓G��LV130�H�ɂȂ�j
	SF_ATKMEMBERNUM,			// �퓬�ɎQ�����郁���o�[���i�P�`�R�j���݂̐l����肱�̐��������Ȃ���ԂŁAJoinParty/RestorePartyMember������ƁA�����I�Ɍ��炳���BJoinParty(-1)�łn�j�B

	SF_CANTUSE_DLC_MENU,		// DLC���j���[�g�p�֎~

	SF_SYS_TIMEATKHELP,			// �^�C���A�^�b�N�̃w���v������������

	//-- �i���U�[�u�j --------------------------------------
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

	SF_NOUSE_MTD_VIBRATION,		// MTD �̐U���R�}���h�𖳎����܂� (�}�b�v�ؑւŃN���A) 

	SF_NOBACKGROUNDTG,			// ���i�p�^�[�Q�b�g�o�b�t�@�i��𑜓x�j���g��Ȃ�			(�}�b�v�ؑւŎ������Z�b�g)
	SF_ADDCONT_CHECKING,		// �_�E�����[�h�R���e���c���m�F��
	SF_KILLDRAGON_COUNT,		// ���^�Ñ�팂�j��

	SF_SAVENPCMODE,				// ��q�C�x���g���[�h�i0-�ʏ�	1-NPC��HP���O�ɂȂ�����Q�[���I�[�o�[�j�@(�}�b�v�ؑւŎ������Z�b�g)
	SF_DISABLE_FISHING,			// �ނ���֎~���� (�}�b�v�ؑւŎ������Z�b�g)

	SF_INDOORMODE,				// �������[�h�i�ړ����x��0.75�{�����j
	SF_SAVEBITDATA,				// �v���O�����p�A�r�b�g�t���O�̃f�[�^�BSAVEBIT_�`�Ŕ���B

	SF_MEMORYEVENT,				// �v���O�������I���I�t����B�L�����j���[����L���C�x���g�����s���i�Z�[�u�s�A�X�L�b�v�A�X�L�b�v�� or ReturnMemoryMenu�Ń��j���[�ɖ߂�j
	SF_MEMORYEVENT_SCP,			// �X�N���v�g�ŃI���I�t����B���C���C�x���g���ŋL���C�x���g�����s���������t���O�B�i�L�����`�F���W�s�A�r�s�`�q�s�{�^���Œ��ڃV�X�e�����j���[���J���j

	SF_BOSS_BATTLE,				// �{�X�o�g����
	SF_EVENT_ON,				// �C�x���g�����n�m�B��{��������

	SF_CANUSE_MAPWARP,			// �n�}�̈ړ��@�\���]�ڋ@�\�ɂȂ�B-1�w�莞�͈ړ��@�\���̂������Ȃ�B�i�A�C�R���͍������ɂȂ炸�A�ړ�����{�^����������B�j
	SF_CANUSE_MEMORYMENU,		// �L���̌��Ѓ��j���[���g����

	SF_WARP_DISABLED,			// ���[�v�֎~�t���O�B�X�g�b�p�[�p�B���̃t���O�������Ă���ƁA���[�v���I�����Ă����[�v���܂���B

	SF_KILLMONSTER_COUNT,	// �G�|�������J�E���g�iZOKU_ABILITY_SPECIAL�p�j

	SF_WAITPROMPT_NOSE,		// WaitPrompt�ŉ���炳�Ȃ��i�}�b�v�؂�ւ��Ŏ����I�Ƀ��Z�b�g�����j

	// ver1.01�Œǉ�
	SF_AFTERLOAD_CT,		// ���[�h����Ƀv���C���[�ɑ��삳���Ȃ��ׂ̃t���O

	// ys4�Œǉ�
	SF_NOTMAPPING,			// �}�b�s���O���������Ȃ����ɗ��Ă�t���O�i�X�����A�}�b�s���O�̕s�v�Ȏ��ɗ��Ă�j	���}�b�v�֖ؑ��ɖ��񃊃Z�b�g
	SF_MAPPING_OFFSET_X,	// �}�b�s���O�̃I�t�Z�b�g�w
	SF_MAPPING_OFFSET_Y,	// �}�b�s���O�̃I�t�Z�b�g�x

	SF_MISSIONNO,			// �n�}�ɕ\������u���݂̖ړI�v���w�肷��Bsce_inc.h�ɂ���MS_�`��ݒ肷��B

	SF_SPMAXBK,				// SP�ő�l�i100�`200�B����ȊO��100�����j�o�b�N�A�b�v

	SF_NOUSE_ITC_SUPPORT,		// �}����ŃT�|�[�g�X�L�����g��Ȃ��i����}����p�j
	SF_NODRAWMAP,				// �}�b�v��`�悵�Ȃ��i�}�b�v�؂�ւ��Ń��Z�b�g�����j
	SF_REALTIMETOUT,			// ���A���^�C���w���v�̃^�C���A�E�g���ԁB-1�̎��̓^�C���A�E�g���Ȃ��B�i�}�b�v�؂�ւ��Ń��Z�b�g�����j
	SF_REALTIMEHELP,			// ���A���^�C���w���v�p�̂h�c�i�[�t���O�B-1�Ŗ����B�i�}�b�v�؂�ւ��Ń��Z�b�g�����j

	SF_CAN_DASH,			// �_�b�V���ł���悤�ɂȂ�
	SF_RETRY,				// ���g���C���Ă���

	SF_WARPGROUP,				// ���[�v���̃O���[�v�ݒ�
	SF_OVERWRITENOTICE,			// �Z�[�u�㏑�����ӕ��\������i�}�b�v�؂�ւ��Ń��Z�b�g�����j
	SF_TIMEATK_RUSH,			// �{�X���b�V����
	SF_TIMEATK_RUSHCT,			// �{�X���b�V�������ԃJ�E���g
	SF_CANTGAINEXP,				// �o���l����ł��Ȃ��ݒ�

	SF_CLEARFLG,				// �N���A�t���O
	SF_2NDSTART,				// �Q���ڈ����p�����t���O

	SF_CHANGEDDIFFICULT,		// ��Փx�ύX����

	SF_NOUSE_MTDSE,				// MTD��SE���߂𖳎�����i�G���A�t���O�Ɠ��l�A�}�b�v�ǂݑւ����Ɏ������Z�b�g�j
	SF_FORCELEARN_SKILL,		// �X�L�����o����^�C�~���O�ŃX�L���������I�Ɋo��������B�o������t���O�͍~���
	SF_CANTLEARN_SKILL,			// �X�L���K���֎~

	SF_DONTSTOP_VIBRATION,		// �}�b�v�ؑ֎��ɐU����������~���������Ȃ��ꍇ�͗��ĂĂ������� (�}�b�v�ؑ֌㎩�����Z�b�g)

	SF_CAMP_CANT_FORMATION,		// �Ґ����j���[�֎~
	SF_CAMP_CANT_MEMORYMENU,	// �L�����j���[�֎~
	SF_CAMP_CANT_DIARY,			// �`���������j���[�֎~
	SF_CAMP_CANT_MAP,			// �n�}���j���[�֎~�B�n�}�J���Ă���Œ��ɗ��Ă�ƁA����Ȃ����܂��B
	SF_CAMP_CANT_EQUIP,			// �������j���[�֎~
	SF_CAMP_CANT_SKILL,			// �X�L�����j���[�֎~

		// �f�o�b�O�p
	SF_DEBUG,					// �f�o�b�O���t���O
	SF_DEBUG_RELOADSCR,			// �S�X�N���v�g�̓ǂݒ���
	SF_DEBUG_LOADMAP,			// �f�o�b�O�@�\�ɂ�郍�[�h�}�b�v

		// �ǉ��n
	SF_CAMP_ONLY_SAVE_ERASE,	// �V�X�e�����j���[�F�Z�[�u���폜�ȊO���֎~�i�N���A�f�[�^�Z�[�u���Ȃǁj

	SF_NPCJOINSTATE,			// NPC�W�������󋵕ۑ��p�t���O�i�v���O�����Ńr�b�g����j

	SF_ADOL_JOINOKBK,			// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_LAXIA_JOINOKBK,			// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_SAHAD_JOINOKBK,			// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_HUMMEL_JOINOKBK,			// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_RICOTTA_JOINOKBK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_DANA_JOINOKBK,			// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_DANACOPY_JOINOKBK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_DANA2_JOINOKBK,			// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_DANA3_JOINOKBK,			// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_DANAOLD_JOINOKBK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v

	SF_RESERVE10_JOINOKBK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_RESERVE11_JOINOKBK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_RESERVE12_JOINOKBK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_RESERVE13_JOINOKBK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_RESERVE14_JOINOKBK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_RESERVE15_JOINOKBK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_RESERVE16_JOINOKBK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_RESERVE17_JOINOKBK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_RESERVE18_JOINOKBK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_RESERVE19_JOINOKBK,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v

	SF_ADOL_JOINED,				// �p�[�e�B�[�ɉ����������Ƃ�����
	SF_LAXIA_JOINED,			// �p�[�e�B�[�ɉ����������Ƃ�����
	SF_SAHAD_JOINED,			// �p�[�e�B�[�ɉ����������Ƃ�����
	SF_HUMMEL_JOINED,			// �p�[�e�B�[�ɉ����������Ƃ�����
	SF_RICOTTA_JOINED,			// �p�[�e�B�[�ɉ����������Ƃ�����
	SF_DANA_JOINED,				// �p�[�e�B�[�ɉ����������Ƃ�����
	SF_DANACOPY_JOINED,			// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_DANA2_JOINED,			// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_DANA3_JOINED,			// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_DANAOLD_JOINED,			// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v

	SF_RESERVE10_JOINED,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_RESERVE11_JOINED,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_RESERVE12_JOINED,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_RESERVE13_JOINED,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_RESERVE14_JOINED,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_RESERVE15_JOINED,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_RESERVE16_JOINED,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_RESERVE17_JOINED,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_RESERVE18_JOINED,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v
	SF_RESERVE19_JOINED,		// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j�o�b�N�A�b�v

	SF_CAMP_CLOSE_CHECK,		// �L�����v�����Ƀ`���[�g���A��������s��
	
	SF_PAST_MODE,				// �ߋ��җp�̃V�X�e������t���O�i�O�F����	�P�F�ߋ�	�Q�F�ߋ��i��͂���j�j
	SF_PAST_AGAIN,				// �ߋ��ҍĖK�p�̃V�X�e������t���O�i�O�F���j���[����ӎ���オ�g���Ȃ�		�O�ȊO�F���j���[����ӎ���オ�g����j

	SF_CAMP_FORCE_CAN_EQUIP,	// �������j���[���������i�Z�[�u�֎~���Ȃǂł�OK�j			// �}�b�v�؂�ւ����ɖ��񃊃Z�b�g�����B

	SF_TAIKEN_MODE, 			// �̌��ŗp���m��ʒ��� 2017.12.19 m.arai

	SF_MAX,
	SF_RESERVE_MAX = 620,		// �V�X�e���t���O�̃��U�[�u�}�b�N�X

	// �O���[�o���t���O�Q
	//---------------------------------------------------
	// �{�җp�@�U�O�O�Ԃ���X�^�[�g
	//
	// �e�́@�@�@�@�@�@	 �Q�O�O�@�@200 * 11�@�v�@2200��(�v�����[�O�y�уG�s���[�O��1�͋y��11�͂Ɋ܂݂܂�)
	// �M�~�b�N			 �P�O�O�@�@100 * 11  �v�@1100��(�M�~�b�N�͉��ɒn�悲�Ƃɕ����Ă����܂�)
	// ���̑��@�@�@�@�@�@�S�O�O��
	//
	// �󔠌n�@�@�@�@�@�@�T�O�O��
	// �A�C�e���|�C���g�@�T�O�O��
	// �\���@�@�@�@�@�@�@�Q�O�O��

	//---------------------------------------------------
	// ���v�����[�O 9/20
	GF_00MPxxxx_START = 680,		// �v�����[�O		// �V�X�e���t���O���N�H���Ă����ׁA��ꕔ�̌��̋󂫗̈�Ɉړ��B

	GF_00MP0011_GO_CAPTAINROOM,		// �D�����֌�����
	GF_00MP0012_START_PATROL,		// ������J�n����
	GF_00MP0012_GO_CAPTAINROOM2,	// �D�����֌������i�Q��ځj
	GF_00MP0016_HEAR_SCREAM,		// �ߖ���������
	GF_00MP0011b_DIVE_OCEAN,		// �C���ɔ�э���

	GF_00MP1102_TALK_LAXIA,			// ���N�V���Ƙb����
	GF_00MP1102_TALK_SAHAD,			// �T�n�h�Ƙb����
	GF_00MP1102_TALK_HUMMEL,		// �q���������Ƙb����
	GF_00MP1102_TALK_DOGI,			// �h�M�Ƙb����
	
	GF_00MPxxxx_MAX,				// �v�����[�O�t���O�I�[�i�t���O���`�F�b�N�p�Ȃ̂ŁAGF_01Mxxxx_START�̒��O�ɒu���j

	//---------------------------------------------------
	// ���P�F��ꕔ�u�Z�C�������v 38/60
	GF_01MPxxxx_START = 620,		// �P�F��ꕔ�u�Z�C�������v

	GF_01MP1110_DRIFT,				// �Y������
	GF_01MP1110_GET_SWORD,			// �K�т��V���[�g�\�[�h����ɓ��ꂽ
	GF_01MP1102_DRINK_WATER,		// ��������
	GF_01MP1101_JOIN_LAXIA,			// ���N�V���ƍs�����J�n����
	GF_01MP1201_IN_BASE,			// ���_�ɓ�������
	GF_01MP1201_TALK_LAXIA,			// ���N�V���Ƙb����
	GF_01MP1201_GET_DRIFT,			// �Y��������肵��
	GF_01MP1201_CHECK_STONE,		// �����΂𒲂ׂ�
	GF_01MP1201_LOOK_MAN,			// �l�e��������
	GF_01MP7301_IN_CAVE,			// ���A�ɓ�����
	GF_01MP7301_KILL_SLUG,			// �A���t���V�����j����					//��  ���g�p  ��
	GF_01MP7302_IN_RUIN,			// �C���̏Z���Ղɓ�����
	GF_01MP7302_GET_ITEM,			// �|�[�V��������肵��
	GF_01MP7302_GET_ARMOR,			// �Z����肵��
	GF_01MP7302_GET_SWORD,			// ������肵��
	GF_01MP7303_ADVICE_LAXIA,		// ���N�V���ɃA�h�o�C�X���ꂽ
	GF_01MP7303_CHECK_SKELETON,		// �[���𒲂ׂ�
	GF_01MP7304_KILL_BAT,			// �啂����j����
	GF_01MP1201_MEET_BARBAROSS,		// �o���o���X�ƍĉ��
	GF_01MP1101_DRAW_MAP,			// �n�}��`����
	GF_01MP1201_DRUG,				// �o���o���X�ɒ���̐����𕷂�
	GF_01MP1111_DASH_HELP,			// �_�b�V���`���[�g���A��������
	GF_01MP1103_JOIN_SAHAD,			// �T�n�h�ƍs�����J�n����
	GF_01MP1201_JOIN_DOGI,			// �h�M�ƍĉ��Q

//	GF_KARI_END,
	GF_01MP1101_IAM_ADVENTURER,		// �`���ƂƖ������		���`�������p
	GF_01MP1101_TEACH_SEIREN,		// �Z�C��������������	���`�������p
	GF_01MP7303_ADVICE_LAXIA_NOTEA,	// ���N�V���ɃA�h�o�C�X���ꂽA	���`�������p
	GF_01MP7303_ADVICE_LAXIA_NOTEB,	// ���N�V���ɃA�h�o�C�X���ꂽB	���`�������p
	GF_01MP7301_GET_SKILL,			// �����Z���v������
	GF_01MP7301_SET_SKILL,			// �X�L���𑕔�����
	GF_01MP1202_IN_MP1202,			// mp1202�ɓ�����
	GF_01MP7304_KILL_BAT_HALF,		// �啂�r���܂Ō��j����				//��  ���g�p  ��
	GF_01MP7302_RUIN_END,			// �C���̏Z���E�����I��
	GF_01MP1110_BATTLE_WIN,			// �I�I�J�~��|����
	GF_01MP7302_TUTO_SET_ARMOR,		// �Z���A�h���ƃ��N�V���ɑ�������		//��  ���g�p  ��
	GF_01MPxxxx_1ST_CHAPTER_FINISH,	// ��ꕔ��

//�ǉ�

	GF_01MPxxxx_MAX,				// �P�F��ꕔ�u�Z�C�������v�t���O�I�[�i�t���O���`�F�b�N�p�Ȃ̂ŁAGF_02Mxxxx_START�̒��O�ɒu���j

	GF_00MP_RESERVED = GF_00MPxxxx_START,	// 680:����������̓v�����[�O�p�Ƀ��U�[�u

	//---------------------------------------------------
	// ���Q�F��񕔁u�Y���҂����̋����v 77/100
	GF_02MPxxxx_START = 700,		// �Q�F��񕔁u�Y���҂����̋����v

	GF_02MP1202_GET_CLOTHES,		// ���N�V������T���������炤
	GF_02MP1201_TALK_DOGISAHAD,		// �h�M�ƃT�n�h�Ƙb��
	GF_02MP1203_START_FISHING,		// ���H�p�̋���ނ�ɍs��
	GF_02MP1203_GET_FISH,			// ���H�p�̋���ނ���
	GF_02MP1201_TEST_SMITH,			// ����̋���������
	GF_02MP1201_TEST_TRADE,			// �A�C�e������������
	GF_02MP1201_TEST_DRUG,			// ���������
	GF_02MP1201_TAKE_BREAKFAST,		// �h�M���������������
	GF_02MP1201_INFO_QUEST,			// �˗��̐������󂯂�
	GF_02MP1101_START_EXPLORE,		// �T�����J�n����
	GF_02MP1110_REMOVE_OBSTACLE,	// �|�؂�P������
	GF_02MP1132_LOOK_LOCE,		// ���߂ă��P�[�V�����|�C���g�𔭌�
	GF_02MP1201_JOIN_ALISON,		// �A���X�����~�o����
	GF_02MP1202_OPEN_DRESS,			// �A���X�����d�������n�߂�
	GF_02MP1105_MAKE_CAMP,			// �͂��߂Ė�c������
	GF_02MP1301_IN_CORAL,			// �X��̐X�ɓ˓�����
	GF_02MP1307_JOIN_KIERGAARD,		// �J�[�����ƃL���S�[���ɏo�����
	GF_02MP1306_KILL_MIDBOSS,		// �X��̐X���{�X��|����
	GF_02MP1306_GET_GROVE,			// �O���[�u����肵��
	GF_02MP1305_CALL_PARO,			// �p������ً}�A����������
	GF_02MP1201_BEFORE_INTERCEPT,	// �}����̏������͂��߂�
	GF_02MP1201_START_INTERCEPT,	// �}������J�n����
	GF_02MP1201_AFTER_INTERCEPT,	// �}������ڂ��I�����
	GF_02MP1308_KILL_CHAMELEON,		// �X��̐X�{�X�����j����
	GF_02MP1201_JOIN_KATRIN,		// �J�g���[�������������i����̋������\�ɂȂ�Q�j
	GF_02MP1201_TEST_RENSEI,		// ����̋�������
	GF_02MP2101_REMOVE_OBSTACLE,	// �y�������P������
	GF_02MP2102_LOOK_MONSTER,		// �Ñ���ڌ�����
	GF_02MP2102_NEAR_MONSTER,		// �Ñ��Ɍ�������
	GF_02MP2102_LOOK_MONSTER2,		// �Ñ���ڌ������Q
	GF_02MP1120_MEET_HUMMEL,		// �q���������ɏo�����
	GF_02MP1121_FIND_CAMP,			// mp1121�ɖ�c�n�����܂���				//��  ���g�p  ��
	GF_02MP1121_MAKE_CAMP,			// mp1121�ɖ�c�n��z����
	GF_02MP3103_LOOK_LOOKOUT,		// ��������������
	GF_02MP3103_CHECK_LOOKOUT,		// �������𒲂ׂ�
	GF_02MP3104_LOOK_CANYON,		// �勬�J�𔭌�����
	GF_02MP1108_JOIN_HUMMEL,		// �q�������������ԂɂȂ���
	GF_02MP4102_MAKE_CAMP,			// mp4102�ɖ�c�n��z����
	GF_02MP2103_MAKE_CAMP,			// mp2103�ɖ�c�n��z����
	GF_02MP4306_KILL_MIDBOSS,		// �Z�H�J���{�X��|����
	GF_02MP4309_KILL_SPIDER,		// �Z�H�J�{�X��|����
	GF_02MP1119_LOOK_DINA,			//�Y���҃f�B�i�𔭌�
	GF_02MP1119_JOIN_DINA,			//�Y���҃f�B�i������
	GF_02MP2301_JOIN_AARON,			// �G�A�����ɏo�����
	GF_02MP2302_LOOK_MAN,			// �l�e��������
	GF_02MP2304_KILL_MIDBOSS,		// ���ђ��{�X��|����
	GF_02MP2308_KILL_HIPPO,			// ���у{�X�����j����
	GF_02MP1118_IN_MP1118,			// ���т𔲂���
	GF_02MP1118_CALL_PARO,			// �p���̌Ăяo�����󂯂�
	GF_02MP1202_HEAR_SHOUT,			// ���ѐ��𕷂���
	GF_02MP1201_BEFORE_INTERCEPT2,	// �}����̏������͂��߂�
	GF_02MP1201_START_INTERCEPT2,	// �}������J�n����
	GF_02MP1201_LOST_CURRAN,		// �J�[���������s���s���ɂȂ���
	GF_02MP1203_CHECK_ROPE,			// ���ʂ�Y�����[�v�𒲂ׂ�				//��  ���g�p  ��
	GF_02MP1201_LOOK_CURRAN,		// �J�[�������𔭌�����
	GF_02MP1101_START_RESCUE,		// �J�[�������������Ɍ�������
	GF_02MP1113_WIN_ENEMY,			// �I�P�A�m�X�̎�芪����ނ���
	GF_02MP1201_START_HEARING,		// �������݂��J�n����
	GF_02MP1201_END_HEARING,		// �������݂ŏ����W�߂�
	GF_02MP1201_LOOK_MAN,			// �l�e��������
	GF_02MP1101_LOOK_WAIE,			// �|���g���b�v��������
	GF_02MP1201_UNMASK_NEMO,		// �������̐��̂���������
	GF_02MP1201_CHASE_KIERGAARD,	// �L���S�[����������
	GF_02MP1101_GUIDE_PARO,			// �p�����ē����͂��߂�
	GF_02MP1111_WOUND_BARBAROSS,	// �o���o���X���v�����𕉂�
	GF_02MP1103_KILL_KIERGAARD,		// �L���S�[�������j����

	GF_02MP43xx_OCCUR_INTERCEPT2,	// �}����Q����������
	GF_02MP43xx_AFTER_INTERCEPT2,	// �}����Q���I������
	GF_02MP23xx_OCCUR_INTERCEPT3,	// �}����R����������
	GF_02MP23xx_AFTER_INTERCEPT3,	// �}����R���I������
	GF_02MPxxxx_AFTER_INTERCEPT2OR3,	// �}����Q���R���I�������i�V���b�v����p�j				//��  ���g�p  ��
	GF_02MP1201_TUTO_NUMA_BOOTS,		//���`���[�g���A���F�����C�imp1201�j					//��  ���g�p  ��
	GF_02MP1201_TUTO_WEAPON_EVOLVE,		//���`���[�g���A���F����i���imp1201�j					//��  ���g�p  ��
	GF_02MP1201_TUTO_WEAPON_EVOLVED,	//���`���[�g���A���F����i���������imp1201�j			//��  ���g�p  ��
	GF_02MP1201_AFTER_INTERCEPT2,	// �}���킪�I�������B�Ñ��ɏP����J�[�������q���������������A�h�M���ǂ������C�x���g������
	GF_02MP1201_DOGITUTO_COMP,		// ��񕔖`���̃h�M�`���[�g���A������ʂ�I����				//���p�b�`1.01�O�͗����Ȃ��P�[�X��������
	GF_02MP1201_TUTO_QS220,			// �o���o���X���ʂ肩����K�{�N�G�X�g(�u�������̌��݁y�K�{�z)
	GF_02MPxxxx_2ND_CHAPTER_FINISH,	// ��񕔗�

//�ǉ�

	GF_02MP1110_REMOVE_OBSTACLE_1ST,	// �|�؂�P������ �̑O��������
	GF_02MPxxxx_MAX,				// �Q�F��񕔁u�Y���҂����̋����v�t���O�I�[�i�t���O���`�F�b�N�p�Ȃ̂ŁAGF_03Mxxxx_START�̒��O�ɒu���j

	//---------------------------------------------------
	// ���R�F��O���@�u�W�����_�������z���āv 32/50
	GF_03MPxxxx_START = 800,		// �R�F��O���u�W�����_�������z���āv

	GF_03MP6410M_HEAR_TREE,			//�_�[�i�҇@	�A���Ղ̐������󂯂�						//���Q�񗧂ĂĂ���
	GF_03MP6410M_TALK_C350,			//�_�[�i�҇@	����b�t���O								//��  ���g�p  ��
	GF_03MP3109M_MOVE_CANYON,		//�_�[�i�҇@	�勬�J�֌�����
									//�_�[�i�҇@	�A���ՊJ�n��錾����
									//�_�[�i�҇@	�k�J���֐i��
									//�_�[�i�҇@	�A���̋V���n�߂�
	
	GF_03MP1202_AWAKE_ADOL,			//���ɋ����A�h��
	GF_03MP1201_STRIKE_KUINA,		//�N�C�i�ƂԂ���A�h��
	GF_03MP1204_VISIT_GRAVE,		//��O�Ń��N�V���Ƙb��
	GF_03MP1201_GOTO_GENSD,			//�W�����_�����֌��������ƂɂȂ�
	GF_03MP1101_LEAVE_CAMP,			//�W�����_�����֏o������
	GF_03MP3104_IN_GENSD,			//�勬�J�ɓ�������
	GF_03MP3104_CROSS_BRIDGE,		//��؂̋���n��I����
	GF_03MP3105_MAKE_CAMP,			//�W�����_�����[�̖�c�n���o������
	GF_03MP4202_IN_LODGE,			//�^�i�g�X�̏����ɓ�������
	GF_03MP4202_LOOK_LODGE,			//�����̒��𒲂ׂ�
	GF_03MP4202_LOOK_NOTE,			//���̏�̎蒠�𒲂ׂ�
	GF_03MP4202_LOOK_FLOWER,		//����ꂽ�Ԃ𒲂ׂ�
	GF_03MP4202_LOOK_BOOK,			//�{�I�𒲂ׂ�
	GF_03MP4202_TALK_LODGE,			//�����̒����ŉ�b
	GF_02MP4337_KILL_MIDBOSS,		//���R�b�^���������ɓ���i���{�X���j	���s�g�p�H		//�������ɗ��ĂĂ�
	GF_03MP4202_JOIN_RICOTTA,		//���R�b�^�̘b�𕷂�									//�������ɗ��ĂĂ�
	GF_03MP1201_VISIT_RICOTTA,		//���R�b�^�����߂ĕY�����ւ���ė���	���s�g�p		//�������ɗ��ĂĂ�
	GF_03MP1201_TALK_KATRIN,		//�J�g���[���ɑ��k����									//�������ɗ��ĂĂ�
	GF_03MP1107_REPAIR_ROPE,		//�݂苴���C������
	GF_03MP7401_IN_CAVERN,			//�Ñ㓴�A�����ɓ�������
	GF_03MP7401_DEPTH_CAVERN,		//�Ñ㓴�A�̍ŉ��ɓ�������
	GF_03MP7401_GET_MATERIAL,		//�Ñ㓴�A�̍ŉ��ɓ�������2
	GF_03MP1201_ALARM_INTERCEPT,	//�x�����苿��
	GF_03MP1201_BACK_GENSD,			//�ĂуW�����_�����֌����ďo������
									//�����^�Ñ��o��
	GF_03MP4341_KILL_ANCIENT,		//�����^�Ñ��{�X��I��
	GF_03MP4107_TOP_GENSD,			//�W�����_�����̒���ɓ�������
	GF_03MP433x_OCCUR_INTERCEPT5,	// �}����T����������
	GF_03MP433x_AFTER_INTERCEPT5,	// �}����T���I������
	GF_03MPxxxx_3RD_CHAPTER_FINISH,	// ��O����

//�ǉ�

	GF_03MPxxxx_MAX,				// �R�F��O���u�W�����_�������z���āv�t���O�I�[�i�t���O���`�F�b�N�p�Ȃ̂ŁAGF_04Mxxxx_START�̒��O�ɒu���j

	//---------------------------------------------------
	// ���S�F��l���@�u����ꂵ���E�v 40/50
	GF_04MPxxxx_START = 850,		// ���S�F��l���u����ꂵ���E�v

	GF_04MP4107_GOTO_NORTH,			//�k���̒T�������ӂ���Q	
	GF_04MP4111_SEE_ORITREE,		//�͂��܂�̑���𒭂߂�
	GF_04MP4111_MAKE_CAMP,			//����O�̖�c�n�ɓ�������	//���s�g�p					�����ۂ͎g���Ă���
	GF_04MP6201_IN_AIGIUS,			//�_�[�i�B �A�C�M�X���U�􂷂�
	GF_04MP6201_SEE_TOWER,			//�_�[�i�B ����������
	GF_04MP6204_MEET_DORAN,			//�_�[�i�B �h�����ɉ
	GF_04MP4111_OUT_CAMP,			//��c�n���o������
	GF_04MP5102_MISS_RICOTTA,		//���R�b�^���s���s���ɂȂ�
	GF_04MP5102_CATCH_MONS,			//���^�Ñ���ǂ��Ă���
	GF_04MP5401_ENTER_DEN,			//�Ñ��̏Z���֓˓�����
	GF_04MP5401_FIND_RICOTTA,		//���R�b�^�𔭌�����
	GF_04MP5401_TALK_RICOTTA, 		//���R�b�^���Z������~�o����
	GF_04MP5102_RESCUE_RICOTTA,		//���R�b�^���Z������~�o����R
	GF_04MP5101_IN_PLAIN,			//�R�����I��蕽�암�ɏo��
	GF_04MP6102_LOOK_GIANT,			//����^�Ñ��ɑ�������
	GF_04MP6101_MAKE_CAMP,			//���s�O�ŗ�����������
	GF_04MP6101_CRYSTAL_FLASH, 		// �����O�ŕs�v�c�Ȍ��ۂ��N����
	GF_04MP6401M_GO_MP6101M,		//�ߋ��T �A�h���̖�������Q
	GF_04MP5101_OUT_CAMP,			//���s�O��c�n���o������
	GF_04MP6202_IN_EAST,			//���s���X��ɓ�������
	GF_04MP6202_SEE_FIGURE,			//���X��Ől�e������
	GF_04MP6201_RUN_WEST,			//�l�e�����X��֓����Ă���
	GF_04MP6203_SEE_BUILD,			//���X��̕�����������������
	GF_04MP6203_RUN_AWAY,			//�l�e�͂���ɒ[�֓����Ă���
	GF_04MP6203_IN_BUILD,			//�l�e�͌����ɓ�������
	GF_04MP6214_GOTO_2F,			//�������ŋC�z�������ĂQ�K�֌�����
	GF_04MP6203_LOOK_BUILD,			//�������𒲂ׂ�
	GF_04MP6203_RUN_CENTER,			//�l�e���������ʂɓ����Ă�
	GF_04MP6201_LOOK_PAGOIDA,		//������������
	GF_04MP6211_LOOK_STATUE,		//�������̐Α�������
	GF_04MP6211_RUN_PAGOIDA,		//�������̉��֐l�e��������
	GF_04MP6204_IN_PAGOIDA,			//�����������𒭂߂�
	GF_04MP6204_SEE_THANATOS,		//���̏�Ń^�i�g�X�ɏo��Q
	GF_04MP6101M_KNOW_DOWNFALL,		//�ߋ��U �_�[�i�������ŖS��m��Q
	GF_04MP6201_TALK_THANATOS,		//�Q���̏�Q�ŗ�����������
	GF_04MP6201_DIS_OBSTACLE,		//�Q���̏�Q�����ł���
	GF_04MP6409_IN_TEM,				//����̎��@�ɓ�������
	GF_04MP6402_CHECK_GIM,			//���̊J���u�𑀍삷��
	GF_04MP6402_IN_DANAROOM,		//�_�[�i�̕����ɓ�������
	GF_04MP6410_KILL_GUARDIAN,		//���@�{�X��I��
	GF_04MP6409_LOOKUP_ORITREE,		//�͂��܂�̑��������
	GF_04MP5101_OCCUR_INTERCEPT7,	// �}����V����������
	GF_04MP5101_AFTER_INTERCEPT7,	// �}����V���I������
	GF_04MPxxxx_4TH_CHAPTER_FINISH,	// ��l����

//�ǉ�

	GF_04MP6409_LOOK_1ST_CUT,		//����ɕ߂���Ă���_�[�i�̃J�b�g������
	GF_04MPxxxx_MAX,				// �S�F��l���u����ꂵ���E�v�t���O�I�[�i�t���O���`�F�b�N�p�Ȃ̂ŁAGF_05Mxxxx_START�̒��O�ɒu���j

	//---------------------------------------------------
	// ���T�F��ܕ��@�u����̛ޏ��v 64/100
	GF_05MPxxxx_START = 900,		// ���T�F��ܕ��u����̛ޏ��v

	GF_05MP1201_IN_MEETING,			//�h�M�����ɖk���̏󋵂�`����
	GF_05MP1213_INTERCEPT_DANA,		//�_�[�i���}����ɎQ������Q
	GF_05MP1201_JOIN_DANA,			//�_�[�i���A�h���ǂɉ����Q
	GF_05MP1201_GOTO_BAHA,			//�o�n�̓��֌��������ƂɂȂ�
	GF_05MP6204_SEE_RUIN,			//�_�[�i�����{�Ղ�����
	GF_05MP6201_IN_EAST,			//�����ʂ̒ʘH�ɏo��
	GF_05MP6203_SEE_BAHA,			//�o�n�̓��𒭂߂�
	GF_05MP6115_SEE_HOLLOW,			//�_�[�i�����ɂɌ�������
	GF_05MP6201M_GOTO_BAHA,			//�ߋ��V�@�_�[�i�����֌�����
	GF_05MP6201M_IN_BAHA,			//�ߋ��V�@�_�[�i�����ɓ�������@	//��	���g�p	��
	GF_05MP6110_OUT_CAMP,			//���O�̖�c�n���o������
	GF_05MP6321_ATTACK_TOWER,		//���̒T�����J�n����
	GF_05MP6325_KILL_MIDBOSS,		//�o�n�̓����{�X�퓬�I��
	GF_05MP6325_GET_DOUBLEJUMP,		//�n�c���̎w�����
	GF_05MP6329_KILL_BAHABOSS,		//�o�n�̓���{�X�퓬�I��
	GF_05MP6330_FIND_MONOLITH,		//�m���̊Ԃɂ��ǂ蒅��
	GF_05MP6330_LOOK_MONOLITH,		//�_�[�i�����m���X���N������
	GF_05MP1201_NOTICE_MIST,		//�Y�����̑��������ɋC�Â�
	GF_05MP1201_UP_LOOKOUT,			//��������o�邱�Ƃɂ���
	GF_05MP1201_GOTO_GHOSTHIP,		//�H��D�𒲍����邱�ƂɂȂ�
	GF_05MP7411_SEE_GHOSTHIP,		//�G���t�Z���A���𔭌�����
	GF_05MP7411_INTO_GHOSTHIP,		//�G���t�Z���A�̓������T��
	GF_05MP7411_READ_NOTE1,			//���[�h�̍q�C�����@��ǂ�
	GF_05MP7411_SAIL_GHOSTSHIP,		//�G���t�Z���A�����o�q����
	GF_05MP0404_READ_NOTE2,			//���[�h�̍q�C�����A��ǂ�
	GF_05MP0404_READ_NOTE3,			//���[�h�̍q�C�����B��ǂ�
	GF_05MP0404_READ_NOTE4,			//���[�h�̍q�C�����C��ǂ�
	GF_05MP0405_WIN_BOSS,			//�L���v�e���E���[�h�퓬��
	GF_05MP0405_READ_NOTE5,			//�Ō�̍q�C������ǂ�
	GF_05MP0404_KILL_MIDBOSS,		//�����g�p�t���O					//��	���g�p	��
	GF_05MP0405_READ_REED,			//�L���v�e���E���[�h�ƕʂ��Q
	GF_05MP1202_CHECK_MAP,			//��󓴂֌��������ƂɂȂ�Q
	GF_05MP1201_GOTO_HOLLOW,		//���s�ɓ]�ڂœ�������Q
	GF_05MP6204_FIND_CRYSTAL,		//�󒆉�L�ɓ��B����
	GF_05MP6202_GOTO_SKYWAY,		//�ߋ��W�@���m�̈�c�ɑ�������
	GF_05MP6204_APPEAR_CASTLE,		//���ł������{����������
	GF_05MP6362_SEE_FALLS,			//�匊�̑��e�z������Q
	GF_05MP6366_KILL_MIDBOSS,		//��󓴒��{�X�퓬�I��
	GF_05MP6365_GET_OXYGEN,			//�s�����̗؁t����ɓ����
	GF_05MP1201_OCEANUS_STANDBY,	//�I�P�A�m�X������̏���
	GF_05MP6371_START_OPS,			//�I�P�A�m�X��������J�n����		//��	���g�p	��
	GF_05MP6367_KILL_OCEANUS,		//�I�P�A�m�X�ɏ�������				//��	���g�p	��
	GF_05MP1201_HOLD_PARTY,			//�Y�����Ō��N��Â����
	GF_05MP1201_REGAIN_MEMORY,		//�L�������߂��̂���`���� �ƕԎ�����
	GF_05MP6231M_GOTO_SKYWAY,		//�ߋ��W�|�Q�@���s�ɐ�����������
	GF_05MP1201_GOTO_VALLAY,		//���Ƃ̒J�֌��������Ƃɂ���
	GF_05MP4105_PASS_TEM,			//���@�̎R��𐼑��֔�����
	GF_05MP6105_CATCH_DANA,			//�_�[�i�ɒǂ����Q
	GF_05MP6203_GOTO_VALLEY,		//�ߋ��X�@�_�[�i�����Ƃ̒J�֏o��
	GF_05MP6106M_SOLDIER_ASK,		// �ߋ��X�@�q�m�����ɒN�����󂯂�
	GF_05MP6105_GOTO_VALLAY,		//���s�̒J��ڎw��
	GF_05MP6108_MALK_CAMP,			//�揊�O�Ŗ�c����
	GF_05MP6345_KILL_MIDBOSS,		//���Ƃ̒J���{�X�퓬�I��
	GF_05MP6349_KILL_BOSS,			//���Ƃ̒J��{�X�퓬�I��
	GF_05MP6350_INTO_GARDEN,		//�揊�̍L����Ԃɏo��
	GF_05MP6351_SEE_WALLPAINT,		//�ǉ�̊Ԃɂ��ǂ蒅��

	GF_05MP1201_OCCUR_INTERCEPT9,	// �}����X����������
	GF_05MP1201_AFTER_INTERCEPT9,	// �}����X���I������
	GF_05MP1202_QUEST_QS510,			// �yQS510�z�̋��̉ԃN�G�X�g�J�n�C�x���g������
	GF_05MPxxxx_5TH_CHAPTER_FINISH,	// ��ܕ���

//�ǉ�
	GF_05MP7411_LOOK_BRIDGE,		// ���̎V���𔭌������@[M05S143][�H��D�𒲍����邱�ƂɂȂ�]�Ŏg�p����t���O
	GF_05MP0404_IN_GHOSTSHIP,		// �H��D�̑D���ɓ������@�� GF_05MP7411_SAIL_GHOSTSHIP�̌��ɂ���
	GF_05MP6370_BOSS_HELP,			// �I�P�A�m�X�풆�̎�_��������J�����ړ�������
	GF_05MP1213_CHECK_DANA,			// �}���풆�Ƀ_�[�i����������Q�[���I�[�o�[��������p

//PS4�ǉ�
	GF_05MP1201_INTO_LOOKOUT,		//��������o����

	GF_05MPxxxx_MAX,				// �T�F��ܕ��u����̛ޏ��v�t���O�I�[�i�t���O���`�F�b�N�p�Ȃ̂ŁAGF_05Mxxxx_START�̒��O�ɒu���j
	
	//---------------------------------------------------
	// ���U�F��Z���@�u��C�̃��N�����T�v 31/50
	GF_06MPxxxx_START = 1000,	// ���U�F��Z���u��C�̃��N�����T�v

	GF_06MP1201_BEFORE_INTERCEPT,		//���Ƃ̒J�ɂ��ĕ񍐂���
	GF_06MP1215_APPEAR_ANCIENT,			//�}����ŐV��ɑ�������
	GF_06MP1201_GOTO_GEND,				//�����̂��߃W�����_�����֌�����		//��  "EV_M07S121_ED"�ɓ��Z�b�g  ��
	GF_06MP4341_SEE_COCOON,				//����ٕ̈ς�ڌ�����
	GF_06MP4109_IN_GATE,				//���̕Y���R��ɓ���
	GF_06MP4105B_START_ROOP,			//���̒��ňٌ`�̌Ñ��Ɛ키�P
	GF_06MP4105B_NONE_PARTY,			//���̒��ňٌ`�̌Ñ��Ɛ키�Q
	GF_06MP6202M_GOTO_GARDEN,			//�ߋ��Y�@�Z�����̉��֌�����
	GF_06MP6350M_IN_GARDEN,				//�ߋ��Y�@�Z�����̉��ɓ�������
	GF_06MP4109_GOTO_GARDEN,			//�A�h�����Z�����̉���ڎw��
	GF_06MP6350_IN_GARDEN,				//�A�h���������Z�����̉��ɓ�������
	GF_06MP6350_TALK_GUARDIAN,			//���l�������]�ڂ��Ă���
	GF_06MP4109_CLEAR_MIST,				//�R��̖���˔j����
	GF_06MP6409_OPEN_GATE,				//�I�N�g�D�X�֐N������
	GF_06MP6301_INTO_WORLDTREE,			//�I�N�g�D�X�̍U�����J�n����
	GF_06MP6301_ATTACK_OXTOS,			//�I�N�g�D�X�̍U�����J�n����Q
	GF_06MP6305_IN_OCEAN,				//�C�̉�L�֓˓�����
	GF_06MP6305_TALK_HYDRA,				//�q�h�D���Ƙb��
	GF_06MP6301_RETURN_CENTER,			//�I�N�g�D�X�����̊Ԃɖ߂� 
	GF_06MP6306_TALK_MINOS,				//�~�m�X�Ƙb��
	GF_06MP6301_OPEN_INSECT,			//峂̉�L�֐i�߂�悤�ɂȂ�
	GF_06MP6307_TALK_NESTOR,			//�l�X�g�[���Ƙb��
	GF_06MP6301_OPEN_HEAVENS,			//�V�̉�L�֐i�߂�悤�ɂȂ�
	GF_06MP6308_TALK_SARAI,				//�T���C���z�O�����߂�
	GF_06MP6301_OPEN_STAIRS,			//���֑����K�i�������
	GF_06MP6350_GET_MISTILTEINN,		//�z���~�X�g���e�B������肷��
	GF_06MP6301_GOTO_BOSSROOM,			//�s�I���̊ԁt�֐i��
	GF_06MP6301_OPEN_BOSSROOM,			//�s�I���̊ԁt�ւ̔����J��
	GF_06MP6310_ATTACK_BOSSROOM,		//�s�I���̊ԁt�U�����J�n����
	GF_06MP6409_OCCUR_INTERCEPT12,		// �}����12����������
	GF_06MP6409_AFTER_INTERCEPT12,		// �}����12���I������
	GF_06MPxxxx_6TH_CHAPTER_FINISH,	// ��Z����


//�ǉ�
	GF_06MP1201_OCCUR_INTERCEPT21,		// �}����21����������
	GF_06MP1201_AFTER_INTERCEPT21,		// �}����21���I������
	GF_06MP1201_OCCUR_INTERCEPT22,		// �}����22����������
	GF_06MP1201_AFTER_INTERCEPT22,		// �}����22���I������
	GF_06MP1201_OCCUR_INTERCEPT23,		// �}����23����������
	GF_06MP1201_AFTER_INTERCEPT23,		// �}����23���I������
	GF_06MP1201_OCCUR_INTERCEPT24,		// �}����24����������
	GF_06MP1201_AFTER_INTERCEPT24,		// �}����24���I������
	GF_06MP1201_OCCUR_INTERCEPT25,		// �}����25����������
	GF_06MP1201_AFTER_INTERCEPT25,		// �}����25���I������
	GF_06MP1201_OCCUR_INTERCEPT26,		// �}����26����������
	GF_06MP1201_AFTER_INTERCEPT26,		// �}����26���I������
	GF_06MP1201_INTERCEPT_ALL_CLEAR,	// �}����S�ăN���A�i�A�h�����h�M�̃T�u�C�x���g�������j

	GF_06MPxxxx_MAX,				// �U�F��Z���u��C�̃��N�����T�v�t���O�I�[�i�t���O���`�F�b�N�p�Ȃ̂ŁAGF_05Mxxxx_START�̒��O�ɒu���j

	//---------------------------------------------------
	// ���V�F�G�s���[�O 11/150
	GF_07MPxxxx_START = 1050,	// ���V�F�G�s���[�O

	GF_07MP1202_AWAKE_ADOL,			//�Y�����ŃA�h�����ڂ��o�܂�
	GF_07MP6409_PARTY_JOIN,			// �d�c�V �R��Œ��Ԃƍ���
	GF_07MP6409_MEET_MAIA,			// �d�c�V ��n�_�}�C�A�Ƃ���
	GF_07MP6409_GOTO_ABYSS,			//�d�c�V �s�͂��܂�̐[���t�˓�					//�����g�p�����������p�b�`1.01�ŗ��Ă�`�ɏC��
	GF_07MP6409_DUNGEON_CLEAR, 	//�d�c�V �s�͂��܂�̐[���t�˔j
	GF_07MP1201_CHECK_VILLAGE,		//�d�c�V �Z�C��������E�o����

//�ǉ�
	GF_07MP1201_VILLAGE_WALK,		// �Y����������Ă݂�
	GF_07MP1201_TALK_HUMMEL,		// �Y����������Ă݂��i�q���������Ƙb�����j
	GF_07MP1201_TALK_RICOTTA,		// �Y����������Ă݂��i���R�b�^�Ƙb�����j
	GF_07MP1201_TALK_SAHAD,			// �Y����������Ă݂��i�T�n�h�Ƙb�����j
	GF_07MP1201_TALK_ALL,			// �Y����������Ă݂��i�S���Ƙb���Ėk���Ɍ��������Ƃɂ����j
	GF_07MPxxxx_MAX,				// �V�F�G�s���[�O�t���O�I�[�i�t���O���`�F�b�N�p�Ȃ̂ŁAGF_05Mxxxx_START�̒��O�ɒu���j

	//---------------------------------------------------

	GF_EVENT_CTL = 1199,		// �C�x���g�ėp�t���O

	/////////////////////////////////////////////////////
	// ���̑��i�T�u�C�x���g��n��܂������j�S��
	/////////////////////////////////////////////////////
	GF_OTHER_START = 1200,		// ���̑��S��
	
	GF_NORMAL_END,				// �����m�[�}���G���h����p
	GF_TRUE_END,				// �����g�D���[�G���h����p

	// �n���\���p
	GF_MPxxxx_MAP_NAME_NO_DRAW,	// �n���\��(0)/��\��(1)�̐؂�ւ��p

	//---------------------------------------------------
	// �W������
	GF_BASECAMP_LV,					// �W�����x��
	GF_SMITHY_LV,					// �b��ꃌ�x��
	GF_TOOLSHOP_LV,					// ������x��
	GF_CLINIC_LV,					// �f�Ï����x��
	GF_KITCHEN_LV,					// �����ꃌ�x��
	GF_SHED_LV,						// ���u���x��
	GF_SHIPYARD_LV,					// ���D�����x��
	GF_FARM_LV,						// �_�ꔨ���x��
	GF_FARMFENCE_LV,				// �_�ꃌ�x��
	
	GF_CAMP_VILLAGE_LV,				// �Y�����̔��W�ݒ�F�W��LV
//	GF_CAMP_GATE_LV,				// �Y�����̔��W�ݒ�F�C�Ƌu���ʂ̖h�q��		//���ɒǉ����Ă܂�
	GF_CAMP_GRAVE_LV,				// �Y�����̔��W�ݒ�F�o���o���X�̕�LV
	GF_CAMP_SHIPYARD_LV,			// �Y�����̔��W�ݒ�F���D��LV
	GF_CAMP_FARM_LV,				// �Y�����̔��W�ݒ�F�_��LV
	GF_CAMP_FARMFENCE_LV,			// �Y�����̔��W�ݒ�F�_���LV
	GF_CAMP_WISHTREE_LV,			// �Y�����̔��W�ݒ�F�肢�̖�LV
	GF_CAMP_PAROWOOD_LV,			// �Y�����̔��W�ݒ�F�p���̎~�܂��LV
	GF_CAMP_ROOM_LV,				// �Y�����̔��W�ݒ�F���_����
	GF_CAMP_BED_LV,					// �Y�����̔��W�ݒ�F�Q��
	GF_CAMP_CURTAIN_LV,				// �Y�����̔��W�ݒ�F�������̃J�[�e��
	GF_CAMP_TAILOR_LV,				// �Y�����̔��W�ݒ�F�d���ĉ�
	GF_CAMP_GATE_LV,				// �Y�����̔��W�ݒ�F�C�Ƌu���ʂ̖h�q��

	GF_MP1202_NOW,					// �������O����p

	//---------------------------------------------------
	// �A�h������l�l����
	GF_PARTY_NONE,					// �p�[�e�B�S���s��

	//---------------------------------------------------
	//---------------------------------------------------
	//---------------------------------------------------
	//---------------------------------------------------
	// <!-- ��������A�e�X�g�⌟�ؔŗp�̃t���O�Ȃ̂ŁA�s�v�ɂȂ���������ׂ�
	// ���퓬�V�d�l���ؗp
	GF_BTLNEWSPEC_TRIAL2,			// �퓬��s���ؗp
	GF_GEIGEKIBATTLE_TRIAL,			// �}���팟�ؔ�

	// �����܂ŁA�e�X�g�⌟�ؔŗp�̃t���O�Ȃ̂ŁA�s�v�ɂȂ���������ׂ� -->
	//---------------------------------------------------
	//---------------------------------------------------
	//---------------------------------------------------
	//---------------------------------------------------

	//---------------------------------------------------
	// �{�X�퐧��p�i����}�b�v�ł̃{�X�퓙�j�@�̑���
	GF_MP6310B_ENDROGRAM_STEP,		// �e�I�X�E�f�E�G���h���O�����̒i�K
	GF_MP1103_KIERGAARD,			// �L���S�[���픻��p
	GF_MP8323_2NDBATTLE,			// �͂��܂�̖��A���i�K�i�e��j����p

	//---------------------------------------------------
	//���ǉ���
	GF_ADOLWEAPON_BACKUP,	//�~�X�g���e�B���ɕς��O�̕�����o�b�N�A�b�v
	GF_NO_UNIWAIT,			//�ҋ@���[�V��������p

	GF_NIGHTHUNT,			//��}�b�v�U��������
	GF_OPEN_CORAL_T2,		//��}�b�v����i�X��̐X
	GF_OPEN_GENSD_T2,		//��}�b�v����i�W�����_����
	GF_OPEN_PANGAIA_T2,		//��}�b�v����i�p���K�C�A
	
	GF_MP7304_KONG,			// �}�X�^�[�R���O�픻��p
	
	GF_EXPOWER_BAK_ADOL,	//EX�Q�[�W�̃o�b�N�A�b�v�i�A�h��
	GF_EXPOWER_BAK_DANA,	//EX�Q�[�W�̃o�b�N�A�b�v�i�_�[�i

	GF_ADOLSIDE_FAME,			//���R�[�h�F�A�h���ƃ_�[�i�̖����l��؂�ւ���t���O
	GF_DANASIDE_FAME,			//���R�[�h�F�A�h���ƃ_�[�i�̖����l��؂�ւ���t���O
	GF_ADOLSIDE_VIRTURE,		//���R�[�h�F�A�h���ƃ_�[�i�̓���؂�ւ���t���O
	GF_DANASIDE_VIRTURE,		//���R�[�h�F�A�h���ƃ_�[�i�̓���؂�ւ���t���O

	GF_OTHER_MAX,		// ���̑��I�[
	//---------------------------------------------------
	//�L���̋ʃt���O ->���P�[�V���������t���O�ɕύX�\��
	GF_MEMORY_START = 1300,		// �L���̌��Џ�

	GF_LOCATION01,//������
	GF_LOCATION02,//�Ɋ�
	GF_LOCATION03,//���F�̑�
	GF_LOCATION04,//���^�{���J���X
	GF_LOCATION05,//�p���Z�R�C�A
	GF_LOCATION06,
	GF_LOCATION07,
	GF_LOCATION08,//���ˊ�
	GF_LOCATION09,//���F�̍z��
	GF_LOCATION10,//�ł��グ��ꂽ��[
	GF_LOCATION11,//�򑐂̌Q���n
	GF_LOCATION12,
	GF_LOCATION13,//�G�A�[�Y���b�N�P����
	GF_LOCATION14,
	GF_LOCATION15,
	GF_LOCATION16,//�����̋u
	GF_LOCATION17,//�ڗ��F�̍z��
	GF_LOCATION18,//�����F�̍z��
	GF_LOCATION19,//�I��
	GF_LOCATION20,
	GF_LOCATION21,//�D�̕��
	GF_LOCATION22,//�B���q
	GF_LOCATION23,//�}���O���[�_
	GF_LOCATION24,//���F�̍z��
	GF_LOCATION25,//���j�J���~�e�X
	GF_LOCATION26,
	GF_LOCATION27,//����̋u
	GF_LOCATION28,//�V����
	GF_LOCATION29,
	GF_LOCATION30,
	GF_LOCATION31,
	GF_LOCATION32,//�X�J�C�K�[�f��
	GF_LOCATION33,//�Î�̊�
	GF_LOCATION34,//�Â��E�m�B�̕��
	GF_LOCATION35,
	GF_LOCATION36,

	GF_MEMORY_MAIN01,		//�e�X�g�g�p�Bmp1135���P�[�V��������
	GF_MEMORY_MAIN02,		//�e�X�g�g�p�Bmp3104���P�[�V��������
	GF_MEMORY_MAIN03,		//�e�X�g�g�p�Bmp1304���P�[�V��������

	GF_MEMORY_END,				// �L���̌��Џ�

	//---------------------------------------------------
	//�M�~�b�N�n�t���O
	GF_GIMMICK_START = 1400,		// �M�~�b�N�n�t���O
	
	// �}����T��
	GF_INTERCEPT_NO,				// ���ݔ������̌}����T��

	// �t�B�[���h
	GF_MP1104_SHORTCUT,				// mp1104�̃V���[�g�J�b�g

	// �X��̐X
	GF_MP130x_GIM_01,				// �X��̐X�M�~�b�N�P
	GF_MP130x_GIM_02,				// �X��̐X�M�~�b�N�Q
	GF_MP130x_GIM_03,				// �X��̐X�M�~�b�N�R
	GF_MP1305_INTERCEPT,			// �X��̐X�}����

	//----
	// �Z�H�J
	GF_MP430x_GIM_01,				//
	GF_MP430x_GIM_02,				//
	GF_MP430x_GIM_03,				//

	//----
	// �W�����_����
	GF_MP433x_GIM_01,				// mp4331 �V���[�g�J�b�g_��������ʂ̓|��
	GF_MP433x_GIM_02,				// mp4333 �V���[�g�J�b�g_���q
	GF_MP433x_GIM_03,				// mp4334 �V���[�g�J�b�g_���A�p�|��
	GF_MP433x_GIM_04,				// mp4335 �V���[�g�J�b�g_���A�p�|��
	GF_MP433x_GIM_05,				// mp4335 �V���[�g�J�b�g_���q

	//----
	// ���Ƃ̒J
	GF_MP634x_GIM_01,				// mp6341 �V���[�g�J�b�g
	GF_MP634x_GIM_02,				// mp6341 �V���[�g�J�b�g
	GF_MP634x_GIM_03,				// mp6341 �V���[�g�J�b�g

	GF_MP634x_FIRE_01,				// mp6341 �ォ���Ԗڂ̐C��B��̖ڂ̑�^�s���G����|���Ɠ_�΂���
	GF_MP634x_FIRE_02,				// mp6341 �ォ���Ԗڂ̐C��B��̖ڂ̑�^�s���G����|���Ɠ_�΂���
	GF_MP634x_FIRE_03,				// mp6341 �ォ��O�Ԗڂ̐C��B�O�̖ڂ̑�^�s���G����|���Ɠ_�΂���
	GF_MP634x_FIRE_04,				// mp6341 �ォ��l�Ԗڂ̐C��B�l�̖ڂ̑�^�s���G����|���Ɠ_�΂���

	GF_MP6346_RESET_SWITCH,			// ���������s�������ǂ����̃t���O
	GF_MP6346_SWITCH_01R,			// mp6346 ��]�X�C�b�`�P�E
	GF_MP6346_SWITCH_01L,			// mp6346 ��]�X�C�b�`�P��
	GF_MP6346_SWITCH_02R,			// mp6346 ��]�X�C�b�`�Q�E
	GF_MP6346_SWITCH_02L,			// mp6346 ��]�X�C�b�`�Q��
	GF_MP6346_SWITCH_03R,			// mp6346 ��]�X�C�b�`�R�E
	GF_MP6346_SWITCH_03L,			// mp6346 ��]�X�C�b�`�R��
	GF_MP6346_DOOR_01,				// mp6346 �h�A�̊J��� 0=close, 1=open
	GF_MP6346_DOOR_02,				// mp6346 �h�A�̊J��� 0=close, 1=open
	GF_MP6346_DOOR_03,				// mp6346 �h�A�̊J��� 0=close, 1=open

	GF_MP6347_RESET_SWITCH,			// ���������s�������ǂ����̃t���O
	GF_MP6347_SWITCH_01,			// mp6347 ��]�X�C�b�`�P
	GF_MP6347_SWITCH_02,			// mp6347 ��]�X�C�b�`�Q
	GF_MP6347_SWITCH_03,			// mp6347 ��]�X�C�b�`�R
	GF_MP6347_SWITCH_04,			// mp6347 ��]�X�C�b�`�S
	GF_MP6347_DOOR_01,				// mp6347 �h�A�̊J��� 0=close, 1=open

	//----
	// �o�n�̎Γ�
	GF_MP6328_SWITCH_00,			// mp6328 �X�C�b�`00
	GF_MP6328_SWITCH_01,			// mp6328 �X�C�b�`01
	GF_MP6328_SWITCH_02,			// mp6328 �X�C�b�`02
	GF_MP6328_SWITCH_03,			// mp6328 �X�C�b�`03

	//----
	// ���v���@
	GF_MP7481_SWITCH_00,			// mp7481 �X�C�b�`00

	//----
	// ��m�@
	GF_MP642x_SWITCH_01,			// mp6422 �X�C�b�`01
	GF_MP642x_SWITCH_02,			// mp6421 �X�C�b�`02
	GF_MP642x_SWITCH_03,			// mp6421 �X�C�b�`03
	GF_MP6422_SWITCH_00,			// mp6422 �X�C�b�`00
//	GF_MP6422_SWITCH_01,			// mp6422 �X�C�b�`01	//���ɒǉ�

	//----
	// ���X�_���E�I�N�g�D�X
	GF_MP630x_SMALLBOSS_00,			// mp630x ���{�X���j�@
	GF_MP630x_SMALLBOSS_01,			// mp630x ���{�X���j�A
	GF_MP630x_SMALLBOSS_02,			// mp630x ���{�X���j�B
	GF_MP630x_SMALLBOSS_03,			// mp630x ���{�X���j�C
	GF_MP630x_SMALLBOSS_04,			// mp630x ���{�X���j�D
	GF_MP630x_SMALLBOSS_05,			// mp630x ���{�X���j�E
	GF_MP630x_SMALLBOSS_06,			// mp630x ���{�X���j�F
	GF_MP630x_SMALLBOSS_07,			// mp630x ���{�X���j�G
	GF_MP630x_SMALLBOSS_08,			// mp630x ���{�X���j�H
	GF_MP630x_SMALLBOSS_09,			// mp630x ���{�X���j�H
	GF_MP630x_SMALLBOSS_10,			// mp630x ���{�X���j�I

	//----
	// �n����̑匊
	GF_MP6369_SWITCH_00,			// mp6369 �X�C�b�`00

	//----
	// ����̎��@�E����
	GF_MP6401_SWITCH_01R,			// mp6401���͔��Q�K�E�X�C�b�`
	GF_MP6401_SWITCH_01L,			// mp6401���͔��Q�K���X�C�b�`
	GF_MP6401_SWITCH_02,			// mp6401���͔��P�K�X�C�b�`
	GF_MP6401_SWITCH_03,			// mp6401���p���o�[

	//----
	// �����n
	GF_MP745x_GIM_01,				// mp7451 �V���[�g�J�b�g_�|��




	//----
	// �N�m�X
	GF_MP1108_FOUNDKNOS,			// mp1108�A�N�m�X�}�[�J�[�ݒ肵��
	GF_MP1108_KNOS01,				// mp1108�A���тւ̓����ǂ��N�m�X�i�r�b�g�t���O�j
	GF_MP1108_KNOS02,				// mp1108�A�T�u���[�g�ւ̓����ǂ��N�m�X�i�r�b�g�t���O�j

	GF_MP2301_FOUNDKNOS,			// mp2301�A�N�m�X�}�[�J�[�ݒ肵��
	GF_MP2301_KNOS,					// mp2301�A�܏��H�ǂ��N�m�X�i�r�b�g�t���O�j

	GF_MP2306_FOUNDKNOS,			// mp2306�A�N�m�X�}�[�J�[�ݒ肵��
	GF_MP2306_KNOS,					// mp2306�A�܏��H�ǂ��N�m�X�i�r�b�g�t���O�j


//�������ǉ���������
	// ��m�@
	GF_MP6422_SWITCH_01,			// mp6422 �X�C�b�`01

	// �n������
	GF_MP6511_SWITCH_01,			// mp6511 �X�C�b�`01
	GF_MP6511_SWITCH_02,			// mp6511 �X�C�b�`02
	GF_MP6511_SWITCH_03,			// mp6511 �X�C�b�`03
	GF_MP6511_SWITCH_04,			// mp6511 �X�C�b�`04
	GF_MP6511_SWITCH_05,			// mp6511 �X�C�b�`05
	GF_MP6511_TUTO_02,				// mp6511 �X�C�b�`02�E����
	GF_MP6521_SWITCH_01,			// mp6521 �X�C�b�`01
	GF_MP6521_TUTO_03,				// mp6521 �񐔐������E����
	GF_MP6531_SWITCH_01,			// mp6531 �X�C�b�`01
	GF_MP6521_SWITCH_01A,			// mp6521 �X�C�b�`01 ���o�[��
	GF_MP6521_SWITCH_01B,			// mp6521 �X�C�b�`01 ���o�[�E
	GF_MP6521_SHORTCUT_01,			// mp6521 �V���[�g�J�b�g1
	GF_MP6541_SWITCH_02A,			// mp6541 �X�C�b�`01 ���o�[�E
	GF_MP6541_SWITCH_02B,			// mp6541 �X�C�b�`01 ���o�[��
	GF_MP6541_SWITCH_01,			// mp6541 �X�C�b�`01 ��
	GF_MP6541_SWITCH_02,			// mp6541 �X�C�b�`02 ��������
	GF_MP6541_TUTO_03,				// mp6541 �񐔐������E����
	GF_MP6541_SHORTCUT_01,			// mp6541 �V���[�g�J�b�g1
	GF_MP6541_SWITCH_04,			// mp6541 �X�C�b�`04 ��@����
	GF_MP6531_SHORTCUT_01,			// mp6531 �V���[�g�J�b�g1

	// �X��̐X�i��j
	GF_MP130xt2_GIM_01,				// �X��̐X�M�~�b�N�P
	GF_MP130xt2_GIM_02,				// �X��̐X�M�~�b�N�Q
	GF_MP130xt2_GIM_03,				// �X��̐X�M�~�b�N�R

	// �ǉ����i�݊����̂��ߌ��ɕt�������j
	GF_MP6511_SWITCH_06,			// mp6511 �X�C�b�`06 ��@����
	GF_MP6521_SWITCH_02,			// mp6521 �X�C�b�`02
	GF_MP6521_SWITCH_02A,			// mp6521 �X�C�b�`02 ���o�[��
	GF_MP6521_SWITCH_02B,			// mp6521 �X�C�b�`02 ���o�[�E

	GF_MP6511_WALL_01,				// mp6511 ���01 ����
	GF_MP6511_WALL_02,				// mp6511 ���02 ����
	GF_MP6521_WALL_01,				// mp6521 ���01 ����
	GF_MP6531_WALL_01,				// mp6531 ���01 ����
	GF_MP6531_WALL_02,				// mp6531 ���02 ����
	GF_MP6541_WALL_01,				// mp6541 ���01 ����
	GF_MP6551_WALL_01,				// mp6551 ���01 ����
	GF_MP6551_WALL_02,				// mp6551 ���02 ����
	GF_MP6551_WALL_03,				// mp6551 ���03 ����

	//----
	// �N�m�X�ǉ���	��PS4�ǉ�
	GF_MP1114_FOUNDKNOS,			// mp1114�A�N�m�X�}�[�J�[�ݒ肵��
	GF_MP1114_KNOS01,				// mp1114�A�N�m�X�i�r�b�g�t���O�j
	
	GF_MP7451_FOUNDKNOS,			// mp7451�A�N�m�X�}�[�J�[�ݒ肵��
	GF_MP7451_KNOS01,				// mp7451�A�N�m�X�i�r�b�g�t���O�j

	GF_MP6201_FOUNDKNOS,			// mp6201�A�N�m�X�}�[�J�[�ݒ肵��
	GF_MP6201_KNOS01,				// mp6201�A�N�m�X�i�r�b�g�t���O�j

	GF_MP6108_FOUNDKNOS,			// mp6108�A�N�m�X�}�[�J�[�ݒ肵��
	GF_MP6108_KNOS01,				// mp6108�A�N�m�X�i�r�b�g�t���O�j

	GF_MP3103_FOUNDKNOS,			// mp3103�A�N�m�X�}�[�J�[�ݒ肵��
	GF_MP3103_KNOS01,				// mp3103�A�N�m�X�i�r�b�g�t���O�j
	
	//�ǉ���
	GF_MP6541_CLOSE_CNT,			//���΃w���v���b�Z�[�W�\���܂ł̃J�E���g
	GF_MP6521_CLOSE_CNT,			//���΃w���v���b�Z�[�W�\���܂ł̃J�E���g

	GF_GIMMICK_MAX,					// �M�~�b�N�n�I�[

	//---------------------------------------------------
	// �ނ�ڋʋ��t���O
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
	GF_FISH_FEATURE_024,		//�@�N�G�X�g��p���p
	
	GF_FISH_FEATURE_B00,	//�@�k�V
	GF_FISH_FEATURE_B01,	//�@�k�V
	GF_FISH_FEATURE_B02,	//�@�k�V

	GF_FISH_FEATURE_M00,	//�@�\��00�p
	GF_FISH_FEATURE_M01,	//�@�\��01�p
	GF_FISH_FEATURE_M02,	//�@�\��02�p
	GF_FISH_FEATURE_M03,	//�@�\��03�p
	GF_FISH_FEATURE_M04,	//�@�\��04�p
	GF_FISH_FEATURE_M05,	//�@�\��05�p
	GF_FISH_FEATURE_M06,	//�@�\��06�p
	GF_FISH_FEATURE_M07,	//�@�\��07�p
	GF_FISH_FEATURE_M08,	//�@�\��08�p
	GF_FISH_FEATURE_M09,	//�@�\��09�p

	GF_FISH_FEATURE_T00,		//�@��
	GF_FISH_FEATURE_T01,		//�@��
	GF_FISH_FEATURE_T02,		//�@��
	GF_FISH_FEATURE_T03,		//�@��
	GF_FISH_FEATURE_T04,		//�@��
	GF_FISH_FEATURE_T05,		//�@��
	GF_FISH_FEATURE_T06,		//�@��
	GF_FISH_FEATURE_T07,		//�@��
	GF_FISH_FEATURE_T08,		//�@��
	GF_FISH_FEATURE_T09,		//�@��
	GF_FISH_FEATURE_T10,		//�@��
	GF_FISH_FEATURE_T11,		//�@��

	//�ǉ���
	GF_FISH_FEATURE_B03,		//�k�V

	GF_FISH_FEATURE_END,

	//---------------------------------------------------
	//�T�u�V�i���I�n�t���O

	//��ʃ��b�Z�[�W�؂�ւ��p�t���O
	GF_NPC_START = 1800,

	GF_NPC_00_01_GO_CAPTAINROOM,		//�D�����Ɍ�����
	GF_NPC_00_02_START_PATROL,			//������J�n����
	GF_NPC_00_03_GO_CAPTAINROOM2,		//�D�����Ɍ������Q
	GF_NPC_00_04_HEAR_SCREAM,			//�ߖ���������
	GF_NPC_01_01_IN_BASE,				//�Y�����\��n�ɓ���
	GF_NPC_01_02_MEET_BARBAROSS,		//�o���o���X�ƍĉ��
	GF_NPC_2A_01_START_EXPLORE,			//�T�����J�n����	
	GF_NPC_2A_02_OBSTACLE_REMOVE,		//���ꂫ��P������	
	GF_NPC_2A_03_JOIN_ALISON,			//�A���X����ی�
	GF_NPC_2A_04_BEFORE_INTERCEPT,		//�}����i���ځj����
	GF_NPC_2A_05_AFTER_INTERCEPT,		//�}������ڂ��I�����
	GF_NPC_2B_01_JOIN_KIERGAARD,		//�Y���ғ�l��ی�
	GF_NPC_2B_02_MEET_KATRIN,			//�J�g���[����������
	GF_NPC_2B_03_CAMP_MP1121,			//����O�̓��A�Ŗ�c����
	GF_NPC_2B_04_JOIN_HUMMEL,			//�q���������ƍĉ��
	GF_NPC_2B_05_MEET_AARON,			//�G�A�����ɏo�����
	GF_NPC_2B_05_HEAR_SHOUT,			//�J�[�������̔ߖ𕷂���	
	GF_NPC_2B_06_BEFORE_INTERCEPT,		//�}����̏������͂��߂�
	GF_NPC_2B_07_CURRAN_LOST,			//�J�[���������s���s���ɂȂ���
	GF_NPC_2B_08_HEARING_START,			//�������݂��J�n����
	GF_NPC_2B_09_UNMASK_NEMO,			//�������̐��̂���������
	                                      

	GF_NPC_00_PROLOGUE,				//�O�F�z�R�Ɍ������܂Łi�v�����[�O�j
	GF_NPC_01_START_CASNAN,			//�@�F�L���X�i�����o��
	GF_NPC_02_A_ASSALUT_COMODU,		//�A�`�F�J�[�i�������Oor��
	GF_NPC_02_A2_COMODU_CLEAR,		//�A�`�U�F�R���h�̎���������
	GF_NPC_02_B_JOIN_OZMA,			//�A�a�F�I�Y�}������
	GF_NPC_02_B2_SELRAY_CLEAR,		//�A�a�U�F�Z�����C�̎���������
	GF_NPC_02_C_ONESIDE_CLEAR,		//�A�b�F�R���hor�Z�����C�Е��N���A
	GF_NPC_02_C2_BOTH_CLEAR,		//�A�b�U�F�R���h���Z�����C�����N���A
	GF_NPC_03_WALK_CASNAN,			//�B�F�A�h���P�l�ŊX�U��
	GF_NPC_03_2_JOIN_CARNA,			//�B�U�F�J�[�i�ƍ���������
	GF_NPC_04_WALK_HIGHLAND,		//�C�F������ňꔑ��A�X���U��
	GF_NPC_05_ASSALUT_HIGHLAND,		//�D�F�n�C�����h�P����
	GF_NPC_06_WALK_DANAN,			//�E�F�_�i�����ē������
	GF_NPC_07_JOIN_FRIDA,			//�F�F�t���[�_������
	GF_NPC_08_ARRIVE_ELEDUK,		//�G�F�G���h�D�[�N�ɓ�����
	GF_NPC_09_3DUNGEON_CLEAR,		//�H�F�R���j�A��ՃN���A��


	GF_NPC_MAX,						// ��ʃ��b�Z�[�W�؂�ւ��悤�t���O�I�[
	//---------------------------------------------------
	// �������V�s
	GF_RECIPE_START = 1850,
	GF_RECIPE_01 = GF_RECIPE_START,	// ����X�[�v
	GF_RECIPE_02,					// �L�m�R�I�����c
	GF_RECIPE_03,					// �������^�g�D�C��
	GF_RECIPE_04,					// �ʂ胀�j�G��
	GF_RECIPE_05,					// �C�N�L�b�V��
	GF_RECIPE_06,					// ���[���L���x�c
	GF_RECIPE_07,					// �������L�m�R�[��
	GF_RECIPE_08,					// �t�B�b�V���t���C
	GF_RECIPE_09,					// �p�C���[�c�f�B�b�V��
	GF_RECIPE_10,					// �ґ�R�[���X���[
	GF_RECIPE_11,					// �^�S�{���l�[�[
	GF_RECIPE_12,					// ���l�p���v�L���p�C
	GF_RECIPE_13,					// ����؃W���[�X�i�������蒠�ɍڂ�j

	GF_RECIPE_END,
	GF_RECIPE_13_DUMMY,				// ���j���[�o�^�p�_�~�[�i�����ĂȂ��Ă����j

	//---------------------------------------------------
	GF_LOVEPT_START = 1870,

//������肱�݂Ɏg�p�\��
//	GF_SUB01_LOVEPT_CAT,			// �y�l���������L�z				�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB01_LOVEPT_PICARD,			// �y�r�[���ň�����s�b�J�[�h�z	�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB01_LOVEPT_DOG,			// �y���_�����~�܂�Ȃ����z		�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB01_LOVEPT_HORSE,			// �y�̊i�̗ǂ��n�z				�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB02_LOVEPT_CHICKENA,		// �y�T�T�~�z					�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB02_LOVEPT_CHICKENB,		// �y�e�o�z						�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB02_LOVEPT_CHICKENC,		// �y�c�N�l�z					�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB02_LOVEPT_PICARDA,		// �y�Y�X�����s�b�J�[�h�z		�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB02_LOVEPT_PICARDB,		// �y���X�����s�b�J�[�h�z		�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB02_LOVEPT_SIKAA,			// �y�E�܂������z				�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB02_LOVEPT_SIKAB,			// �y��l�������z				�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB02_LOVEPT_SIKAC,			// �y�l�����������z				�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB03_LOVEPT_DUCKA,			// �y�D�����e�K���z				�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB03_LOVEPT_DUCKB,			// �y���C�Ȏq�K���z				�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB03_LOVEPT_PICARDA,		// �y�ӂ�ӂ�ю��̃s�b�J�[�h�z	�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB03_LOVEPT_PICARDB,		// �y���킲��ю��̃s�b�J�[�h�z	�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB03_LOVEPT_FLOG,			// �y�ڂ�����炵���J�G���z		�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB04_LOVEPT_PICARD,			// �y�P���s�b�J�[�h�z			�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB04_LOVEPT_URPACA,			// �y�f�p�ȃE���p�J�z			�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB04_LOVEPT_CAMEBULL,		// �y���a�ȃL�����u���z			�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB04_LOVEPT_DOG,			// �y�Ԍ��y���z					�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB04_LOVEPT_CAT,			// �y�A���m�[�z					�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB05_LOVEPT_CAT,			// �y�r�����R�z					�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j
//	GF_SUB05_LOVEPT_FLOG,			// �y���F���f�z					�̍D���x�i-2�F���Ɉ����@-1�F�����@0�F���ʁi������ԁj�@1�F�ǂ��@2:���ɗǂ��j

	GF_LOVEPT_END,

	//����җp
	GF_SUB01_START = 1900,			// �T�u�V�i���I�n�t���O

	GF_SUBEV_1201_CHECK_RIVER,		//�y���_�̏���𒲂ׂ�z
	GF_SUBEV_7302_CHECK_CLOTH,		//�y�k�o�F���ꖋ�𒲂ׂ�z
	GF_SUBEV_7302_CHECK_TARU,		//�y�k�o�F�M�𒲂ׂ�z
	GF_SUBEV_7302_CHECK_BOTTLE,		//�y�k�o�F�r�𒲂ׂ�z
	GF_SUBEV_1133_LOOK_MARK,		//�A���X���̑��ՂɋC�t��
	GF_SUBEV_1203_CHECK_ROPE,		//�y���_�A�C�݂̃��[�v�𒲂ׂ�z
	GF_SUBEV_NEMO_TALK_LICHT,		//�������ɂ��ă��q�g�Ƙb����
	GF_SUBEV_NEMO_TALK_BARBAROSS,	//�������ɂ��ăo���o���X�D���Ƙb����
	GF_SUBEV_NEMO_TALK_HUMMEL,		//�������ɂ��ăq���������Ƙb����
	GF_SUBEV_NEMO_TALK_KIERGAARD,	//�������ɂ��ăL���S�[���Ƙb����
	GF_SUBEV_LP_1107_BRIDGE,		//�y�k�o�F3108�̗������ނ苴������z�f�e����
	GF_SUBEV_LP_1202_IN_CAVE,		//�y�k�o�F�����̓��A�ɓ���z�f�e����
	GF_SUBEV_LP_4202_FIREPLACE,		//�y�k�o�F�g�F�𒲂ׂ�z�^�i�g�X�̏���
	GF_SUBEV_LP_4202_HAMMOCK,		//�y�k�o�F�n�����b�N�𒲂ׂ�z�^�i�g�X�̏���
	GF_SUBEV_LP_4202_SHELF,			//�y�k�o�F�I�𒲂ׂ�z�^�i�g�X�̏���
	GF_SUBEV_ST_6201_DOOR_OPEN,		//�y�X�g�b�p�[�F���s���̗��l���z�����J����
	GF_SUBEV_ST_410x_DOOR_OPEN,		//�y�X�g�b�p�[�F�R�剮�㓌�̗��l���z�����J����
	GF_SUBEV_ST_DOOR_1STTALK,		//�y�X�g�b�p�[�F�R�剮�㓌�̗��l���z�y�X�g�b�p�[�F�R�剮�㓌�̗��l���z�f�e����
	GF_SUBEV_ST_6203_DOOR,			//�y�X�g�b�p�[�F��m�@�̔��z�f�e����
	GF_SUBEV_LP_6211_INSCRIPTION,	//�y�k�o�F�������̔蕶�z�f�e����
	GF_SUBEV_ST_0404_DECK,			//�y�k�o���X�g�b�p�[�F�D������b�ɏo��Ȃ��z�X�g�b�p�[�̃C�x���g������	�����g�p�ɂȂ�܂���
	GF_SUBEV_03_2102_SWAMP,			//�y�Ñ㓴�A�ւ̗U���^���ւ̗U���Ə��ł̃T�u�C�x���g�z
	GF_SUBEV_04_6201_LOOK_BRIDGE,	//�y���s�A�C�M�A�X�F���̋�������z
	GF_SUBEV_05_7411_KILL_MONS,		//�y���̓��A�ł̃C�x���g�퓬�z�����X�^�[�𓢔�����
	GF_SUBEV_05_6435_GET_BELL,		//�y��̗���莞�̃C�x���g�z
	GF_SUBEV_06_6413_KILL_BOSS,		//�y���ق̓��ł̃{�X�퓬�z�{�X��|����
	GF_SUBEV_06_1111_LOOK_BOAT,		//�y���M�𔭌�����z
	GF_SUBEV_GET_MEMO,				//�s�E�C���̃�������ɓ��ꂽ�i�P�ł���ɓ��ꂽ�痧�j
	GF_SUBEV_GET_MEMO_T_01,			//�s�̃����@����ɓ��ꂽ
	GF_SUBEV_GET_MEMO_T_02,			//�s�̃����A����ɓ��ꂽ
	GF_SUBEV_GET_MEMO_T_03,			//�s�̃����B����ɓ��ꂽ
	GF_SUBEV_GET_MEMO_T_04,			//�s�̃����C����ɓ��ꂽ
	GF_SUBEV_GET_MEMO_P_01,			//�C���̃����@����ɓ��ꂽ
	GF_SUBEV_GET_MEMO_P_02,			//�C���̃����A����ɓ��ꂽ
	GF_SUBEV_GET_MEMO_P_03,			//�C���̃����B����ɓ��ꂽ
	GF_SUBEV_GET_MEMO_P_04,			//�C���̃����C����ɓ��ꂽ
	GF_SUBEV_GET_MEMO_P_05,			//�C���̃����D����ɓ��ꂽ
	GF_SUBEV_GET_MEMO_P_06,			//�C���̃����E����ɓ��ꂽ
	GF_SUBEV_AREANAME_4301,			//�y�G���A�J�������o�F�N�H�J�z
	GF_SUBEV_AREANAME_3105,			//�y�G���A�J�������o�F�W�����_�����z
	GF_SUBEV_AREANAME_6321,			//�y�G���A�J�������o�F�o�n�̓��z
	GF_SUBEV_KIKIKOMI_KIERGAARD,	//�y�������̕������݁F�L���S�[���z								��������
	GF_SUBEV_BACKTO_MP5104,			// �Ñ��̏Z�����ĖK������
	GF_SUBEV_ARRIVE_MP7451,			// �ǉ��T�u�C�x���g�y�����n�̍ŉ��ɂ�����z
	GF_SUBEV_MP6341_KILLMONS01,		// �s���U�R��|����
	GF_SUBEV_MP6341_KILLMONS02,		// �s���U�R��|����
	GF_SUBEV_MP6341_KILLMONS03,		// �s���U�R��|����
	GF_SUBEV_MP6341_KILLMONS04,		// �s���U�R��|����
	GF_SUBEV_MP1201_FOLLOW_TALK,	// ���G�h�ƃA���X���̃t�H���[��b ������
	GF_SUBEV_MEMO_P_TALK,			// �C���̃����F���^�i�g�X�ɊC���̃����ɂ��ĕ��� ������
	GF_SUBEV_MEMO_T_TALK,			// �s�̃����F�����߂Ăs�̃��������������b�Z�[�W ������
	GF_SUBEV_HELP_AURA,				// �f�B�i����A�E�����̘b�𕷂���
	GF_SUBEV_FIRST_TIMEATK,			// ���߂č��������΂𒲂ׂ����b�Z�[�W

	//�����ǉ�
	GF_SUBEV_1117_INTOSEASHORE,		//����l�ɏ��߂ē�����
	GF_SUBEV_2102_BIGFISH_TUTO,		//�k�V�ނ�`���[�g���A������
	GF_SUBEV_UNTOUCHABLE,			//2���ڂ������{�X��|����
	GF_SUBEV_LASTINT_START,			//2���ڌ}������󒍂���
	GF_SUBEV_LASTINT_CLEAR,			//2���ڌ}������󒍂���
	GF_SUBEV_CONTROL3_START,		//������R���J������

	GF_SUBEV_CONTROL_ALLCLEAR,		// �������S�ăN���A����

	//�����폟���t���O
	GF_CLEAR_CONTROL31,			// ������P�E���тP			
	GF_CLEAR_CONTROL32,			// ������Q�E���тQ			
	GF_CLEAR_CONTROL33,			// ������R�E�Z�H�J�P		
	GF_CLEAR_CONTROL34,			// ������S�E�Z�H�J�Q		
	GF_CLEAR_CONTROL35,			// ������T�E���Ƃ̒J�P		
	GF_CLEAR_CONTROL36,			// ������U�E���Ƃ̒J�Q		
	GF_CLEAR_CONTROL37,			// ������V�E���тR			
	GF_CLEAR_CONTROL38,			// ������W�E�Z�H�J�R		
	GF_CLEAR_CONTROL39,			// ������X�E���Ƃ̒J�R		

	//�ߋ��҂�������p���\�ȃA�C�e���������Ă���
	GF_OLDITEM_GET_01,				//�����̕�� ���ߋ��҂œ��肵���痧�Ă�t���O�i�f�B�i�̕�Ό����ɕ���
	GF_OLDITEM_GET_02,				//���ۂ̕� ���ߋ��҂œ��肵���痧�Ă�t���O�i�f�B�i�̕�Ό����ɕ���
	GF_OLDITEM_GET_03,				//���Â̕�� ���ߋ��҂œ��肵���痧�Ă�t���O�i�f�B�i�̕�Ό����ɕ���
	GF_OLDITEM_GET_04,				//�����̕��� ���ߋ��҂œ��肵���痧�Ă�t���O�i�f�B�i�̕�Ό����ɕ���
	GF_OLDITEM_GET_05,				//�����̕�r ���ߋ��҂œ��肵���痧�Ă�t���O�i�f�B�i�̕�Ό����ɕ���

	//PS4�ǉ���
	GF_SUBEV_HELP_VEGG,					//�~�����_�̖�؃W���[�X�����C�x���g
	GF_SUBEV_HELP_NUSHI,				//�k�V�ނ蓱���C�x���g

	//�ߋ��҂�������p���\�ȃA�C�e������������
	GF_OLDITEM_TRADE_01,				//�����̕�� ����������
	GF_OLDITEM_TRADE_02,				//���ۂ̕� ����������
	GF_OLDITEM_TRADE_03,				//���Â̕�� ����������
	GF_OLDITEM_TRADE_04,				//�����̕��� ����������
	GF_OLDITEM_TRADE_05,				//�����̕�r ����������

	GF_RESS02_TRADECNT,					//����̎������ɕK�v�ȕ�Ό�

	GF_CRYPT_MARKER_SETED,				//���n�������̃}�[�J�[���Z�b�g����

	GF_OLDITEM_TBOX_KEY,				//�ߋ��N�G�X�g�F�͂��ꂽ���N���A��V�̈����p��

	GF_PAST_CRYSTAL,					//�Y���������΂̉ߋ�����؂�ւ��t���O


	GF_SUB01_MAX,					// �T�u�V�i���I�n�P�t���O�I�[

	//�ߋ��җp
	GF_SUB02_START = 2100,			// �T�u�V�i���I�n�t���O

	GF_SUBEV_PAST_D1_ROOM,			// �_�[�i�҇@�F�y�T�u�C�x���g�F�_�[�i�̎����ɓ���z������
	GF_SUBEV_PAST_D1_LP_1ST,		// �_�[�i�҇@�F�y�k�o�F�_�[�i�̕����̏��ˁz����
	
	GF_SUBEV_PAST_D3_EASTBLOCK,		// �_�[�i�҇B�F�y�T�u�C�x���g�F���X��ɓ������z������
	GF_SUBEV_PAST_D3_TALK_RAS_TRA,	// �_�[�i�҇B�F�y�T�u�C�x���g�F���X�e���E�q�m�g���L���Ɖ�z������
	GF_SUBEV_PAST_D3_ST_1ST,		// �_�[�i�҇B�F�y�X�g�b�p�[�F���X�����ʂ֍s���Ȃ��z����

	GF_SUBEV_PAST_01_TREE,			// �ߋ��҇T�F�y�T�u�C�x���g�F����ɋF��������z������
	GF_SUBEV_PAST_01_ULUGNATA,		// �ߋ��҇T�F�y�T�u�C�x���g�F�����t�E���O�i�[�^�Əo��z������
	GF_SUBEV_PAST_01_VIEW,			// �ߋ��҇T�F�y�T�u�C�x���g�F�ߋ����E�𒭂߂�z������
	GF_SUBEV_PAST_01_SPIRITA_1,		// �ߋ��҇T�F�y����~�o�`�F����̐�����������i�K�{�j�z
	GF_SUBEV_PAST_01_SPIRITA_2,		// �ߋ��҇T�F�y����~�o�`�F�Q���琸���������i�K�{�j�z

	//GF_SUBEV_PAST_01_GIMMICK_L,	// �ߋ��҇T�F�y�ߋ��M�~�b�N�@�F���H�̏C���z������	���ǉ����ɒǉ�
	GF_SUBEV_PAST_01_GIMMICK_A,		// �ߋ��҇T�F�y�ߋ��M�~�b�N�@�F���H�̏C���z��B������
	GF_SUBEV_PAST_01_GIMMICK_C,		// �ߋ��҇T�F�y�ߋ��M�~�b�N�@�F����҂ւ̔��f�z������
	GF_SUBEV_PAST_01_LP_1ST,		// �ߋ��҇T�F�y�k�o�F�_�[�i�̕����̏��ˁz����
	
	GF_SUBEV_PAST_02_QUEST_A,		// �ߋ��҇U�F�y�ߋ��N�G�X�g�A�`�F�������ڂ̘b�𕷂��z������
	GF_SUBEV_PAST_02_QUEST_B,		// �ߋ��҇U�F�y�ߋ��N�G�X�g�A�a�F�~�[�A��������z������
	GF_SUBEV_PAST_02_QUEST_D,		// �ߋ��҇U�F�y�ߋ��N�G�X�g�A�c�F�����ɖ߂��Ă���z������
	GF_SUBEV_PAST_02_QUEST_E,		// �ߋ��҇U�F�y�ߋ��N�G�X�g�A�d�F���ɓ��������𒲂ׂ�z������
	GF_SUBEV_PAST_02_QUEST_F,		// �ߋ��҇U�F�y�ߋ��N�G�X�g�A�e�F�n���ւ̎d�|�������J���z������		���t���O�������������ߗ�O�I�ɒl�i = 2�j�𔻒�Ɏg���Ă���
	GF_SUBEV_PAST_02_QUEST_G,		// �ߋ��҇U�F�y�ߋ��N�G�X�g�A�f�F�n�������t���A�P�ɓ��B����z������
	GF_SUBEV_PAST_02_SPIRITB,		// �ߋ��҇U�F�y����~�o�a�F�Q���琸����~�o����i�K�{�j�z������
	GF_SUBEV_PAST_02_BOSS,			// �ߋ��҇U�F�y�T�u�C�x���g�F�n�������t���A�P�E�{�X���o���z������
	GF_SUBEV_PAST_02_MONOLITH,		// �ߋ��҇U�F�y�T�u�C�x���g�F�n�������t���A�P�̃��m���X��ǂށz������
	GF_SUBEV_PAST_02_DOOR_B1,		// �ߋ��҇U�F�y�T�u�C�x���g�F�n�������t���A�P�̑���𒲂ׂ�z������
	GF_SUBEV_PAST_02_QUEST_C,		// �ߋ��҇U�F�y�ߋ��N�G�X�g�A�b�F�B���C�x���g�z������

	GF_SUBEV_PAST_02_GIMMICK_A,		// �ߋ��҇U�F�y�ߋ��M�~�b�N�A�F���̘b�𕷂��z�̃C�x���g������
	GF_SUBEV_PAST_02_GIMMICK_B,		// �ߋ��҇U�F�y�ߋ��M�~�b�N�A�F���̘b�𕷂��z�����J����

	GF_SUBEV_PAST_02_FIRECNT_A,		// �ߋ��҇U�F�y�ߋ��N�G�X�g�A�d�F���ɓ��������𒲂ׂ�z�@�R�̐C��ɓ��΂�t����
	GF_SUBEV_PAST_02_FIRECNT_B,		// �ߋ��҇U�F�y�ߋ��N�G�X�g�A�d�F���ɓ��������𒲂ׂ�z�@�R�̐C��ɓ��΂�t����
	GF_SUBEV_PAST_02_FIRECNT_C,		// �ߋ��҇U�F�y�ߋ��N�G�X�g�A�d�F���ɓ��������𒲂ׂ�z�@�R�̐C��ɓ��΂�t����
	
	GF_SUBEV_PAST_03_RASTELL,		// �ߋ��҇V�F�y�T�u�C�x���g�F���X�e���Ƙb���z������
	GF_SUBEV_PAST_03_OLGA,			// �ߋ��҇V�F�y�T�u�C�x���g�F�I���K�Ƙb���z������
	GF_SUBEV_PAST_03_ROAD,			// �ߋ��҇V�F�y�T�u�C�x���g�F�C�����̓�������z������
	GF_SUBEV_PAST_03_HUNTA_LOOK,	// �ߋ��҇V�F�y����~�o�b�F�Q���琸����~�o����i�K�{�j�z������
	GF_SUBEV_PAST_03_HUNTA_KILL,	// �ߋ��҇V�F�y�����C�x���g�`�F���j��z������
	GF_SUBEV_PAST_03_GIMMICK_L,		// �ߋ��҇V�F�y�ߋ��M�~�b�N�B�F������������z������
	GF_SUBEV_PAST_03_GIMMICK_A,		// �ߋ��҇V�F�y�ߋ��M�~�b�N�B�F������������z��B�������i2�����j
	GF_SUBEV_PAST_03_GIMMICK_B,		// �ߋ��҇V�F�y�ߋ��M�~�b�N�B�F����҂ւ̔��f�z������

	GF_SUBEV_PAST_OPEN_B2,			// �ߋ��҇V�F�y�T�u�C�x���g�F�n�������t���A�P�̑�����J���z������	
	GF_SUBEV_PAST_GETTO_B2,			// �ߋ��҇V�F�y�T�u�C�x���g�F�n�������t���A�Q�ɓ��B����z������	
	GF_SUBEV_PAST_BOSS_B2,			// �ߋ��҇V�F�y�T�u�C�x���g�F�n�������t���A�Q�E�{�X���o���z������
	GF_SUBEV_PAST_MONOLITH_B2,		// �ߋ��҇V�F�y�T�u�C�x���g�F�n�������t���A�Q�̃��m���X��ǂށz������
	GF_SUBEV_PAST_SPIRITD,			// �ߋ��҇V�F�y����~�o�c�F�Q���琸��c���~�o����z������
	
	GF_SUBEV_PAST_04_TREE,			// �ߋ��҇W�F�y�T�u�C�x���g�F����ɋF��������z�f�e���������
	GF_SUBEV_PAST_04_GIMMICK_L,		// �ߋ��҇W�F�y�ߋ��M�~�b�N�C�F��m�@�̔��𒼂��z������
	GF_SUBEV_PAST_04_GIMMICK,		// �ߋ��҇W�F�y�ߋ��M�~�b�N�C�F��m�@�̔��𒼂��z��B�������i2�����j
	GF_SUBEV_PAST_04_IO_BARO,		// �ߋ��҇W�F�y�T�u�C�x���g�F����ɋF��������z�f�e���������

	GF_SUBEV_PAST_SPIRITE,			// �ߋ��҇W�F�y����~�o�d�F�Q���琸����~�o����z������
	GF_SUBEV_PAST_SPIRITF,			// �ߋ��҇W�F�y����~�o�e�F�Q���琸����~�o����z������
	GF_SUBEV_PAST_OPEN_B3,			// �ߋ��҇W�F�y�T�u�C�x���g�F�n�������t���A�Q�̑�����J���z������	
	GF_SUBEV_PAST_BOSS_B3,			// �ߋ��҇W�F�y�T�u�C�x���g�F�n�������t���A�R�E�{�X���o���z������
	GF_SUBEV_PAST_MONOLITH_B3,		// �ߋ��҇W�F�y�T�u�C�x���g�F�n�������t���A�R���m���X��ǂށz������

	GF_SUBEV_PAST_04_ENCOUNT,		// �ߋ��҇W-2�F�y�T�u�C�x���g�F�s���̓G�Ƒ����z������
	GF_SUBEV_PAST_04_SPIRITG,		// �ߋ��҇W-2�F�y����~�o�f�F�Q���琸����~�o����z������

	GF_SUBEV_PAST_05_QUEST_A,		// �ߋ��҇X�F�y�ߋ��N�G�X�g�D�`�F���ɘb�𕷂��z������
	GF_SUBEV_PAST_05_QUEST_C,		// �ߋ��҇X�F�y�ߋ��N�G�X�g�D�b�F�B���C�x���g�z������
	GF_SUBEV_PAST_05_HUNTB_LOOK,	// �ߋ��҇X�F�y�����C�x���g�a�F����Ƒ����z������
	GF_SUBEV_PAST_05_HUNTB_KILL,	// �ߋ��҇X�F�y�����C�x���g�a�F���j��z������

	GF_SUBEV_PAST_SPIRITH,			// �ߋ��҇X�F�y����~�o�g�F�Q���琸����~�o����z������
	GF_SUBEV_PAST_SPIRITI,			// �ߋ��҇X�F�y����~�o�h�F�Q���琸����~�o����z������
	GF_SUBEV_PAST_OPEN_B4,			// �ߋ��҇X�F�y�T�u�C�x���g�F�n�������t���A�R�̑�����J���z������	
	GF_SUBEV_PAST_GETTO_B4,			// �ߋ��҇X�F�y�T�u�C�x���g�F�n�������t���A�S�ɓ��B����z
	GF_SUBEV_PAST_BOSS_B4,			// �ߋ��҇X�F�y�T�u�C�x���g�F�n�������t���A�S�E�{�X���o���z������
	GF_SUBEV_PAST_MONOLITH_B4,		// �ߋ��҇X�F�y�T�u�C�x���g�F�n�������t���A�S���m���X��ǂށz������

	GF_SUBEV_PAST_06_WEST,			// �ߋ��҇Y�F�y�T�u�C�x���g�F���X�恨������ɂ����Ȃ��z������
	GF_SUBEV_PAST_06_EAST,			// �ߋ��҇Y�F�y�T�u�C�x���g�F���X��Ń_���I�X�������Ɖ�z������
	GF_SUBEV_PAST_06_GATE,			// �ߋ��҇Y�F�y�T�u�C�x���g�F�R��ŏC���������Ɍ�������z������
	GF_SUBEV_PAST_06_THEA,			// �ߋ��҇Y�F�y�T�u�C�x���g�F�V�[�A�Ƙb���z������
	GF_SUBEV_PAST_06_PATH,			// �ߋ��҇Y�F�y�T�u�C�x���g�F������ɔ�����z������
	GF_SUBEV_PAST_06_HUNTC_LOOK,	// �ߋ��҇Y�F�y�����C�x���g�b�F����Ƒ����z������
	GF_SUBEV_PAST_06_HUNTC_KILL,	// �ߋ��҇Y�F�y�����C�x���g�b�F���j��z������
	GF_SUBEV_PAST_06_GIMMICK_A,		// �ߋ��҇Y�F�y�ߋ��M�~�b�N�E�F�ŏ��𔭌��z������
	GF_SUBEV_PAST_06_GIMMICK_B,		// �ߋ��҇Y�F�y�ߋ��M�~�b�N�E�F�ŏ��̏򉻁z�ŗ����̌��Ђ𓮂�����
	GF_SUBEV_PAST_06_GIMMICK_C,		// �ߋ��҇Y�F�y�ߋ��M�~�b�N�E�F����҂ւ̔��f�z������

	GF_SUBEV_PAST_06_SPIRITJ,		// �ߋ��҇Y�F�y����~�o�i�F�Q���琸����~�o����z���N���A����
	GF_SUBEV_PAST_OPEN_B5,			// �ߋ��҇Y�F�y�T�u�C�x���g�F�n�������t���A�S�̑�����J���z������	
	GF_SUBEV_PAST_BOSS_B5,			// �ߋ��҇Y�F�y�T�u�C�x���g�F�n�������t���A�T�E�{�X���o���z������
	GF_SUBEV_PAST_MONOLITH_B5,		// �ߋ��҇Y�F�y�T�u�C�x���g�F�n�������t���A�T�̃��m���X��ǂށz������
	GF_SUBEV_PAST_LOOK_RELIEF,		// �ߋ��҇Y�F�y�T�u�C�x���g�F�n�������t���A�T�̃����[�t�������z������

	GF_SUBEV_PAST_07_ADD,			// �ߋ��҇Z�F���Y�����̐��������ω�����@������
	GF_SUBEV_PAST_07_IN_CASTLE,		// �ߋ��҇Z�F�����{�����ɓ���@������
	GF_SUBEV_PAST_07_LOOK_OLGA,		// �ߋ��҇Z�F���ʍ��̊ԂŃI���K�ƍĉ��@������
	GF_SUBEV_PAST_07_TALK_OLGA,		// �ߋ��҇Z�F���I���K�ɕ񍐂���Q�@������
	GF_SUBEV_PAST_07_LOOK_IO,		// �ߋ��҇Z�F���C�I��������@������
	GF_SUBEV_PAST_07_TALK_IO,		// �ߋ��҇Z�F���C�I�ƍĉ��@������
	GF_SUBEV_PAST_07_INTO_6211,		// �ߋ��҇Z�F���n�������������J���Ă���̂�����@������
	GF_SUBEV_PAST_07_LOOK_STEP,		// �ߋ��҇Z�F���n�������������J���Ă���̂�����Q�@������
	GF_SUBEV_PAST_07_INTO_LAST,		// �ߋ��҇Z�F�������ŉ��w�ɑ��𓥂ݓ����@������
	GF_SUBEV_PAST_07_KILL_IO,		// �ߋ��҇Z�F���C�I�ƑΌ�����@������
	GF_SUBEV_PAST_07_CLEAR,			// �ߋ��҇Z�F������ɖ߂��Ă���@������

	GF_SUBEV_PAST_07_QUEST_A,		// �ߋ��҇Z�F�y�ߋ��N�G�X�g�F�F���p�m�I�h�̈�̂�����z������
	GF_SUBEV_PAST_07_QUEST_B,		// �ߋ��҇Z�F�y�ߋ��N�G�X�g�F�F�Ԃ�������z������
	GF_SUBEV_PAST_07_QUEST_C,		// �ߋ��҇Z�F�y�ߋ��N�G�X�g�F�F�B���C�x���g�z������
	GF_SUBEV_PAST_07_QUEST_NO,		// �ߋ��҇Z�F�y�ߋ��N�G�X�g�F�F���p�m�I�h�̈�̂�����z��������������Ȃ�����

	GF_SUBEV_PAST_D1_TALK_ULUGNATA,	// �_�[�i�҇@�F�������݃t���O�F�����t�E���O�i�[�^
	GF_SUBEV_PAST_D1_TALK_SHENNA,	// �_�[�i�҇@�F�������݃t���O�F�C�����V�F���i
	GF_SUBEV_PAST_D1_TALK_CESIL,	// �_�[�i�҇@�F�������݃t���O�F�C�����Z�V��
	GF_SUBEV_PAST_D1_TALK_ALL,		// �_�[�i�҇@�F�������݃t���O�F�S�ďW�߂�

	GF_SUBEV_PAST_D3_TALK_DARIOS,	// �_�[�i�҇B�F�������݃t���O�F�_���I�X������
	GF_SUBEV_PAST_D3_TALK_MOB,		// �_�[�i�҇B�F�������݃t���O�FCitizen_D3_B01						���g�p�ɂȂ��� 0519
	GF_SUBEV_PAST_D3_TALK_SUBEV,	// �_�[�i�҇B�F�������݃t���O�F�y�T�u�C�x���g�F���X��ɓ������z
	GF_SUBEV_PAST_D3_TALK_ALL,		// �_�[�i�҇B�F�������݃t���O�F�S�ďW�߂�

	GF_SUBEV_PAST_VIEW_MP7451M,		// �ǉ��T�u�C�x���g�y�����̐�����������z
	GF_SUBEV_PAST_VIEW_MP6204M,		// �ǉ��T�u�C�x���g�y�G�^�j�A���{�𒭂߂�z
	GF_SUBEV_PAST_04_CESIL,			// �ǉ��T�u�C�x���g�y�Z�V���Ƙb���z
	GF_SUBEV_PAST_04_RASTELL,		// �ǉ��T�u�C�x���g�y���X�e���Ƙb���z
	GF_SUBEV_PAST_04_LP,			// �ߋ��҇W�F�y�k�o�F�ߋ��҇U�ŐA�����q�����M�𒲂ׂ�z���������

	//�ǉ���
	GF_SUBEV_PAST_01_GIMMICK_L,		// �ߋ��҇T�F�y�ߋ��M�~�b�N�@�F���H�̏C���z������
	GF_SUBEV_PAST_06_SPIRITJ_L,		// �ߋ��҇Y�F�y����~�o�i�F�Q���琸����~�o����z������

	//�ߋ��Ғǉ��G�s�\�[�h�p
	GF_BOSSFLOOR_NUM,				//�ǂ��܂Ń{�X�O�t���A�ɓ��B���Ă��邩
	GF_GET_GRATICA,					//�_�[�i���O���e�B�J�ւ̕ϐg�\�͂��l������
	GF_GET_LUMINOUS,				//�_�[�i�����~�i�X�ւ̕ϐg�\�͂��l������

	GF_OPEN_FLOOR_02,				//��Q�K�w���J���\�m������
	GF_OPEN_FLOOR_03,				//��R�K�w���J���\�m������
	GF_OPEN_FLOOR_04,				//��S�K�w���J���\�m������
	GF_OPEN_FLOOR_05,				//��T�K�w���J���\�m������

	//�ǉ���
	GF_SUBEV_PAST_02_BOSSMAE,		// �ߋ��҇U�F�n�������t���A�P�E�{�X�����O�܂ł����i�G�C�~�[�ړ��p�j
	GF_SUBEV_PAST_GETTO_B3,			// �ߋ��҇W�F�y�T�u�C�x���g�F�n�������t���A�R�ɓ��B����z
	GF_SUBEV_PAST_GETTO_B5,			// �ߋ��҇Y�F�y�T�u�C�x���g�F�n�������t���A�T�ɓ��B����z

	GF_SUB02_MAX,					// �T�u�V�i���I�n�Q�t���O�I�[

	//�ߋ��҈�ʂf�e
	GF_1STTALK_PAST_START = 2220,	// �ߋ��҈�ʂf�e�J�n

	GF_1STTALK_PAST_4_MEER = GF_1STTALK_PAST_START,			//�ߋ��҇W�F�~�[�A�f�e����
	GF_1STTALK_PAST_2_FAN,			//�ߋ��҇U�F�q�m�t�@���f�e����
	GF_1STTALK_PAST_D3_CESIL,		//�_�[�i�҇B�F�C�����Z�V���f�e����
	GF_1STTALK_PAST_D3_TRAKIL,		//�_�[�i�҇B�F�q�m�g���L���f�e����
	GF_1STTALK_PAST_D3_BAROSSA,		//�_�[�i�҇B�F�o���b�T�f�e����
	GF_1STTALK_PAST_D3_DARIOS,		//�_�[�i�҇B�F�_���I�X�������f�e����
	GF_1STTALK_PAST_1_ULUGNATA,		//�ߋ��҇T�F�����t�E���O�i�[�^�f�e����
	GF_1STTALK_PAST_1_CESIL,		//�ߋ��҇T�F�C�����Z�V���f�e����
	GF_1STTALK_PAST_4_CESIL,		//�ߋ��҇W�F�C�����Z�V���f�e����
	GF_1STTALK_PAST_1_MOB03,		//�ߋ��҇T�FCitizen_1_A03�f�e����
	GF_1STTALK_PAST_4_DARIOS,		//�ߋ��҇W�F�_���I�X�������f�e����
	GF_1STTALK_PAST_1B_OLGA,		//���ߋ��҇T�a�F�I���K�Վi���f�e����
	GF_1STTALK_PAST_4_ATRA,			//�ߋ��҇W�F�����A�g���f�e����
	GF_1STTALK_PAST_6_OLGA,			//�ߋ��҇W�F�I���K�Վi���f�e����
	GF_1STTALK_PAST_1_ATRA,			//�ߋ��҇T�F�����A�g���f�e����
	GF_1STTALK_PAST_3_DIOR,			//�ߋ��҇V�F�f�B�I�������f�e����
	GF_1STTALK_PAST_4_ULUGNATA,		//�ߋ��҇W�F�����t�E���O�i�[�^�f�e����

	GF_1STTALK_PAST_7_FREDO,		//�ߋ��҇Z�F�t���h�f�e����
	GF_1STTALK_PAST_7_SHENNA,		//�ߋ��҇Z�F�V�F���i�f�e����
	GF_1STTALK_PAST_7_ANTHEA,		//�ߋ��҇Z�F�A���V�A�f�e����
	GF_1STTALK_PAST_7_THEA,			//�ߋ��҇Z�F�V�[�A�f�e����
	GF_1STTALK_PAST_7_THEA2,		//�ߋ��҇Z�F�V�[�A�f�e����i�Q��ځj
	GF_1STTALK_PAST_7_CESIL,		//�ߋ��҇Z�F�Z�V���f�e����

	//PS4�ǉ�
	GF_1STTALK_PAST_3_EIMY,			//�ߋ��҇V�F�G�C�~�[�f�e����
	GF_1STTALK_PAST_7_EIMY,			//�ߋ��҇Z�F�G�C�~�[�f�e����
	GF_1STTALK_PAST_4_PULA_EL,		//�ߋ��҇W�F�v���E�E�G���h�f�e����
	GF_SUBEV_PAST_D1_TALK_IO,		// �_�[�i�҇@�F�������݃t���O�F�C�I

	GF_SUBEV_SPIRIT_ALL,			//�ߋ��ҁF�����S�ċ~�o����
	GF_SUBEV_PAST_07_SPIRIT,		//�T�u�C�x���g�F���삽���ƕʂ��������
	GF_SUBEV_PAST_07_EIMY,			//�T�u�C�x���g�F����G�C�~�[�Ɖ
	GF_SUBEV_PAST_04_IO_MONO,		//�ߋ��҇W�F���m���X��ǂ�ł��鎞�ɃC�I�Əo�
	GF_SUBEV_PAST_04_IO_RETURN,		//�ߋ��҇W�F�C�I�ƈꏏ�ɒn��֋A����
	GF_SUBEV_PAST_06_SPIRITJ_M,		//����Z���l�@MOB�o��
	GF_SPIRITJ_MOBKILL_CNT,			//����Z���l�@MOB�L���J�E���g
	GF_1ST_FORESIGHT,				//�n�������J���̗\�m�������i�`���[�g���A���p�j
	GF_1ST_REARRIVE,				//�n�߂ĉߋ��тɍĖK�����i�`���[�g���A���p�j

	GF_1STTALK_PAST_MAX,			// �ߋ��҈�ʂf�e�I�[

	//�ߋ��Ҕ���p
	GF_PAST_EPISODE_START = 2260,	// �ߋ��Ҕ���p�J�n

	GF_PAST_EPISODE_D1A_TEM = GF_PAST_EPISODE_START,		//���_�[�i�҇@�`���@�������
	GF_PAST_EPISODE_D1B_CANYON,			//���_�[�i�҇@�a�勬�J���U������
	GF_PAST_EPISODE_D3_WALK_CAPITAL,	//���_�[�i�҇B���s�����
	GF_PAST_EPISODE_1_GO_CAMP,			//���ߋ��҇T�A�h���������|�C���g�֌�����		���ߋ��҇T�ĖK���͗������Ă�B���̃G�s�\�[�h�����l
	GF_PAST_EPISODE_1B_REARRIVE,		//���ߋ��҇T�a�ĖK��							���ߋ��҇T�ĖK���͗������Ă�B���̃G�s�\�[�h�����l
	GF_PAST_EPISODE_2_GO_SOUTHGATE,		//���ߋ��҇U���֌�����
	GF_PAST_EPISODE_2B_REARRIVE,		//���ߋ��҇U�a�ĖK��
	GF_PAST_EPISODE_3_GO_BAHA,			//���ߋ��҇V�o�n�̓��֌�����
	GF_PAST_EPISODE_3B_REARRIVE,		//���ߋ��҇V�a�ĖK��
	GF_PAST_EPISODE_4_GO_CASTLE,		//���ߋ��҇W���{�O�֌�����
	GF_PAST_EPISODE_4B_REARRIVE,		//���ߋ��҇W�a�ĖK��
	GF_PAST_EPISODE_4_2_GO_OUT,			//���ߋ��҇W-�Q���{�̊O�֌�����
	GF_PAST_EPISODE_5_GO_VALLAY,		//���ߋ��҇X���Ƃ̒J�֌�����
	GF_PAST_EPISODE_5B_REARRIVE,		//���ߋ��҇X�a�ĖK��
	GF_PAST_EPISODE_6_GO_GARDEN,		//���ߋ��҇Y�Z�����̉��֌�����
	GF_PAST_EPISODE_6B_REARRIVE,		//���ߋ��҇Y�a�ĖK��
	GF_PAST_EPISODE_7_ENDEPISODE,		//���ߋ��҇Z�G���h�G�s�\�[�h
	GF_PAST_EPISODE_7B_REARRIVE,		//���ߋ��҇Z�a�ĖK��

	GF_BACKUP_SF_MISSIONNO,				//�`�������̂h�c�o�b�N�A�b�v�i�ߋ��ҏ����p�j

	GF_PAST_EPISODE_MAX,				// �ߋ��Ҕ���p�I�[

	//�t�B�[���h�p
	GF_SUB03_START = 2300,			// �T�u�V�i���I�n�t���O

	GF_SUBEV_1111_CHECKED_ROCK_EV,	//�y�k�o�F1111��1112�̊�𒲂ׂ�z�T�u�C�x���g�p�t���O
	GF_SUBEV_1111_CHECKED_ROCK,		//�y�k�o�F1111��1112�̊�𒲂ׂ�z
	GF_SUBEV_1111_REMOVE_ROCK,		//�y�k�o�F1111��1112�̊��P�������z
	GF_SUBEV_2101_CHECKED_ROCK,		//�y�k�o�F2101��2102�̊�𒲂ׂ��z
	GF_SUBEV_2101_REMOVE_ROCK,		//�y�k�o�F2101��2102�̊��P�������z
	GF_SUBEV_1107_CHECKED_BRIDGE,	//�y�k�o�F1107��1108�݂̒苴�𒲂ׂ��z
	GF_SUBEV_1107_REPAIR_BRIDGE,	//�y�k�o�F1107��1108�݂̒苴���C�������z
	GF_SUBEV_1131_CHECKED_ROCK,		//�y�k�o�F1131��3101�̊�𒲂ׂ��z
	GF_SUBEV_1131_REMOVE_ROCK,		//�y�k�o�F1131��3101�̊��P�������z
	GF_SUBEV_1120_CHECKED_ROCK,		//�y�k�o�F1120�˓��A�O�̊�𒲂ׂ��z
	GF_SUBEV_1120_REMOVE_ROCK,		//�y�k�o�F1120�˓��A�O�̊��P�������z
	GF_SUBEV_1117_CHECKED_ROCK,		//�y�k�o�F1117��1135�̊�𒲂ׂ��z
	GF_SUBEV_1117_REMOVE_ROCK,		//�y�k�o�F1117��1135�̊��P�������z
	GF_SUBEV_2105_CHECKED_ROCK,		//�y�k�o�F1117��1135�̓|�؂𒲂ׂ��z
	GF_SUBEV_2105_REMOVE_ROCK,		//�y�k�o�F1117��1135�̓|�؂�P�������z
	GF_SUBEV_1116_CHECKED_ROCK,		//�y�k�o�F1116��1116�̊��I�𒲂ׂ��z
	GF_SUBEV_1116_REMOVE_ROCK,		//�y�k�o�F1116��1116�̊��I��P�������z

	GF_SUBEV_1109_CHECKED_ROCK,		//�y�k�o�F1109�˂�������𒲂ׂ��z
	GF_SUBEV_1109_REMOVE_ROCK,		//�y�k�o�F1109�˂��������⋭�������z
	GF_SUBEV_6102_CHECKED_ROCK,		//�y�k�o�F6102��7491�̊�𒲂ׂ��z
	GF_SUBEV_6102_REMOVE_ROCK,		//�y�k�o�F6102��7491�̊��P�������z
	GF_SUBEV_1132_CHECKED_SAND,		//�y�k�o�F1132�˓D���𒲂ׂ��z
	GF_SUBEV_1132_REMOVE_SAND,		//�y�k�o�F1132�˓D����P�������z
	GF_SUBEV_4110_CHECKED_LADDER,	//�y�k�o�F4110�˓��q�𒲂ׂ��z
	GF_SUBEV_4110_REMOVE_LADDER,	//�y�k�o�F4110�˓��q��ݒu�����z
	GF_SUBEV_6107_CHECKED_SAND,		//�y�k�o�F6107��7481�̓y���𒲂ׂ��z
	GF_SUBEV_6107_REMOVE_SAND,		//�y�k�o�F6107��7481�̓y����P�������z
	GF_SUBEV_6362_CHECKED_PILLAR,	//�y�k�o�F6362�ːΒ��𒲂ׂ��z
	GF_SUBEV_6362_REMOVE_PILLAR,	//�y�k�o�F6362�ːΒ���P�������z
	GF_SUBEV_2104_CHECKED_SAND,		//�y�k�o�F2104��6411�̓y���𒲂ׂ��z
	GF_SUBEV_2104_REMOVE_SAND,		//�y�k�o�F2104��6411�̓y����P�������z

	GF_SUBEV_2101_SIEN03_LOOK,		//�y�k�o�F2101��2102�̊�𒲂ׂ��z�̎x���C�x���gNo.03�ŃJ�[���������A��̂�����


	GF_SUB03_MAX,					// �T�u�V�i���I�n�R�t���O�I�[

	//��ʉ�b�p�f�e
	GF_SUB04_START = 2500,			// �T�u�V�i���I�n�t���O

	GF_1STTALK_2A_03_DOGI,			//�h�M�f�e����
	GF_1STTALK_2A_03_BARBAROSS,		//�o���o���X�f�e����
	GF_1STTALK_2B_01_KIERGAARD,		//�L���S�[���f�e����
	GF_1STTALK_2B_04_DINA,			//�f�B�i�f�e����
	GF_1STTALK_2B_05_ALISON,		//�A���X���f�e����

	GF_1STTALK_2_12_AARON,			// �G�A�����f�e����i����b������j
	GF_1STTALK_3_01_SAHAD,			// �T�n�h�f�e����
	GF_1STTALK_2_05_KIERGAARD,		// �L���S�[���f�e����
	GF_1STTALK_0_02_DOGI,			// �h�M�f�e����
	GF_1STTALK_2_11_DOGI_AARON,		// �h�M�A�G�A�����̋��ʉ�b�f�e����
	GF_1STTALK_2_13_DOGI,			// �h�M�f�e����
	GF_1STTALK_4_01_DOGI,			// �h�M�f�e����
	GF_1STTALK_6_03_DOGI,			// �h�M�f�e����
	GF_1STTALK_0_02_BARBAROSS,		// �o���o���X�D���f�e����i�N�C�i�̃T�u�C�x���g��������j
	GF_1STTALK_4_01_MIRALDA,		// �~�����_�f�e����
	GF_1STTALK_6_03_MIRALDA,		// �~�����_�f�e����
	GF_1STTALK_2_03_LAXIA,			// ���N�V���A�T�n�h�̋��ʉ�b�f�e����
	GF_1STTALK_2_10_LAXIA,			// ���N�V���f�e����
	GF_1STTALK_3_05_RICOTTA,		// ���R�b�^�f�e����
	GF_1STTALK_7_01_RICOTTA,		// ���R�b�^�A�^�i�g�X�̋��ʉ�b�f�e����
	GF_1STTALK_3_01_LICHT,			// ���q�g�f�e����i���f�Ï��V���b�v���J���j
	GF_1STTALK_2_15_REJA,			// ���[���f�e����	�����g�p�ɂȂ�܂���
	GF_1STTALK_3_02_REJA,			// ���[���A�N�C�i�̋��ʉ�b�f�e����
	GF_1STTALK_7_01_REJA,			// ���[���f�e����
	GF_1STTALK_5_06_NIA,			// �V�X�^�[�E�j�A�f�e����

	GF_SUBEV_0_02_KUINA,			// ���A�D�����ŃN�C�i�̃T�u�C�x���g������
	GF_1STTALK_6_03_2H_DOGI,		// �h�M �Z���㔼�f�e����


	GF_SUB04_MAX,			// �T�u�V�i���I�n�S�t���O�I�[

	// �C�ӌ}���� �������N���A��V
	GF_INTERCEPT_REWARD_START = 2680,	// �e�}����A�������N���A��V�X�^�[�g

	GF_INTERCEPT_REWARD_02 = GF_INTERCEPT_REWARD_START,	// F�}����A �������N���A��V
	GF_INTERCEPT_REWARD_03,			// F�}����B �������N���A��V
	GF_INTERCEPT_REWARD_05,			// F�}����D �������N���A��V
	GF_INTERCEPT_REWARD_07,			// F�}����F �������N���A��V
	GF_INTERCEPT_REWARD_09,			// F�}����H �������N���A��V
	GF_INTERCEPT_REWARD_12,			// F�}����K �������N���A��V


	GF_INTERCEPT_REWARD_MAX,	// �e�}����A�������N���A��V�I�[

	//�e���E�v���[���g�E�����C�x���g
	GF_SUB05_START = 2700,			// �T�u�V�i���I�n�t���O

	GF_SUBEV_PRESENT_HUMMEL,		// �v���[���g�C�x���g1�������i�q���������j
	GF_SUBEV_PRESENT_PARO,			// �v���[���g�C�x���g1�������i���g���E�p���j
	GF_SUBEV_PRESENT_REJA,			// �v���[���g�C�x���g�������i���[���j

	GF_SUBEV_SINAI_ALISON,			// �e���C�x���g�������i�A���X���j
	GF_SUBEV_SINAI_AARON,			// �e���C�x���g�������i�G�A�����j
	GF_SUBEV_SINAI_ED,				// �e���C�x���g�������i�G�h�j
	GF_SUBEV_SINAI_AUSTEN,			// �e���C�x���g�������i�I�[�X�e�B���j
	GF_SUBEV_SINAI_CURRAN,			// �e���C�x���g�������i�J�[�����j
	GF_SUBEV_SINAI_KASHU,			// �e���C�x���g�������i�J�V���[�j
	GF_SUBEV_SINAI_KATRIN,			// �e���C�x���g�������i�J�g���[���j
	GF_SUBEV_SINAI_KUINA,			// �e���C�x���g�������i�N�C�i�j
	GF_SUBEV_SINAI_GRISELDA,		// �e���C�x���g�������i�O���[���_�j
	GF_SUBEV_SINAI_SAHAD,			// �e���C�x���g�������i�T�n�h�j
	GF_SUBEV_SINAI_NIA,				// �e���C�x���g�������i�V�X�^�[�E�j�A�j
	GF_SUBEV_SINAI_SILVIA,			// �e���C�x���g�������i�V�����B�A�j
	GF_SUBEV_SINAI_DANA,			// �e���C�x���g�������i�_�[�i�j
	GF_SUBEV_SINAI_THANATOS,		// �e���C�x���g�������i�^�i�g�X�j
	GF_SUBEV_SINAI_DINA,			// �e���C�x���g�������i�f�B�i�j
	GF_SUBEV_SINAI_DOGI,			// �e���C�x���g�������i�h�M�j
	GF_SUBEV_SINAI_HUMMEL,			// �e���C�x���g�������i�q���������j
	GF_SUBEV_SINAI_FRANZ,			// �e���C�x���g�������i�t�����c�j
	GF_SUBEV_SINAI_MIRALDA,			// �e���C�x���g�������i�~�����_�j
	GF_SUBEV_SINAI_LAXIA,			// �e���C�x���g�������i���N�V���j
	GF_SUBEV_SINAI_RICOTTA,			// �e���C�x���g�������i���R�b�^�j
	GF_SUBEV_SINAI_PARO,			// �e���C�x���g�������i���g���E�p���j
	GF_SUBEV_SINAI_LICHT,			// �e���C�x���g�������i���q�g�j
	GF_SUBEV_SINAI_REJA,			// �e���C�x���g�������i���[���j
	
	GF_SUBEV_JOIN_AUSTEN,			// �I�[�X�e�B���ƍ�������
	GF_SUBEV_LOOK_KASHU1,			// �J�V���[�̍����C�x���g�@������
	GF_SUBEV_JOIN_KASHU,			// �J�V���[�ƍ�������
	GF_SUBEV_JOIN_GRISELDA,			// �O���[���_�ƍ�������
	GF_SUBEV_LOOK_NIA1,				// �V�X�^�[�E�j�A�̍����C�x���g�@������
	GF_SUBEV_JOIN_NIA,				// �V�X�^�[�E�j�A�ƍ�������
	GF_SUBEV_LOOK_SILVIA1,			// �V�����B�A�̍����C�x���g�@������
	GF_SUBEV_LOOK_SILVIA2,			// �V�����B�A�̍����C�x���g�A������
	GF_SUBEV_JOIN_SILVIA,			// �V�����B�A�ƍ�������
	GF_SUBEV_JOIN_ED,				// �G�h�ƍ�������	
	GF_SUBEV_JOIN_FRANZ,			// �t�����c�ƍ�������
	GF_SUBEV_JOIN_MIRALDA,			// �~�����_�ƍ�������
	GF_SUBEV_LOOK_REJA1,			// ���[���̍����C�x���g�@������
	GF_SUBEV_JOIN_REJA,				// ���[���ƍ�������
	GF_SUBEV_JOIN_CURRAN2,			// �J�[�����������߂č�������
	
	GF_SPEEDRUN_SKILL_BATTLE,		// ��荞�݃X�L���K���F�퓬���Ǘ��p�i1���퓬���j
	GF_SPEEDRUN_SKILL_SAHAD,		// ��荞�݃X�L���K���F�A���T�n�h�u�r�}�X�^�[�R���O����������
	GF_SPEEDRUN_SKILL_SAHAD_1ST,	// ��荞�݃X�L���K���F�A���T�n�h�u�r�}�X�^�[�R���O�@�����b
	GF_SPEEDRUN_SKILL_DANA,			// ��荞�݃X�L���K���F�B���_�[�i�u�r�}�X�^�[�R���O����������
	GF_SPEEDRUN_SKILL_DANA_1ST,		// ��荞�݃X�L���K���F�B���_�[�i�u�r�}�X�^�[�R���O�@�����b
	GF_SPEEDRUN_SKILL_LAXIA,		// ��荞�݃X�L���K���F�C�����N�V���u�r�}�X�^�[�R���O����������
	GF_SPEEDRUN_SKILL_LAXIA_1ST,	// ��荞�݃X�L���K���F�C�����N�V���u�r�}�X�^�[�R���O�@�����b
	GF_SPEEDRUN_SKILL_HUMMEL,		// ��荞�݃X�L���K���F�D���q���������u�r�}�X�^�[�R���O����������
	GF_SPEEDRUN_SKILL_HUMMEL_1ST,	// ��荞�݃X�L���K���F�D���q���������u�r�}�X�^�[�R���O�@�����b
	GF_SPEEDRUN_SKILL_ADOL,			// ��荞�݃X�L���K���F�E���A�h���u�r�}�X�^�[�R���O����������
	GF_SPEEDRUN_SKILL_ADOL_1ST,		// ��荞�݃X�L���K���F�E���A�h���u�r�}�X�^�[�R���O�@�����b
	GF_SPEEDRUN_LOC_1STTALK,		// ��荞�݃��P�[�V�����񍐁F�I�[�X�e�B�������b
	GF_SPEEDRUN_LOC_HALF,			// ��荞�݃��P�[�V�����񍐁F���P�[�V�����𔼕��������ăA�C�e��������
	GF_SPEEDRUN_LOC_COMP,			// ��荞�݃��P�[�V�����񍐁F���P�[�V������S�Ĕ������ăA�C�e��������
	GF_SPEEDRUN_FISH_1STTALK,		// ��荞�݋��n���F�n�V�r���R�E�E�����b�C�x���g
	GF_SPEEDRUN_FISH_ENCOUNTER,		// ��荞�݋��n���F���R�b�^�ƃn�V�r���R�E�̑����C�x���g
	GF_SPEEDRUN_FISH_PRESENT00,		// ��荞�݋��n���F�T�f�B�[�i��n����
	GF_SPEEDRUN_FISH_PRESENT01,		// ��荞�݋��n���F�{����n����
	GF_SPEEDRUN_FISH_PRESENT02,		// ��荞�݋��n���F�u���[�T�f�B��n����
	GF_SPEEDRUN_FISH_PRESENT03,		// ��荞�݋��n���F�A�}�i��n����
	GF_SPEEDRUN_FISH_PRESENT04,		// ��荞�݋��n���F�Z�C�����}�X��n����
	GF_SPEEDRUN_FISH_PRESENT05,		// ��荞�݋��n���F�K�[���B�X��n����
	GF_SPEEDRUN_FISH_PRESENT06,		// ��荞�݋��n���F���u�V����n����
	GF_SPEEDRUN_FISH_PRESENT07,		// ��荞�݋��n���F�N�C�[���{����n����
	GF_SPEEDRUN_FISH_PRESENT08,		// ��荞�݋��n���F�T�[�}����n����
	GF_SPEEDRUN_FISH_PRESENT09,		// ��荞�݋��n���F�Q�[�e�}�O����n����
	GF_SPEEDRUN_FISH_PRESENT10,		// ��荞�݋��n���F�~���[�W����n����
	GF_SPEEDRUN_FISH_PRESENT11,		// ��荞�݋��n���F�������K��n����
	GF_SPEEDRUN_FISH_PRESENT12,		// ��荞�݋��n���F�����[�i��n����
	GF_SPEEDRUN_FISH_PRESENT13,		// ��荞�݋��n���F�f�B�v���~�X��n����
	GF_SPEEDRUN_FISH_PRESENT14,		// ��荞�݋��n���F�A���P�h����n����
	GF_SPEEDRUN_FISH_PRESENT15,		// ��荞�݋��n���F�L���O�T�[�}����n����
	GF_SPEEDRUN_FISH_PRESENT16,		// ��荞�݋��n���F�A�N�A�}���i��n����
	GF_SPEEDRUN_FISH_PRESENT17,		// ��荞�݋��n���F�s�����[��n����
	GF_SPEEDRUN_FISH_PRESENT18,		// ��荞�݋��n���F�_�C�i�X�e���N�X��n����
	GF_SPEEDRUN_FISH_PRESENT19,		// ��荞�݋��n���F�S���A�e�X��n����
	GF_SPEEDRUN_FISH_PRESENT20,		// ��荞�݋��n���F�K�C�A�E�F���Y��n����
	GF_SPEEDRUN_FISH_PRESENT21,		// ��荞�݋��n���F�V�������J���X��n����
	GF_SPEEDRUN_FISH_PRESENT22,		// ��荞�݋��n���F�n�C�l���A��n����
	GF_SPEEDRUN_FISH_PRESENT23,		// ��荞�݋��n���F�J���J���h����n����
	GF_SPEEDRUN_FISH_04OVER,		// ��荞�݋��n���F�S��ޓn����
	GF_SPEEDRUN_FISH_08OVER,		// ��荞�݋��n���F�W��ޓn����
	GF_SPEEDRUN_FISH_12OVER,		// ��荞�݋��n���F�P�Q��ޓn����
	GF_SPEEDRUN_FISH_16OVER,		// ��荞�݋��n���F�P�U��ޓn����
	GF_SPEEDRUN_FISH_20OVER,		// ��荞�݋��n���F�Q�O��ޓn����
	GF_SPEEDRUN_FISH_24OVER,		// ��荞�݋��n���F�Q�S��ޓn����
	GF_SPEEDRUN_MAP_1STREPO_B,		// ��荞�ݒn�}���j���񍐁F�n�}���j���P�O���ȏ�̕񍐂��o���o���X�ɏ��߂Ă���
	GF_SPEEDRUN_MAP_HALFREPO_B,		// ��荞�ݒn�}���j���񍐁F�n�}���j���T�O���ȏ�̕񍐂��o���o���X�ɏ��߂Ă���
	GF_SPEEDRUN_MAP_1STREPO_A,		// ��荞�ݒn�}���j���񍐁F�n�}���j���P�O���ȏ�̕񍐂��G�A�����ɏ��߂Ă���
	GF_SPEEDRUN_MAP_HALFREPO_A,		// ��荞�ݒn�}���j���񍐁F�n�}���j���T�O���ȏ�̕񍐂��G�A�����ɏ��߂Ă���
	GF_SPEEDRUN_MAP_1ST_ITEM,		// ��荞�ݒn�}���j���񍐁F���߂ăA�C�e��������
	GF_SPEEDRUN_MAP_10P,			// ��荞�ݒn�}���j���񍐁F�n�}���j���P�O���̕񍐂����ăA�C�e��������
	GF_SPEEDRUN_MAP_20P,			// ��荞�ݒn�}���j���񍐁F�n�}���j���Q�O���̕񍐂����ăA�C�e��������
	GF_SPEEDRUN_MAP_30P,			// ��荞�ݒn�}���j���񍐁F�n�}���j���R�O���̕񍐂����ăA�C�e��������
	GF_SPEEDRUN_MAP_40P,			// ��荞�ݒn�}���j���񍐁F�n�}���j���S�O���̕񍐂����ăA�C�e��������
	GF_SPEEDRUN_MAP_50P,			// ��荞�ݒn�}���j���񍐁F�n�}���j���T�O���̕񍐂����ăA�C�e��������
	GF_SPEEDRUN_MAP_60P,			// ��荞�ݒn�}���j���񍐁F�n�}���j���U�O���̕񍐂����ăA�C�e��������
	GF_SPEEDRUN_MAP_70P,			// ��荞�ݒn�}���j���񍐁F�n�}���j���V�O���̕񍐂����ăA�C�e��������
	GF_SPEEDRUN_MAP_80P,			// ��荞�ݒn�}���j���񍐁F�n�}���j���W�O���̕񍐂����ăA�C�e��������
	GF_SPEEDRUN_MAP_90P,			// ��荞�ݒn�}���j���񍐁F�n�}���j���X�O���̕񍐂����ăA�C�e��������
	GF_SPEEDRUN_MAP_COMP,			// ��荞�ݒn�}���j���񍐁F�n�}���j���P�O�O���̕񍐂����ăA�C�e��������
	GF_SPEEDRUN_BOOK_1ST_K,			// ��荞�ݒ������n���F���������L���S�[���ɏ��߂ēn����
	GF_SPEEDRUN_BOOK_1ST_L,			// ��荞�ݒ������n���F�����������q�g�ɏ��߂ēn����
	GF_SPEEDRUN_FARM_GETPICARD,		// ��荞�ݔ_��F�����܂����s�b�J�[�h����ɓ��ꂽ
	GF_SPEEDRUN_FARM_PAPRIKA,		// ��荞�ݔ_��F�p�v���J�̎��n����
	GF_SPEEDRUN_FARM_CABBAGE,		// ��荞�ݔ_��F�L���x�c�̎��n����
	GF_SPEEDRUN_FARM_CORN,			// ��荞�ݔ_��F�R�[���̎��n����
	GF_SPEEDRUN_FARM_TOMATO,		// ��荞�ݔ_��F�g�}�g�̎��n����
	GF_SPEEDRUN_FARM_PUMPKIN,		// ��荞�ݔ_��F�p���v�L���̎��n����
	GF_SPEEDRUN_FARM_PICARD,		// ��荞�ݔ_��F�s�b�J�[�h��n����
	GF_SPEEDRUN_FARM_NASUBI_LV,		// ��荞�ݔ_��F�i�X�r�̎��n�\���i0:���n�s�A1:�R�A2:�U�A3:�X�j
	GF_SPEEDRUN_FARM_PAPRIKA_LV,	// ��荞�ݔ_��F�p�v���J�̎��n�\���i0:���n�s�A1:�R�A2:�U�A3:�X�j
	GF_SPEEDRUN_FARM_CABBAGE_LV,	// ��荞�ݔ_��F�L���x�c�̎��n�\���i0:���n�s�A1:�R�A2:�U�A3:�X�j
	GF_SPEEDRUN_FARM_CORN_LV,		// ��荞�ݔ_��F�R�[���̎��n�\���i0:���n�s�A1:�R�A2:�U�A3:�X�j
	GF_SPEEDRUN_FARM_TOMATO_LV,		// ��荞�ݔ_��F�g�}�g�̎��n�\���i0:���n�s�A1:�R�A2:�U�A3:�X�j
	GF_SPEEDRUN_FARM_PUMPKIN_LV,	// ��荞�ݔ_��F�p���v�L���̎��n�\���i0:���n�s�A1:�R�A2:�U�A3:�X�j
	GF_SPEEDRUN_FARM_NASUBI_KC,		// ��荞�ݔ_��F�i�X�r�p�G���j��
	GF_SPEEDRUN_FARM_PAPRIKA_KC,	// ��荞�ݔ_��F�p�v���J�p�G���j��
	GF_SPEEDRUN_FARM_CABBAGE_KC,	// ��荞�ݔ_��F�L���x�c�p�G���j��
	GF_SPEEDRUN_FARM_CORN_KC,		// ��荞�ݔ_��F�R�[���p�G���j��
	GF_SPEEDRUN_FARM_TOMATO_KC,		// ��荞�ݔ_��F�g�}�g�p�G���j��
	GF_SPEEDRUN_FARM_PUMPKIN_KC,	// ��荞�ݔ_��F�p���v�L���p�G���j��
	GF_SPEEDRUN_COOK_ENCOUNTER,		// ��荞�ݗ����n���F�݂������Ƒ�������
	GF_SPEEDRUN_COOK_PRESENT00,		// ��荞�ݗ����n���F����X�[�v��n����
	GF_SPEEDRUN_COOK_PRESENT01,		// ��荞�ݗ����n���F�L�m�R�I�����c��n����
	GF_SPEEDRUN_COOK_PRESENT02,		// ��荞�ݗ����n���F�������^�g�D�C����n����
	GF_SPEEDRUN_COOK_PRESENT03,		// ��荞�ݗ����n���F�ʂ胀�j�G����n����
	GF_SPEEDRUN_COOK_PRESENT04,		// ��荞�ݗ����n���F�C�N�L�b�V����n����
	GF_SPEEDRUN_COOK_PRESENT05,		// ��荞�ݗ����n���F���[���L���x�c��n����
	GF_SPEEDRUN_COOK_PRESENT06,		// ��荞�ݗ����n���F�������L�m�R��n����
	GF_SPEEDRUN_COOK_PRESENT07,		// ��荞�ݗ����n���F�t�B�b�V���t���C��n����
	GF_SPEEDRUN_COOK_PRESENT08,		// ��荞�ݗ����n���F�p�C���[�c�f�B�b�V����n����
	GF_SPEEDRUN_COOK_PRESENT09,		// ��荞�ݗ����n���F�ґ�R�[���X���[��n����
	GF_SPEEDRUN_COOK_PRESENT10,		// ��荞�ݗ����n���F�^�S�{���l�[�[��n����
	GF_SPEEDRUN_COOK_PRESENT11,		// ��荞�ݗ����n���F���l�p���v�L���p�C��n����
	GF_SPEEDRUN_COOK_2,				// ��荞�ݗ����n���F�������Q��ޓn����
	GF_SPEEDRUN_COOK_4,				// ��荞�ݗ����n���F�������S��ޓn����
	GF_SPEEDRUN_COOK_6,				// ��荞�ݗ����n���F�������U��ޓn����
	GF_SPEEDRUN_COOK_8,				// ��荞�ݗ����n���F�������W��ޓn����
	GF_SPEEDRUN_COOK_10,			// ��荞�ݗ����n���F�������P�O��ޓn����
	GF_SPEEDRUN_COOK_COMP,			// ��荞�ݗ����n���F������S��ޓn����

	GF_DRUG_RECIPE01,				// �����������s���t	�ږ�̃��V�s			�n���Ē����\�ɂȂ����B
	GF_DRUG_RECIPE02,				// �����������s�Át	�Â�����̃��V�s		�n���Ē����\�ɂȂ����B
	GF_DRUG_RECIPE03,				// �����������s���t	�~����̃��V�s			�n���Ē����\�ɂȂ����B
	GF_DRUG_RECIPE04,				// �����������s���t	�t���|�[�V�����̃��V�s	�n���Ē����\�ɂȂ����B
	GF_DRUG_RECIPE05,				// �����������s��t	�ꂢ����̃��V�s		�n���Ē����\�ɂȂ����B
	GF_DRUG_RECIPE06,				// �����������s�b�t	����̎��̃��V�s		�n���Ē����\�ɂȂ����B
	GF_DRUG_RECIPE07,				// �����������s���t	���̗��̃��V�s		�n���Ē����\�ɂȂ����B
	GF_DRUG_RECIPE08,				// �����������s�B�t	�B�҂̖���̃��V�s		�n���Ē����\�ɂȂ����B
	GF_DRUG_RECIPE09,				// �����������s�́t	�̗͂��̃��V�s		�n���Ē����\�ɂȂ����B
	GF_DRUG_RECIPE10,				// �����������s��t	��̗��̃��V�s		�n���Ē����\�ɂȂ����B
	GF_DRUG_RECIPE11,				// �����������s�e�t	�e�����̃��V�s			�n���Ē����\�ɂȂ����B
	GF_DRUG_RECIPE12,				// QS301�B�� ���v��

	GF_SPEEDRUN_COOK_COUNT,			// ��荞�ݗ����n���F���̃J�E���g�i�[

	GF_SUBEV_SILVIA_MODE,			// �V�����B�A�̏�� 0=�V�k 1=��m

// �ǉ�

	GF_SUBEV_PRESENT_LAXIA1,		// �v���[���g1��n�����i���N�V���j
	GF_SUBEV_PRESENT_LAXIA2,		// �v���[���g2��n�����i���N�V���j
	GF_SUBEV_PRESENT_SAHAD1,		// �v���[���g1��n�����i�T�n�h�j
	GF_SUBEV_PRESENT_SAHAD2,		// �v���[���g2��n�����i�T�n�h�j
	GF_SUBEV_PRESENT_HUMMEL1,		// �v���[���g1��n�����i�q���������j
	GF_SUBEV_PRESENT_HUMMEL2,		// �v���[���g2��n�����i�q���������j
	GF_SUBEV_PRESENT_RICOTTA1,		// �v���[���g1��n�����i���R�b�^�j
	GF_SUBEV_PRESENT_RICOTTA2,		// �v���[���g2��n�����i���R�b�^�j
	GF_SUBEV_PRESENT_DANA1,			// �v���[���g1��n�����i�_�[�i�j
	GF_SUBEV_PRESENT_DANA2,			// �v���[���g2��n�����i�_�[�i�j
	GF_SUBEV_PRESENT_DOGI1,			// �v���[���g1��n�����i�h�M�j
	GF_SUBEV_PRESENT_DOGI2,			// �v���[���g2��n�����i�h�M�j

	GF_SPEEDRUN_FARM_1ST_KC,		// ��荞�ݔ_��F�G���j�񐔁i����i�X�r�p�j
	GF_SPEEDRUN_FARM_1ST_PAPRIKA,	// ��荞�ݔ_��F�G���j�񐔁i����p�v���J�p�j
	GF_SPEEDRUN_FARM_1ST_CABBAGE,	// ��荞�ݔ_��F�G���j�񐔁i����L���x�c�p�j
	GF_SPEEDRUN_FARM_1ST_CORN,		// ��荞�ݔ_��F�G���j�񐔁i����R�[���p�j
	GF_SPEEDRUN_FARM_1ST_TOMATO,	// ��荞�ݔ_��F�G���j�񐔁i����g�}�g�p�j
	GF_SPEEDRUN_FARM_1ST_PUMPKIN,	// ��荞�ݔ_��F�G���j�񐔁i����p���v�L���p�j

//PS4�ǉ�
	GF_SPEEDRUN_FISH_PRESENT24,		// ��荞�݋��n���F�O�����A���O����n����
	GF_SPEEDRUN_FISH_PRESENT25,		// ��荞�݋��n���F�l�r���u������n����
	GF_SPEEDRUN_FISH_PRESENT26,		// ��荞�݋��n���F�{���_�[�g��n����
	GF_SPEEDRUN_FISH_PRESENT27,		// ��荞�݋��n���F�G���V�F���g�A�r�X��n����

	GF_SUB05_MAX,				// �T�u�V�i���I�n�T�t���O�I�[

	//�N�G�X�g�E�T�u�C�x���g
	GF_SUB06_START = 2900,			// �T�u�V�i���I�n�t���O
	GF_SUBEV_MAKE_LOOKOUT,			// ���������쐬�����i�yQS220�z��B���������ɗ��ĂĂ��܂��j


	GF_SUB06_MAX,				// �N�G�X�g�E�T�u�n�t���O�I�[

	///////////////////////////////////////////////

	///////////////////////////////////////////////
	// �G�^�j�A�N�G�X�g�g���t�B�[�`�F�b�N�p
	///////////////////////////////////////////////
	GF_TROPHY_PAST_CHECK01			= GF_SUBEV_PAST_01_GIMMICK_A,	// 01. �Y�ꋎ��ꂽ���H
	GF_TROPHY_PAST_CHECK02			= GF_SUBEV_PAST_02_QUEST_C,		// 02. �o�q�̂�������
	GF_TROPHY_PAST_CHECK03			= GF_SUBEV_PAST_02_GIMMICK_A,	// 03. ����ɏ�������
	GF_TROPHY_PAST_CHECK04			= GF_SUBEV_PAST_03_HUNTA_KILL,	// 04. ���퓢���@
	GF_TROPHY_PAST_CHECK05			= GF_SUBEV_PAST_03_GIMMICK_A,	// 05. �ޏ��̎{��
	GF_TROPHY_PAST_CHECK06			= GF_SUBEV_PAST_04_GIMMICK,		// 06. �Â��j���̑��
	GF_TROPHY_PAST_CHECK07			= GF_SUBEV_PAST_05_QUEST_C,		// 07. �͂��ꂽ��
	GF_TROPHY_PAST_CHECK08			= GF_SUBEV_PAST_05_HUNTB_KILL,	// 08. ���퓢���A
	GF_TROPHY_PAST_CHECK09			= GF_SUBEV_PAST_06_HUNTC_KILL,	// 09. ���퓢���B
	GF_TROPHY_PAST_CHECK10			= GF_SUBEV_PAST_06_GIMMICK_B,	// 10. �͂�䂭��n�Ɍb�݂�
	GF_TROPHY_PAST_CHECK11			= GF_SUBEV_PAST_07_QUEST_C,		// 11. ���ӂ̉�

	///////////////////////////////////////////////
	//��ʃ��b�Z�[�W�؂�ւ��p�t���O
	///////////////////////////////////////////////

	GF_NPC_0_01_GO_CAPTAINROOM		= GF_00MP0011_GO_CAPTAINROOM,		// �����@�o���o���X�D���̏��֌�����
	GF_NPC_0_02_START_PATROL		= GF_00MP0012_START_PATROL,			// �����A�D�������񂷂�i��j
	GF_NPC_0_03_ATTACK_SHIP			= GF_00MP0016_HEAR_SCREAM,			// �����B�D���P����i��j
	
	GF_NPC_1_01_IN_BASE				= GF_01MP1201_IN_BASE,				// ����ꕔ�@�Y�����\��n�ɓ���
	GF_NPC_1_02_MEET_BARBAROSS		= GF_01MP1201_MEET_BARBAROSS,		// ����ꕔ�A�o���o���X�D���ƍ�������
	
	GF_NPC_2_01_SEARCH_BARBAROSS	= GF_02MP1201_TAKE_BREAKFAST,		// ����񕔇@�o���o���X�D����T���ɍs��
	GF_NPC_2_02_START_EXPLORE		= GF_02MP1201_INFO_QUEST,			// ����񕔇A�T���J�n
	GF_NPC_2_03_REMOVE_OBSTACLE		= GF_02MP1110_REMOVE_OBSTACLE,		// ����񕔇B��Q����P�������i�ɂ̎X��ʁj	���v�m�F�F�u�|�؂�P�������v�𗘗p���Ă��܂�
	GF_NPC_2_04_JOIN_ALISON			= GF_02MP1201_JOIN_ALISON,			// ����񕔇C�A���X����������
	GF_NPC_2_05_JOIN_KIERGAARD		= GF_02MP1307_JOIN_KIERGAARD,		// ����񕔇D�J�[�����ƃL���S�[����������
	GF_NPC_2_06_BEFORE_INTERCEPT	= GF_02MP1201_BEFORE_INTERCEPT,		// ����񕔇E�}����@������
	GF_NPC_2_07_AFTER_INTERCEPT		= GF_02MP1201_AFTER_INTERCEPT,		// ����񕔇F�}����@���ς܂���
	GF_NPC_2_08_JOIN_KATRIN			= GF_02MP1201_JOIN_KATRIN,			// ����񕔇G�J�g���[����������
	GF_NPC_2_09_CHECK_LOOKOUT		= GF_SUBEV_MAKE_LOOKOUT,			// ����񕔇H���������쐬����
	GF_NPC_2_10_JOIN_HUMMEL			= GF_02MP1108_JOIN_HUMMEL,			// ����񕔇I�q�������������ԂɂȂ���
	GF_NPC_2_10_OCCUR_INTERCEPT2	= GF_02MP43xx_OCCUR_INTERCEPT2,		// ����񕔂e�}����A������
	GF_NPC_2_10_AFTER_INTERCEPT2	= GF_02MP43xx_AFTER_INTERCEPT2,		// ����񕔂e�}����A���ς܂���
	GF_NPC_2_11_JOIN_DINA			= GF_02MP1119_JOIN_DINA,			// ����񕔇J�f�B�i��������
	GF_NPC_2_11_OCCUR_INTERCEPT3	= GF_02MP23xx_OCCUR_INTERCEPT3,		// ����񕔂e�}����B������
	GF_NPC_2_11_AFTER_INTERCEPT3	= GF_02MP23xx_AFTER_INTERCEPT3,		// ����񕔂e�}����B���ς܂���
	GF_NPC_2_12_HEAR_SHOUT			= GF_02MP1202_HEAR_SHOUT,			// ����񕔇K�J�[�������̔ߖ𕷂���
	GF_NPC_2_13_BEFORE_INTERCEPT2	= GF_02MP1201_BEFORE_INTERCEPT2,	// ����񕔇L�}����C�������i�[���j
	GF_NPC_2_14_LOST_CURRAN			= GF_02MP1201_LOST_CURRAN,			// ����񕔇M�J�[��������T���ɍs��
	GF_NPC_2_15_START_HEARING		= GF_02MP1201_START_HEARING,		// ����񕔇N�������̑{�����J�n����
	GF_NPC_2_16_GOTO_KIERGAARD		= GF_02MP1201_UNMASK_NEMO,			// ����񕔇O�L���S�[���̏��֌�����
	GF_NPC_2_17_CHASE_KIERGAARD		= GF_02MP1201_CHASE_KIERGAARD,		// ����񕔇P�L���S�[�������̂𖾂���
	GF_NPC_2_18_WOUND_BARBAROSS		= GF_02MP1111_WOUND_BARBAROSS,		// ����񕔇Q�o���o���X���v�����𕉂����i�l�Ӂj
	
	GF_NPC_3_01_GOTO_LAXIA			= GF_03MP1202_AWAKE_ADOL,			// ����O���@���N�V���̌��֌�����
	GF_NPC_3_02_GOTO_GENSD			= GF_03MP1201_GOTO_GENSD,			// ����O���A�W�����_�����Ɍ�����
	GF_NPC_3_02_OCCUR_INTERCEPT5	= GF_03MP433x_OCCUR_INTERCEPT5,		// ����O���e�}����D������
	GF_NPC_3_02_AFTER_INTERCEPT5	= GF_03MP433x_AFTER_INTERCEPT5,		// ����O���e�}����D���ς܂���
	GF_NPC_3_03_JOIN_RICOTTA		= GF_03MP4202_JOIN_RICOTTA,			// ����O���B���R�b�^�����ԂɂȂ���
	GF_NPC_3_04_ALARM_INTERCEPT		= GF_03MP1201_ALARM_INTERCEPT,		// ����O���C�}����E������
	GF_NPC_3_05_BACK_GENSD			= GF_03MP1201_BACK_GENSD,			// ����O���D�ĂуW�����_�����Ɍ�����
	
	GF_NPC_4_01_GOTO_NORTH			= GF_04MP4107_GOTO_NORTH,			// ����l���@���k���ɑ��𓥂ݓ��ꂽ
	GF_NPC_4_01_OCCUR_INTERCEPT7	= GF_04MP5101_OCCUR_INTERCEPT7,		// ����l���e�}����F������
	GF_NPC_4_01_AFTER_INTERCEPT7	= GF_04MP5101_AFTER_INTERCEPT7,		// ����l���e�}����F���ς܂���
	GF_NPC_4_02_SEE_THANATOS		= GF_04MP6204_SEE_THANATOS,			// ����l���A�^�i�g�X�Əo�����
	
	GF_NPC_5_01_BEFORE_INTERCEPT8	= GF_05MP1201_IN_MEETING,			// ����ܕ��@�}����G������
	GF_NPC_5_02_GOTO_BAHA			= GF_05MP1201_GOTO_BAHA,			// ����ܕ��A�o�n�̓��Ɍ�����
	GF_NPC_5_02_GOTO_LOOKOUT		= GF_05MP1201_NOTICE_MIST,			// ����ܕ��������Ɍ�����
	GF_NPC_5_03_GOTO_GHOSTHIP		= GF_05MP1201_GOTO_GHOSTHIP,		// ����ܕ��B�H��D�𒲂ׂɌ�����
	GF_NPC_5_03_OCCUR_INTERCEPT9	= GF_05MP1201_OCCUR_INTERCEPT9,		// ����ܕ��e�}����H�������i�A���X���o�Y��j
	GF_NPC_5_03_AFTER_INTERCEPT9	= GF_05MP1201_AFTER_INTERCEPT9,		// ����ܕ��e�}����H���ς܂���
	GF_NPC_5_04_GOTO_HOLLOW			= GF_05MP1201_GOTO_HOLLOW,			// ����ܕ��C��󓴂֌�����
	GF_NPC_5_05_BEFORE_INTERCEPT10	= GF_05MP1201_OCEANUS_STANDBY,		// ����ܕ��D�}����I�i�΃I�P�A�m�X�j������
	GF_NPC_5_06_HOLD_PARTY			= GF_05MP1201_HOLD_PARTY,			// ����ܕ��E���̕Y�������U��i��j
	GF_NPC_5_07_GOTO_VALLAY			= GF_05MP1201_GOTO_VALLAY,			// ����ܕ��F���Ƃ̒J�֌�����
	GF_NPC_5_08_MEET_DANA			= GF_05MP6105_GOTO_VALLAY,			// ����ܕ��G�_�[�i�ƍ�������
	
	GF_NPC_6_01_BEFORE_INTERCEPT11	= GF_06MP1201_BEFORE_INTERCEPT,		// ����Z���@�}����J������
	GF_NPC_6_02_GOTO_GEND			= GF_06MP1201_GOTO_GEND,			// ����Z���A�W�����_��������֌�����
	GF_NPC_6_03_GOTO_GARDEN			= GF_06MP4109_GOTO_GARDEN,			// ����Z���B�Z�����̉���ڎw��
	GF_NPC_6_03_OCCUR_INTERCEPT12	= GF_06MP6409_OCCUR_INTERCEPT12,	// ����Z���e�}����K�������i�Z�����̉�������j
	GF_NPC_6_03_AFTER_INTERCEPT12	= GF_06MP6409_AFTER_INTERCEPT12,	// ����Z���e�}����K���ς܂���
	GF_NPC_6_04_GET_MISTILTEINN		= GF_06MP6350_GET_MISTILTEINN,		// ����Z���C�z���~�X�g���e�B�������
	
	GF_NPC_7_01_GOTO_TEM			= GF_07MP1202_AWAKE_ADOL,			// ���G�s���[�O�@���@�O�֌�����
	GF_NPC_7_02_GOTO_ABYSS			= GF_07MP6409_GOTO_ABYSS,			// ���G�s���[�O�A�͂��܂�̐[�����U��
	GF_NPC_7_03_CHECK_VILLAGE		= GF_07MP1201_CHECK_VILLAGE,		// ���G�s���[�O�B�Y�������Ō�Ɍ����

	///////////////////////////////////////////////
	// �V���b�v�X�V�t���O
	///////////////////////////////////////////////

	GF_SHOP_RANK_2_08				= GF_02MP1201_JOIN_KATRIN,			// ����񕔇G�J�g���[����������
	GF_SHOP_RANK_2_11				= GF_02MP1119_JOIN_DINA,			// ����񕔇J�f�B�i��������
	GF_SHOP_RANK_3_02				= GF_03MP1201_STRIKE_KUINA,			//�N�C�i�ƂԂ���A�h��
	GF_SHOP_RANK_3_05				= GF_03MP1201_BACK_GENSD,			// ����O���D�ĂуW�����_�����Ɍ�����
	GF_SHOP_RANK_4_01				= GF_04MP4107_GOTO_NORTH,			// ����l���@���k���ɑ��𓥂ݓ��ꂽ
	GF_SHOP_RANK_5_02				= GF_05MP1201_GOTO_BAHA,			// ����ܕ��A�o�n�̓��Ɍ�����
	GF_SHOP_RANK_5_04				= GF_05MP1201_GOTO_HOLLOW,			// ����ܕ��C��󓴂֌�����
	GF_SHOP_RANK_5_07				= GF_05MP1201_GOTO_VALLAY,			// ����ܕ��F���Ƃ̒J�֌�����
	GF_SHOP_RANK_6_01				= GF_06MP1201_BEFORE_INTERCEPT,		// ����Z���@�}����J������
	GF_SHOP_RANK_EDO				= GF_05MP1201_GOTO_HOLLOW,			// �G�h������

	///////////////////////////////////////////////
	// �恛���A�I������p�t���O
	///////////////////////////////////////////////
	GF_CHAPTER_0_END				= GF_00MP0011b_DIVE_OCEAN,			// �v�����[�O�I��
	GF_CHAPTER_1_END				= GF_01MPxxxx_1ST_CHAPTER_FINISH,	// ��ꕔ�I��
	GF_CHAPTER_2_END				= GF_02MPxxxx_2ND_CHAPTER_FINISH,	// ��񕔏I��
	GF_CHAPTER_3_END				= GF_03MPxxxx_3RD_CHAPTER_FINISH,	// ��O���I��
	GF_CHAPTER_4_END				= GF_04MPxxxx_4TH_CHAPTER_FINISH,	// ��l���I��
	GF_CHAPTER_5_END				= GF_05MPxxxx_5TH_CHAPTER_FINISH,	// ��ܕ��I��
	GF_CHAPTER_6_END				= GF_06MPxxxx_6TH_CHAPTER_FINISH,	// ��Z���I��
//	GF_EPILOGUE_1_END				= 0,								// �G���f�B���O�P	// ��p�t���O�����i�^�G���h�ł��m�[�}���G���h�ł��Ȃ���΂n�j�j
//	GF_EPILOGUE_2_END				= GF_NORMAL_END,					// �G���f�B���O�Q	// �恛������ƈ���āA��p�t���O������̂ŕʖ���`���Ȃ�
//	GF_EPILOGUE_3_END				= GF_TRUE_END,						// �^�G���f�B���O	// �恛������ƈ���āA��p�t���O������̂ŕʖ���`���Ȃ�

	///////////////////////////////////////////////
	// �󔠃t���O
	///////////////////////////////////////////////
	//
	// ���ɕʖ���`�������Ă���ׂ킩��Â炢���Atest:testflag�ł�GF_SUB06_MAX�Œ�`���I�[�o�[���肵�Ă���̂Œ���
	//
	GF_TBOX_START_dummy = 3000,		// �󔠃X�^�[�g�_�~�[

	// ���̊Ԃɕ󔠃t���O��邱��
	// ���Z�[�u�f�[�^�݊����ׁ̈A�������ύX�̎���GF_TBOX_END��O�ɒǋL���Ă������ƁB
	//   ��|����ȕύX�̎��̓Z�[�u�f�[�^���̂��ω�����\���������̂ŋC�ɂ��Ȃ�

	// ���_(�{�c)	�����Ƃ����̂ł��̂܂܎c��
	GF_MP1201_dummy_TBOX01,		//�Y�����p�i�{�c�E���g�p�j
	GF_MP1201_dummy_TBOX02,		//�Y�����p�i�{�c�E���g�p�j
	GF_MP1201_dummy_TBOX03,		//�Y�����p�i�{�c�E���g�p�j
	GF_MP1201_dummy_TBOX04,		//�Y�����p�i�{�c�E���g�p�j
	GF_MP1201_dummy_TBOX05,		//�Y�����p�i�{�c�E���g�p�j
	GF_MP1201_dummy_TBOX06,		//�Y�����p�i�{�c�E���g�p�j
	GF_MP1201_dummy_TBOX07,		//�Y�����p�i�{�c�E���g�p�j
	GF_MP1201_dummy_TBOX08,		//�Y�����p�i�{�c�E���g�p�j
	GF_MP1201_dummy_TBOX09,		//�Y�����p�i�{�c�E���g�p�j
	GF_MP1201_dummy_TBOX10,		//�Y�����p�i�{�c�E���g�p�j
	GF_MP1201_dummy_TBOX11,		//�Y�����p�i�{�c�E���g�p�j
	GF_MP1201_dummy_TBOX12,		//�Y�����p�i�{�c�E���g�p�j
	GF_MP1201_dummy_TBOX13,		//�Y�����p�i�{�c�E���g�p�j
	GF_MP1201_dummy_TBOX14,		//�Y�����p�i�{�c�E���g�p�j
	GF_MP1201_dummy_TBOX15,		//�Y�����p�i�{�c�E���g�p�j
	GF_MP1201_dummy_TBOX16,		//�Y�����p�i�{�c�E���g�p�j

	GF_TBOX_START = GF_MP1201_dummy_TBOX16,		// �󔠃X�^�[�g

	// �����̓��A
	GF_MP7302_TBOX02,
	GF_MP7302_TBOX03,
	GF_MP7303_TBOX01,

	// ���������C��
	GF_MP1131_TBOX01,
	GF_MP1111_TBOX01,
	GF_MP1104_TBOX01,
	GF_MP1104_TBOX02,
	GF_MP1104_TBOX03,	// ��PS4�ǉ�
	GF_MP1112_TBOX01,
	GF_MP1112_TBOX02,
	GF_MP2101_TBOX01,
	GF_MP2101_TBOX02,
	GF_MP1106_TBOX01,

	// �X���
	GF_MP1113_TBOX01,
	GF_MP1132_TBOX01,
	GF_MP1132_TBOX02,
//	GF_MP1132_TBOX03,	//�㔼�ɒǉ�
	GF_MP1133_TBOX01,
	GF_MP1134_TBOX01,
//	GF_MP1134_TBOX02,	//�㔼�ɒǉ�

	// �X��̐X
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

	// ����l(���̕l��)
	GF_MP1117_TBOX01,
//	GF_MP1117_TBOX02,	//�㔼�ɒǉ�
	GF_MP1135_TBOX01,
	GF_MP1135_TBOX02,

	// ��������
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

	//�ꗠ�̏ߓ���
	GF_MP7471_TBOX01,
	GF_MP7471_TBOX02,

	// ������
	GF_MP1108_TBOX01,

	GF_MP1109_TBOX01,
	GF_MP1109_TBOX02,
	GF_MP1109_TBOX03,

	// �Z�H�J
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
//	GF_MP4306_TBOX01,	//���ɒǉ�
	GF_MP4307_TBOX01,
	GF_MP4307_TBOX02,
	GF_MP4307_TBOX03,
	GF_MP4308_TBOX01,
//	GF_MP4309_TBOX01,	//���ɒǉ�

	// �k���̕l��

	//�����̍���
	GF_MP3101_TBOX01,
//	GF_MP3101_TBOX02,	//�㔼�ɒǉ�
	GF_MP3102_TBOX01,

	//�����n
	GF_MP7451_TBOX01,
	GF_MP7451_TBOX02,
	GF_MP7451_TBOX03,
	GF_MP7451_TBOX04,
	GF_MP7451_TBOX05,

	GF_MP7461_TBOX01,
	GF_MP7461_TBOX02,
	GF_MP7461_TBOX03,

	//���̊C��
	GF_MP1114_TBOX01,
	GF_MP1115_TBOX01,
	GF_MP1115_TBOX02,
	GF_MP1115_TBOX03,

	//�Z���̐X
	GF_MP2105_TBOX01,

	// ����
	GF_MP2301_TBOX01,
	GF_MP2301_TBOX02,
	GF_MP2301_TBOX03,
	GF_MP2302_TBOX01,
//	GF_MP2304_TBOX01,		���ɒǉ�
	GF_MP2305_TBOX01,
//	GF_MP2305_TBOX02,		���ɒǉ�
	GF_MP2306_TBOX01,
	GF_MP2306_TBOX02,
	GF_MP2307_TBOX01,

	// ���̕l��

	//����
	GF_MP1107_TBOX01,
	GF_MP3106_TBOX01,
	GF_MP3107_TBOX01,

	//�W�����_����
	GF_MP4331_TBOX01,
	GF_MP4333_TBOX01,
//	GF_MP4333_TBOX02,		//�㔼�ɒǉ�
	GF_MP4334_TBOX01,
	GF_MP4334_TBOX02,
//	GF_MP4334_TBOX03,		���ɒǉ�
	GF_MP4335_TBOX01,
	GF_MP4336_TBOX01,
	GF_MP4336_TBOX02,
	GF_MP4338_TBOX01,
//	GF_MP4338_TBOX02,		���ɒǉ�
	GF_MP4339_TBOX01,

// ���_�R��
	GF_MP4103_TBOX01,
	GF_MP7101_TBOX01,
	GF_MP4104_TBOX01,
	GF_MP4106_TBOX01,
	GF_MP4108_TBOX01,
	GF_MP4108_TBOX02,

// ������
	GF_MP5103_TBOX01,
	GF_MP5102_TBOX01,
	GF_MP5102_TBOX02,
	GF_MP5102_TBOX03,
	GF_MP5101_TBOX01,

// ���Â̑啽��
	GF_MP6116_TBOX01,
	GF_MP6116_TBOX02,
	GF_MP6111_TBOX01,
	GF_MP6112_TBOX01,

//��Β��̕���
	GF_MP7491_TBOX01,
	GF_MP7491_TBOX02,
	GF_MP7491_TBOX03,
	GF_MP7491_TBOX04,
	GF_MP7491_TBOX05,

//�g�����X��
//	GF_MP6115_TBOX01,		���ɒǉ�
	GF_MP6104_TBOX01,

	//�o�n�̓�
	GF_MP6322_TBOX01,
	GF_MP6322_TBOX02,
	GF_MP6322_TBOX03,
	GF_MP6323_TBOX01,
	GF_MP6323_TBOX02,
	GF_MP6323_TBOX03,
	GF_MP6323_TBOX04,
	GF_MP6325_TBOX01,	//���@��
	GF_MP6326_TBOX01,
	GF_MP6326_TBOX02,
	GF_MP6328_TBOX01,
	GF_MP6328_TBOX02,
	GF_MP6328_TBOX03,
	GF_MP6328_TBOX04,
	GF_MP6328_TBOX05,

	//��]��
	GF_MP1116_TBOX01,

//���ق̓��O��
//	GF_MP2104_TBOX01,		���ɒǉ�
//	GF_MP2104_TBOX02,		���ɒǉ�

// �C�ݓ��A_mp741x
	GF_MP7411_TBOX01,
	GF_MP7411_TBOX02,
	GF_MP7411_TBOX03,

//�H��D
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
//����
	GF_MP0401_TBOX01,
	GF_MP0401_TBOX02,
	GF_MP0401_TBOX03,
	GF_MP0401_TBOX04,

//�n����̑匊
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

//�V�R�u��
	GF_MP4110_TBOX01,
	GF_MP4110_TBOX02,

//�����n��
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

//���Ƃ̒J
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

//�I�v�̋u
	GF_MP6109_TBOX01,

//���v��n
	GF_MP7481_TBOX01,
	GF_MP7481_TBOX02,

//��m�@
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

//���v������
	GF_MP6412_TBOX01,
	GF_MP6412_TBOX02,
	GF_MP6412_TBOX03,

	GF_MP6413_TBOX01,
	GF_MP6413_TBOX02,
	GF_MP6413_TBOX03,
	GF_MP6413_TBOX04,

//�I�N�g�D�X�E�C�̉�L
	GF_MP6305_TBOX01,
	GF_MP6305_TBOX02,

//�I�N�g�D�X�E�X�̉�L
	GF_MP6306_TBOX01,
	GF_MP6306_TBOX02,
	GF_MP6306_TBOX03,

//�I�N�g�D�X�E峂̉�L
	GF_MP6307_TBOX01,
	GF_MP6307_TBOX02,
	GF_MP6307_TBOX03,

//�I�N�g�D�X�E�V�̉�L
	GF_MP6308_TBOX01,
	GF_MP6308_TBOX02,
	GF_MP6308_TBOX03,

//�I�N�g�D�X�E�I���̊�
	GF_MP6310_TBOX01,
	GF_MP6310_TBOX02,
	GF_MP6310_TBOX03,





//����
	GF_MP2305_TBOX02,
//�W�����_����
	GF_MP4334_TBOX03,
	GF_MP4338_TBOX02,
//�Ñ��̔�����
	GF_MP3109_TBOX01,
//�^�i�g�X�̃����֘A
	GF_MP1134_TBOX02,		//������
	GF_MP1117_TBOX02,		//����l
	GF_MP3101_TBOX02,		//�����̍���
	GF_MP4333_TBOX02,		//�W�����_����
//���_�R��
	GF_MP4104_TBOX02,
//�Ñ��̔�����
	GF_MP3109_TBOX02,
//�g�����X��
	GF_MP6115_TBOX01,
//�G�^�j�A���s����
	GF_MP6213_TBOX01,
	GF_MP6213_TBOX02,
	GF_MP6213_TBOX03,
	GF_MP6214_TBOX01,
//���꓇
	GF_MP1123_TBOX01,
//���l���i�x��20�j
	GF_MP1132_TBOX03,	//�㔼�ɒǉ�
//�`����
	GF_MP2304_TBOX01,	//�����֌C
	GF_MP4306_TBOX01,	//�����
//���ق̓��O��
	GF_MP2104_TBOX01,
	GF_MP2104_TBOX02,
//�G�^�j�A���s����
	GF_MP6214_TBOX02,

//��������PS4�ǉ�����������
	// �G�^�j�A���s�A�N�m�X�̉�
	GF_MP6201_TBOX01,
	GF_MP6201_TBOX02,
	
	// ����ҁA�勬�J����ǉ���
	GF_MP1107_TBOX02,	// �x�X�e�B�A���|�[�V����
	
	// ���Ƃ̒J����
	GF_MP6108_TBOX01,	
	
	GF_TBOX_END,				// �󔠃G���h�i�t���O���`�F�b�N�p�Ȃ̂ŁAGF_ITEMPOINT_START���O�ɒu���悤�Ɂj
								// �����܂ł̃t���O��󔠂̐��Ƃ���B
								// �������A�ŏ��̂P�U�͌v�Z���珜�O����i�Y�����͌v�Z�ɓ���Ȃ��B�j

//��������͕󔠂̃g���t�B�[�Ɍv�Z����Ȃ�����
	GF_TBOX_START2 = 3700,				//�g���t�B�[�Ɍv�Z����Ȃ��󔠃t���O
		
//��������PS4�ǉ�����������
	// ���n�������P�w
	GF_MP6511_TBOX01,
	GF_MP6511_TBOX02,
	GF_MP6511_TBOX03,
	GF_MP6512_TBOX01,
//	GF_MP6512_TBOX02,			//���ォ��ǉ������̂ŕʂ̏��ɒ�`���Ă���
	GF_MP6513_TBOX01,
	GF_MP6513_TBOX02,
	GF_MP6519_TBOX01,

	// ���n�������Q�w
	GF_MP6521_TBOX01,
	GF_MP6521_TBOX02,
	GF_MP6521_TBOX03,
	GF_MP6522_TBOX01,
	GF_MP6522_TBOX02,
	GF_MP6529_TBOX01,

	// ���n�������R�w
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
//	GF_MP6531_TBOX07,			//���ォ��ǉ������̂ŕʂ̏��ɒ�`���Ă���

	// ���n�������S�w
	GF_MP6541_TBOX01,
	GF_MP6541_TBOX02,
	GF_MP6541_TBOX03,
	GF_MP6541_TBOX04,
	GF_MP6542_TBOX01,
	GF_MP6542_TBOX02,
	GF_MP6542_TBOX03,
	GF_MP6542_TBOX04,
	GF_MP6549_TBOX01,

	// ���n�������T�w
	GF_MP6551_TBOX01,
	GF_MP6551_TBOX02,
	GF_MP6551_TBOX03,
	GF_MP6552_TBOX01,
	GF_MP6554_TBOX01,
	GF_MP6554_TBOX02,
	GF_MP6554_TBOX03,
//	GF_MP6554_TBOX04,			//���ォ��ǉ������̂ŕʂ̏��ɒ�`���Ă���
	GF_MP6555_TBOX01,
	GF_MP6555_TBOX02,
	GF_MP6559_TBOX01,

	// ���n�������U�w
	GF_MP6561_TBOX01,
	GF_MP6561_TBOX02,
	GF_MP6561_TBOX03,
	GF_MP6561_TBOX04,

	//�ߋ��ҁE�n�������F�{�X���j���
	GF_MP6519m_TBOX01,
	GF_MP6529m_TBOX01,
	GF_MP6539m_TBOX01,
	GF_MP6549m_TBOX01,
	GF_MP6559m_TBOX01,

	// ����ҁE�n�������R�w
	GF_MP6531_TBOX07,			//
	
	// �X��̐X��ǉ���
	GF_MP1303t2_TBOX02,
	
	// ����ҁE�n�������P�w�ǉ���
	GF_MP6512_TBOX02,

	// ����ҁE�n�������T�w�ǉ���
	GF_MP6554_TBOX04,
	
	// �ߋ��ҁE�n�������P�w�ǉ���
	GF_MP6512m_TBOX01,
	GF_MP6513m_TBOX01,
	
	// ����ҁE�n�������U�w���_����
	GF_MP6569_TBOX01,

	// �ߋ��ҁE�n�������Q�w�ǉ���
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
	GF_TBOX_DUMMY131, //Load zone from temple approach -> pinnacle
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

	// ���_
	GF_MP1201_TBOX01,		//�Y�����p�i�m�ہj���`���[�g���A��
	GF_MP1201_TBOX02,		//�Y�����p�i�m�ہj����񕔇A�T���J�n					���Z�b�g
	GF_MP1201_TBOX03,		//�Y�����p�i�m�ہj����񕔇G�J�g���[����������			�����V�s���E���^�g�D�C��
	GF_MP1201_TBOX04,		//�Y�����p�i�m�ہj����񕔇J�f�B�i��������				�H�ރZ�b�g
	GF_MP1201_TBOX05,		//�Y�����p�i�m�ہj����O���@���N�V���̌��֌�����		��Ԉُ�񕜖�Z�b�g
	GF_MP1201_TBOX06,		//�Y�����p�i�m�ہj����l���@���k���ɑ��𓥂ݓ��ꂽ		���c�R�F�L���x�c�̕c
	GF_MP1201_TBOX07,		//�Y�����p�i�m�ہj����ܕ��A�o�n�̓��Ɍ�����			�ʕ��Z�b�g
	GF_MP1201_TBOX08,		//�Y�����p�i�m�ہj����ܕ��C��󓴂֌�����				�}���N�X����E�����i�v���[���g�E���R�b�^�j
	GF_MP1201_TBOX09,		//�Y�����p�i�m�ہj����Z���A�W�����_��������֌�����	����{���Z�b�g
	GF_MP1201_TBOX10,		//�Y�����p�i�m�ہj���g�p
	GF_MP1201_TBOX11,		//�Y�����p�i�m�ہj���g�p
	GF_MP1201_TBOX12,		//�Y�����p�i�m�ہj���g�p
	GF_MP1201_TBOX13,		//�Y�����p�i�m�ہj���g�p
	GF_MP1201_TBOX14,		//�Y�����p�i�m�ہj���g�p
	GF_MP1201_TBOX15,		//�Y�����p�i�m�ہj���g�p
	GF_MP1201_TBOX16,		//�Y�����p�i�m�ہj���g�p

	//�[������A�C�e��
	GF_MP7303_SKELETON01,	//�����̓��A
	GF_MP0402_SKELETON01,	//�H��D

	GF_MP4301_SKELETON01,	//�Z�H�J		�C���̃����@
	GF_MP4305_SKELETON01,	//�Z�H�J		�C���̃����A
	GF_MP4308_SKELETON01,	//�Z�H�J		�C���̃����B
	GF_MP2303_SKELETON01,	//����			�C���̃����C
	GF_MP1115_SKELETON01,	//���̊C��		�C���̃����D
	GF_MP0408_SKELETON01,	//�H��D		�C���̃����E

	//�L���L�����Ƃ�������A�C�e��
	GF_MP1116_KIRAKIRA01,	//�]�����E�l��
	GF_MP7461_KIRAKIRA01,	//�����n
	GF_MP1122_KIRAKIRA01,	//���꓇
	GF_MP6370_KIRAKIRA01,	//�匊�F�D���v���[�g

	//�Y�����E����K���o���t���O
	GF_MP1110_RANDBOX01,
	GF_MP1111_RANDBOX01,
	GF_MP1112_RANDBOX01,

//��������PS4�ǉ�����������
	// �X��̐X�E��
	GF_MP1301t2_TBOX01,
	GF_MP1301t2_TBOX02,
	GF_MP1301t2_TBOX03,
	
	GF_MP1302t2_TBOX01,
	GF_MP1302t2_TBOX02,
	GF_MP1302t2_TBOX03,
	GF_MP1302t2_TBOX04,
	GF_MP1303t2_TBOX01,
//	GF_MP1303t2_TBOX02,			//���ォ��ǉ������̂ŕʂ̏��ɒ�`���Ă���
	GF_MP1304t2_TBOX01,
	GF_MP1304t2_TBOX02,
	GF_MP1304t2_TBOX03,
	GF_MP1306t2_TBOX01,
	GF_MP1307t2_TBOX01,

	// �W�����_�����E��
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

	// �ߋ��ҁE�n�������P�w
	GF_MP6511m_TBOX01,
	GF_MP6514m_TBOX01,
	GF_MP6514m_TBOX02,

	// �ߋ��ҁE�n�������Q�w
	GF_MP6523m_TBOX01,
	GF_MP6524m_TBOX01,

	// �ߋ��ҁE�n�������R�w
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

	// �ߋ��ҁE�n�������S�w
	GF_MP6541m_TBOX01,
	GF_MP6541m_TBOX02,
	GF_MP6542m_TBOX01,
	GF_MP6542m_TBOX02,
	GF_MP6542m_TBOX03,

	// �ߋ��ҁE�n�������T�w
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

	// �ߋ��ҁE�n�������U�w
	GF_MP6561m_TBOX01,
	GF_MP6561m_TBOX02,
	GF_MP6561m_TBOX03,
	GF_MP6561m_TBOX04,


	GF_TBOX_MAX2,				//�g���t�B�[�Ɍv�Z����Ȃ��󔠃t���O�I�[


	///////////////////////////////////////////////
	// �\���t���O
	///////////////////////////////////////////////
	GF_RESERVE_START = 4000,	// �\���t���O�X�^�[�g

	///////////////////////////////////////////////
	// �N�G�X�g�t���O
	///////////////////////////////////////////////
	// �N�G�X�g�t���O�́A
	// QUEST_NOTHING=�u���o�^�v
	// QUEST_END=�u�B���ς݁v
	// QUEST_START=�u�i�s���v�Ƃ��܂��B
	// �蒠�ł́AQUEST_NOTHING�̂Ƃ��͍��ڂ��u�H�H�H�H�H�v�ŁA�\�����Ė��o�^�����Ƃ��܂��B
	// QUEST_END�̂Ƃ��͒B���ς݂̃}�[�N���t���ŕ\�����܂��B��
	// ����ȊO�̓O���[�\���ɂ��āA�܂��i�s�������Ƃ��܂��B

	// scr_inc.h

//	enum {
//		QUEST_NOTHING = 0,		// 00:�N�G�X�g�܂����o�^
//		QUEST_BBS,				// 01:�f��������
//		QUEST_START,			// 02:�˗����J�n����
//		QUEST_FALSE,			// 03:���s����
//
//		QUEST_SUCCESS = 98,		// 98:�N�G�X�g�B������
//		QUEST_END = 99,			// 99:�N�G�X�g�񍐂���
//	};
//
//
//	�蒠�d�l����
//		�X�N���v�g�ɐ�p�R�}���h��p�ӂ��āA���ݎ������t���O�ɑ���ł���悤�ɂ���B
//		���b�Z�[�W���O�̓t���O���O���ۂ��Ŕ��肵�A�t���O�ɒl�������Ă���ꍇ�A
//		�t���O�ɃZ�b�g����Ă���l�����������Ƀ\�[�g�������Ń��b�Z�[�W��\������B
//
//		��j�ȉ��̂悤�Ƀt���O�ƃ��b�Z�[�W���Ή����Ă���ꍇ
//				GF_MAIN_01			�A�h���͋L����������
//				GF_MAIN_02			�f�����������ԂɂȂ���
//				GF_MAIN_03			�L���X�i�����o��
//				GF_MAIN_04			�L�����v�𒣂���
//				GF_MAIN_05			�R���h�ɓ�������
//
//			�ȏ�̏�Ԃ̎��ɁA���ꂼ��t���O�̒��g���ȉ��ƂȂ��Ă���ꍇ�A
//
//				GF_MAIN_01			50
//				GF_MAIN_02			100
//				GF_MAIN_03			75
//				GF_MAIN_04			60
//				GF_MAIN_05			0
//
//			�蒠�ɂ͈ȉ��̂悤�ɕ\�������
//
//				�A�h���͋L����������				// GF_MAIN_01	�l  50
//				�L�����v�𒣂���					// GF_MAIN_04	�l  60
//				�L���X�i�����o��					// GF_MAIN_03	�l  75
//				�f�����������ԂɂȂ���				// GF_MAIN_02	�l 100
//
//			��GF_MAIN_05��0�Ȃ̂ŕ\������Ȃ�
//			�����b�Z�[�W�e�[�u���́A�t���O�ƃ��b�Z�[�W��o�^���A
//			�@�t���O���̓X�N���v�^�[���D���Ȗ��O�œo�^�ł���悤�ɂ��Ă����B
//

	GF_QUEST_START,				// �N�G�X�g�t���O��`�J�n�i���ꂪ�Ȃ��ƃv���O�����Ɉُ�𗈂��j

	//-- �蒠�E�N�G�X�g�C�x���g����p ----------------------------------------------------------
	GF_QUEST_200,				// �Q���̍쐬
	GF_QUEST_201,				// ���~�p�̑f��

	GF_QUEST_210,				// �J�[�e���̎d����

	GF_QUEST_220,				// �������̍쐬
	GF_QUEST_221,				// ���D�̍쐬
	GF_QUEST_222,				// �d���Ă̗��K
	GF_QUEST_223,				// ���b�̓����˗��@

	GF_QUEST_230,				// �C���̂���T��
	GF_QUEST_231,				// �����Ȃ�H��

	GF_QUEST_300,				// �肢�̖�
	GF_QUEST_301,				// �V������̃e�X�g
	GF_QUEST_302,				// ���b�̓����˗��A

	GF_QUEST_310,				// �H�|�i�̃e�X�g
	GF_QUEST_311,				// �_�ɋF���

	GF_QUEST_400,				// ������[�ւ̌���
	GF_QUEST_401,				// �V����̕ߊl
	GF_QUEST_402,				// �h�{���_�̓�����

	GF_QUEST_500,				// �E�o�D�̍ޗ��W��
	GF_QUEST_501,				// ���̔z�B
	GF_QUEST_502,				// �D���ւ̂�����
	GF_QUEST_503,				// ���b�̓����˗��B

	GF_QUEST_510,				// �̋��̍���

	GF_QUEST_520,				// �ō��̖��O
	GF_QUEST_521,				// ����ȉ��G
	GF_QUEST_522,				// �G�^�j�A�̒���

	GF_QUEST_530,				// ���b�̓����˗��C

	GF_QUEST_600,				// �ŋ��h��̍쐬
	GF_QUEST_601,				// �`���Ƃւ̈˗�
	GF_QUEST_602,				// �����̒��B

	GF_QUEST_610,				// �I���K�̔�����
	GF_QUEST_611,				// �V���Ƃ̎荇�킹
	GF_QUEST_612,				// ���������m���X

	//��PS4�ǉ���
	GF_QUEST_232,				// �Ŗ�̉�
	GF_QUEST_303,				// ��������I���ђn��
	GF_QUEST_504,				// �������I�Z�H�J
	GF_QUEST_505,				// �������̍̎�
	GF_QUEST_603,				// ���ł���I���Ƃ̒J
	GF_QUEST_613,				// ���̒D��

	GF_QUEST_END,

//-- �N�G�X�g�p���[�N+�e��N�G�X�g�p�f�e ------------------------------------------------
// 160���炢�͎g����

	//���A�C�R���p
	GF_QSHEADICON_START = 4050,	// ����A�C�R���p�X�^�[�g

	GF_QS200_END = GF_QSHEADICON_START,		// �Q���̍쐬
	GF_QS201_END,				// ���~�p�̑f��

	GF_QS210_END,				// �J�[�e���̎d����

	GF_QS220_END,				// �������̍쐬
	GF_QS221_END,				// ���D�̍쐬
	GF_QS222_END,				// �d���Ă̗��K
	GF_QS223_END,				// ���b�̓����˗��@

	GF_QS230_END,				// �C���̂���T��
	GF_QS231_END,				// �����Ȃ�H��

	GF_QS300_END,				// �肢�̖�
	GF_QS301_END,				// �V������̃e�X�g
	GF_QS302_END,				// ���b�̓����˗��A

	GF_QS310_END,				// �H�|�i�̃e�X�g
	GF_QS311_END,				// �_�ɋF���

	GF_QS400_END,				// ������[�ւ̌���
	GF_QS401_END,				// �V����̕ߊl
	GF_QS402_END,				// �h�{���_�̓�����

	GF_QS500_END,				// �E�o�D�̍ޗ��W��
	GF_QS501_END,				// ���̔z�B
	GF_QS502_END,				// �D���ւ̂�����
	GF_QS503_END,				// ���b�̓����˗��B

	GF_QS510_END,				// �̋��̍���

	GF_QS520_END,				// �ō��̖��O
	GF_QS521_END,				// ����ȉ��G
	GF_QS522_END,				// �G�^�j�A�̒���

	GF_QS530_END,				// ���b�̓����˗��C

	GF_QS600_END,				// �ŋ��h��̍쐬
	GF_QS601_END,				// �`���Ƃւ̈˗�
	GF_QS602_END,				// �����̒��B

	GF_QS610_END,				// �I���K�̔�����
	GF_QS611_END,				// �V���Ƃ̎荇�킹
	GF_QS612_END,				// ���������m���X

	GF_QS101_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS102_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS103_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS104_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS105_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS106_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS107_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS108_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS109_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j

	GF_QS202_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS203_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS204_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS205_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS206_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS207_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS208_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS209_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j

	GF_QS303_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS304_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS305_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS306_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS307_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS308_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS309_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j

	GF_QS403_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS404_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS405_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j

	GF_QS504_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j
	GF_QS505_END,				// ���Z���Z�^�̃N�G�X�g�i�폜�\��j


	GF_QSHEADICON_MAX,	// ����A�C�R���p�I�[

	//�J�n�������؂��p
	GF_QSLIMIT_START = 4120,	// �J�n�������؂��p�X�^�[�g

	GF_QS101_FALSE = GF_QSLIMIT_START,		// �����؂�iquest.csv�p�j
	GF_QS102_FALSE,				// �����؂�iquest.csv�p�j

	GF_QS401_STARTOK,			// �J�n�����ɂȂ����i���A�C�R���p�j
	GF_QS403_STARTOK,			// �J�n�����ɂȂ����i���A�C�R���p�j
	GF_QS204_STARTOK,			// �J�n�����ɂȂ����i���A�C�R���p�j
	GF_QS207_STARTOK,			// �J�n�����ɂȂ����i���A�C�R���p�j
	GF_QS208_STARTOK,			// �J�n�����ɂȂ����i���A�C�R���p�j

	GF_QS201_FALSE,				// �����؂�iquest.csv�p�j
	GF_QS301_FALSE,				// �����؂�iquest.csv�p�j


	GF_QSLIMIT_MAX,	// �J�n�������؂��p�I�[

	//�e�N�G�X�g�p�T�u�t���O
	GF_QSSUB_START = 4150,		// �e�N�G�X�g�p�T�u�t���O�X�^�[�g

	GF_QS_EVENT_TMP = GF_QSSUB_START,		//�N�G�X�g�C�x���g�������ɁA��ʃ��b�Z�[�W�̑I�������[�v�𔲂��邽�߂̃e���|����
	GF_QS200_1STTALK,			//�yQS200�z�f�e����
	GF_QS220_CHECK_A,			//�yQS220�z���k�o�����C�x���g�` ������
	GF_QS220_CHECK_B,			//�yQS220�z���k�o�����C�x���g�a ������
	GF_QS220_CHECK_C,			//�yQS220�z���k�o�����C�x���g�b ������
	GF_QS223_KILL_CT,			//�yQS223�z�q���b�p�[�̑|�� �|���������X�^�[�̃J�E���^
	GF_QS223_KILL_MONS,			//�yQS223�z�q���b�p�[�̑|�� �����X�^�[�𓢔�����
//	GF_QS223_SET_MARKER,		//�yQS223�z�q���b�p�[�̑|�� �}�[�J�[���Z�b�g����	���ɒǉ�
	GF_QS230_GET_TREASURE,		//�yQS230�z�����󔭌��C�x���g ������
	GF_QS300_GET_TREE,			//�yQS300�z���؂���肷�� ������
	GF_QS302_KILL_MONS,			//�yQS302�z�A�M�A�M���̓��� �����X�^�[�𓢔�����
//	GF_QS302_SET_MARKER,		//�yQS302�z�A�M�A�M���̓��� �}�[�J�[���Z�b�g����	���ɒǉ�
	GF_QS310_KILL_ANCIENT_1,	//�yQS310�z�W�����_�����ɂ���Ñ���|�����P
	GF_QS310_KILL_ANCIENT_2,	//�yQS310�z�W�����_�����ɂ���Ñ���|�����Q
	GF_QS311_ESCORT_START,		//�yQS311�z����q�J�n�C�x���g ������
	GF_QS311_LOOK_EVENT,		//�yQS311�z���N�G�X�g�C�x���g ������
	GF_QS400_CHECK_EVENT,		//�yQS400�z���N�G�X�g�C�x���g ������
	GF_QS400_QUEST_BATTLE,		//�yQS400�z1:�N�G�X�g�퓬��
	GF_QS400_KONG_LV,			//�yQS400�z�}�X�^�[�R���O�̃��[�h�w��(0=���R�b�^,1=�T�n�h,2=�_�[�i,3=���N�V��,4=�q��������,5=�A�h��)
	GF_QS401_LOOK_PICARD_1,		//�yQS401�z���s�b�J�[�h�ߊl�C�x���g�i�l�Ӂj ������
	GF_QS401_LOOK_PICARD_2,		//�yQS401�z���s�b�J�[�h�ߊl�C�x���g�i�W��j ������
	GF_QS401_LOOK_PICARD_A,		//�yQS401�z���s�b�J�[�h�ߊl�C�x���g�i�����`�j ������
	GF_QS401_LOOK_PICARD_B,		//�yQS401�z���s�b�J�[�h�ߊl�C�x���g�i�����a�j ������
	GF_QS503_KILL_CT,			//�yQS503�z�O���h���O�D�̑|�� �|���������X�^�[�̃J�E���^
	GF_QS503_KILL_MONS,			//�yQS503�z�O���h���O�D�̑|�� �����X�^�[�𓢔�����
//	GF_QS503_SET_MARKER,		//�yQS503�z�O���h���O�D�̑|�� �}�[�J�[���Z�b�g����	���ɒǉ�
	GF_QS510_LOOK_SUBEV,		//�yQS510�z���T�u�C�x���g�E�A���X�����|��� ������
	GF_QS520_BABY_NAME_HOPE,	//�yQS520�z�Ԃ����̖��O�Ɂw�z�[�v�x��I�񂾁i0�������̓C�x���g�X�L�b�v�Ȃ�w�E�B���x,1�w�z�[�v�x,2�w���[�N�x�j
	GF_QS521_GET_FISH,			//�yQS521�z������s�����N��ނ������̃C�x���g ������
	GF_QS522_TALK_SERACH1,		//�yQS522�z���y���T���C�x���g�@ ������
	GF_QS522_TALK_SERACH2,		//�yQS522�z���y���T���C�x���g�A ������
	GF_QS522_TALK_SERACH3,		//�yQS522�z���y���T���C�x���g�B ������
	GF_QS522_TALK_SERACH4,		//�yQS522�z���y���T���C�x���g�B �i�R�j������
	GF_QS530_KILL_CT,			//�yQS530�z�A���V���R�E�̓��� �|���������X�^�[�̃J�E���^�i�t���O�j
	GF_QS530_KILL_MONS,			//�yQS530�z�A���V���R�E�̓��� �����X�^�[�𓢔�����
//	GF_QS530_SET_MARKER,		//�yQS530�z�A���V���R�E�̓��� �}�[�J�[���Z�b�g����	���ɒǉ�
	GF_QS600_1STTALK,			//�yQS600�z�f�e����
	GF_QS600_ARMOR_WOMEN,		//�yQS600�z�����p�̊Z�𑢂��Ă��炤 ��I��
	GF_QS602_PRESENT_KASHU,		//�J�V���[�F���v���[���g�C�x���g ������
	GF_QS602_SAP_A,				//�yQS602�z�����y���t����肷�� ������
	GF_QS602_SAP_B,				//�yQS602�z�����y���t����肷�� ������
	GF_QS602_SAP_C,				//�yQS602�z�����y���t����肷�� ������
	GF_QS610_LOOK_DESK,			//�yQS610�z���������˂̊��𒲂ׂ� ������
	GF_QS610_LOOK_STELE,		//�yQS610�z���o�n�̓��̐Δ�𒲂ׂ� ������
	GF_QS611_QUEST_BATTLE,		//�yQS611�z1:�N�G�X�g�퓬��
	GF_QS611_LOSE,				//�yQS611�z���s�k�C�x���g ������
	GF_QS310_GET_ITEM,			//�yQS310�z��V����������B�V���b�v�X�V�p

	//���������ǉ�����������
	GF_QS223_SET_MARKER,		//�yQS223�z�q���b�p�[�̑|�� �}�[�J�[���Z�b�g����
	GF_QS302_SET_MARKER,		//�yQS302�z�A�M�A�M���̓��� �}�[�J�[���Z�b�g����
	GF_QS503_SET_MARKER,		//�yQS503�z�O���h���O�D�̑|�� �}�[�J�[���Z�b�g����
	GF_QS530_SET_MARKER,		//�yQS530�z�A���V���R�E�̓��� �}�[�J�[���Z�b�g����

	GF_QS311_START_READY,		//�yQS311�z�J�n�����𖞂���
	GF_QS400_SEE_KONG_VISUAL,	//�yQS400�z�}�X�^�[�R���O�r�W���A���������܂���
	GF_QS611_SEE_SILVIA_VISUAL,	//�yQS611�z�V�����B�A�r�W���A���������܂���
	GF_QS201_SHOP_ADD,			//�yQS201�z�u���~�p�̑f�ށv�N���A��V���b�v�ɒǉ�
	GF_QS610_TALK_DANA,			//�yQS610�z�_�[�i�[�̘b�𕷂�
	GF_QS222_SHOP_ADD,			//�yQS222�z�u�d���Ă̗��K�v�N���A��V���b�v�ɒǉ�
	GF_QS600_SHOP_ADD,			//�yQS600�z�u�P����Z�v�N���A��V���b�v�ɒǉ�
	GF_QS310_GET_ITEM2,			//�yQS310�z�V���b�v�X�V�p�E�\���̎��ΐ�p�t���O				�匊�Ɍ�����
	//�N�G�X�g�ł͂Ȃ����̂����邯�ǂ����ɓ���܂��B
	GF_SHOP_ADD_RECIPE05,		//�y��� �z���R�b�^�̈�ʂ𓦂�����@��o�����ɕ���
	GF_SHOP_ADD_RECIPE06,		//�yQS402�z�~�����_�̃N�G�X�g�𓦂�����@��o�����ɕ���
	GF_SHOP_ADD_RECIPE10,		//�y��� �z�V�X�^�[�E�j�A�̈�ʂ𓦂�����@��o�����ɕ���
	GF_QS310_GET_ITEM3,			//�yQS310�z�V���b�v�X�V�p�E�\���̌아��p�t���O�@0519			�o�n�Ɍ�����

	//�N�G�X�g
	GF_QS311_QUEST_CANCEL,		//�yQS311�z�N�G�X�g�r���ŃL�����Z��

	GF_QS510_FIND_ED,			// �yQS510�z���͂ŃG�h���������i�̋��̉Ԃ�B�������j

	//PS4�ǉ���_�N�G�X�g�T�u�t���O
	GF_QS303_QUESTEVENT,		//�yQS311�z��������I�@���ђn�с@�����C�x���g������
	GF_QS303_QUESTCLEAR,		//�yQS311�z��������I�@���ђn�с@�N�G�X�g���N���A����

	//PS4�ǉ���_��_���W�����N�G�X�g
	GF_QS232_EVENT_1,			//�yQS232�z�N�G�X�g�C�x���g�P������
	GF_QS232_EVENT_2,			//�yQS232�z�N�G�X�g�C�x���g�Q������
	GF_QS232_EVENT_3,			//�yQS232�z�N�G�X�g�C�x���g�R������
	GF_QS232_EVENT_4,			//�yQS232�z�N�G�X�g�C�x���g�S������
	GF_QS232_EVENT_5,			//�yQS232�z�N�G�X�g�C�x���g�T������

	GF_QS505_EVENT_1,				//�yQS505�z�N�G�X�g�C�x���g�P������
	GF_QS505_GET_HERB_1,			//�yQS505�z�������P����ɓ��ꂽ
	GF_QS505_GET_HERB_2,			//�yQS505�z�������Q����ɓ��ꂽ
	GF_QS505_GET_HERB_3,			//�yQS505�z�������R����ɓ��ꂽ
	GF_QS505_GET_HERB_4,			//�yQS505�z�������S����ɓ��ꂽ
	GF_QS505_GET_HERB_5,			//�yQS505�z�������T����ɓ��ꂽ
	GF_QS505_GET_HERB_ALL,			//�yQS505�z��������S�Ď�ɓ��ꂽ
	GF_QS505_EVENT_2,				//�yQS505�z�N�G�X�g�C�x���g�Q������
	GF_QS505_QUESTCLEAR,			//�yQS505�z�N�G�X�g���N���A����

	GF_QS613_EVENT_1,				//�yQS613�z�N�G�X�g�C�x���g�P������
	GF_QS613_EVENT_2,				//�yQS613�z�N�G�X�g�C�x���g�Q������
	GF_QS613_QUESTCLEAR,			//�yQS613�z�N�G�X�g���N���A����

	//PS4�ǉ���_������i�c��j
	GF_QS504_QUESTEVENT,		//�yQS504�z�������I�@�Z�H�J�@�h�M�̊J�n�C�x���g������	
	GF_QS504_QUESTCLEAR,		//�yQS504�z�������I�@�Z�H�J�@�N�G�X�g���N���A����

	GF_QS603_QUESTEVENT,		//�yQS603�z���ł���I�@���Ƃ̒J�@�h�M�̊J�n�C�x���g������
	GF_QS603_QUESTCLEAR,		//�yQS603�z���ł���I�@���Ƃ̒J�@�N�G�X�g���N���A����

	//PS4�ǉ����@�����؂�̌@��o�����t�H���[
	GF_ADD_DRUG_RECIPE02,		//�yQS230�z�f�B�i�̃N�G�X�g�𓦂�����V���b�v�ɕ���
	GF_ADD_AR_028,				//�yQS500�z�Y�����i�h�M�j�̃N�G�X�g�𓦂�����@��o�����ɕ���
	GF_DRUG_RECIPE13,			//�yQS505�z�Y�����i���q�g�j�̃N�G�X�g�𓦂�����U���Œ����\�ɂȂ�

	//������`���[�g���A��������
	GF_QS303_TUTORIAL,			//�yQS311�z��������I�@���ђn�с@�`���[�g���A��������


	GF_QSSUB_MAX,			// �e�N�G�X�g�p�T�u�t���O�I�[

//--------------------------------------------------------------------
//-- ���N�G�X�g�蒠�p ------------------------------------------------
//--------------------------------------------------------------------
	DF_QS_START = 4400,		// �N�G�X�g�蒠�p�X�^�[�g

	//�yQS200�z�x�b�h�̍쐬�i�o���o���X�j
	DF_QS200_START = DF_QS_START,		//�yQS200�z���o���o���X�D���ɑf�ނ�n���A�˗���B�������I

	//�yQS201�z���~�p�̑f�ށi�h�M�j
	DF_QS201_START,				//�yQS201�z���h�M����b�𕷂����B�ȉ��̑f�ނ��W�߂悤�B
	DF_QS201_END,				//�yQS201�z���h�M�ɑf�ނ�n���A�˗���B���B

	//�yQS210�z�J�[�e���̍쐬�i���N�V���j
	DF_QS210_START,				//�yQS210�z�����N�V������b�𕷂����B�ȉ��̑f�ނ��W�߂悤�B
	DF_QS210_END,				//�yQS210�z�����N�V���ɑf�ނ�n���č�Ƃ���`�����I

	//�yQS220�z�������̌��݁i�o���o���X�j
	DF_QS220_START,				//�yQS220�z�����m�炸�C�݂̖k�ɍL�����Ă���Ƃ���
	DF_QS220_001A,				//�yQS220�z���L���ׂ̍����΂��������B
	DF_QS220_001B,				//�yQS220�z���Y���������܂��Ă���ꏊ���������B
	DF_QS220_001C,				//�yQS220�z�����h�Ȗ؂��������B
	DF_QS220_END,				//�yQS220�z���ޗ��̏ꏊ���o���o���X�D���ɕ񍐁B

	//�yQS221�z���M�̍쐬�i�h�M�j
	DF_QS221_END_1ST,			//�yQS221�z���h�M�ɑf�ނ�n���A���D������`�����B
	DF_QS221_END_2ND,			//�yQS221�z���h�M�ɑf�ނ�n���A���D������`�����B

	//�yQS222�z�d���Ă̗��K�i�A���X���j
	DF_QS222_END,				//�yQS222�z���A���X���ɑf�ނ�n���A�˗���B���B

	//�yQS223�z�q���b�p�[�̑|��
	DF_QS223_001,				//�yQS223�z���q���b�p�[�̌Q���|�������I�@�Y�����ɖ߂��ĕ񍐂��悤�B
	DF_QS223_END,				//�yQS223�z���b�����̕񍐂��s�����I

	//�yQS230�z�C���̂���T���i�f�B�i�j
	DF_QS230_START,				//�yQS230�z���f�B�i����C���̕��Ǝv����
	DF_QS230_001,				//�yQS230�z����𔭌��A�܂����ăf�B�i�ɕ񍐂��悤�B
	DF_QS230_END,				//�yQS230�z���f�B�i�ƈꏏ�ɕ󔠂̒��g���m�F�B

	//�yQS231�z�����Ȃ�H���i�J�[�������j
	DF_QS231_START,				//�yQS231�z���J�[�������ɗ�����n���A�˗���B���B

	//�yQS300�z�F��̖؁i�T�n�h�j
	DF_QS300_START,				//�yQS300�z���T�n�h����b�𕷂����B
	DF_QS300_001,				//�yQS300�z���W�����_�����ŗǂ������Ȗ؂��������B
	DF_QS300_END,				//�yQS300�z�Y�����ɋF��̖؂�ݒu���A

	//�yQS301�z�V������̒����i���q�g�j
	DF_QS301_END,				//�yQS301�z�����q�g�ɑf�ނ�n���A�˗���B���B

	//�yQS302�z�A�M�A�M���̓���
	DF_QS302_001,				//�yQS302�z���A�M�A�M���𓢔������I�@�Y�����ɖ߂��ĕ񍐂��悤�B
	DF_QS302_END,				//�yQS302�z���b�����̕񍐂��s�����I

	//�yQS310�z����i�̐��\�e�X�g�i�G�A�����j
	DF_QS310_START,				//�yQS310�z���G�A�������玎��i��
	DF_QS310_001,				//�yQS310�z������i�̃e�X�g���ς܂����B
	DF_QS310_END,				//�yQS310�z���G�A�����ɕ񍐂��A�˗���B�������I

	//�yQS311�z�_�ɋF����i�V�X�^�[�E�j�A�j
	DF_QS311_START,				//�yQS311�z���V�X�^�[�E�j�A����b�𕷂����B
	DF_QS311_END,				//�yQS311�z���V�X�^�[�𕗌��u�˂̒���܂Ŗ����ɑ���͂�

	//�yQS400�z������[�ւ̌���i���R�b�^�j
	DF_QS400_START,				//�yQS400�z�����R�b�^����b�𕷂����B
	DF_QS400_END,				//�yQS400�z�����R�b�^��������[�Ɍm�Â����Ă�������I

	//�yQS401�z�V����͂������i���[���j
	DF_QS401_START,				//�yQS401�z�����[������b�𕷂����B
	DF_QS401_001,				//�yQS401�z���������Ńs�b�J�[�h�𔭌����邪
	DF_QS401_002,				//�yQS401�z���j���p�̋x�����Ńs�b�J�[�h�𔭌��c�c
	DF_QS401_003,				//�yQS401�z�������p�̋x�����Ńs�b�J�[�h�𔭌��c�c
	DF_QS401_END,				//�yQS401�z���x�����̋��L�X�y�[�X�Ńs�b�J�[�h�𔭌��B

	//�yQS402�z�h�{���_�̓������i�~�����_�j
	DF_QS402_END,				//�yQS402�z���~�����_����ɐH�ނ�n���A�˗���B�������I

	//�yQS500�z�E�o�D�̎��ޏW�߁i�h�M�j
	DF_QS500_END,				//�yQS500�z���h�M�ɑf�ނ�n���A�˗���B�������I

	//�yQS501�z���̔z�B�i�q���������j
	DF_QS501_START,				//�yQS501�z���q������������b�𕷂����B
	DF_QS501_END,				//�yQS501�z���Ñ��̗��𖳎��A���ɑ���͂����I

	//�yQS502�z�q�C�̂����i�N�C�i�j
	DF_QS502_START,				//�yQS502�z���N�C�i����b�𕷂����B�ȉ��̑f�ނ��W�߂悤�B
	DF_QS502_END,				//�yQS502�z���N�C�i�ɑf�ނ�n���Ĉ˗���B�������I

	//�yQS503�z�O���h���O�D�̑|��
	DF_QS503_001,				//�yQS503�z���O���h���O�D�̌Q���|�������I�@�Y�����ɖ߂��ĕ񍐂��悤�B
	DF_QS503_END,				//�yQS503�z���b�����̕񍐂��s�����I

	//�yQS510�z�̋��̉�
	DF_QS510_END,				//�yQS510�z���]�����ɂĎ��鑐��������Ɠ�����

	//�yQS520�z�^�g�̎Y�߁i�G�h�j
	DF_QS520_END_A,				//�yQS520�z���G�h�ɑf�ނ�n���Ĉ˗���B���B
	DF_QS520_END_B,				//�yQS520�z���G�h�ɑf�ނ�n���Ĉ˗���B���B

	//�yQS521�z����ȉ��G�i�^�i�g�X�j
	DF_QS521_START,				//�yQS521�z���^�i�g�X���񂩂�b�𕷂����B
	DF_QS521_001,				//�yQS521�z������ނ����B
	DF_QS521_END,				//�yQS521�z���^�i�g�X����ɋ���n���A�F�ŐH�ׂ��I

	//�yQS522�z���N�̉��t��i�I�[�X�e�B���j
	DF_QS522_START,				//�yQS522�z���I�[�X�e�B������b�𕷂����B
	DF_QS522_END,				//�yQS522�z���I�[�X�e�B���Ɂw�����L���̊y���x��n���A

	//�yQS530�z�A���V���R�E�̓���
	DF_QS530_001,				//�yQS530�z���A���V���R�E�𓢔������I�@�Y�����ɖ߂��ĕ񍐂��悤�B
	DF_QS530_END,				//�yQS530�z���b�����̕񍐂��s�����I

	//�yQS600�z�P����Z�i�J�g���[���j
	DF_QS600_END,				//�yQS600�z���J�g���[������Ƀq�C���J�l�̌��΂�n���A

	//�yQS601�z�`���Ƃւ̈˗��i�t�����c�j
	DF_QS601_START,				//�yQS601�z���t�����c����Ƙb�����B
	DF_QS601_END,				//�yQS601�z���v�����ȏ�̐��ƑΛ����邱�ƂɂȂ������̂�

	//�yQS602�z�����̒��B�i�J�V���[�j
	DF_QS602_START,				//�yQS602�z���J�V���[�Ƙb�����B�ȉ��̕���T�����B
	DF_QS602_END,				//�yQS602�z���J�V���[�ɔ��y���t��n���A

	//�yQS610�z�e�F�̈⌾�i�_�[�i�j
	DF_QS610_START,				//�yQS610�z���I���K�������ƌ�����炵��
	DF_QS610_001,				//�yQS610�z���w�����x�ɂ��Ă̓`�����m�F������
	DF_QS610_002,				//�yQS610�z�����s�A�C�M�A�X�̑吹���ɕ��ԃ����[�t��
	DF_QS610_END,				//�yQS610�z���I���K�̌`���̕i�ƂƂ��ɁA

	//�yQS611�z�V���炭�̌�
	DF_QS611_START,				//�yQS611�z���V�����B�A����Ƙb�����B
	DF_QS611_END,				//�yQS611�z���V�����B�A����ɉ��Ƃ������Ƃ��ł����I

	//�yQS612�z�F�򂹂����m���X�i�O���[���_�j
	DF_QS612_START,				//�yQS612�z���O���[���_����Ƙb�����B
	DF_QS612_END,				//�yQS612�z�����m���X�̌��Ђ�n���A�˗���B���B

	//�yQS232�z�Ŗ�̉�
	DF_QS232_START,				//�yQS232�z�@�@���h�M����b�𕷂����B
	DF_QS232_001,				//�yQS232�z�@�@���Y�����ɏo�v���Ă����Ǝv����
	DF_QS232_END,				//�yQS232�z�@�@�������̊ԁA�Y�����ł��������݂��i��

	//�yQS505�z�������̍̎�
	DF_QS505_START,				//�yQS505�z
	DF_QS505_001,				//�yQS505�z
	DF_QS505_002,				//�yQS505�z
	DF_QS505_END,				//�yQS505�z

	//�yQS613�z���̒D��
	DF_QS613_START,				//�yQS613�z
	DF_QS613_001,				//�yQS613�z
	DF_QS613_END,				//�yQS613�z

	//�yQS303�z��������I�@���ђn��
	DF_QS303_START,				//�yQS303�z
	DF_QS303_END,				//�yQS303�z�@�@�����ђn�т𐧈����A�b�̑�ʔ����𒾐É������I

	//�yQS504�z�������I�@�Z�H�J
	DF_QS504_START,				//�yQS504�z
	DF_QS504_END,				//�yQS504�z�@�@���Z�H�J�𐧈����A�b�̑�ʔ����𒾐É������I

	//�yQS303�z���ł���I�@���Ƃ̒J
	DF_QS603_START,				//�yQS603�z
	DF_QS603_END,				//�yQS603�z�@�@�����Ƃ̒J�𐧈����A�b�̑�ʔ����𒾐É������I

	DF_QS_MAX,		// �N�G�X�g�蒠�p�I�[

//--------------------------------------------------------------------
//-- �����C���蒠�p --------------------------------------------------
//--------------------------------------------------------------------

	//�Y���ҍ���
	DF_JOIN_START = 4600,		// �Y���ҍ����X�^�[�g

	DF_JOIN_LAXIA = DF_JOIN_START,			// �����N�V�������Ԃɉ�������B
	DF_JOIN_BARBAROSS,				// ���o���o���X�D���ƍĉ���B
	DF_JOIN_DOGI,					// ���h�M�ƍĉ���B
	DF_JOIN_SAHAD,					// ���T�n�h�����Ԃɉ�������B
	DF_JOIN_ALISON,					// ���A���X�����~�o�����B
	DF_JOIN_CURRAN,					// ���J�[���������~�o�����B
	DF_JOIN_KIERGAARD,				// ���L���S�[�����~�o�����B
	DF_JOIN_KATRIN,					// ���J�g���[�����~�o�����B
	DF_JOIN_NIA,					// ���V�X�^�[�E�j�A���~�o�����B
	DF_JOIN_HUMMEL,					// ���q�������������Ԃɉ�������B
	DF_JOIN_DINA,					// ���f�B�i���~�o�����B
	DF_JOIN_REJA,					// �����[�����~�o�����B
	DF_JOIN_MIRALDA,				// ���~�����_���~�o�����B
	DF_JOIN_AARON,					// ���G�A�������Y�����ɉ�������B
	DF_JOIN_LICHT,					// �����q�g���~�o�����B
	DF_JOIN_KUINA,					// ���N�C�i���~�o�����B
	DF_JOIN_RICOTTA,				// �����R�b�^�����Ԃɉ�������B
	DF_JOIN_AUSTEN,					// ���I�[�X�e�B�����~�o�����B
	DF_JOIN_SILVIA,					// ���V�����B�A���Y�����ɉ�������B
	DF_JOIN_THANATOS,				// ���^�i�g�X���Y�����ɉ�������B
	DF_JOIN_DANA,					// ���_�[�i�����Ԃɉ�������B
	DF_JOIN_KASHU,					// ���J�V���[���~�o�����B
	DF_JOIN_ED,						// ���G�h���~�o�����B
	DF_JOIN_FRANZ,					// ���t�����c���Y�����ɉ�������B
	DF_JOIN_CURRAN2,				// ���J�[�����������߂ĕY�����ɉ�������B
	DF_JOIN_GRISELDA,				// ���O���[���_���Y�����ɉ�������B


	DF_JOIN_MAX,		// �Y���ҍ����I�[

	//�x���C�x���g
	DF_SUBEV_START = 4650,		// �x���C�x���g�X�^�[�g

	DF_SUBEV_1110_REMOVE_WOOD = DF_SUBEV_START,// �����m�炸�C�݂ɂ���������ȓ|�؂�P�������B				�����͍ς�
	DF_SUBEV_1111_REMOVE_ROCK,		// �����m�炸�C�ݕl�ӂ̑���P�������B						�����͍ς�
	DF_SUBEV_2101_REMOVE_ROCK,		// �����m�炸�C�݂̐X�ɂ������y�������P�������B			�����͍ς�
	DF_SUBEV_1120_REMOVE_ROCK,		// ���勬�J����ɂ���������P�������B						�����͍ς�
	DF_SUBEV_1131_REMOVE_ROCK,		// �����m�炸�C�݂̐��ɂ���������P�������B				�����͍ς�
	DF_SUBEV_2105_REMOVE_WOOD,		// �����ƐX�̋u�ɂ���������ȓ|�؂�P�������B				�����͍ς�
	DF_SUBEV_1117_REMOVE_ROCK,		// ������l�ɂ���������P�������B						�����͍ς�
	DF_SUBEV_1107_REPAIR_BRIDGE,	// ���勬�J���扜�̉�ꂽ�݂苴���C�������B					�����͍ς�
	DF_SUBEV_1109_REPAIR_CLIFF,		// ���b�����̋u�ɂ��������ꂽ�R��⋭�����B					�����͍ς�
	DF_SUBEV_1116_REMOVE_ROCK,		// ���]�����ɂ������y����P�������B							�����͍ς�
	DF_SUBEV_6102_REMOVE_PILLAR,	// ���p���K�C�A�啽���ɂ������傫�ȐΒ���P�������B			�����͍ς�
	DF_SUBEV_1132_REMOVE_SAND,		// �����l���ɂ������D����P�������B							�����͍ς�
	DF_SUBEV_4110_SET_LADDER,		// �������炵���ɂ������R�ɓ��q��ݒu�����B				�����͍ς�
	DF_SUBEV_6107_REMOVE_SAND,		// �����f�B�j�A�Ώ��n�тɂ������y����P�������B				�����͍ς�
	DF_SUBEV_6362_REMOVE_PILLAR,	// ���n����̑匊�ɂ������傫�ȐΒ���P�������B				�����͍ς�
	DF_SUBEV_2104_REMOVE_SAND,		// �����ƐX�̋u���ɂ������y����P�������B					�����͍ς�


	DF_SUBEV_MAX,		// �x���C�x���g�I�[

//-- ���A�N�e�B�u�{�C�X�p --------------------------------------------
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
	GF_AVOICE_0212,		//���̒��ŌÑ��Ɍ��������t���O�E���C���Ŕ���
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

	//���g���p���̌}����`��
	GF_AVOICE_INTBTL002,
	GF_AVOICE_INTBTL003,
	GF_AVOICE_INTBTL005,
	GF_AVOICE_INTBTL007,
	GF_AVOICE_INTBTL012,

//���ǉ���
	GF_AVOICE_P_MARK01,
	GF_AVOICE_P_MARK02,
	GF_AVOICE_P_MARK03,

	GF_AVOICE_0219B,		//�J�G����{�点�đދp�����i����񕔒��̂݁j//���N�V����
	GF_AVOICE_0510B,		//���߂ăG���A�ɓ�������
	GF_AVOICE_0801B,		//���ɗ���������@���邢��

	GF_AVOICE_0230,			//�L���S�[���̒ǐՁA3101�ɓ�����

//��PS4�ǉ���
	GF_AVOICE_1401,			//	������~�o����C�x���g��
	GF_AVOICE_1402,			//	�͂��߂ăM�~�b�N�G���A�ɓ�������iB1���΃G���A�̃`���[�g���A����j
	GF_AVOICE_1403,			//	�n�������̓r����
	GF_AVOICE_1404,			//	�n�������Ő���~�o�|�C���g��O�ɂ�����
	GF_AVOICE_1405,			//	�{�X���j��A�ŉ��̔����J�����̂�����

	GF_AVOICE_1501,			//	�s���H�������k�ɓ������������
	GF_AVOICE_1502,			//	���삪����}�b�v�ɓ����
	GF_AVOICE_1503,			//	�n�������t���A�Q�ɓ��B�C�x���g��
	GF_AVOICE_1504,			//	��m�@�̔����C������G�^�j�A�N�G�X�g������������
	GF_AVOICE_1505,			//	�����J���\�m��������
	GF_AVOICE_1506,			//	�{�X���A���m���X�ɋ߂Â���
	GF_AVOICE_1507,			//	���̒��ŕs���̓G���牽�x���_���[�W���󂯂��
	GF_AVOICE_1508,			//	���̒��Ō���Q�ɋ߂Â���
	GF_AVOICE_1509,			//	�����J���\�m��������
	GF_AVOICE_1510,			//	���Ƃ̎��L�n�̖�Ԃ���������

	GF_AVOICE_1601,			//	�����J���\�m��������
	GF_AVOICE_1602,			//	�{�X���A���m���X�ɋ߂Â���
	GF_AVOICE_1603,			//	�֊���֌�����������
	GF_AVOICE_1604,			//	���{�̏󋵂�m��C�x���g��A�I���K�̂���ʍ��ɓ��B����O��
	GF_AVOICE_1605,			//	�A�T�ȉ��{���̗l�X�ȏꏊ�ŁE�s���i���l�g�i�j���E���N�j�j
	GF_AVOICE_1606,			//	�A�T�ȉ��{���̗l�X�ȏꏊ�ŁE�s���i���l�h�i�����E���j�j
	GF_AVOICE_1607,			//	�A�T�ȉ��{���̗l�X�ȏꏊ�ŁE�s���i���l�i�i�����E���N�j�j
	GF_AVOICE_1608,			//	�A�T�ȉ��{���̗l�X�ȏꏊ�ŁE�s���i���l�j�i�j���E���N�j�j
	GF_AVOICE_1609,			//	�A�T�ȉ��{���̗l�X�ȏꏊ�ŁE�s���i���l�k�i�j���E�N�j�j
	GF_AVOICE_1610,			//	�A�T�ȉ��{���̗l�X�ȏꏊ�ŁE�s���i���l�l�i�j���E�N�j�j
	GF_AVOICE_1611,			//	�C�I�ɉ������A������ɓ����
	GF_AVOICE_1612,			//	���X�������Ă����

	GF_AVOICE_1801,			//	�͂��߂Ă̓��΃G���A�ŁA�΂̒��ɓ��΂��ē_�����ꂽ��
	GF_AVOICE_1802,			//	�͂��߂ău���b�N�E�p�Y���G���A�ɓ�������
	GF_AVOICE_1803,			//	�͂��߂ĕ��G���A�ŉ����߂��ꂽ
	GF_AVOICE_1804,			//	�͂��߂�4�w�ɓ�������
	GF_AVOICE_1805,			//	���𔭐�������G�ɋ߂Â�����
	GF_AVOICE_1806,			//	���������Ă���G�ɋ߂Â�����
	GF_AVOICE_1807,			//	��ܑw�̗n��]�[���ɓ�������

	GF_AVOICE_1901,			//	�퓬�J�n����
	GF_AVOICE_1902,			//	�C�I��HP��60���܂Ō��炵��
	GF_AVOICE_1903,			//	�C�I��HP��30���܂Ō��炵��
	GF_AVOICE_1904,			//	��Z�Ɍ����������t�F�C�N�U����������
	GF_AVOICE_1905,			//	�C�I���n�X�^�C���ɕω������i����̂݁j
	GF_AVOICE_1906,			//	�C�I�����X�^�C���ɕω������i����̂݁j

//���ǉ�����Ƃ��͂�������




	GF_AVOICE_MAX,		// �A�N�e�B�u�{�C�X�I�[

//-- ���w���v�摜�p --------------------------------------------
	GF_HELP_START = 5300,	// �w���v�摜�p�X�^�[�g

	GF_HELP_A01 = GF_HELP_START,	// ��{����
	GF_HELP_A02,			// �Z�[�u�^���[�h
	GF_HELP_A03,			// �~�j�}�b�v
	GF_HELP_A04,			// �{�^������ꗗ
	GF_HELP_A05,			// �`������
	GF_HELP_A06,			// �����΂ƃ��g���C
	GF_HELP_A07,			// �Y����
	GF_HELP_A08,			// �f�ނ̍̎�
	GF_HELP_A09,			// �A�C�e���̎g�p
	GF_HELP_A10,			// ����
	GF_HELP_A11,			// �񕜖�̒���
	GF_HELP_A12,			// �n�}���j���[
	GF_HELP_A13,			// �n�}�̕]��
	GF_HELP_A14,			// �n�}���g�����ړ�
	GF_HELP_A15,			// �ߑ��ύX
	GF_HELP_A16,			// �ނ�@
	GF_HELP_A17,			// �ނ�A
	GF_HELP_A18,			// �ނ�}��
	GF_HELP_A19,			// �ނ�̕]��
	GF_HELP_A20,			// ����
	GF_HELP_A21,			// �A�C�e������
	GF_HELP_A22,			// ����̋���
	GF_HELP_A23,			// �N�G�X�g
	GF_HELP_A24,			// �x���C�x���g
	GF_HELP_A25,			// ���P�[�V�����|�C���g
	GF_HELP_A26,			// �Y���҂̋~�o
	GF_HELP_A27,			// ��c�n
	GF_HELP_A28,			// �`����
	GF_HELP_A29,			// �O���b�v�O���[�u�̌���
	GF_HELP_A30,			// ����΂̌���
	GF_HELP_A31,			// �����C�̌���
	GF_HELP_A32,			// �n�c���̎w�̌���
	GF_HELP_A33,			// �A���s�r�A�̎w�̌���
	GF_HELP_A34,			// ��̗�̌���
	GF_HELP_A35,			// ����̐i��
	GF_HELP_A36,			// �h��̍쐬
	GF_HELP_A37,			// �p�[�e�B�Ґ�
	GF_HELP_A38,			// ���Տ��^���p
	GF_HELP_A39,			// ���쏜�܂̎g����
	GF_HELP_A40,			// �_��
	GF_HELP_A41,			// �v���[���g�C�x���g
	GF_HELP_A42,			// �D���x
	GF_HELP_A43,			// ���
	GF_HELP_A44,			// �ӎ����L
	GF_HELP_A45,			// �Y�����̋���

	GF_HELP_B01,			// �U���ƃ^�[�Q�b�g���b�N
	GF_HELP_B02,			// ����^�_�b�V��
	GF_HELP_B03,			// �W�����v�^�W�����v�U��
	GF_HELP_B04,			// �X�L���̏C���ƃZ�b�g
	GF_HELP_B05,			// �X�L���̎g����
	GF_HELP_B06,			// �U������
	GF_HELP_B07,			// �u���C�N
	GF_HELP_B08,			// �퓬�{�[�i�X
	GF_HELP_B09,			// �h���b�v�A�C�e���Ɛ}��
	GF_HELP_B10,			// �u���C�N�I�u�W�F
	GF_HELP_B11,			// �d�w�s�q�`�X�L��
	GF_HELP_B12,			// �퓬�̃R�c
	GF_HELP_B13,			// �㋉�e�N�j�b�N
	GF_HELP_B13_B,			// �_�b�V��
	GF_HELP_B14,			// �t�B�[���h�ł̋x��
	GF_HELP_B15,			// ��Ԉُ�
	GF_HELP_B16,			// �}����@
	GF_HELP_B17,			// �}����A�i�틵�Q�[�W�j
	GF_HELP_B18,			// �}����B�i�T�|�[�g�X�L���j
	GF_HELP_B19,			// �}����C�i���U���g�]���j
	GF_HELP_B20,			// �}����D�i�����^�Đ�ɂ��āj

//0512�ǉ�
	GF_HELP_A46,			// �n�}�A�C�R���ꗗ
	GF_HELP_A47,			// �j��̖E�q

//PS4�Ńw���v
	GF_HELP_A48,			// �k�V�ނ�
	GF_HELP_A49,			// �M������΁i�Z�H�J�j
	GF_HELP_A50,			// ����̋~�o
	GF_HELP_A51,			// �_�[�i�̓�
	GF_HELP_A52,			// �G�C�~�[�̃V���b�v
	GF_HELP_A53,			// �n���������̓]��
	GF_HELP_A54,			// �s�������o�[���̕ύX
	GF_HELP_A55,			// ��ԒT��
	GF_HELP_A56,			// ���󔭌�
	GF_HELP_A57,			// ��΂̌���

	GF_HELP_B21,			// �_�[�i�̃X�^�C���`�F���W
	GF_HELP_B22,			// �n�������w���Α�x
	GF_HELP_B23,			// �O���e�B�J�̔\��
	GF_HELP_B24,			// �C�N���V�A���̔\��
	GF_HELP_B25,			// ���~�i�X�̔\��
	GF_HELP_B26,			// �C�N���V�A���̃X�^�C������
	GF_HELP_B27,			// �O���e�B�J�̃X�^�C������
	GF_HELP_B28,			// ���~�i�X�̃X�^�C������
	GF_HELP_B29,			// ������̉��
	GF_HELP_B30,			// ������̃t���[
	GF_HELP_B31,			// ���Ԃ̍s�����w��

//�w���v�ǉ���
	GF_HELP_A58,			// �_�E�����[�h�R���e���c
	GF_HELP_A59,			// �A�N�Z�T���̍쐬
	GF_HELP_A44_B,			// �ӎ����

	GF_HELP_MAX,			//�w���v���`�F�b�N�i�I�[�j

	///////////////////////////////////////////////
	// �̏W�|�C���g�t���O
	///////////////////////////////////////////////
	GF_ITEMPOINT_START = 5500,	// �A�C�e���|�C���g�X�^�[�g
	// �����g�p�h�c�͕K�������Ă��������B������̌v�Z���o���Ȃ��Ȃ�܂��B
	// ���_

	// �����̓��A
	GF_MP7302_ATKIP_01,
	GF_MP7302_ATKIP_02,
	GF_MP7303_ATKIP_01,

	// ���������C��
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

	// �X���
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

	// �X��̐X
	GF_MP1301_ATKIP_01,
	GF_MP1301_ATKIP_02,
	GF_MP1301_ATKIP_03,

	GF_MP1302_ATKIP_01,
	GF_MP1302_ATKIP_02,
	GF_MP1302_ATKIP_03,
	GF_MP1302_ATKIP_04,
	GF_MP1302_ATKIP_05,
	GF_MP1302_ATKIP_06,
//	GF_MP1302_ATKIP_07,		���ɒǉ�

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

	// ���̕l��
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

	// ��������
	GF_MP2102_ATKIP_01,
	GF_MP2102_ATKIP_02,
	GF_MP2102_ATKIP_03,
	GF_MP2102_ATKIP_04,
	GF_MP2102_ATKIP_05,
	GF_MP2102_ATKIP_06,
	GF_MP2102_ATKIP_07,
	GF_MP2102_ATKIP_08,
	GF_MP2102_ATKIP_09,
//	GF_MP2102_ATKIP_10,		//���ɒǉ�

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

	//�ߓ���
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

	// ������
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

	// �Z�H�J
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

	// �k���̕l��
	GF_MP1119_ATKIP_01,
	GF_MP1119_ATKIP_02,
	GF_MP1119_ATKIP_03,
	GF_MP1119_ATKIP_04,

	//�����̍���
	GF_MP3101_ATKIP_01,
	GF_MP3101_ATKIP_02,
	GF_MP3101_ATKIP_03,
	GF_MP3102_ATKIP_01,
	GF_MP3102_ATKIP_02,
	GF_MP3102_ATKIP_03,
	GF_MP3102_ATKIP_04,

	//�����n
	GF_MP7451_ATKIP_01,
	GF_MP7451_ATKIP_02,
	GF_MP7451_ATKIP_03,
	GF_MP7451_ATKIP_04,
	GF_MP7451_ATKIP_05,
//	GF_MP7451_ATKIP_06,	//�ǉ����͌���
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

	// ����
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

	//���l
	GF_MP1118_ATKIP_01,
	GF_MP1118_ATKIP_02,

	//�Z���̐X
	GF_MP2105_ATKIP_01,
	GF_MP2105_ATKIP_02,
	GF_MP2105_ATKIP_03,
	GF_MP2105_ATKIP_04,
	GF_MP2105_ATKIP_05,
	GF_MP2105_ATKIP_06,

	//���̊C��
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

	//����
	GF_MP3109_ATKIP_01,
	GF_MP3109_ATKIP_02,
	GF_MP3109_ATKIP_03,
	GF_MP3109_ATKIP_04,
	GF_MP3109_ATKIP_05,
	GF_MP3109_ATKIP_06,
//	GF_MP3109_ATKIP_07,
//	GF_MP3109_ATKIP_08,
//	GF_MP3109_ATKIP_09,

	//�W�����_����
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

	//����
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

	//�Ñ�̓��A
	GF_MP7401_ATKIP_01,
	GF_MP7401_ATKIP_02,
	GF_MP7401_ATKIP_03,

	//�W�����_����
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

//���_�R��
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

	//����ւ̎Q��
	GF_MP4109_ATKIP_01,
	GF_MP4109_ATKIP_02,

	//������
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

// ���Â̑啽��
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

//�ߋ��ҁE��

	GF_MP5103m_ATKIP_01,
	GF_MP5103m_ATKIP_02,
	GF_MP5103m_ATKIP_03,
	GF_MP5103m_ATKIP_04,
	GF_MP5103m_ATKIP_05,
	GF_MP5103m_ATKIP_06,
	GF_MP5103m_ATKIP_07,

	GF_MP6112m_ATKIP_01,
	GF_MP6112m_ATKIP_02,

//�g�����X��

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

//�ߋ��ҁE���E�g�����X��
	GF_MP6103m_ATKIP_01,
	GF_MP6103m_ATKIP_02,
	GF_MP6103m_ATKIP_03,
	GF_MP6103m_ATKIP_04,
	GF_MP6103m_ATKIP_05,
	GF_MP6103m_ATKIP_06,
	GF_MP6103m_ATKIP_07,
	GF_MP6103m_ATKIP_08,

//�o�n�̎Γ�
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

//��]��
	GF_MP1116_ATKIP_01,
	GF_MP1116_ATKIP_02,
	GF_MP1116_ATKIP_03,
	GF_MP1116_ATKIP_04,
//	GF_MP1116_ATKIP_05,
//	GF_MP1116_ATKIP_06,

// �C�ݓ��A_mp741x
	GF_MP7411_ATKIP_01,
	GF_MP7411_ATKIP_02,
	GF_MP7411_ATKIP_03,
	GF_MP7411_ATKIP_04,
	GF_MP7411_ATKIP_05,

//�H��D

//�n����̑匊
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

//�V�R�u��
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

//�����n��
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
//	GF_MP6113_ATKIP_08,		���ɒǉ�

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

//�ߋ��ҁE��
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

//�I�v�̋u
	GF_MP6109_ATKIP_01,
	GF_MP6109_ATKIP_02,
	GF_MP6109_ATKIP_03,
	GF_MP6109_ATKIP_04,
	GF_MP6109_ATKIP_05,
	GF_MP6109_ATKIP_06,
	GF_MP6109_ATKIP_07,
//	GF_MP6109_ATKIP_08,		//���ɒǉ�
//	GF_MP6109_ATKIP_09,
//	GF_MP6109_ATKIP_10,

// ���v������_mp641x
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

//�I�N�g�D�X�E�X�̉�L
	GF_MP6306_ATKIP_01,
	GF_MP6306_ATKIP_02,
	GF_MP6306_ATKIP_03,

//�I�N�g�D�X�E峂̉�L
	GF_MP6307_ATKIP_01,
	GF_MP6307_ATKIP_02,
	GF_MP6307_ATKIP_03,

//�I�N�g�D�X�E�V�̉�L
	GF_MP6308_ATKIP_01,
	GF_MP6308_ATKIP_02,
	GF_MP6308_ATKIP_03,

// ��Β��̕���_mp749x
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

//�ǉ�

	//�����n
	GF_MP7451_ATKIP_06,
	GF_MP7451_ATKIP_07,
	GF_MP7451_ATKIP_08,
	GF_MP7451_ATKIP_09,
	GF_MP7451_ATKIP_10,
	GF_MP7451_ATKIP_11,
	GF_MP7451_ATKIP_12,

//�ߋ��҃_�[�i�@�E�勬�J
	GF_MP3109m_ATKIP_01,
	GF_MP3110m_ATKIP_01,

//�ߋ��҇T�E
	GF_MP5103m_ATKIP_08,
	GF_MP6101m_ATKIP_01,
//�ߋ��҇V�E
	GF_MP6103m_ATKIP_09,
	GF_MP6103m_ATKIP_10,
//�ߋ��҇X�E
	GF_MP6106m_ATKIP_07,
	GF_MP6106m_ATKIP_08,
//�ǉ�
	GF_MP5101_ATKIP_05,	//���ɒǉ�
	GF_MP6113_ATKIP_08,		//���ɒǉ�
	GF_MP6109_ATKIP_08,		//���ɒǉ�
	GF_MP6109_ATKIP_09,
	GF_MP6109_ATKIP_10,
	GF_MP1302_ATKIP_07,		//���ɒǉ�
	GF_MP2102_ATKIP_10,		//���ɒǉ�
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

// PS4�ǉ���
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
	// �n������
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
	// ���n������
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

	// ����ɒǉ���
	GF_MP1302t2_ATKIP_13,
	GF_MP1302t2_ATKIP_14,

	GF_ITEMPOINT_MAX,			// �A�C�e���|�C���g�����܂Łi�t���O���`�F�b�N�p�Ȃ̂ŁAGF_RESERVE_START���O�ɒu���悤�Ɂj

//���M�������[���[�h�p------------------------------------------------------------------
	GF_GALL_START = 6535,	// ���ݎg�p��=108

	GF_GALL_CLEAR_ED3 = GF_GALL_START,		//�^ED�N���A �L�����E�G�N�X�g���C���X�g�A���[�r�[�J��

	GF_GALL_EV_PL_01,			// M00S001:�A�h�����h�M�o��
	GF_GALL_EV_PL_02,			// M00S010:�o���o���X�o��
	GF_GALL_EV_PL_03,			// M00S050:����ȐG��Ɛ퓬����
	GF_GALL_EV_PL_04,			// M00S060:�����o���f�B�A�����v����
	GF_GALL_EV_01_01,			// M01S000:�Z�C�������ɕY������
	GF_GALL_EV_01_02,			// M01S030:���N�V���ɑ�������
	GF_GALL_EV_01_03,			// M01S180:�Ñ��Ƒ���
	GF_GALL_EV_01_04,			// M01S181:�T�n�h������
	GF_GALL_EV_02_01,			// M02S101:�͂��߂Ė�c������Q
	GF_GALL_EV_02_02,			// M02S260:�q���������Əo�
	GF_GALL_EV_02_03,			// M02S271:mp1121�Ŗ�c����Q
	GF_GALL_EV_02_04,			// M02S320:�q������������������
	GF_GALL_EV_02_05,			// M02S331:�N�I�J�O�̖�c�Q
	GF_GALL_EV_02_06,			// M02S361:���ёO�̖�c�Q
	GF_GALL_EV_02_07,			// M02S490:���N�V���Ɠ�l����Řb��
	GF_GALL_EV_02_08,			// M02S560:�J�[�����������S����
	GF_GALL_EV_02_09,			// M02S650:�o���o���X���v�����𕉂�
	GF_GALL_EV_02_10,			// M02S670:�L���S�[�������S
	GF_GALL_EV_02_11,			// M02S680:�o���o���X�����𗎂Ƃ�
	GF_GALL_EV_03_01,			// M03S010:�_�[�i�@ �A���Ղ̐������󂯂�
	GF_GALL_EV_03_02,			// M03S031:�_�[�i�@ �A���̋V�Q
	GF_GALL_EV_03_03,			// M03S111:�_�[�i�A �T���C�Ƃ̕ʂ�Q
	GF_GALL_EV_03_04,			// M03S150:�W�����_�����ő�^�Ñ��ɑ���
	GF_GALL_EV_03_05,			// M03S151:���R�b�^���������ɓ���
	GF_GALL_EV_03_06,			// M03S160:���R�b�^�̘b�𕷂�
	GF_GALL_EV_03_07,			// M03S250:���߂ČÑ���œ|����
	GF_GALL_EV_03_08,			// M03S270:�����^�Ñ��o��
	GF_GALL_EV_03_09,			// M03S290:�W�����_�����̒���ɓ�������
	GF_GALL_EV_04_01,			// M04S060:�_�[�i�B �V�����T���C�ւ̉y��
	GF_GALL_EV_04_02,			// M04S080:���R�b�^���s���s���ɂȂ�
	GF_GALL_EV_04_03,			// M04S121:���s�O�Ŗ�c����
	GF_GALL_EV_04_04,			// M04S132:�ߋ��T ���߂Đ����ΑO�ɐA��
	GF_GALL_EV_04_05,			// M04S170:���̏�Ń^�i�g�X�ɏo�
	GF_GALL_EV_04_06,			// M04S260:�_�[�i�𔭌�����
	GF_GALL_EV_05_01,			// M05S010:�_�[�i���}����ɎQ������
	GF_GALL_EV_05_02,			// M05S130:�_�[�i�����m���X���N������
	GF_GALL_EV_05_03,			// M05S147:�G���t�Z���A�����o�q����
	GF_GALL_EV_05_04,			// M05S171:�L���v�e���E���[�h�ƕʂ��
	GF_GALL_EV_05_05,			// M05S230:���ł������{����������
	GF_GALL_EV_05_06,			// M05S280:�I�P�A�m�X��������J�n����
	GF_GALL_EV_05_07,			// M05S293:�I�P�A�m�X�ɏ�������
	GF_GALL_EV_05_08,			// M05S310:����Ń_�[�i�Ƙb��
	GF_GALL_EV_05_09,			// M05S320:�ߋ��W�|�Q�@���̗�����\�m����
	GF_GALL_EV_05_10,			// M05S341:�ߋ��W�|�Q�@��̗���Ƃ̐퓬��
	GF_GALL_EV_05_11,			// M05S381:�_�[�i�ɒǂ����Q
	GF_GALL_EV_05_12,			// M05S421:�揊�O�Ŗ�c����
	GF_GALL_EV_05_13,			// M05S460:�ǉ�̊Ԃɂ��ǂ蒅��
	GF_GALL_EV_06_01,			// M06S044:�R��O�Ō��l�����ɑ�������Q
	GF_GALL_EV_06_02,			// M06S070:�ߋ��Y�@�_�[�i�������𕕈󂷂�
	GF_GALL_EV_06_03,			// M06S203:�T���C���z�O�����߂�
	GF_GALL_EV_06_04,			// M06S210:�z���~�X�g���e�B������肷��
	GF_GALL_EV_06_05,			// M06S230:�s�I���̊ԁt�ւ̔����J��
	GF_GALL_EV_06_06,			// M06S240:õ���ޥ����۸��тƂ̐킢
	GF_GALL_EV_06_07,			// M06S241:õ���ޥ����۸��тƂ̐킢�Q
	GF_GALL_EV_EL_01,			// M07S000:�Y�����ŃA�h�����ڂ��o�܂�
	GF_GALL_EV_EL_02,			// M07S010:�d�c�T ���@�Ղ�K��違�E�o
	GF_GALL_EV_EL_03,			// M07S040:�d�c�U ��n�_�}�C�A�Ƃ���
	GF_GALL_EV_EL_04,			// M07S040:�d�c�V ��n�_�}�C�A�Ƃ���
	GF_GALL_EV_EL_05,			// M07S100:�d�c�V �s�͂��܂�̐[���t�˔j
	GF_GALL_EV_EL_06,			// M07S121:�d�c�V �Z�C��������E�o����

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
	
	GF_GALL_EVIMG_01,			// p_10000 �A�h���̖��T[�q���̏���]�F������グ��_�[�i
	GF_GALL_EVIMG_02,			// p_10001 �A�h���̖��T[�q���̏���]�F�U��Ԃ�_�[�i
	GF_GALL_EVIMG_03,			// p_10010 �A�h���̖��T[���@�̎g�҂���]
	GF_GALL_EVIMG_04,			// p_10020 �A�h���̖��U[�ޏ��̌��҂���]
	GF_GALL_EVIMG_05,			// p_10030 �A�h���̖��U[�_�[�i�ƛޏ�]
	GF_GALL_EVIMG_06,			// p_10031 �A�h���̖��U[�_�[�i�ƛޏ�]�i�ޏ��Ȃ������j
	GF_GALL_EVIMG_07,			// p_10032 �A�h���̖��U[�D�F�̗\�m] �}�C�A�̎p
	GF_GALL_EVIMG_08,			// p_10040 �A�h���̖��U[�O�l�̌���]
	GF_GALL_EVIMG_09,			// p_10050 �A�h���̖��V[�ґz���Ă���_�[�i]�F�Җ�
	GF_GALL_EVIMG_10,			// p_10051 �A�h���̖��V[�ґz���Ă���_�[�i]�F�J��
	GF_GALL_EVIMG_11,			// p_10070 �A�h���̖��W[�ޏ��̌v�炢]
	GF_GALL_EVIMG_12,			// p_10080 �A�h���̖��X[�X���삯��_�[�i����]
	GF_GALL_EVIMG_13,			// p_10090 �A�h���̖��X[����ɗ��_�[�i����]
	GF_GALL_EVIMG_14,			// p_10120 �A�h���̖��Y[�ޏ��I��̋V]
	GF_GALL_EVIMG_15,			// p_10130 �A�h���̖��Y[�T���C�ƃI���K]
	GF_GALL_EVIMG_16,			// p_10100 ���N�V����z[���ւ̑z��]
	GF_GALL_EVIMG_17,			// p_10113 ���N�V����z[���Y�E�F���Ƃ̋��]�F�̒n���D�̗ߏ�
	GF_GALL_EVIMG_18,			// p_10140 �_�[�i��z[��Y����c���_�[�i]
	GF_GALL_EVIMG_19,			// p_10150 �_�[�i��z[�_�[�i�ƕ�]
	GF_GALL_EVIMG_20,			// p_10160 �_�[�i��z[��̎�]
	GF_GALL_EVIMG_21,			// p_10190 �_�[�i�t���b�V���o�b�N[��̎�]�F�Ă��������
	GF_GALL_EVIMG_22,			// p_10170 �q����������z�u�o�z�v
	GF_GALL_EVIMG_23,			// p_10180 �q����������z�u�e�q�̍ĉ�v
	GF_GALL_EVIMG_24,			//p_10200 �_�[�i�҃��m���X�|�[�g���[�g
	GF_GALL_EVIMG_25,			//p_10220 �_�[�i�҃��m���X�|�[�g���[�g
	GF_GALL_EVIMG_26,			//p_10230 �_�[�i�҃��m���X�|�[�g���[�g
	GF_GALL_EVIMG_27,			//p_10240 �_�[�i�҃��m���X�|�[�g���[�g
	GF_GALL_EVIMG_28,			//p_10250 �_�[�i�҃��m���X�|�[�g���[�g
	GF_GALL_EVIMG_29,			//p_10260,p_10261 �_�[�i�҃��m���X�|�[�g���[�g

	//�ǉ����i���[�r�[�����J���j
	GF_GALL_MOVIE_01,				//	�I�[�v�j���O		���ŏ�����J�������̂Ō���
	GF_GALL_MOVIE_02,				//	�A���Ղ̗\�m
	GF_GALL_MOVIE_03,				//	�D�F�̗\�m
	GF_GALL_MOVIE_04,				//	���s���͏�ǓW�J
	GF_GALL_MOVIE_05,				//	覐ΌQ�̔�
	GF_GALL_MOVIE_06,				//	���͏�ǌ���
	GF_GALL_MOVIE_07,				//	���N�����T�̏���
	GF_GALL_MOVIE_08,				//	�ʏ�G���f�B���O���[��
	GF_GALL_MOVIE_09,				//	�^�G���f�B���O���[��

	//�ǉ����i�ߋ��҃|�[�g���[�g�̒ǉ��j
	GF_GALL_EVIMG_30,			//���m���X�|�[�g���[�g����
	GF_GALL_EVIMG_31,			//���m���X�|�[�g���[�g����
	GF_GALL_EVIMG_32,			//���m���X�|�[�g���[�g����
	GF_GALL_EVIMG_33,			//���m���X�|�[�g���[�g����

	GF_GALL_CLEAR_ED1,			//�o�b�h�G���h�E�m�[�}���G���h
	GF_GALL_CLEAR_ED4,			//�^�d�c�{�G�^�j�A�N�G�X�g�S�N���A

	GF_GALL_END,
	// ��GF_GALL_END - GF_GALL_START < SYSTEMSAVE_GALLERY_FLAG_MAX(256) �ł���K�v������B

//�� �T�u�V�X�e���p------------------------------------------------------------------
	GF_MENUSAVE_PAST_START = 6845,	// 

	GF_MENUSAVE_PAST_TAB1 = GF_MENUSAVE_PAST_START,			// �ߋ��҃��j���[�ۑ��p
	GF_MENUSAVE_PAST_ITEM_ITEM,
	GF_MENUSAVE_PAST_SCR_ITEM,

	GF_MENUSAVE_PAST_MAX,
	GF_SHOP_VOICE_INTERCEPT,				// �}����̃V���b�v�{�C�X��炷

	GF_SHOP_GETONCE_START = 6850,			// ��i���擾�Ǘ��X�^�[�g�i�v���O�����Ńr�b�g����B�ő�96�z��j
	GF_SHOP_GETONCE_00 = GF_SHOP_GETONCE_START,
	GF_SHOP_GETONCE_01,
	GF_SHOP_GETONCE_02,
	GF_DIARY_SHOP_INFO = 6853,				// �f�ގ蒠�ɍڂ���V���b�v�i�v���O�����Ńr�b�g����j
	
	GF_VIRTURE_POINT,						// ���|�C���g
	
	GF_DR_CHARA_START = 6855,				// �l�������t���O�X�^�[�g�i�v���O�����Ńr�b�g����B�ő�60�l�j
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

	GF_SHOP_VOICE_ALISON,					// �A���X���̃V���b�v�{�C�X��炷
	GF_SHOP_VOICE_USED1,					// �d���g�p�`�F�b�N�P
	GF_SHOP_VOICE_USED2,					// �d���g�p�`�F�b�N�Q

	GF_GALLERY_EVENT_RETURN,				// �M�������[�C�x���g����߂�����


	GF_DR_CHARA_MAX,					// GF_DR_CHARA_START�ɑ΂���I�[�iGF_LIKELV_START�̐��𒴂��Ă��Ȃ�������p�j

	GF_LIKELV_START = 6870,					// �D���x���x���X�^�[�g�i�����̕��т�NPC_�`�Ɠ����ɂ��ׂ��j	�i0�`3�F�\����ł�LV1�`LV4�ɂȂ�j
		// NPC
	GF_LIKELV_BARBAROSS = GF_LIKELV_START,	// �o���o���X�D��
	GF_LIKELV_DOGI,							// �h�M
	GF_LIKELV_ALISON,						// �A���X��
	GF_LIKELV_KIERGAARD,					// �L���S�[��
	GF_LIKELV_CURRAN,						// �J�[������
	GF_LIKELV_KATRIN,						// �J�g���[��
	GF_LIKELV_DINA,							// �f�B�i
	GF_LIKELV_AARON,						// �G�A����
	GF_LIKELV_LICHT,						// ���q�g
	GF_LIKELV_REJA,							// ���[��
	GF_LIKELV_MIRALDA,						// �~�����_
	GF_LIKELV_KUINA,						// �N�C�i
	GF_LIKELV_NIA,							// �V�X�^�[�j�A
	GF_LIKELV_KASHU,						// �J�V���[
	GF_LIKELV_FRANZ,						// �t�����c
	GF_LIKELV_THANATOS,						// �^�i�g�X
	GF_LIKELV_ED,							// �G�h				// ���Ԃ�s��
	GF_LIKELV_GRISELDA,						// �O���[���_
	GF_LIKELV_AUSTEN,						// �I�[�X�e�B��		// ���Ԃ�s��
	GF_LIKELV_SILVIA,						// �V���r�A			// ���Ԃ�s��
		// ��l
	GF_LIKELV_PARO,							// ���g���E�p��
	GF_LIKELV_SKILLMONKY,					// �X�L���U��
	GF_LIKELV_BALAENICEPS_REX,				// �n�V�r���R�E
		// �v���C���[
	GF_LIKELV_ADOL,							// �A�h��			// ���̏����ƍ��킹��ׂɓ���Ă���B
	GF_LIKELV_LAXIA,						// ���N�V��
	GF_LIKELV_SAHAD,						// �T�n�h
	GF_LIKELV_HUMMEL,						// �q��������
	GF_LIKELV_RICOTTA,						// ���R�b�^
	GF_LIKELV_DANA,							// �_�[�i
	GF_LIKELV_DANACOPY,						// �_�[�i�o�b�N�A�b�v�R�s�[
	GF_LIKELV_DANA2,						// �_�[�i�Q
	GF_LIKELV_DANA3,						// �_�[�i�R
	GF_LIKELV_DANAOLD,						// �ߋ��҃_�[�i�o�b�N�A�b�v�R�s�[

	GF_LIKELV_RESERVE10,					// ���U�[�u10
	GF_LIKELV_RESERVE11,					// ���U�[�u11
	GF_LIKELV_RESERVE12,					// ���U�[�u12
	GF_LIKELV_RESERVE13,					// ���U�[�u13
	GF_LIKELV_RESERVE14,					// ���U�[�u14
	GF_LIKELV_RESERVE15,					// ���U�[�u15
	GF_LIKELV_RESERVE16,					// ���U�[�u16
	GF_LIKELV_RESERVE17,					// ���U�[�u17
	GF_LIKELV_RESERVE18,					// ���U�[�u18
	GF_LIKELV_RESERVE19,					// ���U�[�u19

	GF_LIKELV_MAX,	// 44�l

	GF_SHOP_START = 6915,		//�V���b�v����NPC�̃A�C�R���p�@�Q�[���J�n����ɗ��Ă�
	GF_SHOP_END,				//�V���b�v����NPC�̃A�C�R���p�@�Q�[�����A��΂ɗ��ĂȂ�

	GF_FAME_POINT,				//�����l

	GF_INTERCEPT_STAGEID,		// �}����X�e�[�W�h�c�i�}���폀�����ȊO�͖����j
	GF_INTERCEPT_LEFTTIME,		// �}����J�n�܂ł̎c�莞��
	GF_INTERCEPT_LASTSTAGEID,	// �Ō�ɍs�����}����X�e�[�W�h�c�iINTERCEPT_STAGE01���j	���}����I�����ɐݒ肷��ȊO�ł́A�v���O�����ł͈�ؐG��Ȃ��̂œK�X INTERCEPT_STAGE_NONE �ɐݒ肷�铙���ĉ������B
	GF_INTERCEPT_LASTRESULT,	// �Ō�ɍs�����}����̌��ʁi0:�s�k	1:�����j

	// 
	GF_INTERCEPT_MAX,

	// �}����A�������
	GF_INTERCEPT_BUILDUP_START = 6923,
	// ���̊Ԃ̃t���O�͌}���틭�����Ɏg���̂ŁA����ȊO�Ŏg���Ă͂����Ȃ�
	GF_INTERCEPT_BUILDUP_END = 6924,

	GF_MENUSAVE_START = 6925,	// ���j���[�̍��ڈʒu�ێ��֘A�̃Z�[�u�p
	GF_MENUSAVE_TAB1 = GF_MENUSAVE_START,// [�^�uindex]�A�C�e���E�����^�X�g�[���[�̃e�L�X�g�ʒu
	GF_MENUSAVE_ITEM_ITEM,		// [����ID]�g�p�A�C�e���E�����A�C�e��
	GF_MENUSAVE_ITEM_DIARY1,	// [����ID]�X�g�[���[�E�N�G�X�g
	GF_MENUSAVE_ITEM_DIARY2,	// [����ID]�l���EA�{�C�X
	GF_MENUSAVE_ITEM_DIARY3,	// [����ID]�����E�ނ�
	GF_MENUSAVE_ITEM_DIARY4,	// [����ID]�����X�^�[�E�f��
	GF_MENUSAVE_ITEM_DIARY5,	// [����ID]�w���v�E�ŐV�X�g�[���[�t���O
	GF_MENUSAVE_SCR_DIARY1,		// [���ڈʒu]�X�g�[���[�E�N�G�X�g
	GF_MENUSAVE_SCR_DIARY2,		// [���ڈʒu]�l���EA�{�C�X
	GF_MENUSAVE_SCR_DIARY3,		// [���ڈʒu]�����E�ނ�
	GF_MENUSAVE_SCR_DIARY4,		// [���ڈʒu]�����X�^�[�E�f��
	GF_MENUSAVE_SCR_DIARY5,		// [���ڈʒu]�w���v�E(�\��)
	GF_MENUSAVE_SCR_ITEM,		// [���ڈʒu]����E�ꗗ
	GF_MENUSAVE_RESERVE01,

		
	GF_MENUSAVE_END,		// ���j���[�̍��ڈʒu�ێ��֘A�̃Z�[�u�p�����܂�

	GF_NLTIPS_START = 6940,		// NowLoading���̃`�b�v�X�������Ƃ���ۑ��p
	// ���̊Ԃ̃t���O�̓`�b�v�X�Ǘ��Ɏg���̂ŁA����ȊO�ł͎g���Ă͂����Ȃ�
	GF_NLTIPS_END = 6949,

	// ���^�C���A�^�b�N�t���O�i�Z���Z�^����̕��BYs8�ł͓�Փx�ʂŕ⊮�������̂ŁA�������ƃt���O�������Ȃ������̂ŁA�����͎g��Ȃ��B�������A�Z�[�u�f�[�^�ێ��ׁ̈A���U�[�u�Ƃ��Ēu���Ă���j
	__GF_TIMEATK_START = 6950,	// �^�C���A�^�b�N�p�t���O

	__GF_TIMEATK_B900,			// �A�_�}���e�B�X
	__GF_TIMEATK_B901,			// �h�X�u���C�r�[
	__GF_TIMEATK_B000,			// �V���R�c����
	__GF_TIMEATK_B050,			// �w�r�h�����[
	__GF_TIMEATK_B001,			// �k�d�c�A���R�E�Q
	__GF_TIMEATK_B002,			// �_�r�b�h�\��
	__GF_TIMEATK_B003,			// �K�[�f�B�A���P
	__GF_TIMEATK_B0033,			// �K�[�f�B�A���R
	__GF_TIMEATK_B0042,			// �\�����K�����@�P
	__GF_TIMEATK_B052,			// �Q���R�L���O
	__GF_TIMEATK_B054,			// �K�f�B�X
	__GF_TIMEATK_B053,			// �o�~�[
	__GF_TIMEATK_B004,			// �\�����K�����@�Q
	__GF_TIMEATK_B005,			// �S���{�X
	__GF_TIMEATK_B006,			// ���G���f�B�[��
	__GF_TIMEATK_B055,			// ���̒��{�X
	__GF_TIMEATK_B056,			// ����̒��{�X
	__GF_TIMEATK_B057,			// �����̒��{�X

	GF_TIMEATK_MENUCONTROL,		// �^�C���A�^�b�N���j���[����p
	GF_TIMEATK_CTFLAG,			// ���݂̃x�X�g�X�R�A��ۑ����ׂ��t���O�ԍ�
	GF_TIMEATK_GAMERANK,		// ���ݑI�𒆂̓�Փx (ETIMEATK_GAMERANK)
	GF_TIMEATK_STAGENO,			// ���ݑI�𒆂̃X�e�[�W�h�c

	GF_TIMEATK_RETRY,			// �{�X���b�V�����g���C��
	GF_TIMEATK_GAMEMODE,		// ���ݑI�𒆂̃^�C���A�^�b�N���[�h (ETIMEATK_GAMEMODE)

	// �ȉ��A���R�[�h�A�g���t�B�[�p
	GF_LASTMAXMONEY,			// �ߋ��ő及���f�n�k�c
	GF_TOTALMOVE,				// ���ړ�����
	GF_FLASHGUARDCT,			// �t���b�V���K�[�h��
	GF_FLASHMOVECT,				// �t���b�V�����[�u��
	GF_BREAKCT,					// �u���C�N��
	GF_SKILLFINISHCT,			// �X�L���t�B�j�b�V����
	GF_EXTRASKILLCT,			// �G�N�X�g���X�L���g�p��

	GF_ADOLPLAYTIME,			// �A�h���v���C����
	GF_LAXIAPLAYTIME,			// ���N�V���v���C����
	GF_SAHADPLAYTIME,			// �T�n�h�v���C����
	GF_HUMMELPLAYTIME,			// �q���������v���C����
	GF_RICOTTAPLAYTIME,			// ���R�b�^�v���C����
	GF_DANAPLAYTIME,			// �_�[�i�v���C����
	GF_DANACOPYPLAYTIME,		// �i�g��Ȃ��j�_�[�i�o�b�N�A�b�v�R�s�[�v���C����
	GF_DANA2PLAYTIME,			// �i�g��Ȃ��j�_�[�i�Q�v���C����
	GF_DANA3PLAYTIME,			// �i�g��Ȃ��j�_�[�i�R�v���C����
	GF_DANAOLDPLAYTIME,			// �i�g��Ȃ��j�ߋ��҃_�[�i�o�b�N�A�b�v�R�s�[�v���C����

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

	GF_TIMEATK_NODMG,			// �^�C���A�^�b�N�m�[�_���[�W�`�F�b�N

//-------------------------------------------------------------------------------
//�� Tips �蒠�ŕ\�����ėǂ����t���O
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
//�� �g���t�B�[�֘A�t���O

	// �ߋ��҃_���W�������j��
	GF_TROPHY_ETERNIADUNGEON_START,
	GF_TROPHY_ETERNIADUNGEON_01,
	GF_TROPHY_ETERNIADUNGEON_02,
	GF_TROPHY_ETERNIADUNGEON_03,
	GF_TROPHY_ETERNIADUNGEON_04,
	GF_TROPHY_ETERNIADUNGEON_05,
	GF_TROPHY_ETERNIADUNGEON_06,
	GF_TROPHY_ETERNIADUNGEON_END,

	// �ߋ��Ґ���~�o��
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
	GF_DUMMY_ZERO = 8099,		// �_�~�[����p�t���O�i�K���O�������Ă��鎖���ۏ؂���Ă���t���O�Ƃ��ė��p�j
//�� �^�C���A�^�b�N�p------------------------------------------------------------------
	GF_TIMEATK_START = 8100,	// 250�\��	�i�l���ʁ~�{�X���~��Փx�j
								//	���ʏ�
								//		�l��	�@�R	�i�P�l�^�Q�l�^�R�l�j
								//		�{�X��	�S�O	�i�R�R��{�{�X���b�V���{���U�[�u���U�j
								//		��Փx	�@�T
								//	------------------
								//		���v	 600
								//
								//	���_�[�i��
								//		�l��	�@�P	�i�_�[�i�̂݁j
								//		�{�X��	�P�O	�i�V��{�{�X���b�V���{���U�[�u���Q�j
								//		��Փx	�@�T
								//	------------------
								//		���v	  50
								//
								//	������҃{�X�ʃ^�C���A�^�b�N�����o�[�ۑ��p�i5bit�ŊǗ��B�R�l���[�h15bit	�Q�l���[�h10bit �P�l���[�h5bit �v30bit�j
								//		�{�X��	�S�O
								//		��Փx	�@�T
								//	------------------
								//		���v	 200
			
								//	�t���O850�͕K�v

	// ���ŏ�ʃr�b�g�������Ă���ƁA�X�V�����\���ɂȂ�
	// �����j���[���鎞�ɍŏ�ʃr�b�g�͑S�č~���B

	// �����3�l

		// EASY3�l�p
	GF_TIMEATK_EASY_ST = GF_TIMEATK_START,
	GF_TIMEATK_EASY_M0111 = GF_TIMEATK_EASY_ST,	// �C�[�W�[00�A�P���A�r�t�e���U
	GF_TIMEATK_EASY_B150,	// �C�[�W�[01�A�P���A�A���@���h���M��
	GF_TIMEATK_EASY_B100,	// �C�[�W�[02�A�Q���A�Z���y���^�X
	GF_TIMEATK_EASY_B000,	// �C�[�W�[03�A�Q���A�N�����I��
	GF_TIMEATK_EASY_B101B,	// �C�[�W�[04�A�Q���A�����u���Q�E�X
	GF_TIMEATK_EASY_B001,	// �C�[�W�[05�A�Q���A�O���K���`����
	GF_TIMEATK_EASY_B102,	// �C�[�W�[06�A�Q���A�}�K�}���h��
	GF_TIMEATK_EASY_B002,	// �C�[�W�[07�A�Q���A���X�s�X�[�X
	GF_TIMEATK_EASY_B152,	// �C�[�W�[08�A�Q���A�L���S�[��
	GF_TIMEATK_EASY_B154,	// �C�[�W�[09�A�R���A�A���@���h���M��
	GF_TIMEATK_EASY_B003,	// �C�[�W�[10�A�R���A�M�A�X�o�[��
	GF_TIMEATK_EASY_B006,	// �C�[�W�[11�A�S���A�u���L�I��
	GF_TIMEATK_EASY_B104,	// �C�[�W�[12�A�T���A�G�N�X���[�e��
	GF_TIMEATK_EASY_B004,	// �C�[�W�[13�A�T���A�J�����F���X
	GF_TIMEATK_EASY_B103,	// �C�[�W�[14�A�T���A�s���e�B�X�A�j�}
	GF_TIMEATK_EASY_B106,	// �C�[�W�[15�A�T���A�V�G���J���g�D�X
	GF_TIMEATK_EASY_B007,	// �C�[�W�[16�A�T���A�I�P�A�m�X
	GF_TIMEATK_EASY_B105,	// �C�[�W�[17�A�T���A�h�N�T�E�O���G��
	GF_TIMEATK_EASY_B005,	// �C�[�W�[18�A�T���A�o�V���E�X
	GF_TIMEATK_EASY_B012,	// �C�[�W�[19�A�U���A���E�G�����g����
	GF_TIMEATK_EASY_B112,	// �C�[�W�[20�A�U���A�A�j���X�E�q�h�D��
	GF_TIMEATK_EASY_B110,	// �C�[�W�[21�A�U���A�A�j���X�E�~�m�X
	GF_TIMEATK_EASY_B111,	// �C�[�W�[22�A�U���A�A�j���X�E�l�X�g�[��
	GF_TIMEATK_EASY_B008,	// �C�[�W�[23�A�U���A�A�j���X�E�E�[��
	GF_TIMEATK_EASY_B021_1,	// �C�[�W�[24�A�U���A�e�I�X�E�f�E�G���h���O�����P
	GF_TIMEATK_EASY_B021_2,	// �C�[�W�[25�A�U���A�e�I�X�E�f�E�G���h���O�����Q
	GF_TIMEATK_EASY_B021_3,	// �C�[�W�[26�A�U���A�e�I�X�E�f�E�G���h���O�����R
	GF_TIMEATK_EASY_B009,	// �C�[�W�[28�A�V���A�͂��܂�̖��E�q
	GF_TIMEATK_EASY_B010,	// �C�[�W�[28�A�V���A�͂��܂�̖��E�e
	GF_TIMEATK_EASY_B155,	// �C�[�W�[29�A�V�����B�A
	GF_TIMEATK_EASY_B151,	// �C�[�W�[30�A�}�X�^�[�R���O
	GF_TIMEATK_EASY_B153,	// �C�[�W�[31�A�U���A���t�H���V����
	GF_TIMEATK_EASY_B170,	// �C�[�W�[32�A�U���A�������F�Q�T�ڃ_���W�����{�X
	__GF_TIMEATK_EASY_RSV33,// �C�[�W�[34�A���U�[�u33
	__GF_TIMEATK_EASY_RSV34,// �C�[�W�[34�A���U�[�u34
	__GF_TIMEATK_EASY_RSV35,// �C�[�W�[35�A���U�[�u35
	__GF_TIMEATK_EASY_RSV36,// �C�[�W�[36�A���U�[�u36
	__GF_TIMEATK_EASY_RSV37,// �C�[�W�[37�A���U�[�u37
	__GF_TIMEATK_EASY_RSV38,// �C�[�W�[38�A���U�[�u38
	GF_TIMEATK_EASY_RUSH,	// �C�[�W�[39�A�{�X���b�V��

	GF_TIMEATK_EASY_ED,

		// NORMAL3�l�p
	GF_TIMEATK_NORMAL_ST = GF_TIMEATK_EASY_ED,
	GF_TIMEATK_NORMAL_M0111 = GF_TIMEATK_NORMAL_ST,	// �m�[�}��00�A�P���A�r�t�e���U
	GF_TIMEATK_NORMAL_B150,		// �m�[�}��01�A�P���A�A���@���h���M��
	GF_TIMEATK_NORMAL_B100,		// �m�[�}��02�A�Q���A�Z���y���^�X
	GF_TIMEATK_NORMAL_B000,		// �m�[�}��03�A�Q���A�N�����I��
	GF_TIMEATK_NORMAL_B101B,	// �m�[�}��04�A�Q���A�����u���Q�E�X
	GF_TIMEATK_NORMAL_B001,		// �m�[�}��05�A�Q���A�O���K���`����
	GF_TIMEATK_NORMAL_B102,		// �m�[�}��06�A�Q���A�}�K�}���h��
	GF_TIMEATK_NORMAL_B002,		// �m�[�}��07�A�Q���A���X�s�X�[�X
	GF_TIMEATK_NORMAL_B152,		// �m�[�}��08�A�Q���A�L���S�[��
	GF_TIMEATK_NORMAL_B154,		// �m�[�}��09�A�R���A�A���@���h���M��
	GF_TIMEATK_NORMAL_B003,		// �m�[�}��10�A�R���A�M�A�X�o�[��
	GF_TIMEATK_NORMAL_B006,		// �m�[�}��11�A�S���A�u���L�I��
	GF_TIMEATK_NORMAL_B104,		// �m�[�}��12�A�T���A�G�N�X���[�e��
	GF_TIMEATK_NORMAL_B004,		// �m�[�}��13�A�T���A�J�����F���X
	GF_TIMEATK_NORMAL_B103,		// �m�[�}��14�A�T���A�s���e�B�X�A�j�}
	GF_TIMEATK_NORMAL_B106,		// �m�[�}��15�A�T���A�V�G���J���g�D�X
	GF_TIMEATK_NORMAL_B007,		// �m�[�}��16�A�T���A�I�P�A�m�X
	GF_TIMEATK_NORMAL_B105,		// �m�[�}��17�A�T���A�h�N�T�E�O���G��
	GF_TIMEATK_NORMAL_B005,		// �m�[�}��18�A�T���A�o�V���E�X
	GF_TIMEATK_NORMAL_B012,		// �m�[�}��19�A�U���A���E�G�����g����
	GF_TIMEATK_NORMAL_B112,		// �m�[�}��20�A�U���A�A�j���X�E�q�h�D��
	GF_TIMEATK_NORMAL_B110,		// �m�[�}��21�A�U���A�A�j���X�E�~�m�X
	GF_TIMEATK_NORMAL_B111,		// �m�[�}��22�A�U���A�A�j���X�E�l�X�g�[��
	GF_TIMEATK_NORMAL_B008,		// �m�[�}��23�A�U���A�A�j���X�E�E�[��
	GF_TIMEATK_NORMAL_B021_1,	// �m�[�}��24�A�U���A�e�I�X�E�f�E�G���h���O�����P
	GF_TIMEATK_NORMAL_B021_2,	// �m�[�}��25�A�U���A�e�I�X�E�f�E�G���h���O�����Q
	GF_TIMEATK_NORMAL_B021_3,	// �m�[�}��26�A�U���A�e�I�X�E�f�E�G���h���O�����R
	GF_TIMEATK_NORMAL_B009,		// �m�[�}��27�A�V���A�͂��܂�̖��E�q
	GF_TIMEATK_NORMAL_B010,		// �m�[�}��28�A�V���A�͂��܂�̖��E�e
	GF_TIMEATK_NORMAL_B155,		// �m�[�}��29�A�V�����B�A
	GF_TIMEATK_NORMAL_B151,		// �m�[�}��30�A�}�X�^�[�R���O
	GF_TIMEATK_NORMAL_B153,		// �m�[�}��31�A�U���A���t�H���V����
	GF_TIMEATK_NORMAL_B170,	// �m�[�}��32�A�U���A�������F�Q�T�ڃ_���W�����{�X
	__GF_TIMEATK_NORMAL_RSV33,	// �m�[�}��34�A���U�[�u33
	__GF_TIMEATK_NORMAL_RSV34,	// �m�[�}��34�A���U�[�u34
	__GF_TIMEATK_NORMAL_RSV35,	// �m�[�}��35�A���U�[�u35
	__GF_TIMEATK_NORMAL_RSV36,	// �m�[�}��36�A���U�[�u36
	__GF_TIMEATK_NORMAL_RSV37,	// �m�[�}��37�A���U�[�u37
	__GF_TIMEATK_NORMAL_RSV38,	// �m�[�}��38�A���U�[�u38
	GF_TIMEATK_NORMAL_RUSH,		// �m�[�}��39�A�{�X���b�V��

	GF_TIMEATK_NORMAL_ED,

		// HARD3�l�p
	GF_TIMEATK_HARD_ST = GF_TIMEATK_NORMAL_ED,
	GF_TIMEATK_HARD_M0111 = GF_TIMEATK_HARD_ST,		// �n�[�h00�A�P���A�r�t�e���U
	GF_TIMEATK_HARD_B150,		// �n�[�h01�A�P���A�A���@���h���M��
	GF_TIMEATK_HARD_B100,		// �n�[�h02�A�Q���A�Z���y���^�X
	GF_TIMEATK_HARD_B000,		// �n�[�h03�A�Q���A�N�����I��
	GF_TIMEATK_HARD_B101B,		// �n�[�h04�A�Q���A�����u���Q�E�X
	GF_TIMEATK_HARD_B001,		// �n�[�h05�A�Q���A�O���K���`����
	GF_TIMEATK_HARD_B102,		// �n�[�h06�A�Q���A�}�K�}���h��
	GF_TIMEATK_HARD_B002,		// �n�[�h07�A�Q���A���X�s�X�[�X
	GF_TIMEATK_HARD_B152,		// �n�[�h08�A�Q���A�L���S�[��
	GF_TIMEATK_HARD_B154,		// �n�[�h09�A�R���A�A���@���h���M��
	GF_TIMEATK_HARD_B003,		// �n�[�h10�A�R���A�M�A�X�o�[��
	GF_TIMEATK_HARD_B006,		// �n�[�h11�A�S���A�u���L�I��
	GF_TIMEATK_HARD_B104,		// �n�[�h12�A�T���A�G�N�X���[�e��
	GF_TIMEATK_HARD_B004,		// �n�[�h13�A�T���A�J�����F���X
	GF_TIMEATK_HARD_B103,		// �n�[�h14�A�T���A�s���e�B�X�A�j�}
	GF_TIMEATK_HARD_B106,		// �n�[�h15�A�T���A�V�G���J���g�D�X
	GF_TIMEATK_HARD_B007,		// �n�[�h16�A�T���A�I�P�A�m�X
	GF_TIMEATK_HARD_B105,		// �n�[�h17�A�T���A�h�N�T�E�O���G��
	GF_TIMEATK_HARD_B005,		// �n�[�h18�A�T���A�o�V���E�X
	GF_TIMEATK_HARD_B012,		// �n�[�h19�A�U���A���E�G�����g����
	GF_TIMEATK_HARD_B112,		// �n�[�h20�A�U���A�A�j���X�E�q�h�D��
	GF_TIMEATK_HARD_B110,		// �n�[�h21�A�U���A�A�j���X�E�~�m�X
	GF_TIMEATK_HARD_B111,		// �n�[�h22�A�U���A�A�j���X�E�l�X�g�[��
	GF_TIMEATK_HARD_B008,		// �n�[�h23�A�U���A�A�j���X�E�E�[��
	GF_TIMEATK_HARD_B021_1,		// �n�[�h24�A�U���A�e�I�X�E�f�E�G���h���O�����P
	GF_TIMEATK_HARD_B021_2,		// �n�[�h25�A�U���A�e�I�X�E�f�E�G���h���O�����Q
	GF_TIMEATK_HARD_B021_3,		// �n�[�h26�A�U���A�e�I�X�E�f�E�G���h���O�����R
	GF_TIMEATK_HARD_B009,		// �n�[�h27�A�V���A�͂��܂�̖��E�q
	GF_TIMEATK_HARD_B010,		// �n�[�h28�A�V���A�͂��܂�̖��E�e
	GF_TIMEATK_HARD_B155,		// �n�[�h29�A�V�����B�A
	GF_TIMEATK_HARD_B151,		// �n�[�h30�A�}�X�^�[�R���O
	GF_TIMEATK_HARD_B153,		// �n�[�h31�A�U���A���t�H���V����
	GF_TIMEATK_HARD_B170,		// �n�[�h32�A�U���A�������F�Q�T�ڃ_���W�����{�X
	__GF_TIMEATK_HARD_RSV33,	// �n�[�h33�A���U�[�u33
	__GF_TIMEATK_HARD_RSV34,	// �n�[�h34�A���U�[�u34
	__GF_TIMEATK_HARD_RSV35,	// �n�[�h35�A���U�[�u35
	__GF_TIMEATK_HARD_RSV36,	// �n�[�h36�A���U�[�u36
	__GF_TIMEATK_HARD_RSV37,	// �n�[�h37�A���U�[�u37
	__GF_TIMEATK_HARD_RSV38,	// �n�[�h38�A���U�[�u38
	GF_TIMEATK_HARD_RUSH,		// �n�[�h39�A�{�X���b�V��

	GF_TIMEATK_HARD_ED,

		// NIGHTMARE3�l�p
	GF_TIMEATK_NIGHTMARE_ST = GF_TIMEATK_HARD_ED,
	GF_TIMEATK_NIGHTMARE_M0111 = GF_TIMEATK_NIGHTMARE_ST,	// �i�C�g���A00�A�P���A�r�t�e���U
	GF_TIMEATK_NIGHTMARE_B150,		// �i�C�g���A01�A�P���A�A���@���h���M��
	GF_TIMEATK_NIGHTMARE_B100,		// �i�C�g���A02�A�Q���A�Z���y���^�X
	GF_TIMEATK_NIGHTMARE_B000,		// �i�C�g���A03�A�Q���A�N�����I��
	GF_TIMEATK_NIGHTMARE_B101B,		// �i�C�g���A04�A�Q���A�����u���Q�E�X
	GF_TIMEATK_NIGHTMARE_B001,		// �i�C�g���A05�A�Q���A�O���K���`����
	GF_TIMEATK_NIGHTMARE_B102,		// �i�C�g���A06�A�Q���A�}�K�}���h��
	GF_TIMEATK_NIGHTMARE_B002,		// �i�C�g���A07�A�Q���A���X�s�X�[�X
	GF_TIMEATK_NIGHTMARE_B152,		// �i�C�g���A08�A�Q���A�L���S�[��
	GF_TIMEATK_NIGHTMARE_B154,		// �i�C�g���A09�A�R���A�A���@���h���M��
	GF_TIMEATK_NIGHTMARE_B003,		// �i�C�g���A10�A�R���A�M�A�X�o�[��
	GF_TIMEATK_NIGHTMARE_B006,		// �i�C�g���A11�A�S���A�u���L�I��
	GF_TIMEATK_NIGHTMARE_B104,		// �i�C�g���A12�A�T���A�G�N�X���[�e��
	GF_TIMEATK_NIGHTMARE_B004,		// �i�C�g���A13�A�T���A�J�����F���X
	GF_TIMEATK_NIGHTMARE_B103,		// �i�C�g���A14�A�T���A�s���e�B�X�A�j�}
	GF_TIMEATK_NIGHTMARE_B106,		// �i�C�g���A15�A�T���A�V�G���J���g�D�X
	GF_TIMEATK_NIGHTMARE_B007,		// �i�C�g���A16�A�T���A�I�P�A�m�X
	GF_TIMEATK_NIGHTMARE_B105,		// �i�C�g���A17�A�T���A�h�N�T�E�O���G��
	GF_TIMEATK_NIGHTMARE_B005,		// �i�C�g���A18�A�T���A�o�V���E�X
	GF_TIMEATK_NIGHTMARE_B012,		// �i�C�g���A19�A�U���A���E�G�����g����
	GF_TIMEATK_NIGHTMARE_B112,		// �i�C�g���A20�A�U���A�A�j���X�E�q�h�D��
	GF_TIMEATK_NIGHTMARE_B110,		// �i�C�g���A21�A�U���A�A�j���X�E�~�m�X
	GF_TIMEATK_NIGHTMARE_B111,		// �i�C�g���A22�A�U���A�A�j���X�E�l�X�g�[��
	GF_TIMEATK_NIGHTMARE_B008,		// �i�C�g���A23�A�U���A�A�j���X�E�E�[��
	GF_TIMEATK_NIGHTMARE_B021_1,	// �i�C�g���A24�A�U���A�e�I�X�E�f�E�G���h���O�����P
	GF_TIMEATK_NIGHTMARE_B021_2,	// �i�C�g���A25�A�U���A�e�I�X�E�f�E�G���h���O�����Q
	GF_TIMEATK_NIGHTMARE_B021_3,	// �i�C�g���A26�A�U���A�e�I�X�E�f�E�G���h���O�����R
	GF_TIMEATK_NIGHTMARE_B009,		// �i�C�g���A27�A�V���A�͂��܂�̖��E�q
	GF_TIMEATK_NIGHTMARE_B010,		// �i�C�g���A28�A�V���A�͂��܂�̖��E�e
	GF_TIMEATK_NIGHTMARE_B155,		// �i�C�g���A29�A�V�����B�A
	GF_TIMEATK_NIGHTMARE_B151,		// �i�C�g���A30�A�}�X�^�[�R���O
	GF_TIMEATK_NIGHTMARE_B153,		// �i�C�g���A31�A�U���A���t�H���V����
	GF_TIMEATK_NIGHTMARE_B170,		// �i�C�g���A32�A�U���A�������F�Q�T�ڃ_���W�����{�X
	__GF_TIMEATK_NIGHTMARE_RSV33,	// �i�C�g���A33�A���U�[�u33
	__GF_TIMEATK_NIGHTMARE_RSV34,	// �i�C�g���A34�A���U�[�u34
	__GF_TIMEATK_NIGHTMARE_RSV35,	// �i�C�g���A35�A���U�[�u35
	__GF_TIMEATK_NIGHTMARE_RSV36,	// �i�C�g���A36�A���U�[�u36
	__GF_TIMEATK_NIGHTMARE_RSV37,	// �i�C�g���A37�A���U�[�u37
	__GF_TIMEATK_NIGHTMARE_RSV38,	// �i�C�g���A38�A���U�[�u38
	GF_TIMEATK_NIGHTMARE_RUSH,		// �i�C�g���A39�A�{�X���b�V��

	GF_TIMEATK_NIGHTMARE_ED,

		// INFERNO3�l�p
	GF_TIMEATK_INFERNO_ST = GF_TIMEATK_NIGHTMARE_ED,
	GF_TIMEATK_INFERNO_M0111 = GF_TIMEATK_INFERNO_ST,	// �C���t�F���m00�A�P���A�r�t�e���U
	GF_TIMEATK_INFERNO_B150,		// �C���t�F���m01�A�P���A�A���@���h���M��
	GF_TIMEATK_INFERNO_B100,		// �C���t�F���m02�A�Q���A�Z���y���^�X
	GF_TIMEATK_INFERNO_B000,		// �C���t�F���m03�A�Q���A�N�����I��
	GF_TIMEATK_INFERNO_B101B,		// �C���t�F���m04�A�Q���A�����u���Q�E�X
	GF_TIMEATK_INFERNO_B001,		// �C���t�F���m05�A�Q���A�O���K���`����
	GF_TIMEATK_INFERNO_B102,		// �C���t�F���m06�A�Q���A�}�K�}���h��
	GF_TIMEATK_INFERNO_B002,		// �C���t�F���m07�A�Q���A���X�s�X�[�X
	GF_TIMEATK_INFERNO_B152,		// �C���t�F���m08�A�Q���A�L���S�[��
	GF_TIMEATK_INFERNO_B154,		// �C���t�F���m09�A�R���A�A���@���h���M��
	GF_TIMEATK_INFERNO_B003,		// �C���t�F���m10�A�R���A�M�A�X�o�[��
	GF_TIMEATK_INFERNO_B006,		// �C���t�F���m11�A�S���A�u���L�I��
	GF_TIMEATK_INFERNO_B104,		// �C���t�F���m12�A�T���A�G�N�X���[�e��
	GF_TIMEATK_INFERNO_B004,		// �C���t�F���m13�A�T���A�J�����F���X
	GF_TIMEATK_INFERNO_B103,		// �C���t�F���m14�A�T���A�s���e�B�X�A�j�}
	GF_TIMEATK_INFERNO_B106,		// �C���t�F���m15�A�T���A�V�G���J���g�D�X
	GF_TIMEATK_INFERNO_B007,		// �C���t�F���m16�A�T���A�I�P�A�m�X
	GF_TIMEATK_INFERNO_B105,		// �C���t�F���m17�A�T���A�h�N�T�E�O���G��
	GF_TIMEATK_INFERNO_B005,		// �C���t�F���m18�A�T���A�o�V���E�X
	GF_TIMEATK_INFERNO_B012,		// �C���t�F���m19�A�U���A���E�G�����g����
	GF_TIMEATK_INFERNO_B112,		// �C���t�F���m20�A�U���A�A�j���X�E�q�h�D��
	GF_TIMEATK_INFERNO_B110,		// �C���t�F���m21�A�U���A�A�j���X�E�~�m�X
	GF_TIMEATK_INFERNO_B111,		// �C���t�F���m22�A�U���A�A�j���X�E�l�X�g�[��
	GF_TIMEATK_INFERNO_B008,		// �C���t�F���m23�A�U���A�A�j���X�E�E�[��
	GF_TIMEATK_INFERNO_B021_1,		// �C���t�F���m24�A�U���A�e�I�X�E�f�E�G���h���O�����P
	GF_TIMEATK_INFERNO_B021_2,		// �C���t�F���m25�A�U���A�e�I�X�E�f�E�G���h���O�����Q
	GF_TIMEATK_INFERNO_B021_3,		// �C���t�F���m26�A�U���A�e�I�X�E�f�E�G���h���O�����R
	GF_TIMEATK_INFERNO_B009,		// �C���t�F���m27�A�V���A�͂��܂�̖��E�q
	GF_TIMEATK_INFERNO_B010,		// �C���t�F���m28�A�V���A�͂��܂�̖��E�e
	GF_TIMEATK_INFERNO_B155,		// �C���t�F���m29�A�V�����B�A
	GF_TIMEATK_INFERNO_B151,		// �C���t�F���m30�A�}�X�^�[�R���O
	GF_TIMEATK_INFERNO_B153,		// �C���t�F���m31�A�U���A���t�H���V����
	GF_TIMEATK_INFERNO_B170,		// �C���t�F���m32�A�U���A�������F�Q�T�ڃ_���W�����{�X
	__GF_TIMEATK_INFERNO_RSV33,		// �C���t�F���m33�A���U�[�u33
	__GF_TIMEATK_INFERNO_RSV34,		// �C���t�F���m34�A���U�[�u34
	__GF_TIMEATK_INFERNO_RSV35,		// �C���t�F���m35�A���U�[�u35
	__GF_TIMEATK_INFERNO_RSV36,		// �C���t�F���m36�A���U�[�u36
	__GF_TIMEATK_INFERNO_RSV37,		// �C���t�F���m37�A���U�[�u37
	__GF_TIMEATK_INFERNO_RSV38,		// �C���t�F���m38�A���U�[�u38
	GF_TIMEATK_INFERNO_RUSH,		// �C���t�F���m39�A�{�X���b�V��

	GF_TIMEATK_INFERNO_ED,

	// �����2�l

		// EASY2�l�p
	GF_TIMEATK_2_EASY_ST = GF_TIMEATK_INFERNO_ED,
	GF_TIMEATK_2_EASY_M0111 = GF_TIMEATK_2_EASY_ST,	// �C�[�W�[00�A�P���A�r�t�e���U
	GF_TIMEATK_2_EASY_B150,	// �C�[�W�[01�A�P���A�A���@���h���M��
	GF_TIMEATK_2_EASY_B100,	// �C�[�W�[02�A�Q���A�Z���y���^�X
	GF_TIMEATK_2_EASY_B000,	// �C�[�W�[03�A�Q���A�N�����I��
	GF_TIMEATK_2_EASY_B101B,	// �C�[�W�[04�A�Q���A�����u���Q�E�X
	GF_TIMEATK_2_EASY_B001,	// �C�[�W�[05�A�Q���A�O���K���`����
	GF_TIMEATK_2_EASY_B102,	// �C�[�W�[06�A�Q���A�}�K�}���h��
	GF_TIMEATK_2_EASY_B002,	// �C�[�W�[07�A�Q���A���X�s�X�[�X
	GF_TIMEATK_2_EASY_B152,	// �C�[�W�[08�A�Q���A�L���S�[��
	GF_TIMEATK_2_EASY_B154,	// �C�[�W�[09�A�R���A�A���@���h���M��
	GF_TIMEATK_2_EASY_B003,	// �C�[�W�[10�A�R���A�M�A�X�o�[��
	GF_TIMEATK_2_EASY_B006,	// �C�[�W�[11�A�S���A�u���L�I��
	GF_TIMEATK_2_EASY_B104,	// �C�[�W�[12�A�T���A�G�N�X���[�e��
	GF_TIMEATK_2_EASY_B004,	// �C�[�W�[13�A�T���A�J�����F���X
	GF_TIMEATK_2_EASY_B103,	// �C�[�W�[14�A�T���A�s���e�B�X�A�j�}
	GF_TIMEATK_2_EASY_B106,	// �C�[�W�[15�A�T���A�V�G���J���g�D�X
	GF_TIMEATK_2_EASY_B007,	// �C�[�W�[16�A�T���A�I�P�A�m�X
	GF_TIMEATK_2_EASY_B105,	// �C�[�W�[17�A�T���A�h�N�T�E�O���G��
	GF_TIMEATK_2_EASY_B005,	// �C�[�W�[18�A�T���A�o�V���E�X
	GF_TIMEATK_2_EASY_B012,	// �C�[�W�[19�A�U���A���E�G�����g����
	GF_TIMEATK_2_EASY_B112,	// �C�[�W�[20�A�U���A�A�j���X�E�q�h�D��
	GF_TIMEATK_2_EASY_B110,	// �C�[�W�[21�A�U���A�A�j���X�E�~�m�X
	GF_TIMEATK_2_EASY_B111,	// �C�[�W�[22�A�U���A�A�j���X�E�l�X�g�[��
	GF_TIMEATK_2_EASY_B008,	// �C�[�W�[23�A�U���A�A�j���X�E�E�[��
	GF_TIMEATK_2_EASY_B021_1,	// �C�[�W�[24�A�U���A�e�I�X�E�f�E�G���h���O�����P
	GF_TIMEATK_2_EASY_B021_2,	// �C�[�W�[25�A�U���A�e�I�X�E�f�E�G���h���O�����Q
	GF_TIMEATK_2_EASY_B021_3,	// �C�[�W�[26�A�U���A�e�I�X�E�f�E�G���h���O�����R
	GF_TIMEATK_2_EASY_B009,	// �C�[�W�[28�A�V���A�͂��܂�̖��E�q
	GF_TIMEATK_2_EASY_B010,	// �C�[�W�[28�A�V���A�͂��܂�̖��E�e
	GF_TIMEATK_2_EASY_B155,	// �C�[�W�[29�A�V�����B�A
	GF_TIMEATK_2_EASY_B151,	// �C�[�W�[30�A�}�X�^�[�R���O
	GF_TIMEATK_2_EASY_B153,	// �C�[�W�[31�A�U���A���t�H���V����
	GF_TIMEATK_2_EASY_B170,	// �C�[�W�[32�A�U���A�������F�Q�T�ڃ_���W�����{�X
	__GF_TIMEATK_2_EASY_RSV33,// �C�[�W�[34�A���U�[�u33
	__GF_TIMEATK_2_EASY_RSV34,// �C�[�W�[34�A���U�[�u34
	__GF_TIMEATK_2_EASY_RSV35,// �C�[�W�[35�A���U�[�u35
	__GF_TIMEATK_2_EASY_RSV36,// �C�[�W�[36�A���U�[�u36
	__GF_TIMEATK_2_EASY_RSV37,// �C�[�W�[37�A���U�[�u37
	__GF_TIMEATK_2_EASY_RSV38,// �C�[�W�[38�A���U�[�u38
	GF_TIMEATK_2_EASY_RUSH,	// �C�[�W�[39�A�{�X���b�V��

	GF_TIMEATK_2_EASY_ED,

		// NORMAL2�l�p
	GF_TIMEATK_2_NORMAL_ST = GF_TIMEATK_2_EASY_ED,
	GF_TIMEATK_2_NORMAL_M0111 = GF_TIMEATK_2_NORMAL_ST,	// �m�[�}��00�A�P���A�r�t�e���U
	GF_TIMEATK_2_NORMAL_B150,		// �m�[�}��01�A�P���A�A���@���h���M��
	GF_TIMEATK_2_NORMAL_B100,		// �m�[�}��02�A�Q���A�Z���y���^�X
	GF_TIMEATK_2_NORMAL_B000,		// �m�[�}��03�A�Q���A�N�����I��
	GF_TIMEATK_2_NORMAL_B101B,	// �m�[�}��04�A�Q���A�����u���Q�E�X
	GF_TIMEATK_2_NORMAL_B001,		// �m�[�}��05�A�Q���A�O���K���`����
	GF_TIMEATK_2_NORMAL_B102,		// �m�[�}��06�A�Q���A�}�K�}���h��
	GF_TIMEATK_2_NORMAL_B002,		// �m�[�}��07�A�Q���A���X�s�X�[�X
	GF_TIMEATK_2_NORMAL_B152,		// �m�[�}��08�A�Q���A�L���S�[��
	GF_TIMEATK_2_NORMAL_B154,		// �m�[�}��09�A�R���A�A���@���h���M��
	GF_TIMEATK_2_NORMAL_B003,		// �m�[�}��10�A�R���A�M�A�X�o�[��
	GF_TIMEATK_2_NORMAL_B006,		// �m�[�}��11�A�S���A�u���L�I��
	GF_TIMEATK_2_NORMAL_B104,		// �m�[�}��12�A�T���A�G�N�X���[�e��
	GF_TIMEATK_2_NORMAL_B004,		// �m�[�}��13�A�T���A�J�����F���X
	GF_TIMEATK_2_NORMAL_B103,		// �m�[�}��14�A�T���A�s���e�B�X�A�j�}
	GF_TIMEATK_2_NORMAL_B106,		// �m�[�}��15�A�T���A�V�G���J���g�D�X
	GF_TIMEATK_2_NORMAL_B007,		// �m�[�}��16�A�T���A�I�P�A�m�X
	GF_TIMEATK_2_NORMAL_B105,		// �m�[�}��17�A�T���A�h�N�T�E�O���G��
	GF_TIMEATK_2_NORMAL_B005,		// �m�[�}��18�A�T���A�o�V���E�X
	GF_TIMEATK_2_NORMAL_B012,		// �m�[�}��19�A�U���A���E�G�����g����
	GF_TIMEATK_2_NORMAL_B112,		// �m�[�}��20�A�U���A�A�j���X�E�q�h�D��
	GF_TIMEATK_2_NORMAL_B110,		// �m�[�}��21�A�U���A�A�j���X�E�~�m�X
	GF_TIMEATK_2_NORMAL_B111,		// �m�[�}��22�A�U���A�A�j���X�E�l�X�g�[��
	GF_TIMEATK_2_NORMAL_B008,		// �m�[�}��23�A�U���A�A�j���X�E�E�[��
	GF_TIMEATK_2_NORMAL_B021_1,	// �m�[�}��24�A�U���A�e�I�X�E�f�E�G���h���O�����P
	GF_TIMEATK_2_NORMAL_B021_2,	// �m�[�}��25�A�U���A�e�I�X�E�f�E�G���h���O�����Q
	GF_TIMEATK_2_NORMAL_B021_3,	// �m�[�}��26�A�U���A�e�I�X�E�f�E�G���h���O�����R
	GF_TIMEATK_2_NORMAL_B009,		// �m�[�}��27�A�V���A�͂��܂�̖��E�q
	GF_TIMEATK_2_NORMAL_B010,		// �m�[�}��28�A�V���A�͂��܂�̖��E�e
	GF_TIMEATK_2_NORMAL_B155,	// �m�[�}��29�A�V�����B�A
	GF_TIMEATK_2_NORMAL_B151,	// �m�[�}��30�A�}�X�^�[�R���O
	GF_TIMEATK_2_NORMAL_B153,		// �m�[�}��31�A�U���A���t�H���V����
	GF_TIMEATK_2_NORMAL_B170,	// �m�[�}��32�A�U���A�������F�Q�T�ڃ_���W�����{�X
	__GF_TIMEATK_2_NORMAL_RSV33,	// �m�[�}��34�A���U�[�u33
	__GF_TIMEATK_2_NORMAL_RSV34,	// �m�[�}��34�A���U�[�u34
	__GF_TIMEATK_2_NORMAL_RSV35,	// �m�[�}��35�A���U�[�u35
	__GF_TIMEATK_2_NORMAL_RSV36,	// �m�[�}��36�A���U�[�u36
	__GF_TIMEATK_2_NORMAL_RSV37,	// �m�[�}��37�A���U�[�u37
	__GF_TIMEATK_2_NORMAL_RSV38,	// �m�[�}��38�A���U�[�u38
	GF_TIMEATK_2_NORMAL_RUSH,		// �m�[�}��39�A�{�X���b�V��

	GF_TIMEATK_2_NORMAL_ED,

		// HARD2�l�p
	GF_TIMEATK_2_HARD_ST = GF_TIMEATK_2_NORMAL_ED,
	GF_TIMEATK_2_HARD_M0111 = GF_TIMEATK_2_HARD_ST,		// �n�[�h00�A�P���A�r�t�e���U
	GF_TIMEATK_2_HARD_B150,		// �n�[�h01�A�P���A�A���@���h���M��
	GF_TIMEATK_2_HARD_B100,		// �n�[�h02�A�Q���A�Z���y���^�X
	GF_TIMEATK_2_HARD_B000,		// �n�[�h03�A�Q���A�N�����I��
	GF_TIMEATK_2_HARD_B101B,		// �n�[�h04�A�Q���A�����u���Q�E�X
	GF_TIMEATK_2_HARD_B001,		// �n�[�h05�A�Q���A�O���K���`����
	GF_TIMEATK_2_HARD_B102,		// �n�[�h06�A�Q���A�}�K�}���h��
	GF_TIMEATK_2_HARD_B002,		// �n�[�h07�A�Q���A���X�s�X�[�X
	GF_TIMEATK_2_HARD_B152,		// �n�[�h08�A�Q���A�L���S�[��
	GF_TIMEATK_2_HARD_B154,		// �n�[�h09�A�R���A�A���@���h���M��
	GF_TIMEATK_2_HARD_B003,		// �n�[�h10�A�R���A�M�A�X�o�[��
	GF_TIMEATK_2_HARD_B006,		// �n�[�h11�A�S���A�u���L�I��
	GF_TIMEATK_2_HARD_B104,		// �n�[�h12�A�T���A�G�N�X���[�e��
	GF_TIMEATK_2_HARD_B004,		// �n�[�h13�A�T���A�J�����F���X
	GF_TIMEATK_2_HARD_B103,		// �n�[�h14�A�T���A�s���e�B�X�A�j�}
	GF_TIMEATK_2_HARD_B106,		// �n�[�h15�A�T���A�V�G���J���g�D�X
	GF_TIMEATK_2_HARD_B007,		// �n�[�h16�A�T���A�I�P�A�m�X
	GF_TIMEATK_2_HARD_B105,		// �n�[�h17�A�T���A�h�N�T�E�O���G��
	GF_TIMEATK_2_HARD_B005,		// �n�[�h18�A�T���A�o�V���E�X
	GF_TIMEATK_2_HARD_B012,		// �n�[�h19�A�U���A���E�G�����g����
	GF_TIMEATK_2_HARD_B112,		// �n�[�h20�A�U���A�A�j���X�E�q�h�D��
	GF_TIMEATK_2_HARD_B110,		// �n�[�h21�A�U���A�A�j���X�E�~�m�X
	GF_TIMEATK_2_HARD_B111,		// �n�[�h22�A�U���A�A�j���X�E�l�X�g�[��
	GF_TIMEATK_2_HARD_B008,		// �n�[�h23�A�U���A�A�j���X�E�E�[��
	GF_TIMEATK_2_HARD_B021_1,		// �n�[�h24�A�U���A�e�I�X�E�f�E�G���h���O�����P
	GF_TIMEATK_2_HARD_B021_2,		// �n�[�h25�A�U���A�e�I�X�E�f�E�G���h���O�����Q
	GF_TIMEATK_2_HARD_B021_3,		// �n�[�h26�A�U���A�e�I�X�E�f�E�G���h���O�����R
	GF_TIMEATK_2_HARD_B009,		// �n�[�h27�A�V���A�͂��܂�̖��E�q
	GF_TIMEATK_2_HARD_B010,		// �n�[�h28�A�V���A�͂��܂�̖��E�e
	GF_TIMEATK_2_HARD_B155,		// �n�[�h29�A�V�����B�A
	GF_TIMEATK_2_HARD_B151,		// �n�[�h30�A�}�X�^�[�R���O
	GF_TIMEATK_2_HARD_B153,		// �n�[�h31�A�U���A���t�H���V����
	GF_TIMEATK_2_HARD_B170,		// �n�[�h32�A�U���A�������F�Q�T�ڃ_���W�����{�X
	__GF_TIMEATK_2_HARD_RSV33,	// �n�[�h33�A���U�[�u33
	__GF_TIMEATK_2_HARD_RSV34,	// �n�[�h34�A���U�[�u34
	__GF_TIMEATK_2_HARD_RSV35,	// �n�[�h35�A���U�[�u35
	__GF_TIMEATK_2_HARD_RSV36,	// �n�[�h36�A���U�[�u36
	__GF_TIMEATK_2_HARD_RSV37,	// �n�[�h37�A���U�[�u37
	__GF_TIMEATK_2_HARD_RSV38,	// �n�[�h38�A���U�[�u38
	GF_TIMEATK_2_HARD_RUSH,		// �n�[�h39�A�{�X���b�V��

	GF_TIMEATK_2_HARD_ED,

		// NIGHTMARE2�l�p
	GF_TIMEATK_2_NIGHTMARE_ST = GF_TIMEATK_2_HARD_ED,
	GF_TIMEATK_2_NIGHTMARE_M0111 = GF_TIMEATK_2_NIGHTMARE_ST,	// �i�C�g���A00�A�P���A�r�t�e���U
	GF_TIMEATK_2_NIGHTMARE_B150,		// �i�C�g���A01�A�P���A�A���@���h���M��
	GF_TIMEATK_2_NIGHTMARE_B100,		// �i�C�g���A02�A�Q���A�Z���y���^�X
	GF_TIMEATK_2_NIGHTMARE_B000,		// �i�C�g���A03�A�Q���A�N�����I��
	GF_TIMEATK_2_NIGHTMARE_B101B,		// �i�C�g���A04�A�Q���A�����u���Q�E�X
	GF_TIMEATK_2_NIGHTMARE_B001,		// �i�C�g���A05�A�Q���A�O���K���`����
	GF_TIMEATK_2_NIGHTMARE_B102,		// �i�C�g���A06�A�Q���A�}�K�}���h��
	GF_TIMEATK_2_NIGHTMARE_B002,		// �i�C�g���A07�A�Q���A���X�s�X�[�X
	GF_TIMEATK_2_NIGHTMARE_B152,		// �i�C�g���A08�A�Q���A�L���S�[��
	GF_TIMEATK_2_NIGHTMARE_B154,		// �i�C�g���A09�A�R���A�A���@���h���M��
	GF_TIMEATK_2_NIGHTMARE_B003,		// �i�C�g���A10�A�R���A�M�A�X�o�[��
	GF_TIMEATK_2_NIGHTMARE_B006,		// �i�C�g���A11�A�S���A�u���L�I��
	GF_TIMEATK_2_NIGHTMARE_B104,		// �i�C�g���A12�A�T���A�G�N�X���[�e��
	GF_TIMEATK_2_NIGHTMARE_B004,		// �i�C�g���A13�A�T���A�J�����F���X
	GF_TIMEATK_2_NIGHTMARE_B103,		// �i�C�g���A14�A�T���A�s���e�B�X�A�j�}
	GF_TIMEATK_2_NIGHTMARE_B106,		// �i�C�g���A15�A�T���A�V�G���J���g�D�X
	GF_TIMEATK_2_NIGHTMARE_B007,		// �i�C�g���A16�A�T���A�I�P�A�m�X
	GF_TIMEATK_2_NIGHTMARE_B105,		// �i�C�g���A17�A�T���A�h�N�T�E�O���G��
	GF_TIMEATK_2_NIGHTMARE_B005,		// �i�C�g���A18�A�T���A�o�V���E�X
	GF_TIMEATK_2_NIGHTMARE_B012,		// �i�C�g���A19�A�U���A���E�G�����g����
	GF_TIMEATK_2_NIGHTMARE_B112,		// �i�C�g���A20�A�U���A�A�j���X�E�q�h�D��
	GF_TIMEATK_2_NIGHTMARE_B110,		// �i�C�g���A21�A�U���A�A�j���X�E�~�m�X
	GF_TIMEATK_2_NIGHTMARE_B111,		// �i�C�g���A22�A�U���A�A�j���X�E�l�X�g�[��
	GF_TIMEATK_2_NIGHTMARE_B008,		// �i�C�g���A23�A�U���A�A�j���X�E�E�[��
	GF_TIMEATK_2_NIGHTMARE_B021_1,	// �i�C�g���A24�A�U���A�e�I�X�E�f�E�G���h���O�����P
	GF_TIMEATK_2_NIGHTMARE_B021_2,	// �i�C�g���A25�A�U���A�e�I�X�E�f�E�G���h���O�����Q
	GF_TIMEATK_2_NIGHTMARE_B021_3,	// �i�C�g���A26�A�U���A�e�I�X�E�f�E�G���h���O�����R
	GF_TIMEATK_2_NIGHTMARE_B009,		// �i�C�g���A27�A�V���A�͂��܂�̖��E�q
	GF_TIMEATK_2_NIGHTMARE_B010,		// �i�C�g���A28�A�V���A�͂��܂�̖��E�e
	GF_TIMEATK_2_NIGHTMARE_B155,		// �i�C�g���A29�A�V�����B�A
	GF_TIMEATK_2_NIGHTMARE_B151,		// �i�C�g���A30�A�}�X�^�[�R���O
	GF_TIMEATK_2_NIGHTMARE_B153,		// �i�C�g���A31�A�U���A���t�H���V����
	GF_TIMEATK_2_NIGHTMARE_B170,		// �i�C�g���A32�A�U���A�������F�Q�T�ڃ_���W�����{�X
	__GF_TIMEATK_2_NIGHTMARE_RSV33,	// �i�C�g���A33�A���U�[�u33
	__GF_TIMEATK_2_NIGHTMARE_RSV34,	// �i�C�g���A34�A���U�[�u34
	__GF_TIMEATK_2_NIGHTMARE_RSV35,	// �i�C�g���A35�A���U�[�u35
	__GF_TIMEATK_2_NIGHTMARE_RSV36,	// �i�C�g���A36�A���U�[�u36
	__GF_TIMEATK_2_NIGHTMARE_RSV37,	// �i�C�g���A37�A���U�[�u37
	__GF_TIMEATK_2_NIGHTMARE_RSV38,	// �i�C�g���A38�A���U�[�u38
	GF_TIMEATK_2_NIGHTMARE_RUSH,		// �i�C�g���A39�A�{�X���b�V��

	GF_TIMEATK_2_NIGHTMARE_ED,

		// INFERNO2�l�p
	GF_TIMEATK_2_INFERNO_ST = GF_TIMEATK_2_NIGHTMARE_ED,
	GF_TIMEATK_2_INFERNO_M0111 = GF_TIMEATK_2_INFERNO_ST,	// �C���t�F���m00�A�P���A�r�t�e���U
	GF_TIMEATK_2_INFERNO_B150,		// �C���t�F���m01�A�P���A�A���@���h���M��
	GF_TIMEATK_2_INFERNO_B100,		// �C���t�F���m02�A�Q���A�Z���y���^�X
	GF_TIMEATK_2_INFERNO_B000,		// �C���t�F���m03�A�Q���A�N�����I��
	GF_TIMEATK_2_INFERNO_B101B,		// �C���t�F���m04�A�Q���A�����u���Q�E�X
	GF_TIMEATK_2_INFERNO_B001,		// �C���t�F���m05�A�Q���A�O���K���`����
	GF_TIMEATK_2_INFERNO_B102,		// �C���t�F���m06�A�Q���A�}�K�}���h��
	GF_TIMEATK_2_INFERNO_B002,		// �C���t�F���m07�A�Q���A���X�s�X�[�X
	GF_TIMEATK_2_INFERNO_B152,		// �C���t�F���m08�A�Q���A�L���S�[��
	GF_TIMEATK_2_INFERNO_B154,		// �C���t�F���m09�A�R���A�A���@���h���M��
	GF_TIMEATK_2_INFERNO_B003,		// �C���t�F���m10�A�R���A�M�A�X�o�[��
	GF_TIMEATK_2_INFERNO_B006,		// �C���t�F���m11�A�S���A�u���L�I��
	GF_TIMEATK_2_INFERNO_B104,		// �C���t�F���m12�A�T���A�G�N�X���[�e��
	GF_TIMEATK_2_INFERNO_B004,		// �C���t�F���m13�A�T���A�J�����F���X
	GF_TIMEATK_2_INFERNO_B103,		// �C���t�F���m14�A�T���A�s���e�B�X�A�j�}
	GF_TIMEATK_2_INFERNO_B106,		// �C���t�F���m15�A�T���A�V�G���J���g�D�X
	GF_TIMEATK_2_INFERNO_B007,		// �C���t�F���m16�A�T���A�I�P�A�m�X
	GF_TIMEATK_2_INFERNO_B105,		// �C���t�F���m17�A�T���A�h�N�T�E�O���G��
	GF_TIMEATK_2_INFERNO_B005,		// �C���t�F���m18�A�T���A�o�V���E�X
	GF_TIMEATK_2_INFERNO_B012,		// �C���t�F���m19�A�U���A���E�G�����g����
	GF_TIMEATK_2_INFERNO_B112,		// �C���t�F���m20�A�U���A�A�j���X�E�q�h�D��
	GF_TIMEATK_2_INFERNO_B110,		// �C���t�F���m21�A�U���A�A�j���X�E�~�m�X
	GF_TIMEATK_2_INFERNO_B111,		// �C���t�F���m22�A�U���A�A�j���X�E�l�X�g�[��
	GF_TIMEATK_2_INFERNO_B008,		// �C���t�F���m23�A�U���A�A�j���X�E�E�[��
	GF_TIMEATK_2_INFERNO_B021_1,		// �C���t�F���m24�A�U���A�e�I�X�E�f�E�G���h���O�����P
	GF_TIMEATK_2_INFERNO_B021_2,		// �C���t�F���m25�A�U���A�e�I�X�E�f�E�G���h���O�����Q
	GF_TIMEATK_2_INFERNO_B021_3,		// �C���t�F���m26�A�U���A�e�I�X�E�f�E�G���h���O�����R
	GF_TIMEATK_2_INFERNO_B009,		// �C���t�F���m27�A�V���A�͂��܂�̖��E�q
	GF_TIMEATK_2_INFERNO_B010,		// �C���t�F���m28�A�V���A�͂��܂�̖��E�e
	GF_TIMEATK_2_INFERNO_B155,		// �C���t�F���m29�A�V�����B�A
	GF_TIMEATK_2_INFERNO_B151,		// �C���t�F���m30�A�}�X�^�[�R���O
	GF_TIMEATK_2_INFERNO_B153,		// �C���t�F���m31�A�U���A���t�H���V����
	GF_TIMEATK_2_INFERNO_B170,		// �C���t�F���m32�A�U���A�������F�Q�T�ڃ_���W�����{�X
	__GF_TIMEATK_2_INFERNO_RSV33,		// �C���t�F���m33�A���U�[�u33
	__GF_TIMEATK_2_INFERNO_RSV34,		// �C���t�F���m34�A���U�[�u34
	__GF_TIMEATK_2_INFERNO_RSV35,		// �C���t�F���m35�A���U�[�u35
	__GF_TIMEATK_2_INFERNO_RSV36,		// �C���t�F���m36�A���U�[�u36
	__GF_TIMEATK_2_INFERNO_RSV37,		// �C���t�F���m37�A���U�[�u37
	__GF_TIMEATK_2_INFERNO_RSV38,		// �C���t�F���m38�A���U�[�u38
	GF_TIMEATK_2_INFERNO_RUSH,		// �C���t�F���m39�A�{�X���b�V��

	GF_TIMEATK_2_INFERNO_ED,

	// �����1�l

		// EASY1�l�p
	GF_TIMEATK_1_EASY_ST = GF_TIMEATK_2_INFERNO_ED,
	GF_TIMEATK_1_EASY_M0111 = GF_TIMEATK_1_EASY_ST,	// �C�[�W�[00�A�P���A�r�t�e���U
	GF_TIMEATK_1_EASY_B150,	// �C�[�W�[01�A�P���A�A���@���h���M��
	GF_TIMEATK_1_EASY_B100,	// �C�[�W�[02�A�Q���A�Z���y���^�X
	GF_TIMEATK_1_EASY_B000,	// �C�[�W�[03�A�Q���A�N�����I��
	GF_TIMEATK_1_EASY_B101B,	// �C�[�W�[04�A�Q���A�����u���Q�E�X
	GF_TIMEATK_1_EASY_B001,	// �C�[�W�[05�A�Q���A�O���K���`����
	GF_TIMEATK_1_EASY_B102,	// �C�[�W�[06�A�Q���A�}�K�}���h��
	GF_TIMEATK_1_EASY_B002,	// �C�[�W�[07�A�Q���A���X�s�X�[�X
	GF_TIMEATK_1_EASY_B152,	// �C�[�W�[08�A�Q���A�L���S�[��
	GF_TIMEATK_1_EASY_B154,	// �C�[�W�[09�A�R���A�A���@���h���M��
	GF_TIMEATK_1_EASY_B003,	// �C�[�W�[10�A�R���A�M�A�X�o�[��
	GF_TIMEATK_1_EASY_B006,	// �C�[�W�[11�A�S���A�u���L�I��
	GF_TIMEATK_1_EASY_B104,	// �C�[�W�[12�A�T���A�G�N�X���[�e��
	GF_TIMEATK_1_EASY_B004,	// �C�[�W�[13�A�T���A�J�����F���X
	GF_TIMEATK_1_EASY_B103,	// �C�[�W�[14�A�T���A�s���e�B�X�A�j�}
	GF_TIMEATK_1_EASY_B106,	// �C�[�W�[15�A�T���A�V�G���J���g�D�X
	GF_TIMEATK_1_EASY_B007,	// �C�[�W�[16�A�T���A�I�P�A�m�X
	GF_TIMEATK_1_EASY_B105,	// �C�[�W�[17�A�T���A�h�N�T�E�O���G��
	GF_TIMEATK_1_EASY_B005,	// �C�[�W�[18�A�T���A�o�V���E�X
	GF_TIMEATK_1_EASY_B012,	// �C�[�W�[19�A�U���A���E�G�����g����
	GF_TIMEATK_1_EASY_B112,	// �C�[�W�[20�A�U���A�A�j���X�E�q�h�D��
	GF_TIMEATK_1_EASY_B110,	// �C�[�W�[21�A�U���A�A�j���X�E�~�m�X
	GF_TIMEATK_1_EASY_B111,	// �C�[�W�[22�A�U���A�A�j���X�E�l�X�g�[��
	GF_TIMEATK_1_EASY_B008,	// �C�[�W�[23�A�U���A�A�j���X�E�E�[��
	GF_TIMEATK_1_EASY_B021_1,	// �C�[�W�[24�A�U���A�e�I�X�E�f�E�G���h���O�����P
	GF_TIMEATK_1_EASY_B021_2,	// �C�[�W�[25�A�U���A�e�I�X�E�f�E�G���h���O�����Q
	GF_TIMEATK_1_EASY_B021_3,	// �C�[�W�[26�A�U���A�e�I�X�E�f�E�G���h���O�����R
	GF_TIMEATK_1_EASY_B009,	// �C�[�W�[28�A�V���A�͂��܂�̖��E�q
	GF_TIMEATK_1_EASY_B010,	// �C�[�W�[28�A�V���A�͂��܂�̖��E�e
	GF_TIMEATK_1_EASY_B155,	// �C�[�W�[29�A�V�����B�A
	GF_TIMEATK_1_EASY_B151,	// �C�[�W�[30�A�}�X�^�[�R���O
	GF_TIMEATK_1_EASY_B153,	// �C�[�W�[31�A�U���A���t�H���V����
	GF_TIMEATK_1_EASY_B170,	// �C�[�W�[32�A�U���A�������F�Q�T�ڃ_���W�����{�X
	__GF_TIMEATK_1_EASY_RSV33,// �C�[�W�[34�A���U�[�u33
	__GF_TIMEATK_1_EASY_RSV34,// �C�[�W�[34�A���U�[�u34
	__GF_TIMEATK_1_EASY_RSV35,// �C�[�W�[35�A���U�[�u35
	__GF_TIMEATK_1_EASY_RSV36,// �C�[�W�[36�A���U�[�u36
	__GF_TIMEATK_1_EASY_RSV37,// �C�[�W�[37�A���U�[�u37
	__GF_TIMEATK_1_EASY_RSV38,// �C�[�W�[38�A���U�[�u38
	GF_TIMEATK_1_EASY_RUSH,	// �C�[�W�[39�A�{�X���b�V��

	GF_TIMEATK_1_EASY_ED,

		// NORMAL1�l�p
	GF_TIMEATK_1_NORMAL_ST = GF_TIMEATK_1_EASY_ED,
	GF_TIMEATK_1_NORMAL_M0111 = GF_TIMEATK_1_NORMAL_ST,	// �m�[�}��00�A�P���A�r�t�e���U
	GF_TIMEATK_1_NORMAL_B150,		// �m�[�}��01�A�P���A�A���@���h���M��
	GF_TIMEATK_1_NORMAL_B100,		// �m�[�}��02�A�Q���A�Z���y���^�X
	GF_TIMEATK_1_NORMAL_B000,		// �m�[�}��03�A�Q���A�N�����I��
	GF_TIMEATK_1_NORMAL_B101B,	// �m�[�}��04�A�Q���A�����u���Q�E�X
	GF_TIMEATK_1_NORMAL_B001,		// �m�[�}��05�A�Q���A�O���K���`����
	GF_TIMEATK_1_NORMAL_B102,		// �m�[�}��06�A�Q���A�}�K�}���h��
	GF_TIMEATK_1_NORMAL_B002,		// �m�[�}��07�A�Q���A���X�s�X�[�X
	GF_TIMEATK_1_NORMAL_B152,		// �m�[�}��08�A�Q���A�L���S�[��
	GF_TIMEATK_1_NORMAL_B154,		// �m�[�}��09�A�R���A�A���@���h���M��
	GF_TIMEATK_1_NORMAL_B003,		// �m�[�}��10�A�R���A�M�A�X�o�[��
	GF_TIMEATK_1_NORMAL_B006,		// �m�[�}��11�A�S���A�u���L�I��
	GF_TIMEATK_1_NORMAL_B104,		// �m�[�}��12�A�T���A�G�N�X���[�e��
	GF_TIMEATK_1_NORMAL_B004,		// �m�[�}��13�A�T���A�J�����F���X
	GF_TIMEATK_1_NORMAL_B103,		// �m�[�}��14�A�T���A�s���e�B�X�A�j�}
	GF_TIMEATK_1_NORMAL_B106,		// �m�[�}��15�A�T���A�V�G���J���g�D�X
	GF_TIMEATK_1_NORMAL_B007,		// �m�[�}��16�A�T���A�I�P�A�m�X
	GF_TIMEATK_1_NORMAL_B105,		// �m�[�}��17�A�T���A�h�N�T�E�O���G��
	GF_TIMEATK_1_NORMAL_B005,		// �m�[�}��18�A�T���A�o�V���E�X
	GF_TIMEATK_1_NORMAL_B012,		// �m�[�}��19�A�U���A���E�G�����g����
	GF_TIMEATK_1_NORMAL_B112,		// �m�[�}��20�A�U���A�A�j���X�E�q�h�D��
	GF_TIMEATK_1_NORMAL_B110,		// �m�[�}��21�A�U���A�A�j���X�E�~�m�X
	GF_TIMEATK_1_NORMAL_B111,		// �m�[�}��22�A�U���A�A�j���X�E�l�X�g�[��
	GF_TIMEATK_1_NORMAL_B008,		// �m�[�}��23�A�U���A�A�j���X�E�E�[��
	GF_TIMEATK_1_NORMAL_B021_1,	// �m�[�}��24�A�U���A�e�I�X�E�f�E�G���h���O�����P
	GF_TIMEATK_1_NORMAL_B021_2,	// �m�[�}��25�A�U���A�e�I�X�E�f�E�G���h���O�����Q
	GF_TIMEATK_1_NORMAL_B021_3,	// �m�[�}��26�A�U���A�e�I�X�E�f�E�G���h���O�����R
	GF_TIMEATK_1_NORMAL_B009,		// �m�[�}��27�A�V���A�͂��܂�̖��E�q
	GF_TIMEATK_1_NORMAL_B010,		// �m�[�}��28�A�V���A�͂��܂�̖��E�e
	GF_TIMEATK_1_NORMAL_B155,	// �m�[�}��29�A�V�����B�A
	GF_TIMEATK_1_NORMAL_B151,	// �m�[�}��30�A�}�X�^�[�R���O
	GF_TIMEATK_1_NORMAL_B153,		// �m�[�}��31�A�U���A���t�H���V����
	GF_TIMEATK_1_NORMAL_B170,	// �m�[�}��32�A�U���A�������F�Q�T�ڃ_���W�����{�X
	__GF_TIMEATK_1_NORMAL_RSV33,	// �m�[�}��34�A���U�[�u33
	__GF_TIMEATK_1_NORMAL_RSV34,	// �m�[�}��34�A���U�[�u34
	__GF_TIMEATK_1_NORMAL_RSV35,	// �m�[�}��35�A���U�[�u35
	__GF_TIMEATK_1_NORMAL_RSV36,	// �m�[�}��36�A���U�[�u36
	__GF_TIMEATK_1_NORMAL_RSV37,	// �m�[�}��37�A���U�[�u37
	__GF_TIMEATK_1_NORMAL_RSV38,	// �m�[�}��38�A���U�[�u38
	GF_TIMEATK_1_NORMAL_RUSH,		// �m�[�}��39�A�{�X���b�V��

	GF_TIMEATK_1_NORMAL_ED,

		// HARD1�l�p
	GF_TIMEATK_1_HARD_ST = GF_TIMEATK_1_NORMAL_ED,
	GF_TIMEATK_1_HARD_M0111 = GF_TIMEATK_1_HARD_ST,		// �n�[�h00�A�P���A�r�t�e���U
	GF_TIMEATK_1_HARD_B150,		// �n�[�h01�A�P���A�A���@���h���M��
	GF_TIMEATK_1_HARD_B100,		// �n�[�h02�A�Q���A�Z���y���^�X
	GF_TIMEATK_1_HARD_B000,		// �n�[�h03�A�Q���A�N�����I��
	GF_TIMEATK_1_HARD_B101B,		// �n�[�h04�A�Q���A�����u���Q�E�X
	GF_TIMEATK_1_HARD_B001,		// �n�[�h05�A�Q���A�O���K���`����
	GF_TIMEATK_1_HARD_B102,		// �n�[�h06�A�Q���A�}�K�}���h��
	GF_TIMEATK_1_HARD_B002,		// �n�[�h07�A�Q���A���X�s�X�[�X
	GF_TIMEATK_1_HARD_B152,		// �n�[�h08�A�Q���A�L���S�[��
	GF_TIMEATK_1_HARD_B154,		// �n�[�h09�A�R���A�A���@���h���M��
	GF_TIMEATK_1_HARD_B003,		// �n�[�h10�A�R���A�M�A�X�o�[��
	GF_TIMEATK_1_HARD_B006,		// �n�[�h11�A�S���A�u���L�I��
	GF_TIMEATK_1_HARD_B104,		// �n�[�h12�A�T���A�G�N�X���[�e��
	GF_TIMEATK_1_HARD_B004,		// �n�[�h13�A�T���A�J�����F���X
	GF_TIMEATK_1_HARD_B103,		// �n�[�h14�A�T���A�s���e�B�X�A�j�}
	GF_TIMEATK_1_HARD_B106,		// �n�[�h15�A�T���A�V�G���J���g�D�X
	GF_TIMEATK_1_HARD_B007,		// �n�[�h16�A�T���A�I�P�A�m�X
	GF_TIMEATK_1_HARD_B105,		// �n�[�h17�A�T���A�h�N�T�E�O���G��
	GF_TIMEATK_1_HARD_B005,		// �n�[�h18�A�T���A�o�V���E�X
	GF_TIMEATK_1_HARD_B012,		// �n�[�h19�A�U���A���E�G�����g����
	GF_TIMEATK_1_HARD_B112,		// �n�[�h20�A�U���A�A�j���X�E�q�h�D��
	GF_TIMEATK_1_HARD_B110,		// �n�[�h21�A�U���A�A�j���X�E�~�m�X
	GF_TIMEATK_1_HARD_B111,		// �n�[�h22�A�U���A�A�j���X�E�l�X�g�[��
	GF_TIMEATK_1_HARD_B008,		// �n�[�h23�A�U���A�A�j���X�E�E�[��
	GF_TIMEATK_1_HARD_B021_1,		// �n�[�h24�A�U���A�e�I�X�E�f�E�G���h���O�����P
	GF_TIMEATK_1_HARD_B021_2,		// �n�[�h25�A�U���A�e�I�X�E�f�E�G���h���O�����Q
	GF_TIMEATK_1_HARD_B021_3,		// �n�[�h26�A�U���A�e�I�X�E�f�E�G���h���O�����R
	GF_TIMEATK_1_HARD_B009,		// �n�[�h27�A�V���A�͂��܂�̖��E�q
	GF_TIMEATK_1_HARD_B010,		// �n�[�h28�A�V���A�͂��܂�̖��E�e
	GF_TIMEATK_1_HARD_B155,		// �n�[�h29�A�V�����B�A
	GF_TIMEATK_1_HARD_B151,		// �n�[�h30�A�}�X�^�[�R���O
	GF_TIMEATK_1_HARD_B153,		// �n�[�h31�A�U���A���t�H���V����
	GF_TIMEATK_1_HARD_B170,		// �n�[�h32�A�U���A�������F�Q�T�ڃ_���W�����{�X
	__GF_TIMEATK_1_HARD_RSV33,	// �n�[�h33�A���U�[�u33
	__GF_TIMEATK_1_HARD_RSV34,	// �n�[�h34�A���U�[�u34
	__GF_TIMEATK_1_HARD_RSV35,	// �n�[�h35�A���U�[�u35
	__GF_TIMEATK_1_HARD_RSV36,	// �n�[�h36�A���U�[�u36
	__GF_TIMEATK_1_HARD_RSV37,	// �n�[�h37�A���U�[�u37
	__GF_TIMEATK_1_HARD_RSV38,	// �n�[�h38�A���U�[�u38
	GF_TIMEATK_1_HARD_RUSH,		// �n�[�h39�A�{�X���b�V��

	GF_TIMEATK_1_HARD_ED,

		// NIGHTMARE1�l�p
	GF_TIMEATK_1_NIGHTMARE_ST = GF_TIMEATK_1_HARD_ED,
	GF_TIMEATK_1_NIGHTMARE_M0111 = GF_TIMEATK_1_NIGHTMARE_ST,	// �i�C�g���A00�A�P���A�r�t�e���U
	GF_TIMEATK_1_NIGHTMARE_B150,		// �i�C�g���A01�A�P���A�A���@���h���M��
	GF_TIMEATK_1_NIGHTMARE_B100,		// �i�C�g���A02�A�Q���A�Z���y���^�X
	GF_TIMEATK_1_NIGHTMARE_B000,		// �i�C�g���A03�A�Q���A�N�����I��
	GF_TIMEATK_1_NIGHTMARE_B101B,		// �i�C�g���A04�A�Q���A�����u���Q�E�X
	GF_TIMEATK_1_NIGHTMARE_B001,		// �i�C�g���A05�A�Q���A�O���K���`����
	GF_TIMEATK_1_NIGHTMARE_B102,		// �i�C�g���A06�A�Q���A�}�K�}���h��
	GF_TIMEATK_1_NIGHTMARE_B002,		// �i�C�g���A07�A�Q���A���X�s�X�[�X
	GF_TIMEATK_1_NIGHTMARE_B152,		// �i�C�g���A08�A�Q���A�L���S�[��
	GF_TIMEATK_1_NIGHTMARE_B154,		// �i�C�g���A09�A�R���A�A���@���h���M��
	GF_TIMEATK_1_NIGHTMARE_B003,		// �i�C�g���A10�A�R���A�M�A�X�o�[��
	GF_TIMEATK_1_NIGHTMARE_B006,		// �i�C�g���A11�A�S���A�u���L�I��
	GF_TIMEATK_1_NIGHTMARE_B104,		// �i�C�g���A12�A�T���A�G�N�X���[�e��
	GF_TIMEATK_1_NIGHTMARE_B004,		// �i�C�g���A13�A�T���A�J�����F���X
	GF_TIMEATK_1_NIGHTMARE_B103,		// �i�C�g���A14�A�T���A�s���e�B�X�A�j�}
	GF_TIMEATK_1_NIGHTMARE_B106,		// �i�C�g���A15�A�T���A�V�G���J���g�D�X
	GF_TIMEATK_1_NIGHTMARE_B007,		// �i�C�g���A16�A�T���A�I�P�A�m�X
	GF_TIMEATK_1_NIGHTMARE_B105,		// �i�C�g���A17�A�T���A�h�N�T�E�O���G��
	GF_TIMEATK_1_NIGHTMARE_B005,		// �i�C�g���A18�A�T���A�o�V���E�X
	GF_TIMEATK_1_NIGHTMARE_B012,		// �i�C�g���A19�A�U���A���E�G�����g����
	GF_TIMEATK_1_NIGHTMARE_B112,		// �i�C�g���A20�A�U���A�A�j���X�E�q�h�D��
	GF_TIMEATK_1_NIGHTMARE_B110,		// �i�C�g���A21�A�U���A�A�j���X�E�~�m�X
	GF_TIMEATK_1_NIGHTMARE_B111,		// �i�C�g���A22�A�U���A�A�j���X�E�l�X�g�[��
	GF_TIMEATK_1_NIGHTMARE_B008,		// �i�C�g���A23�A�U���A�A�j���X�E�E�[��
	GF_TIMEATK_1_NIGHTMARE_B021_1,	// �i�C�g���A24�A�U���A�e�I�X�E�f�E�G���h���O�����P
	GF_TIMEATK_1_NIGHTMARE_B021_2,	// �i�C�g���A25�A�U���A�e�I�X�E�f�E�G���h���O�����Q
	GF_TIMEATK_1_NIGHTMARE_B021_3,	// �i�C�g���A26�A�U���A�e�I�X�E�f�E�G���h���O�����R
	GF_TIMEATK_1_NIGHTMARE_B009,		// �i�C�g���A27�A�V���A�͂��܂�̖��E�q
	GF_TIMEATK_1_NIGHTMARE_B010,		// �i�C�g���A28�A�V���A�͂��܂�̖��E�e
	GF_TIMEATK_1_NIGHTMARE_B155,		// �i�C�g���A29�A�V�����B�A
	GF_TIMEATK_1_NIGHTMARE_B151,		// �i�C�g���A30�A�}�X�^�[�R���O
	GF_TIMEATK_1_NIGHTMARE_B153,		// �i�C�g���A31�A�U���A���t�H���V����
	GF_TIMEATK_1_NIGHTMARE_B170,		// �i�C�g���A32�A�U���A�������F�Q�T�ڃ_���W�����{�X
	__GF_TIMEATK_1_NIGHTMARE_RSV33,	// �i�C�g���A33�A���U�[�u33
	__GF_TIMEATK_1_NIGHTMARE_RSV34,	// �i�C�g���A34�A���U�[�u34
	__GF_TIMEATK_1_NIGHTMARE_RSV35,	// �i�C�g���A35�A���U�[�u35
	__GF_TIMEATK_1_NIGHTMARE_RSV36,	// �i�C�g���A36�A���U�[�u36
	__GF_TIMEATK_1_NIGHTMARE_RSV37,	// �i�C�g���A37�A���U�[�u37
	__GF_TIMEATK_1_NIGHTMARE_RSV38,	// �i�C�g���A38�A���U�[�u38
	GF_TIMEATK_1_NIGHTMARE_RUSH,		// �i�C�g���A39�A�{�X���b�V��

	GF_TIMEATK_1_NIGHTMARE_ED,

		// INFERNO1�l�p
	GF_TIMEATK_1_INFERNO_ST = GF_TIMEATK_1_NIGHTMARE_ED,
	GF_TIMEATK_1_INFERNO_M0111 = GF_TIMEATK_1_INFERNO_ST,	// �C���t�F���m00�A�P���A�r�t�e���U
	GF_TIMEATK_1_INFERNO_B150,		// �C���t�F���m01�A�P���A�A���@���h���M��
	GF_TIMEATK_1_INFERNO_B100,		// �C���t�F���m02�A�Q���A�Z���y���^�X
	GF_TIMEATK_1_INFERNO_B000,		// �C���t�F���m03�A�Q���A�N�����I��
	GF_TIMEATK_1_INFERNO_B101B,		// �C���t�F���m04�A�Q���A�����u���Q�E�X
	GF_TIMEATK_1_INFERNO_B001,		// �C���t�F���m05�A�Q���A�O���K���`����
	GF_TIMEATK_1_INFERNO_B102,		// �C���t�F���m06�A�Q���A�}�K�}���h��
	GF_TIMEATK_1_INFERNO_B002,		// �C���t�F���m07�A�Q���A���X�s�X�[�X
	GF_TIMEATK_1_INFERNO_B152,		// �C���t�F���m08�A�Q���A�L���S�[��
	GF_TIMEATK_1_INFERNO_B154,		// �C���t�F���m09�A�R���A�A���@���h���M��
	GF_TIMEATK_1_INFERNO_B003,		// �C���t�F���m10�A�R���A�M�A�X�o�[��
	GF_TIMEATK_1_INFERNO_B006,		// �C���t�F���m11�A�S���A�u���L�I��
	GF_TIMEATK_1_INFERNO_B104,		// �C���t�F���m12�A�T���A�G�N�X���[�e��
	GF_TIMEATK_1_INFERNO_B004,		// �C���t�F���m13�A�T���A�J�����F���X
	GF_TIMEATK_1_INFERNO_B103,		// �C���t�F���m14�A�T���A�s���e�B�X�A�j�}
	GF_TIMEATK_1_INFERNO_B106,		// �C���t�F���m15�A�T���A�V�G���J���g�D�X
	GF_TIMEATK_1_INFERNO_B007,		// �C���t�F���m16�A�T���A�I�P�A�m�X
	GF_TIMEATK_1_INFERNO_B105,		// �C���t�F���m17�A�T���A�h�N�T�E�O���G��
	GF_TIMEATK_1_INFERNO_B005,		// �C���t�F���m18�A�T���A�o�V���E�X
	GF_TIMEATK_1_INFERNO_B012,		// �C���t�F���m19�A�U���A���E�G�����g����
	GF_TIMEATK_1_INFERNO_B112,		// �C���t�F���m20�A�U���A�A�j���X�E�q�h�D��
	GF_TIMEATK_1_INFERNO_B110,		// �C���t�F���m21�A�U���A�A�j���X�E�~�m�X
	GF_TIMEATK_1_INFERNO_B111,		// �C���t�F���m22�A�U���A�A�j���X�E�l�X�g�[��
	GF_TIMEATK_1_INFERNO_B008,		// �C���t�F���m23�A�U���A�A�j���X�E�E�[��
	GF_TIMEATK_1_INFERNO_B021_1,		// �C���t�F���m24�A�U���A�e�I�X�E�f�E�G���h���O�����P
	GF_TIMEATK_1_INFERNO_B021_2,		// �C���t�F���m25�A�U���A�e�I�X�E�f�E�G���h���O�����Q
	GF_TIMEATK_1_INFERNO_B021_3,		// �C���t�F���m26�A�U���A�e�I�X�E�f�E�G���h���O�����R
	GF_TIMEATK_1_INFERNO_B009,		// �C���t�F���m27�A�V���A�͂��܂�̖��E�q
	GF_TIMEATK_1_INFERNO_B010,		// �C���t�F���m28�A�V���A�͂��܂�̖��E�e
	GF_TIMEATK_1_INFERNO_B155,		// �C���t�F���m29�A�V�����B�A
	GF_TIMEATK_1_INFERNO_B151,		// �C���t�F���m30�A�}�X�^�[�R���O
	GF_TIMEATK_1_INFERNO_B153,		// �C���t�F���m31�A�U���A���t�H���V����
	GF_TIMEATK_1_INFERNO_B170,		// �C���t�F���m32�A�U���A�������F�Q�T�ڃ_���W�����{�X
	__GF_TIMEATK_1_INFERNO_RSV33,		// �C���t�F���m33�A���U�[�u33
	__GF_TIMEATK_1_INFERNO_RSV34,		// �C���t�F���m34�A���U�[�u34
	__GF_TIMEATK_1_INFERNO_RSV35,		// �C���t�F���m35�A���U�[�u35
	__GF_TIMEATK_1_INFERNO_RSV36,		// �C���t�F���m36�A���U�[�u36
	__GF_TIMEATK_1_INFERNO_RSV37,		// �C���t�F���m37�A���U�[�u37
	__GF_TIMEATK_1_INFERNO_RSV38,		// �C���t�F���m38�A���U�[�u38
	GF_TIMEATK_1_INFERNO_RUSH,		// �C���t�F���m39�A�{�X���b�V��

	GF_TIMEATK_1_INFERNO_ED,

	// ����҃p�[�e�B�����o�[

		// EASY����҃p�[�e�B�����o�[�p
	GF_TIMEATK_M_EASY_ST = GF_TIMEATK_1_INFERNO_ED,
	GF_TIMEATK_M_EASY_M0111 = GF_TIMEATK_M_EASY_ST,	// �C�[�W�[00�A�P���A�r�t�e���U
	GF_TIMEATK_M_EASY_B150,	// �C�[�W�[01�A�P���A�A���@���h���M��
	GF_TIMEATK_M_EASY_B100,	// �C�[�W�[02�A�Q���A�Z���y���^�X
	GF_TIMEATK_M_EASY_B000,	// �C�[�W�[03�A�Q���A�N�����I��
	GF_TIMEATK_M_EASY_B101B,	// �C�[�W�[04�A�Q���A�����u���Q�E�X
	GF_TIMEATK_M_EASY_B001,	// �C�[�W�[05�A�Q���A�O���K���`����
	GF_TIMEATK_M_EASY_B102,	// �C�[�W�[06�A�Q���A�}�K�}���h��
	GF_TIMEATK_M_EASY_B002,	// �C�[�W�[07�A�Q���A���X�s�X�[�X
	GF_TIMEATK_M_EASY_B152,	// �C�[�W�[08�A�Q���A�L���S�[��
	GF_TIMEATK_M_EASY_B154,	// �C�[�W�[09�A�R���A�A���@���h���M��
	GF_TIMEATK_M_EASY_B003,	// �C�[�W�[10�A�R���A�M�A�X�o�[��
	GF_TIMEATK_M_EASY_B006,	// �C�[�W�[11�A�S���A�u���L�I��
	GF_TIMEATK_M_EASY_B104,	// �C�[�W�[12�A�T���A�G�N�X���[�e��
	GF_TIMEATK_M_EASY_B004,	// �C�[�W�[13�A�T���A�J�����F���X
	GF_TIMEATK_M_EASY_B103,	// �C�[�W�[14�A�T���A�s���e�B�X�A�j�}
	GF_TIMEATK_M_EASY_B106,	// �C�[�W�[15�A�T���A�V�G���J���g�D�X
	GF_TIMEATK_M_EASY_B007,	// �C�[�W�[16�A�T���A�I�P�A�m�X
	GF_TIMEATK_M_EASY_B105,	// �C�[�W�[17�A�T���A�h�N�T�E�O���G��
	GF_TIMEATK_M_EASY_B005,	// �C�[�W�[18�A�T���A�o�V���E�X
	GF_TIMEATK_M_EASY_B012,	// �C�[�W�[19�A�U���A���E�G�����g����
	GF_TIMEATK_M_EASY_B112,	// �C�[�W�[20�A�U���A�A�j���X�E�q�h�D��
	GF_TIMEATK_M_EASY_B110,	// �C�[�W�[21�A�U���A�A�j���X�E�~�m�X
	GF_TIMEATK_M_EASY_B111,	// �C�[�W�[22�A�U���A�A�j���X�E�l�X�g�[��
	GF_TIMEATK_M_EASY_B008,	// �C�[�W�[23�A�U���A�A�j���X�E�E�[��
	GF_TIMEATK_M_EASY_B021_1,	// �C�[�W�[24�A�U���A�e�I�X�E�f�E�G���h���O�����P
	GF_TIMEATK_M_EASY_B021_2,	// �C�[�W�[25�A�U���A�e�I�X�E�f�E�G���h���O�����Q
	GF_TIMEATK_M_EASY_B021_3,	// �C�[�W�[26�A�U���A�e�I�X�E�f�E�G���h���O�����R
	GF_TIMEATK_M_EASY_B009,	// �C�[�W�[28�A�V���A�͂��܂�̖��E�q
	GF_TIMEATK_M_EASY_B010,	// �C�[�W�[28�A�V���A�͂��܂�̖��E�e
	GF_TIMEATK_M_EASY_B155,	// �C�[�W�[29�A�V�����B�A
	GF_TIMEATK_M_EASY_B151,	// �C�[�W�[30�A�}�X�^�[�R���O
	GF_TIMEATK_M_EASY_B153,	// �C�[�W�[31�A�U���A���t�H���V����
	GF_TIMEATK_M_EASY_B170,	// �C�[�W�[32�A�U���A�������F�Q�T�ڃ_���W�����{�X
	__GF_TIMEATK_M_EASY_RSV33,// �C�[�W�[34�A���U�[�u33
	__GF_TIMEATK_M_EASY_RSV34,// �C�[�W�[34�A���U�[�u34
	__GF_TIMEATK_M_EASY_RSV35,// �C�[�W�[35�A���U�[�u35
	__GF_TIMEATK_M_EASY_RSV36,// �C�[�W�[36�A���U�[�u36
	__GF_TIMEATK_M_EASY_RSV37,// �C�[�W�[37�A���U�[�u37
	__GF_TIMEATK_M_EASY_RSV38,// �C�[�W�[38�A���U�[�u38
	GF_TIMEATK_M_EASY_RUSH,	// �C�[�W�[39�A�{�X���b�V��

	GF_TIMEATK_M_EASY_ED,

		// NORMAL����҃p�[�e�B�����o�[�p
	GF_TIMEATK_M_NORMAL_ST = GF_TIMEATK_M_EASY_ED,
	GF_TIMEATK_M_NORMAL_M0111 = GF_TIMEATK_M_NORMAL_ST,	// �m�[�}��00�A�P���A�r�t�e���U
	GF_TIMEATK_M_NORMAL_B150,		// �m�[�}��01�A�P���A�A���@���h���M��
	GF_TIMEATK_M_NORMAL_B100,		// �m�[�}��02�A�Q���A�Z���y���^�X
	GF_TIMEATK_M_NORMAL_B000,		// �m�[�}��03�A�Q���A�N�����I��
	GF_TIMEATK_M_NORMAL_B101B,	// �m�[�}��04�A�Q���A�����u���Q�E�X
	GF_TIMEATK_M_NORMAL_B001,		// �m�[�}��05�A�Q���A�O���K���`����
	GF_TIMEATK_M_NORMAL_B102,		// �m�[�}��06�A�Q���A�}�K�}���h��
	GF_TIMEATK_M_NORMAL_B002,		// �m�[�}��07�A�Q���A���X�s�X�[�X
	GF_TIMEATK_M_NORMAL_B152,		// �m�[�}��08�A�Q���A�L���S�[��
	GF_TIMEATK_M_NORMAL_B154,		// �m�[�}��09�A�R���A�A���@���h���M��
	GF_TIMEATK_M_NORMAL_B003,		// �m�[�}��10�A�R���A�M�A�X�o�[��
	GF_TIMEATK_M_NORMAL_B006,		// �m�[�}��11�A�S���A�u���L�I��
	GF_TIMEATK_M_NORMAL_B104,		// �m�[�}��12�A�T���A�G�N�X���[�e��
	GF_TIMEATK_M_NORMAL_B004,		// �m�[�}��13�A�T���A�J�����F���X
	GF_TIMEATK_M_NORMAL_B103,		// �m�[�}��14�A�T���A�s���e�B�X�A�j�}
	GF_TIMEATK_M_NORMAL_B106,		// �m�[�}��15�A�T���A�V�G���J���g�D�X
	GF_TIMEATK_M_NORMAL_B007,		// �m�[�}��16�A�T���A�I�P�A�m�X
	GF_TIMEATK_M_NORMAL_B105,		// �m�[�}��17�A�T���A�h�N�T�E�O���G��
	GF_TIMEATK_M_NORMAL_B005,		// �m�[�}��18�A�T���A�o�V���E�X
	GF_TIMEATK_M_NORMAL_B012,		// �m�[�}��19�A�U���A���E�G�����g����
	GF_TIMEATK_M_NORMAL_B112,		// �m�[�}��20�A�U���A�A�j���X�E�q�h�D��
	GF_TIMEATK_M_NORMAL_B110,		// �m�[�}��21�A�U���A�A�j���X�E�~�m�X
	GF_TIMEATK_M_NORMAL_B111,		// �m�[�}��22�A�U���A�A�j���X�E�l�X�g�[��
	GF_TIMEATK_M_NORMAL_B008,		// �m�[�}��23�A�U���A�A�j���X�E�E�[��
	GF_TIMEATK_M_NORMAL_B021_1,	// �m�[�}��24�A�U���A�e�I�X�E�f�E�G���h���O�����P
	GF_TIMEATK_M_NORMAL_B021_2,	// �m�[�}��25�A�U���A�e�I�X�E�f�E�G���h���O�����Q
	GF_TIMEATK_M_NORMAL_B021_3,	// �m�[�}��26�A�U���A�e�I�X�E�f�E�G���h���O�����R
	GF_TIMEATK_M_NORMAL_B009,		// �m�[�}��27�A�V���A�͂��܂�̖��E�q
	GF_TIMEATK_M_NORMAL_B010,		// �m�[�}��28�A�V���A�͂��܂�̖��E�e
	GF_TIMEATK_M_NORMAL_B155,	// �m�[�}��29�A�V�����B�A
	GF_TIMEATK_M_NORMAL_B151,	// �m�[�}��30�A�}�X�^�[�R���O
	GF_TIMEATK_M_NORMAL_B153,		// �m�[�}��31�A�U���A���t�H���V����
	GF_TIMEATK_M_NORMAL_B170,	// �m�[�}��32�A�U���A�������F�Q�T�ڃ_���W�����{�X
	__GF_TIMEATK_M_NORMAL_RSV33,	// �m�[�}��34�A���U�[�u33
	__GF_TIMEATK_M_NORMAL_RSV34,	// �m�[�}��34�A���U�[�u34
	__GF_TIMEATK_M_NORMAL_RSV35,	// �m�[�}��35�A���U�[�u35
	__GF_TIMEATK_M_NORMAL_RSV36,	// �m�[�}��36�A���U�[�u36
	__GF_TIMEATK_M_NORMAL_RSV37,	// �m�[�}��37�A���U�[�u37
	__GF_TIMEATK_M_NORMAL_RSV38,	// �m�[�}��38�A���U�[�u38
	GF_TIMEATK_M_NORMAL_RUSH,		// �m�[�}��39�A�{�X���b�V��

	GF_TIMEATK_M_NORMAL_ED,

		// HARD����҃p�[�e�B�����o�[�p
	GF_TIMEATK_M_HARD_ST = GF_TIMEATK_M_NORMAL_ED,
	GF_TIMEATK_M_HARD_M0111 = GF_TIMEATK_M_HARD_ST,		// �n�[�h00�A�P���A�r�t�e���U
	GF_TIMEATK_M_HARD_B150,		// �n�[�h01�A�P���A�A���@���h���M��
	GF_TIMEATK_M_HARD_B100,		// �n�[�h02�A�Q���A�Z���y���^�X
	GF_TIMEATK_M_HARD_B000,		// �n�[�h03�A�Q���A�N�����I��
	GF_TIMEATK_M_HARD_B101B,		// �n�[�h04�A�Q���A�����u���Q�E�X
	GF_TIMEATK_M_HARD_B001,		// �n�[�h05�A�Q���A�O���K���`����
	GF_TIMEATK_M_HARD_B102,		// �n�[�h06�A�Q���A�}�K�}���h��
	GF_TIMEATK_M_HARD_B002,		// �n�[�h07�A�Q���A���X�s�X�[�X
	GF_TIMEATK_M_HARD_B152,		// �n�[�h08�A�Q���A�L���S�[��
	GF_TIMEATK_M_HARD_B154,		// �n�[�h09�A�R���A�A���@���h���M��
	GF_TIMEATK_M_HARD_B003,		// �n�[�h10�A�R���A�M�A�X�o�[��
	GF_TIMEATK_M_HARD_B006,		// �n�[�h11�A�S���A�u���L�I��
	GF_TIMEATK_M_HARD_B104,		// �n�[�h12�A�T���A�G�N�X���[�e��
	GF_TIMEATK_M_HARD_B004,		// �n�[�h13�A�T���A�J�����F���X
	GF_TIMEATK_M_HARD_B103,		// �n�[�h14�A�T���A�s���e�B�X�A�j�}
	GF_TIMEATK_M_HARD_B106,		// �n�[�h15�A�T���A�V�G���J���g�D�X
	GF_TIMEATK_M_HARD_B007,		// �n�[�h16�A�T���A�I�P�A�m�X
	GF_TIMEATK_M_HARD_B105,		// �n�[�h17�A�T���A�h�N�T�E�O���G��
	GF_TIMEATK_M_HARD_B005,		// �n�[�h18�A�T���A�o�V���E�X
	GF_TIMEATK_M_HARD_B012,		// �n�[�h19�A�U���A���E�G�����g����
	GF_TIMEATK_M_HARD_B112,		// �n�[�h20�A�U���A�A�j���X�E�q�h�D��
	GF_TIMEATK_M_HARD_B110,		// �n�[�h21�A�U���A�A�j���X�E�~�m�X
	GF_TIMEATK_M_HARD_B111,		// �n�[�h22�A�U���A�A�j���X�E�l�X�g�[��
	GF_TIMEATK_M_HARD_B008,		// �n�[�h23�A�U���A�A�j���X�E�E�[��
	GF_TIMEATK_M_HARD_B021_1,		// �n�[�h24�A�U���A�e�I�X�E�f�E�G���h���O�����P
	GF_TIMEATK_M_HARD_B021_2,		// �n�[�h25�A�U���A�e�I�X�E�f�E�G���h���O�����Q
	GF_TIMEATK_M_HARD_B021_3,		// �n�[�h26�A�U���A�e�I�X�E�f�E�G���h���O�����R
	GF_TIMEATK_M_HARD_B009,		// �n�[�h27�A�V���A�͂��܂�̖��E�q
	GF_TIMEATK_M_HARD_B010,		// �n�[�h28�A�V���A�͂��܂�̖��E�e
	GF_TIMEATK_M_HARD_B155,		// �n�[�h29�A�V�����B�A
	GF_TIMEATK_M_HARD_B151,		// �n�[�h30�A�}�X�^�[�R���O
	GF_TIMEATK_M_HARD_B153,		// �n�[�h31�A�U���A���t�H���V����
	GF_TIMEATK_M_HARD_B170,		// �n�[�h32�A�U���A�������F�Q�T�ڃ_���W�����{�X
	__GF_TIMEATK_M_HARD_RSV33,	// �n�[�h33�A���U�[�u33
	__GF_TIMEATK_M_HARD_RSV34,	// �n�[�h34�A���U�[�u34
	__GF_TIMEATK_M_HARD_RSV35,	// �n�[�h35�A���U�[�u35
	__GF_TIMEATK_M_HARD_RSV36,	// �n�[�h36�A���U�[�u36
	__GF_TIMEATK_M_HARD_RSV37,	// �n�[�h37�A���U�[�u37
	__GF_TIMEATK_M_HARD_RSV38,	// �n�[�h38�A���U�[�u38
	GF_TIMEATK_M_HARD_RUSH,		// �n�[�h39�A�{�X���b�V��

	GF_TIMEATK_M_HARD_ED,

		// NIGHTMARE����҃p�[�e�B�����o�[�p
	GF_TIMEATK_M_NIGHTMARE_ST = GF_TIMEATK_M_HARD_ED,
	GF_TIMEATK_M_NIGHTMARE_M0111 = GF_TIMEATK_M_NIGHTMARE_ST,	// �i�C�g���A00�A�P���A�r�t�e���U
	GF_TIMEATK_M_NIGHTMARE_B150,		// �i�C�g���A01�A�P���A�A���@���h���M��
	GF_TIMEATK_M_NIGHTMARE_B100,		// �i�C�g���A02�A�Q���A�Z���y���^�X
	GF_TIMEATK_M_NIGHTMARE_B000,		// �i�C�g���A03�A�Q���A�N�����I��
	GF_TIMEATK_M_NIGHTMARE_B101B,		// �i�C�g���A04�A�Q���A�����u���Q�E�X
	GF_TIMEATK_M_NIGHTMARE_B001,		// �i�C�g���A05�A�Q���A�O���K���`����
	GF_TIMEATK_M_NIGHTMARE_B102,		// �i�C�g���A06�A�Q���A�}�K�}���h��
	GF_TIMEATK_M_NIGHTMARE_B002,		// �i�C�g���A07�A�Q���A���X�s�X�[�X
	GF_TIMEATK_M_NIGHTMARE_B152,		// �i�C�g���A08�A�Q���A�L���S�[��
	GF_TIMEATK_M_NIGHTMARE_B154,		// �i�C�g���A09�A�R���A�A���@���h���M��
	GF_TIMEATK_M_NIGHTMARE_B003,		// �i�C�g���A10�A�R���A�M�A�X�o�[��
	GF_TIMEATK_M_NIGHTMARE_B006,		// �i�C�g���A11�A�S���A�u���L�I��
	GF_TIMEATK_M_NIGHTMARE_B104,		// �i�C�g���A12�A�T���A�G�N�X���[�e��
	GF_TIMEATK_M_NIGHTMARE_B004,		// �i�C�g���A13�A�T���A�J�����F���X
	GF_TIMEATK_M_NIGHTMARE_B103,		// �i�C�g���A14�A�T���A�s���e�B�X�A�j�}
	GF_TIMEATK_M_NIGHTMARE_B106,		// �i�C�g���A15�A�T���A�V�G���J���g�D�X
	GF_TIMEATK_M_NIGHTMARE_B007,		// �i�C�g���A16�A�T���A�I�P�A�m�X
	GF_TIMEATK_M_NIGHTMARE_B105,		// �i�C�g���A17�A�T���A�h�N�T�E�O���G��
	GF_TIMEATK_M_NIGHTMARE_B005,		// �i�C�g���A18�A�T���A�o�V���E�X
	GF_TIMEATK_M_NIGHTMARE_B012,		// �i�C�g���A19�A�U���A���E�G�����g����
	GF_TIMEATK_M_NIGHTMARE_B112,		// �i�C�g���A20�A�U���A�A�j���X�E�q�h�D��
	GF_TIMEATK_M_NIGHTMARE_B110,		// �i�C�g���A21�A�U���A�A�j���X�E�~�m�X
	GF_TIMEATK_M_NIGHTMARE_B111,		// �i�C�g���A22�A�U���A�A�j���X�E�l�X�g�[��
	GF_TIMEATK_M_NIGHTMARE_B008,		// �i�C�g���A23�A�U���A�A�j���X�E�E�[��
	GF_TIMEATK_M_NIGHTMARE_B021_1,	// �i�C�g���A24�A�U���A�e�I�X�E�f�E�G���h���O�����P
	GF_TIMEATK_M_NIGHTMARE_B021_2,	// �i�C�g���A25�A�U���A�e�I�X�E�f�E�G���h���O�����Q
	GF_TIMEATK_M_NIGHTMARE_B021_3,	// �i�C�g���A26�A�U���A�e�I�X�E�f�E�G���h���O�����R
	GF_TIMEATK_M_NIGHTMARE_B009,		// �i�C�g���A27�A�V���A�͂��܂�̖��E�q
	GF_TIMEATK_M_NIGHTMARE_B010,		// �i�C�g���A28�A�V���A�͂��܂�̖��E�e
	GF_TIMEATK_M_NIGHTMARE_B155,		// �i�C�g���A29�A�V�����B�A
	GF_TIMEATK_M_NIGHTMARE_B151,		// �i�C�g���A30�A�}�X�^�[�R���O
	GF_TIMEATK_M_NIGHTMARE_B153,		// �i�C�g���A31�A�U���A���t�H���V����
	GF_TIMEATK_M_NIGHTMARE_B170,		// �i�C�g���A32�A�U���A�������F�Q�T�ڃ_���W�����{�X
	__GF_TIMEATK_M_NIGHTMARE_RSV33,	// �i�C�g���A33�A���U�[�u33
	__GF_TIMEATK_M_NIGHTMARE_RSV34,	// �i�C�g���A34�A���U�[�u34
	__GF_TIMEATK_M_NIGHTMARE_RSV35,	// �i�C�g���A35�A���U�[�u35
	__GF_TIMEATK_M_NIGHTMARE_RSV36,	// �i�C�g���A36�A���U�[�u36
	__GF_TIMEATK_M_NIGHTMARE_RSV37,	// �i�C�g���A37�A���U�[�u37
	__GF_TIMEATK_M_NIGHTMARE_RSV38,	// �i�C�g���A38�A���U�[�u38
	GF_TIMEATK_M_NIGHTMARE_RUSH,		// �i�C�g���A39�A�{�X���b�V��

	GF_TIMEATK_M_NIGHTMARE_ED,

		// INFERNO����҃p�[�e�B�����o�[�p
	GF_TIMEATK_M_INFERNO_ST = GF_TIMEATK_M_NIGHTMARE_ED,
	GF_TIMEATK_M_INFERNO_M0111 = GF_TIMEATK_M_INFERNO_ST,	// �C���t�F���m00�A�P���A�r�t�e���U
	GF_TIMEATK_M_INFERNO_B150,		// �C���t�F���m01�A�P���A�A���@���h���M��
	GF_TIMEATK_M_INFERNO_B100,		// �C���t�F���m02�A�Q���A�Z���y���^�X
	GF_TIMEATK_M_INFERNO_B000,		// �C���t�F���m03�A�Q���A�N�����I��
	GF_TIMEATK_M_INFERNO_B101B,		// �C���t�F���m04�A�Q���A�����u���Q�E�X
	GF_TIMEATK_M_INFERNO_B001,		// �C���t�F���m05�A�Q���A�O���K���`����
	GF_TIMEATK_M_INFERNO_B102,		// �C���t�F���m06�A�Q���A�}�K�}���h��
	GF_TIMEATK_M_INFERNO_B002,		// �C���t�F���m07�A�Q���A���X�s�X�[�X
	GF_TIMEATK_M_INFERNO_B152,		// �C���t�F���m08�A�Q���A�L���S�[��
	GF_TIMEATK_M_INFERNO_B154,		// �C���t�F���m09�A�R���A�A���@���h���M��
	GF_TIMEATK_M_INFERNO_B003,		// �C���t�F���m10�A�R���A�M�A�X�o�[��
	GF_TIMEATK_M_INFERNO_B006,		// �C���t�F���m11�A�S���A�u���L�I��
	GF_TIMEATK_M_INFERNO_B104,		// �C���t�F���m12�A�T���A�G�N�X���[�e��
	GF_TIMEATK_M_INFERNO_B004,		// �C���t�F���m13�A�T���A�J�����F���X
	GF_TIMEATK_M_INFERNO_B103,		// �C���t�F���m14�A�T���A�s���e�B�X�A�j�}
	GF_TIMEATK_M_INFERNO_B106,		// �C���t�F���m15�A�T���A�V�G���J���g�D�X
	GF_TIMEATK_M_INFERNO_B007,		// �C���t�F���m16�A�T���A�I�P�A�m�X
	GF_TIMEATK_M_INFERNO_B105,		// �C���t�F���m17�A�T���A�h�N�T�E�O���G��
	GF_TIMEATK_M_INFERNO_B005,		// �C���t�F���m18�A�T���A�o�V���E�X
	GF_TIMEATK_M_INFERNO_B012,		// �C���t�F���m19�A�U���A���E�G�����g����
	GF_TIMEATK_M_INFERNO_B112,		// �C���t�F���m20�A�U���A�A�j���X�E�q�h�D��
	GF_TIMEATK_M_INFERNO_B110,		// �C���t�F���m21�A�U���A�A�j���X�E�~�m�X
	GF_TIMEATK_M_INFERNO_B111,		// �C���t�F���m22�A�U���A�A�j���X�E�l�X�g�[��
	GF_TIMEATK_M_INFERNO_B008,		// �C���t�F���m23�A�U���A�A�j���X�E�E�[��
	GF_TIMEATK_M_INFERNO_B021_1,		// �C���t�F���m24�A�U���A�e�I�X�E�f�E�G���h���O�����P
	GF_TIMEATK_M_INFERNO_B021_2,		// �C���t�F���m25�A�U���A�e�I�X�E�f�E�G���h���O�����Q
	GF_TIMEATK_M_INFERNO_B021_3,		// �C���t�F���m26�A�U���A�e�I�X�E�f�E�G���h���O�����R
	GF_TIMEATK_M_INFERNO_B009,		// �C���t�F���m27�A�V���A�͂��܂�̖��E�q
	GF_TIMEATK_M_INFERNO_B010,		// �C���t�F���m28�A�V���A�͂��܂�̖��E�e
	GF_TIMEATK_M_INFERNO_B155,		// �C���t�F���m29�A�V�����B�A
	GF_TIMEATK_M_INFERNO_B151,		// �C���t�F���m30�A�}�X�^�[�R���O
	GF_TIMEATK_M_INFERNO_B153,		// �C���t�F���m31�A�U���A���t�H���V����
	GF_TIMEATK_M_INFERNO_B170,		// �C���t�F���m32�A�U���A�������F�Q�T�ڃ_���W�����{�X
	__GF_TIMEATK_M_INFERNO_RSV33,		// �C���t�F���m33�A���U�[�u33
	__GF_TIMEATK_M_INFERNO_RSV34,		// �C���t�F���m34�A���U�[�u34
	__GF_TIMEATK_M_INFERNO_RSV35,		// �C���t�F���m35�A���U�[�u35
	__GF_TIMEATK_M_INFERNO_RSV36,		// �C���t�F���m36�A���U�[�u36
	__GF_TIMEATK_M_INFERNO_RSV37,		// �C���t�F���m37�A���U�[�u37
	__GF_TIMEATK_M_INFERNO_RSV38,		// �C���t�F���m38�A���U�[�u38
	GF_TIMEATK_M_INFERNO_RUSH,		// �C���t�F���m39�A�{�X���b�V��

	GF_TIMEATK_M_INFERNO_ED,

	// �_�[�i��

		// �_�[�i��EASY�p
	GF_TIMEATK_D_EASY_ST = GF_TIMEATK_M_INFERNO_ED,

	GF_TIMEATK_D_EASY_B161 = GF_TIMEATK_D_EASY_ST,		// �_�[�i�҃C�[�W�[00�A�������F��P�w�A���{�X
	GF_TIMEATK_D_EASY_B162,			// �_�[�i�҃C�[�W�[01�A�������F��Q�w�A���{�X
	GF_TIMEATK_D_EASY_B163,			// �_�[�i�҃C�[�W�[02�A�������F��R�w�A���{�X
	GF_TIMEATK_D_EASY_B011,			// �_�[�i�҃C�[�W�[03�A�U���A���E�L���A�m�X
	GF_TIMEATK_D_EASY_B164,			// �_�[�i�҃C�[�W�[04�A�������F��S�w�A���{�X
	GF_TIMEATK_D_EASY_B165,			// �_�[�i�҃C�[�W�[05�A�������F��T�w�A���{�X
	GF_TIMEATK_D_EASY_B030,			// �_�[�i�҃C�[�W�[06�A�������F�C�I
	__GF_TIMEATK_D_EASY_RSV07,		// �_�[�i�҃C�[�W�[07�A���U�[�u07
	__GF_TIMEATK_D_EASY_RSV08,		// �_�[�i�҃C�[�W�[08�A���U�[�u08
	GF_TIMEATK_D_EASY_RUSH,			// �_�[�i�҃C�[�W�[09�A�{�X���b�V��

	GF_TIMEATK_D_EASY_ED,

		// �_�[�i��NORMAL�p
	GF_TIMEATK_D_NORMAL_ST = GF_TIMEATK_D_EASY_ED,

	GF_TIMEATK_D_NORMAL_B161 = GF_TIMEATK_D_NORMAL_ST,		// �_�[�i�҃m�[�}��00�A�������F��P�w�A���{�X
	GF_TIMEATK_D_NORMAL_B162,		// �_�[�i�҃m�[�}��01�A�������F��Q�w�A���{�X
	GF_TIMEATK_D_NORMAL_B163,		// �_�[�i�҃m�[�}��02�A�������F��R�w�A���{�X
	GF_TIMEATK_D_NORMAL_B011,		// �_�[�i�҃m�[�}��03�A�U���A���E�L���A�m�X
	GF_TIMEATK_D_NORMAL_B164,		// �_�[�i�҃m�[�}��04�A�������F��S�w�A���{�X
	GF_TIMEATK_D_NORMAL_B165,		// �_�[�i�҃m�[�}��05�A�������F��T�w�A���{�X
	GF_TIMEATK_D_NORMAL_B030,		// �_�[�i�҃m�[�}��06�A�������F�C�I
	__GF_TIMEATK_D_NORMAL_RSV07,	// �_�[�i�҃m�[�}��07�A���U�[�u07
	__GF_TIMEATK_D_NORMAL_RSV08,	// �_�[�i�҃m�[�}��08�A���U�[�u08
	GF_TIMEATK_D_NORMAL_RUSH,		// �_�[�i�҃m�[�}��09�A�{�X���b�V��

	GF_TIMEATK_D_NORMAL_ED,

		// �_�[�i��HARD�p
	GF_TIMEATK_D_HARD_ST = GF_TIMEATK_D_NORMAL_ED,

	GF_TIMEATK_D_HARD_B161 = GF_TIMEATK_D_HARD_ST,		// �_�[�i�҃n�[�h00�A�������F��P�w�A���{�X
	GF_TIMEATK_D_HARD_B162,			// �_�[�i�҃n�[�h01�A�������F��Q�w�A���{�X
	GF_TIMEATK_D_HARD_B163,			// �_�[�i�҃n�[�h02�A�������F��R�w�A���{�X
	GF_TIMEATK_D_HARD_B011,			// �_�[�i�҃n�[�h03�A�U���A���E�L���A�m�X
	GF_TIMEATK_D_HARD_B164,			// �_�[�i�҃n�[�h04�A�������F��S�w�A���{�X
	GF_TIMEATK_D_HARD_B165,			// �_�[�i�҃n�[�h05�A�������F��T�w�A���{�X
	GF_TIMEATK_D_HARD_B030,			// �_�[�i�҃n�[�h06�A�������F�C�I
	__GF_TIMEATK_D_HARD_RSV07,		// �_�[�i�҃n�[�h07�A���U�[�u07
	__GF_TIMEATK_D_HARD_RSV08,		// �_�[�i�҃n�[�h08�A���U�[�u08
	GF_TIMEATK_D_HARD_RUSH,			// �_�[�i�҃n�[�h09�A�{�X���b�V��

	GF_TIMEATK_D_HARD_ED,

		// �_�[�i��NIGHTMARE�p
	GF_TIMEATK_D_NIGHTMARE_ST = GF_TIMEATK_D_HARD_ED,

	GF_TIMEATK_D_NIGHTMARE_B161 = GF_TIMEATK_D_NIGHTMARE_ST,		// �_�[�i�҃i�C�g���A00�A�������F��P�w�A���{�X
	GF_TIMEATK_D_NIGHTMARE_B162,	// �_�[�i�҃i�C�g���A01�A�������F��Q�w�A���{�X
	GF_TIMEATK_D_NIGHTMARE_B163,	// �_�[�i�҃i�C�g���A02�A�������F��R�w�A���{�X
	GF_TIMEATK_D_NIGHTMARE_B011,	// �_�[�i�҃i�C�g���A03�A�U���A���E�L���A�m�X
	GF_TIMEATK_D_NIGHTMARE_B164,	// �_�[�i�҃i�C�g���A04�A�������F��S�w�A���{�X
	GF_TIMEATK_D_NIGHTMARE_B165,	// �_�[�i�҃i�C�g���A05�A�������F��T�w�A���{�X
	GF_TIMEATK_D_NIGHTMARE_B030,	// �_�[�i�҃i�C�g���A06�A�������F�C�I
	__GF_TIMEATK_D_NIGHTMARE_RSV07,	// �_�[�i�҃i�C�g���A07�A���U�[�u07
	__GF_TIMEATK_D_NIGHTMARE_RSV08,	// �_�[�i�҃i�C�g���A08�A���U�[�u08
	GF_TIMEATK_D_NIGHTMARE_RUSH,	// �_�[�i�҃i�C�g���A09�A�{�X���b�V��

	GF_TIMEATK_D_NIGHTMARE_ED,

		// �_�[�i��INFERNO�p
	GF_TIMEATK_D_INFERNO_ST = GF_TIMEATK_D_NIGHTMARE_ED,

	GF_TIMEATK_D_INFERNO_B161 = GF_TIMEATK_D_INFERNO_ST,		// �_�[�i�҃C���t�F���m00�A�������F��P�w�A���{�X
	GF_TIMEATK_D_INFERNO_B162,		// �_�[�i�҃C���t�F���m01�A�������F��Q�w�A���{�X
	GF_TIMEATK_D_INFERNO_B163,		// �_�[�i�҃C���t�F���m02�A�������F��R�w�A���{�X
	GF_TIMEATK_D_INFERNO_B011,		// �_�[�i�҃C���t�F���m03�A�U���A���E�L���A�m�X
	GF_TIMEATK_D_INFERNO_B164,		// �_�[�i�҃C���t�F���m04�A�������F��S�w�A���{�X
	GF_TIMEATK_D_INFERNO_B165,		// �_�[�i�҃C���t�F���m05�A�������F��T�w�A���{�X
	GF_TIMEATK_D_INFERNO_B030,		// �_�[�i�҃C���t�F���m06�A�������F�C�I
	__GF_TIMEATK_D_INFERNO_RSV07,	// �_�[�i�҃C���t�F���m07�A���U�[�u07
	__GF_TIMEATK_D_INFERNO_RSV08,	// �_�[�i�҃C���t�F���m08�A���U�[�u08
	GF_TIMEATK_D_INFERNO_RUSH,		// �_�[�i�҃C���t�F���m09�A�{�X���b�V��

	GF_TIMEATK_D_INFERNO_ED,

	GF_TIMEATK_END = GF_TIMEATK_D_INFERNO_ED,

	// �^�C���A�^�b�N�����܂�
	//--------------------------------------------------------------------

	GF_MENUSAVE2_START = 8950,	// �ߋ����j���[�̍��ڈʒu�ێ��֘A�̃Z�[�u�p
	GF_MENUSAVE2_ITEM_DIARY1=GF_MENUSAVE2_START,	// �ߋ�[����ID]�X�g�[���[�E�N�G�X�g
	GF_MENUSAVE2_ITEM_DIARY2,	// �ߋ�[����ID]�l���EA�{�C�X
	GF_MENUSAVE2_ITEM_DIARY3,	// �ߋ�[����ID]�����E�ނ�
	GF_MENUSAVE2_ITEM_DIARY4,	// �ߋ�[����ID]�����X�^�[�E�f��
	GF_MENUSAVE2_ITEM_DIARY5,	// �ߋ�[����ID]�w���v�E�ŐV�X�g�[���[�t���O
	GF_MENUSAVE2_SCR_DIARY1,	// �ߋ�[���ڈʒu]�X�g�[���[�E�N�G�X�g
	GF_MENUSAVE2_SCR_DIARY2,	// �ߋ�[���ڈʒu]�l���EA�{�C�X
	GF_MENUSAVE2_SCR_DIARY3,	// �ߋ�[���ڈʒu]�����E�ނ�
	GF_MENUSAVE2_SCR_DIARY4,	// �ߋ�[���ڈʒu]�����X�^�[�E�f��
	GF_MENUSAVE2_SCR_DIARY5,	// �ߋ�[���ڈʒu]�w���v�E(�\��)
	GF_MENUSAVE2_END,			// �ߋ����j���[�̍��ڈʒu�ێ��֘A�̃Z�[�u�p�����܂�

	GF_RESERVE_MAX,				// �\���t���O�����܂Łi�t���O���`�F�b�N�p�Ȃ̂ŁAGLOBAL_FLAG_MAX���O�ɒu���悤�Ɂj

	GLOBAL_FLAG_MAX,			// �O���[�o���t���O�@�����܂�


	FLAG_MAX = 9000,			// �t���O�S���ł����܂�


	FLAG_RESERVE_MAX = 9000,	// �t���O�}�b�N�X�̃��U�[�u
};
#define SYSTEMSAVE_GALLERY_FLAG_MAX		256
#define SYSTEMSAVE_TIMEATK_FLAG_MAX		1000

// �}����V�[���{�C�X�A�����_���Đ����ɃL����������Ȃ��悤�ɂ���ׂ̃e���|�����t���O�ivo_scene.csv�Ŏg���Ă���j
enum
{
	// �}���킵��ׂ鋖�t���O�@NPC
	TF_VOICEOK_ST = 150,

	TF_VOICEOK_BARBAROSS = TF_VOICEOK_ST,		// 00:�o���o���X�D��
	TF_VOICEOK_DOGI,							// 01:�h�M
	TF_VOICEOK_ALISON,							// 02:�A���X��
	TF_VOICEOK_KIERGAARD,						// 03:�L���S�[��
	TF_VOICEOK_CURRAN,							// 04:�J�[������
	TF_VOICEOK_KATRIN,							// 05:�J�g���[��
	TF_VOICEOK_AARON,							// 06:�G�A����
	TF_VOICEOK_DINA,							// 07:�f�B�i
	TF_VOICEOK_LICHT,							// 08:���q�g
	TF_VOICEOK_REJA,							// 09:���[��
	TF_VOICEOK_MIRALDA,							// 10:�~�����_
	TF_VOICEOK_KUINA,							// 11:�N�C�i
	TF_VOICEOK_NIA,								// 12:�V�X�^�[�j�A
	TF_VOICEOK_KASHU,							// 13:�J�V���[
	TF_VOICEOK_FRANZ,							// 14:�t�����c
	TF_VOICEOK_THANATOS,						// 15:�^�i�g�X
	TF_VOICEOK_ED,								// 16:�G�h				// ���Ԃ�s��
	TF_VOICEOK_GRISELDA,						// 17:�O���[���_
	TF_VOICEOK_AUSTEN,							// 18:�I�[�X�e�B��		// ���Ԃ�s��
	TF_VOICEOK_SILVIA,							// 19:�V���r�A			// ���Ԃ�s��
	TF_VOICEOK_CURRAN_B,						// 20:�J�[������2�i�㔼�p�j
	TF_VOICEOK_AUSTEN2,							// 21:�I�[�X�e�B���Q
	TF_VOICEOK_PARO,							// 22:���g���E�p��
	TF_VOICEOK_SKILLMONKY,						// 23:�X�L���U��
	TF_VOICEOK_BALAENICEPS_REX,					// 24:�n�V�r���R�E

	// �}���킵��ׂ鋖�t���O�@PC
	TF_VOICEOK_ADOL,							// �A�h��
	TF_VOICEOK_LAXIA,							// ���N�V��
	TF_VOICEOK_SAHAD,							// �T�n�h
	TF_VOICEOK_HUMMEL,							// �q��������
	TF_VOICEOK_RICOTTA,							// ���R�b�^
	TF_VOICEOK_DANA,							// �_�[�i

	// ���ꕪ��
	TF_VOICEOK_KUINA_A,							// �N�C�i�i�}�b�v�C���j
	TF_VOICEOK_KUINA_B,							// �N�C�i�i�}�b�v�R���j
	TF_VOICEOK_NIA_A,							// �V�X�^�[�E�j�A�i�O����p�j
	TF_VOICEOK_NIA_B,							// �V�X�^�[�E�j�A�i�㔼��p�j
	TF_VOICEOK_AUSTEN_A,						// �I�[�X�e�B���i�O����p�j		// ���Ԃ�s��
	TF_VOICEOK_AUSTEN_B,						// �I�[�X�e�B���i�㔼��p�j		// ���Ԃ�s��
	TF_VOICEOK_PARO_A,							// ���g���E�p���i�X�L���E�^�_���[�W�A�b�v�j
	TF_VOICEOK_PARO_B,							// ���g���E�p���i�X�L���E��_���[�W�_�E���j
	TF_VOICEOK_PARO_C,							// ���g���E�p���i�X�L���E�N���e�B�J���A�b�v�j
	TF_VOICEOK_PARO_D,							// ���g���E�p���i�X�L���E�틵�Q�[�W�l�`�w�j

	TF_VOICEOK_FINISH,
};

// �V�X�e���t���O�Ƃ��Ĉ���GF
#define SF_MAP_NAME_NO_DRAW		GF_MPxxxx_MAP_NAME_NO_DRAW

	// �{�C�X����p�t���O�̕ʖ���`�i�t���O�����܂�����O�����ւ���K�v����j
#define SF_CHANGEVOICE_CURRAN	GF_SUBEV_JOIN_CURRAN2	// �J�[�������̃{�C�X��؂�ւ���
#define SF_CHNAGEVOICE_NIA		DF_QS311_END			// �V�X�^�[�E�j�A�̃{�C�X��؂�ւ���
#define SF_CHANGEVOICE_AUSTEN	DF_QS522_END			// �I�[�X�e�B���̃{�C�X��؂�ւ���
#define SF_VOICE_LAXIA_2ND		GF_02MP1201_LOST_CURRAN	// ���R�b�^�㔼
#define SF_VOICE_RICOTTA_2ND	GF_04MP6101_MAKE_CAMP	// ���R�b�^�㔼

// �݊����ׂ̈Ɏc���Ă���
#define	SF_DOGI_JOINOK		SF_SAHAD_JOINOK				// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j
#define	SF_AISHA_JOINOK		SF_LAXIA_JOINOK			// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j
#define	SF_GEIS_JOINOK		SF_HUMMEL_JOINOK				// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j
#define SF_KRSHE_JOINOK		SF_RICOTTA_JOINOK			// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j
#define SF_MISHERA_JOINOK	SF_DANA_JOINOK				// �p�[�e�B�[�����\�I�i�O�|�����s�@�P�|����ւ����R�@�Q�|�����j

#define SF_WING_LIMIT		SF_WARP_DISABLED			// �E�B���O����

// �p�~�����t���O�A�݊����ׂ̈Ɏc���Ă���
#define SF_TAME_SPEED_UP		0	// �����ȃt���O�ԍ���ݒ�
#define SF_WING_LIMIT_SEGRAM	0	// �����ȃt���O�ԍ���ݒ�

// ��Փx�t���O�̒��g�p
#define DIFFICULT_NORMAL		0x000		// �m�[�}��
#define DIFFICULT_HARD			0x001		// HARD�t���O
#define DIFFICULT_NIGHTMARE		0x002		// NIGHTMARE�t���O
#define DIFFICULT_EASY			0x004		// EASY�t���O


// �N�G�X�g�ꏊ��`
enum
{
	QUEST_NOBOARD = 0,			// �f������Ȃ���
	QUEST_CASNAN,				// �L���X�i��
	QUEST_COMODO,				// �R���h
	QUEST_SELRAY,				// �Z�����C
	QUEST_HIGHLAND,				// �n�C�����h
	QUEST_DANAN,				// �_�i��
	QUEST_ELDUKE,				// �G���h�D�[�N
	QUEST_OTHERS,				// ���̑�
};


// �}�b�v����`�t�@�C���̒�`�p
enum{
	MN_NONE = 0,				// ���o�^�p�ɒu���Ă���

	// F001�F�Z�C�������E����
	MN_F_SOUTHWEST_PLANE_MP1101,	// �쐼��
	MN_F_SOUTHWEST_PLANE_MP1102,	// �쐼��
	MN_F_SOUTHWEST_PLANE_MP1103,	// �쐼��
	MN_F_SOUTHWEST_PLANE_MP1104,	// �쐼��
	MN_F_SOUTHWEST_PLANE_MP1110,	// �쐼��
	MN_F_SOUTHWEST_PLANE_MP1111,	// �쐼��
	MN_F_SOUTHWEST_PLANE_MP1131,	// �쐼��
	MN_F_SOUTHWEST_PLANE_MP1112,	// �쐼��
	MN_F_SOUTHWEST_PLANE_MP2101,	// �쐼��
	MN_F_SOUTHWEST_PLANE_MP1105,	// �쐼��
	MN_F_SOUTHWEST_PLANE_MP1106,	// �쐼��

	// MP120x�F�Y����
	MN_T_VILLAGE_MP1201,			// ���_
	MN_T_VILLAGE_MP1202,			// ���_
	MN_T_VILLAGE_MP1201_2,			// ���_�i���O�ύX��j
	MN_T_VILLAGE_MP1202_2,			// ���_�i���O�ύX��j

	// MP730x�F���������q
	MN_D_CELLAR_MP7301,				// ���q�P
	MN_D_CELLAR_MP7302,				// ���q�Q
	MN_D_CELLAR_MP7303,				// ���q�R
	MN_D_CELLAR_MP7304,				// ���q�S
	MN_D_CELLAR_MP7305,				// ���q�E�Q���̒f�R

	//MP130x�F�X��̐X
	MN_D_MP1301,		// �X��̐X
	MN_D_MP1302,		// �X��̐X
	MN_D_MP1303,		// �X��̐X
	MN_D_MP1304,		// �X��̐X
	MN_D_MP1305,		// �X��̐X
	MN_D_MP1306,		// �X��̐X
	MN_D_MP1307,		// �X��̐X
	MN_D_MP1308,		// �X��̐X
	MN_D_MP1309,		// �X��̐X

	//MP230x�F����
	MN_D_MP2301,		// ���� 
	MN_D_MP2302,		// ���� 
	MN_D_MP2303,		// ���� 
	MN_D_MP2304,		// ���� 
	MN_D_MP2305,		// ���� 
	MN_D_MP2306,		// ���� 
	MN_D_MP2307,		// ���� 
	MN_D_MP2308,		// ���� 

	//MP430x�F�Z�H�J
	MN_D_MP4301,		// �Z�H�J
	MN_D_MP4302,		// �Z�H�J
	MN_D_MP4303,		// �Z�H�J
	MN_D_MP4304,		// �Z�H�J
	MN_D_MP4305,		// �Z�H�J
	MN_D_MP4306,		// �Z�H�J
	MN_D_MP4307,		// �Z�H�J
	MN_D_MP4308,		// �Z�H�J

	// ��F002�F������
	MN_F_MP1120,
	MN_F_MP1121,
	MN_F_MP1107,		// �݂苴�@���X�N���v�g�Ŏg�p�ς݁B�ύX����Ƃ��͈ꏏ�ɕύX�B
	MN_F_MP3103,
	MN_F_MP3104,
	MN_F_MP2102,
	
	// ��F003�F����
	MN_F_MP1108,
	MN_F_MP1109,
	MN_F_MP4102,
	MN_F_MP2103,
	
	// ��F004�F��]��
	MN_F_MP1116,
	
	// ��F005�F�����E��[�i�X��ʁj
	MN_F_MP1113,
	MN_F_MP1132,
	MN_F_MP1133,
	MN_F_MP1134,
	
	// F006�F���������E(�����̍���)
	MN_F_MP3101,
	MN_F_MP3102,
	
	// F007�F��������
	MN_F_MP3105,
	MN_F_MP3106,
	MN_F_MP3107,
	MN_F_MP3108,
	MN_F_MP3109,
	MN_F_MP4101,

	// �勬�J(�A����)
	MN_F_MP3109m,
	MN_F_MP3110m,
	MN_F_MP3111m,

	// ��F008�F����l
	MN_F_MP1117,
	MN_F_MP1135,
	
	// ��F009�F�Y���l
	MN_F_MP1118,
	
	// ��F010�F�Y���l
	MN_F_MP1119,

	// ��F011�F�Z���̐X
	MN_F_MP2104,
	MN_F_MP2105,
	MN_F_MP2106,
	
	// ��F012�F���̊C��
	MN_F_MP1114,
	MN_F_MP1115,

	// ��F013�F���꓇
	MN_F_MP1122,
	MN_F_MP1123,

	// ��F031�F���_�R��
	MN_F_MP4103,
	MN_F_MP4104,
	MN_F_MP4106,
	MN_F_MP4108,
	MN_F_MP7101,
	MN_F_MP7102,

	// ��F032�F���s
	MN_F_MP6201,
	MN_F_MP6202,
	MN_F_MP6203,
	MN_F_MP6204,
	MN_F_MP6211,
	MN_F_MP6212,
	MN_F_MP6213,
	MN_F_MP6214,
	MN_F_MP6215,


	// ��F033�F������
	MN_F_MP5101,
	MN_F_MP5102,
	MN_F_MP5103,

	// ��F034�F���Â̑啽��
	MN_F_MP6101,
	MN_F_MP6102,
	MN_F_MP6111,
	MN_F_MP6112,
	MN_F_MP6116,

	// ��F035�F�g�����X��
	MN_F_MP6103,
	MN_F_MP6104,
	MN_F_MP6110,
	MN_F_MP6115,

	// ��F036�F�V�U�u��
	MN_F_MP4110,
	MN_F_MP5104,

	// ��F037�F�����n��
	MN_F_MP6105,
	MN_F_MP6106,
	MN_F_MP6107,
	MN_F_MP6108,
	MN_F_MP6113,
	MN_F_MP6114,
	
	// ��F038�F�I�v�̋u
	MN_F_MP6109,

	// ��F039�F����ւ̎R��
	MN_F_MP4105,
	MN_F_MP4109,
	MN_F_MP4111,

	//MP433x�F�W�����_����
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
	
	MN_F_MP4202,	//����

	// ��FXXXM�F�ߋ��҃t�B�[���h
	MN_F_MPXXXM,


	// ��������@(�ߋ��j
	MN_F_MP6401m,
	MN_F_MP6402m,
	MN_F_MP6408m,
	MN_F_MP6409m,
	MN_F_MP6410m,


	// ��������@(���݁j
	MN_D_MP6401,
	MN_D_MP6402,
	MN_D_MP6408,
	MN_D_MP6409,
	MN_D_MP6410,


	// ��������@(�ߋ��j
	MN_F_MP6409v2,
	
	
	// �����s����(���݁j
	MN_D_MP6211,
	MN_D_MP6214,

	// �����s����(�ߋ��j
	MN_F_MP6211m,
	MN_F_MP6212m,
	MN_F_MP6213m,
	MN_F_MP6214m,
	MN_F_MP6215m,
	MN_F_MP6216m,
	MN_F_MP6222m,
	MN_F_MP6222m2,
	MN_F_MP6231m,

	// �������o���f�B�A��
	MN_F_MP0011,
	MN_F_MP0012,
	MN_F_MP0013,
	MN_F_MP0014,
	MN_F_MP0015,
	MN_F_MP0016,
	MN_F_MP0017,
	MN_F_MP0018,

	// ���H��D
	MN_D_MP0401,
	MN_D_MP0402,
	MN_D_MP0403,
	MN_D_MP0404,
	MN_D_MP0405,
	MN_D_MP0406,
	MN_D_MP0407,
	MN_D_MP0408,
	
	// �����Ƃ̒J
	MN_D_MP6341,		// ���Ƃ̒J�E���w�L��
	MN_D_MP6342,		// ���Ƃ̒J�E�������P
	MN_D_MP6343,		// ���Ƃ̒J�E�������Q
	MN_D_MP6344,		// ���Ƃ̒J�E�������R
	MN_D_MP6345,		// ���Ƃ̒J�E���{�X����
	MN_D_MP6346,		// ���Ƃ̒J�E�㔼�啔���P
	MN_D_MP6347,		// ���Ƃ̒J�E�㔼�啔���Q
	MN_D_MP6349,		// ���Ƃ̒J�E��{�X����
	MN_D_MP6350,		// ���Ƃ̒J�E�����u�����E�����O
	MN_D_MP6350m,		// ���Ƃ̒J�E�����u�����E�ߋ�
	MN_D_MP6350v1,		// ���Ƃ̒J�E�����u�����E������
	MN_D_MP6351,		// ���Ƃ̒J�E�ǉ敔��

	// �����X�_���E���ʕ���
	MN_D_MP6301,		// ���X�_���E���ԁi�V�ر�j
	MN_D_MP6302,		// ���X�_���E���ԁi�C�ر�j
	MN_D_MP6303,		// ���X�_���E���ԁi�X�ر�j
	MN_D_MP6304,		// ���X�_���E���ԁi峴ر�j

	// �����X�_���E�C�G���A
	MN_D_MP6305,		// �C�G���A�E�U��
	MN_D_MP6305b,		// �C�G���A�E�{�X

	// �����X�_���E�X�G���A
	MN_D_MP6306,		// �X�G���A�E�U��
	MN_D_MP6306b,		// �X�G���A�E�{�X

	// �����X�_���E峃G���A
	MN_D_MP6307,		// 峃G���A�E�U��
	MN_D_MP6307b,		// 峃G���A�E�{�X

	// �����X�_���E�V�G���A
	MN_D_MP6308,		// �V�G���A�E�U��
	MN_D_MP6308b,		// �V�G���A�E�{�X

	// �����X�_���E���X�{�X�G���A
	MN_D_MP6310,		// ���X�{�X�G���A�E�U��
	MN_D_MP6310b,		// ���X�{�X�G���A�E�{�X

	// ���o�n�̎Γ�
	MN_D_MP6321,		// �o�n�̎Γ��E���w�P
	MN_D_MP6322,		// �o�n�̎Γ��E���w�Q
	MN_D_MP6323,		// �o�n�̎Γ��E���w�R
	MN_D_MP6324,		// �o�n�̎Γ��E��L�P
	MN_D_MP6325,		// �o�n�̎Γ��E���{�X����
	MN_D_MP6326,		// �o�n�̎Γ��E��w�P
	MN_D_MP6327,		// �o�n�̎Γ��E��L�Q
	MN_D_MP6328,		// �o�n�̎Γ��E��w�Q
	MN_D_MP6329,		// �o�n�̎Γ��E�{�X����
	MN_D_MP6330,		// �o�n�̎Γ��E�ŏ�K

	// ���n����̑匊
	MN_D_MP6361,		// �n����̑匊�E���{�ՂP
	MN_D_MP6362,		// �n����̑匊�E�O��
	MN_D_MP6363,		// �n����̑匊�E���A�P
	MN_D_MP6364,		// �n����̑匊�E���A�Q
	MN_D_MP6365,		// �n����̑匊�E���A�R
	MN_D_MP6366,		// �n����̑匊�E���{�X�}�b�v
	MN_D_MP6367,		// �n����̑匊�E���A�S
	MN_D_MP6368,		// �n����̑匊�E���{�ՂQ
	MN_D_MP6369,		// �n����̑匊�E���{�ՂR
	MN_D_MP6370,		// �n����̑匊�E�{�X�}�b�v

	// ���Z�H�J
	MN_D_EROSIONVALLEY_MP4301,		// �Z�H�J
	MN_D_EROSIONVALLEY_MP4302,		// �Z�H�J
	MN_D_EROSIONVALLEY_MP4303,		// �Z�H�J
	MN_D_EROSIONVALLEY_MP4304,		// �Z�H�J
	MN_D_EROSIONVALLEY_MP4305,		// �Z�H�J
	MN_D_EROSIONVALLEY_MP4306,		// �Z�H�J
	MN_D_EROSIONVALLEY_MP4307,		// �Z�H�J
	MN_D_EROSIONVALLEY_MP4308,		// �Z�H�J
	MN_D_EROSIONVALLEY_MP4309,		// �Z�H�J
		
	// �����v������
	MN_D_MP6411,					// ���v������
	MN_D_MP6412,					// ���v������
	MN_D_MP6413,					// ���v������
	
	// ��MP832x�F�͂��܂�̐[��
	MN_D_MP8321,					// �͂��܂�̐[������
	MN_D_MP8322,					// �͂��܂�̐[���ʘH
	MN_D_MP8323,					// �͂��܂�̐[���{�X�}�b�v

	// ����m�@
	MN_D_MP6421,
	MN_D_MP6422,

	// ���Ñ��̏Z��
	MN_D_MP5401,	

	// ���Ñ�̓��A
	MN_D_MP7401,	

	// �����̓��A
	MN_D_MP7411,

	// �������n
	MN_D_MP7451,
	MN_D_MP7452,

	// ���n������
	MN_D_MP7461,
	MN_D_MP7462,

	// ���ߓ���
	MN_D_MP7471,
	MN_D_MP7472,

	// �����v��n
	MN_D_MP7481,
	MN_D_MP7482,

	// ����Β��̕���
	MN_D_MP7491,
	MN_D_MP7492,

	// ���E�o�D
	MN_F_MP0021,


	// ���ߋ��҃t�B�[���h
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

	MN_DIARY_OTHER,		// �A����			�ߋ��ҁE�_�[�i�@
	MN_DIARY_OTHER2,	// �y���ƍĉ��		�ߋ��ҁE�_�[�i�B
	MN_DIARY_OTHER3,	// �Ԗт̌��m		�ߋ��҇T
	MN_DIARY_OTHER4,	// �����̕c��		�ߋ��҇U
	MN_DIARY_OTHER5,	// ���]�k�ޏ��̈��	�ߋ��҇V
	MN_DIARY_OTHER6,	// ����				�ߋ��҇W
	MN_DIARY_OTHER7,	// �^���̓�			�ߋ��҇W�|�Q
	MN_DIARY_OTHER8,	// ������̉���		�ߋ��҇X
	MN_DIARY_OTHER9,	// �ߑs�Ȃ錈��		�ߋ��҇Y

//�ǉ���
	MN_D_MP6409B,

// ���ߋ��Ғǉ��_���W����
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
	
// ����_���W����
	//MP130x�F�X��̐X
	MN_D_MP1301T2,		// �X��̐X
	MN_D_MP1302T2,		// �X��̐X
	MN_D_MP1303T2,		// �X��̐X
	MN_D_MP1304T2,		// �X��̐X
	MN_D_MP1305T2,		// �X��̐X
	MN_D_MP1306T2,		// �X��̐X
	MN_D_MP1307T2,		// �X��̐X
	MN_D_MP1308T2,		// �X��̐X
	MN_D_MP1309T2,		// �X��̐X

	//MP433x�F�W�����_����
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

	// ��F034�F���Â̑啽��
	MN_F_MP6101T2,
	MN_F_MP6102T2,
	MN_F_MP6111T2,
	MN_F_MP6112T2,
	MN_F_MP6116T2,

	//�ߋ��҃A�N�e�B�u�{�C�X�ł���������`�F�ߋ��҇Z�p
	MN_DIARY_OTHER10,			//�ߋ��҇Z�p
	MN_DIARY_OTHER11,			//�ߋ��ҁE�n�������p



	//// ��ys8 �}�b�v���h�c��`�͂����܂� ////
	//////////////////////////////////////////







	MN_MAX,							// �}�b�v����`�A�ő�l
};


// ���R�[�h�p��`�h�c
enum{
	// ����
	RD_PLAYTIME = 0,			// �v���C����
	RD_TOTALMOVE,				// ���ړ�����
	RD_MAPRATIO,				// �����T����
	RD_NPCNUM,					// �Y�����l���i�x���\�l���j
	RD_TBOXRATIO,				// �󔠔�����
	RD_MATRATIO,				// �̎�|�C���g������
	RD_LOCATIONRATIO,			// ���P�[�V�����|�C���g������
	RD_VILLAGELV_RATIO,			// �Y����������
	RD_LIKE_RATIO,				// �D���x�B����
	RD_COOP_RATIO,				// �x���C�x���g�B����
	RD_FAME_RATIO,				// �����l
	RD_VIRTURE_RATIO,			// �_�[�i�̓�
	RD_FAME_RATIO2,				// �����l
	RD_VIRTURE_RATIO2,			// �_�[�i�̓�
	//RD_PASTDUNGEON,				// �n���������j��

	// �G���A�T����
	RD_AREA_TITLE,				// 
	RD_AREA_S,					// ���G���A��������
	RD_AREA01=RD_AREA_S,		// �Y����
	RD_AREA02,					// ���m�炸�C��
	RD_AREA03,					// �����̓��A
	RD_AREA04,					// ���l��
	RD_AREA05,					// ���N�X��̐X
	RD_AREA06,					// ����l
	RD_AREA07,					// �勬�J����
	RD_AREA08,					// �ꗠ�̏ߓ���
	RD_AREA09,					// �b�����̋u
	RD_AREA10,					// �Z�H�J
	RD_AREA11,					// ���̏o���l
	RD_AREA12,					// �����u��
	RD_AREA13,					// �����̑�
	RD_AREA14,					// ���n������
	RD_AREA15,					// �����O�t�H�[���C��
	RD_AREA16,					// ���ƐX�̋u
	RD_AREA17,					// �V���������ђn��
	RD_AREA18,					// ���C��
	RD_AREA19,					// �Ñ��̔�����
	RD_AREA20,					// �W�����_����
	RD_AREA21,					// ���[����
	RD_AREA22,					// �É��̊ތA
	RD_AREA23,					// �V�R�R��
	RD_AREA24,					// �e���y���Q��
	RD_AREA25,					// �e�B�e�B�X���n��
	RD_AREA26,					// �Ñ��̏Z��
	RD_AREA27,					// �p���K�C�A�啽��
	RD_AREA28,					// �G�^�j�A���s���
	RD_AREA29,					// ����̎��@
	RD_AREA30,					// ��Β��̕���
	RD_AREA31,					// �g�����X��
	RD_AREA32,					// �o�n�̎Γ�
	RD_AREA33,					// �]����
	RD_AREA34,					// ���̊C�ݓ��A
	RD_AREA35,					// �C���D�G���t�Z���A��
	RD_AREA36,					// �n����̑匊
	RD_AREA37,					// �����炵��
	RD_AREA38,					// ���f�B�j�A�Ώ��n��
	RD_AREA39,					// �{���h��m�@
	RD_AREA40,					// ���v��n
	RD_AREA41,					// ���Ƃ̒J
	RD_AREA42,					// �I�v�̋u
	RD_AREA43,					// �ЂƂ蓇
	RD_AREA44,					// ���ق̓�
	RD_AREA45,					// ���͂��̋u
	RD_AREA46,					// �C�̓�
	RD_AREA47,					// �X�̓�
	RD_AREA48,					// 峂̓�
	RD_AREA49,					// �V�̓�
	RD_AREA50,					// �I���̊�
	RD_AREA51,					// ������̎��@�E����

	RD_AREA_E,					// ���G���A�����܂�

	// �퓬
	RD_NUMKILLEDMONS=RD_AREA_E,	// �����X�^�[���j��
	RD_NUMKILLEDDRAGON,			// ���^�Ñ�팂�j��
	RD_NUMSKILLFINISH,			// �X�L���t�B�j�b�V��������
	RD_NUMBRAKE,				// �u���C�N������
	RD_NUMFLASHGUARD,			// �t���b�V���K�[�h������
	RD_NUMFLASHMOVE,			// �t���b�V�����[�u������
	RD_NUMEXSKILL,				// �G�N�X�g���X�L��������
	RD_SPACE01,					// ��
	RD_INTERCEPT,				// �}����]��
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
	RD_SPACE01B,				// ��
	RD_INTERCEPT_C,				// �}����]��
	RD_INTERCEPT_C_BAT01,		// INTERCEPT_STAGE31
	RD_INTERCEPT_C_BAT02,		// INTERCEPT_STAGE32
	RD_INTERCEPT_C_BAT03,		// INTERCEPT_STAGE33
	RD_INTERCEPT_C_BAT04,		// INTERCEPT_STAGE34
	RD_INTERCEPT_C_BAT05,		// INTERCEPT_STAGE35
	RD_INTERCEPT_C_BAT06,		// INTERCEPT_STAGE36
	RD_INTERCEPT_C_BAT07,		// INTERCEPT_STAGE37
	RD_INTERCEPT_C_BAT08,		// INTERCEPT_STAGE38
	RD_INTERCEPT_C_BAT09,		// INTERCEPT_STAGE39

	// �R���N�V����
	RD_DIARY_CHARA,				// �`�������u�l���v�J����
	RD_DIARY_COOK,				// �`�������u�����v�J����
	RD_DIARY_FISH,				// �`�������u�ނ�v�J����
	RD_DIARY_MONSTER,			// �`�������u�����X�^�[�v�J�����i�\���ȊO�j
	RD_DIARY_MATERIAL,			// �`�������u�f�ށE�H�ށv�J����
	RD_SPACE02,					// ��
	RD_QUEST_RATIO,				// �N�G�X�g�B����
	RD_PASTQUEST_RATIO,			// �G�^�j�A�N�G�X�g�B����
	RD_PASTQUEST_01,			// �@�Y�ꋎ��ꂽ���H
	RD_PASTQUEST_02,			// �@�o�q�̂�������
	RD_PASTQUEST_03,			// �@����ɏ�������
	RD_PASTQUEST_04,			// �@���퓢���@
	RD_PASTQUEST_05,			// �@�ޏ��̎{��
	RD_PASTQUEST_06,			// �@�Â��j���̑��
	RD_PASTQUEST_07,			// �@�͂��ꂽ��
	RD_PASTQUEST_08,			// �@���퓢���A
	RD_PASTQUEST_09,			// �@���퓢���B
	RD_PASTQUEST_10,			// �@�͂�䂭��n�Ɍb�݂�
	RD_PASTQUEST_11,			// �@���ǉ��G�^�j�A�N�G�X�g
	RD_PASTSPIRIT_RATIO,		// �G�^�j�A����~�o��
	RD_PASTSPIRIT_01,			// �@������01
	RD_PASTSPIRIT_02,			// �@������02
	RD_PASTSPIRIT_03,			// �@������03
	RD_PASTSPIRIT_04,			// �@������04
	RD_PASTSPIRIT_05,			// �@������05
	RD_PASTSPIRIT_06,			// �@������06
	RD_PASTSPIRIT_07,			// �@������07
	RD_PASTSPIRIT_08,			// �@������08
	RD_PASTSPIRIT_09,			// �@������09
	RD_PASTSPIRIT_10,			// �@������10

	//�ǉ���
	RD_PASTDUNGEON_00,			//�n������
	RD_PASTDUNGEON_01,			//�n�������P�w
	RD_PASTDUNGEON_02,			//�n�������Q�w
	RD_PASTDUNGEON_03,			//�n�������R�w
	RD_PASTDUNGEON_04,			//�n�������S�w
	RD_PASTDUNGEON_05,			//�n�������T�w
	RD_PASTDUNGEON_06,			//�n�������U�w

	RD_SPACE03,					// ��
	RD_ITEMALLRATIO,			// �A�C�e�����W���i�����c�k�b�͊܂߂Ȃ��j
	RD_ITEM_MATRATIO,			// �ėp�f��
	RD_ITEM_RMATRATIO,			// ���A�f��
	RD_ITEM_DRUGBTLRATIO,		// �r��
	RD_ITEM_DRUGRATIO,			// �Ō`��
	RD_ITEM_FOODRATIO,			// �ʕ�
	RD_ITEM_COOKRATIO,			// ����
	RD_ITEM_COOKSTUFFRATIO,		// �H��
	RD_ITEM_FISHRATIO,			// ��
	RD_ITEM_MAGICRATIO,			// �`����
	RD_ITEM_WEAPONRATIO,		// ����
	RD_ITEM_ARMORRATIO,			// �̖h��
	RD_ITEM_RINGRATIO,			// �r�h��
	RD_ITEM_ACCESSORYRATIO,		// �A�N�Z�T��
	RD_ITEM_DRESSRATIO,			// �ߑ�(�R�X�`���[��)
	RD_ITEM_ATTACHRATIO,		// �A�^�b�`(�R�X�`���[��)
	RD_ITEM_BOOKRATIO,			// ����
	RD_ITEM_INVRATIO,			// �厖�ȕ�
	//RD_SPACE01,					// �X�y�[�X

	RD_MAX
};
// ���R�[�h�\����`�p
enum{
	// ����
	RD_SHOW_FLAG= 0,			// �t���O
	RD_SHOW_MINIMAP,			// �~�j�}�b�vID
	RD_SHOW_INTERCEPT,			// �}���퓬ID
	RD_SHOW_KIND_MAX,
};

// �����X�g�[���[�A��`�h�c
enum{
	DIARY_STORY = 0,		// �`���̋L�^
	DIARY_TIPS,				// ������������
	DIARY_VOYAGE,			// �q�C����
	DIARY2_STORY,			// �s���̋L�^
	DIARY2_MONOLITH,		// �����������m���X
};

// �A�C�e���|�C���g�p��`�h�c
enum{

	// �����̓��A_mp730x
	IP_MP7302_01 = 0,
	IP_MP7302_02,
	IP_MP7303_01,

	// ���������C��
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

	// �X���
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

	// �X��̐X
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

	// ���̕l��
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
	
	// ��������
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

	// ������
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

	// �Z�H�J
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

	// �k���̕l��
	IP_MP1119_01,
	IP_MP1119_02,
	IP_MP1119_03,
	IP_MP1119_04,

	//�����̍���
	IP_MP3101_01,
	IP_MP3101_02,
	IP_MP3101_03,

	IP_MP3102_01,
	IP_MP3102_02,
	IP_MP3102_03,
	IP_MP3102_04,

	// �����n_mp745x
	IP_MP7451_01,
	IP_MP7451_02,
	IP_MP7451_03,
	IP_MP7451_04,
	IP_MP7451_05,
//	IP_MP7451_06,	�ǉ����͌���
//	IP_MP7451_07,
//	IP_MP7451_08,
//	IP_MP7451_09,
//	IP_MP7451_10,
//	IP_MP7451_11,
//	IP_MP7451_12,
	// �n������_mp746x		�I�P�A�m�X��
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

	// ���̊C��
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

	// �Z���̐X
	IP_MP2105_01,
	IP_MP2105_02,
	IP_MP2105_03,
	IP_MP2105_04,
	IP_MP2105_05,
	IP_MP2105_06,

	// ����
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
//	IP_MP2306_09,	//���ɒǉ�
//	IP_MP2306_10,
//	IP_MP2306_11,
//	IP_MP2306_12,
//	IP_MP2306_13,
//	IP_MP2306_14,
//	IP_MP2306_15,

	IP_MP2307_01,
	IP_MP2307_02,

	// ���l
	IP_MP1118_01,
	IP_MP1118_02,

// �����G���A_mp31xx
	IP_MP3109_01,
	IP_MP3109_02,
	IP_MP3109_03,
	IP_MP3109_04,
	IP_MP3109_05,
	IP_MP3109_06,
//	IP_MP3109_07,
//	IP_MP3109_08,
//	IP_MP3109_09,

// �W�����_����_mp433x
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

// �����G���A_mp31xx
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
// �Ñ�̓��A
	IP_MP7401_01,
	IP_MP7401_02,
	IP_MP7401_03,

// �W�����_����_mp433x
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

// �R�x�G���A_mp41xx
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

//����ւ̎Q��
	IP_MP4109_01,
	IP_MP4109_02,

// �H��D_mp04xx

// �Ñ㌴���уG���A_mp510x
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
//	IP_MP5101_05,	//���ɒǉ�

// �Ñ��̏Z��_mp540x

// �Ñ㕽��_mp61xx

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

//�ߋ��ҁE��
	IP_MP5103m_01,
	IP_MP5103m_02,
	IP_MP5103m_03,
	IP_MP5103m_04,
	IP_MP5103m_05,
	IP_MP5103m_06,
	IP_MP5103m_07,

	IP_MP6112m_01,
	IP_MP6112m_02,

// �G�^�j�A_mp62xx

// ����̎��@_mp640x		break_object

//�g�����X��

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

//�ߋ��ҁE���E�g�����X��
	IP_MP6103m_01,
	IP_MP6103m_02,
	IP_MP6103m_03,
	IP_MP6103m_04,
	IP_MP6103m_05,
	IP_MP6103m_06,
	IP_MP6103m_07,
	IP_MP6103m_08,

// �Γ�_mp632x
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

//��]��
	IP_MP1116_01,
	IP_MP1116_02,
	IP_MP1116_03,
	IP_MP1116_04,
//	IP_MP1116_05,
//	IP_MP1116_06,

// �C�ݓ��A_mp741x
	IP_MP7411_01,
	IP_MP7411_02,
	IP_MP7411_03,
	IP_MP7411_04,
	IP_MP7411_05,

//�H��D

// ���Ƃ̒J_mp634x
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

// ���_mp636x
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

//�V�R�u��
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

//�����n��
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
//	IP_MP6113_08,		//���ɒǉ�

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

//�ߋ��ҁE��
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

//���Ƃ̒J


//�I�v�̋u
	IP_MP6109_01,
	IP_MP6109_02,
	IP_MP6109_03,
	IP_MP6109_04,
	IP_MP6109_05,
	IP_MP6109_06,
	IP_MP6109_07,
//	IP_MP6109_08,	���ɒǉ�
//	IP_MP6109_09,
//	IP_MP6109_10,

//�I�N�g�D�X�E�C�̉�L

//�I�N�g�D�X�E�X�̉�L
	IP_MP6306_01,
	IP_MP6306_02,
	IP_MP6306_03,

//�I�N�g�D�X�E峂̉�L
	IP_MP6307_01,
	IP_MP6307_02,
	IP_MP6307_03,

//�I�N�g�D�X�E�V�̉�L
	IP_MP6308_01,
	IP_MP6308_02,
	IP_MP6308_03,

//�I�N�g�D�X�E�I���̊�





// ���v������_mp641x
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

// ��m�@_mp642x
// �͂��܂�̑��_mp630x
// �ꗠ�̏ߓ���_mp747x
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

// ���v��n_mp748x

// ��Β��̕���_mp749x
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

// �͂��܂�̐[��_mp832x

//�����n�E�ǉ���
	IP_MP7451_06,
	IP_MP7451_07,
	IP_MP7451_08,
	IP_MP7451_09,
	IP_MP7451_10,
	IP_MP7451_11,
	IP_MP7451_12,

//�ߋ��҃_�[�i�@�E�勬�J
	IP_MP3109m_01,
	IP_MP3110m_01,

//�ߋ��҇T�E
	IP_MP5103m_08,
	IP_MP6101m_01,
//�ߋ��҇V�E
	IP_MP6103m_09,
	IP_MP6103m_10,
//�ߋ��҇X�E
	IP_MP6106m_07,
	IP_MP6106m_08,

//�ǉ�
	IP_MP5101_05,	//���ɒǉ�
	IP_MP6113_08,		//���ɒǉ�
	IP_MP6109_08,	//���ɒǉ�
	IP_MP6109_09,
	IP_MP6109_10,
	IP_MP1302_07,
	IP_MP2102_10,
	IP_MP2306_09,	//���ɒǉ�
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
// PS4�ǉ���
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

	// ����ɒǉ���
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


	// �ȉ��̓f�o�b�O�p
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

