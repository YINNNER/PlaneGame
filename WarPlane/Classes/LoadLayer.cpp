#include "LoadLayer.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
bool LoadLayer::init() {
	auto winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	_background = Sprite::create("res/UI/0aStart/background.png");
	_background->setPosition(Vec2(origin.x + winSize.width/2, origin.y + winSize.height/2));
	auto scale = winSize.width / _background->getContentSize().width;
	_background->setScale(scale);
	this->addChild(_background);

	_logo = Sprite::create("res/UI/0aStart/logo.png");
	_logo->setPosition(Vec2(origin.x + winSize.width /2, origin.y + winSize.height *3/5));
	//_logo->setScale(2);
	this->addChild(_logo);

	/*
	loadLabel = LabelTTF::create("Loading", "fonts/Anklepan.ttf", 20);
	loadLabel->setPosition(Vec2(winSize.width*0.5, winSize.height*0.5));
	this->addChild(loadLabel);

	percentLabel = LabelTTF::create("0%", "fonts/Anklepan.ttf", 15);
	percentLabel->setPosition(Vec2(winSize.width*0.5, winSize.height*0.45));
	this->addChild(percentLabel);

	auto loadBg = Sprite::create("res/UI/0Loading/loadingBarEmpty.png");
	loadBg->setPosition(Vec2(winSize.width*0.5, winSize.height*0.4));
	this->addChild(loadBg, 1);
	
	loadProgress = ProgressTimer::create(Sprite::
		create("res/UI/0Loading/loadingBarFull.png"));//����������
	loadProgress->setBarChangeRate(Point(1, 0));//���ñ仯����
	loadProgress->setType(ProgressTimer::Type::BAR);//���ý�����������
	loadProgress->setMidpoint(Point(0, 1));//���ý��ȵ��˶�����
	loadProgress->setPosition(Vec2(winSize.width*0.5, winSize.height*0.4));
	loadProgress->setPercentage(0.0f);//���ó�ʼֵΪ0
	this->addChild(loadProgress, 2);

	m_numSp = 19;
	loading();
*/
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/background1.mp3");
	SimpleAudioEngine::sharedEngine()->preloadEffect("music/trans1.wav");
	
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/background3.mp3",true);
	scheduleOnce(CC_SCHEDULE_SELECTOR(LoadLayer::onScheduleOnce),1.0f);
	return true;
}

void LoadLayer::onScheduleOnce(float dt){
	/*
	auto menuScene = Scene::create();
	MenuLayer *layer = MenuLayer::create();
	menuScene->addChild(layer);
	Director::getInstance()->replaceScene(menuScene);*/
	int tag = 1;
	SceneManager::goMenuLayer(tag);

}

void LoadLayer::loading() {

	Director::getInstance()->getTextureCache()->addImageAsync("res/UI/1Menu/title.png", CC_CALLBACK_1(LoadLayer::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("res/UI/1Menu/new.png", CC_CALLBACK_1(LoadLayer::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("res/UI/1Menu/newS.png", CC_CALLBACK_1(LoadLayer::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("res/UI/1Menu/load.png", CC_CALLBACK_1(LoadLayer::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("res/UI/1Menu/loadS.png", CC_CALLBACK_1(LoadLayer::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("res/UI/1Menu/option.png", CC_CALLBACK_1(LoadLayer::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("res/UI/1Menu/optionS.png", CC_CALLBACK_1(LoadLayer::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("res/UI/1Menu/exit.png", CC_CALLBACK_1(LoadLayer::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("res/UI/1Menu/exitS.png", CC_CALLBACK_1(LoadLayer::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("res/UI/a1CreatePlayer/plane1_unselected.png", CC_CALLBACK_1(LoadLayer::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("res/UI/a1CreatePlayer/plane3_unselected.png", CC_CALLBACK_1(LoadLayer::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("res/UI/a1CreatePlayer/bar1.png", CC_CALLBACK_1(LoadLayer::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("res/UI/a1CreatePlayer/bar2.png", CC_CALLBACK_1(LoadLayer::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("res/UI/a1CreatePlayer/bar3.png", CC_CALLBACK_1(LoadLayer::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("res/UI/a1CreatePlayer/createButton.png", CC_CALLBACK_1(LoadLayer::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("res/UI/a1CreatePlayer/createButtonS.png", CC_CALLBACK_1(LoadLayer::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("res/UI/a1CreatePlayer/background.png", CC_CALLBACK_1(LoadLayer::loadingCallback, this));

}
void LoadLayer::loadingCallback(Object *pSender) {
	m_loadedSp++;

	char buf_str[56];
	sprintf(buf_str, "%d%%", (int)(((float)m_loadedSp / m_numSp) * 100), m_numSp);
	percentLabel->setString(buf_str);//����percentLabel��ֵ  

	float newPercent = 100 - ((float)m_numSp - (float)m_loadedSp) / ((float)m_numSp / 100);//�����������ǰ�İٷֱ�  
																						   //��Ϊ����ͼƬ�ٶȺܿ죬���Ծ�û��ʹ��ProgressTo��  
																						   //����ProgressFromTo���ֶ��������½�����  
	loadProgress->setPercentage(newPercent);//���½�����  

											//ͼƬ������ɺ�  
	if (m_loadedSp == m_numSp)
	{
		this->removeChild(loadProgress);//����ӵļ�������ɾ����  
		this->removeChild(percentLabel);
		this->removeChild(loadLabel);
	}
}
