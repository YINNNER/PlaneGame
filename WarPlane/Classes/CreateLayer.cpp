#include "CreateLayer.h"
#include "SimpleAudioEngine.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32   //判断是mac平台还是win32
#include <Winuser.h>
#endif
using namespace CocosDenshion;

bool CreateLayer::capslock = false;
CreateLayer::CreateLayer() {
	
}


bool CreateLayer::init() {
	auto winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	planeName = "";
	planeType = 0;
	addTimes = 0;
	

	auto _background = Sprite::create("res/UI/1Menu/background.png");
	_background->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height / 2));
	auto scale = winSize.width / _background->getContentSize().width;
	_background->setScale(scale);
	this->addChild(_background);
	//SpriteBatchNode*batchNode = SpriteBatchNode::create("res/UI/a1CreatePlayer/createScene.png");
	
	MenuItemImage* show1 = MenuItemImage::create("res/UI/a1CreatePlayer/plane1U.png","res/UI/a1CreatePlayer/plane1U.png", CC_CALLBACK_1(CreateLayer::CallBack, this));
	show1->setPosition(Vec2(winSize.width *0.18, winSize.height*0.6));
	show1->setTag(10);
	selected_1 = Sprite::create("res/UI/a1CreatePlayer/plane1.png");
	selected_1->setPosition(Vec2(winSize.width *0.19, winSize.height*0.61));
	selected_1->retain();
	this->addChild(selected_1, 1);
	selected_1->setVisible(false);

	auto show2 = MenuItemImage::create("res/UI/a1CreatePlayer/plane2U.png", "res/UI/a1CreatePlayer/plane2U.png", CC_CALLBACK_1(CreateLayer::CallBack, this));
	show2->setPosition(Vec2(winSize.width *0.5, winSize.height*0.6));
	//show2->setScale(1.2);
	show2->setTag(11);
	selected_2 = Sprite::create("res/UI/a1CreatePlayer/plane2.png");
	selected_2->setPosition(Vec2(winSize.width *0.51, winSize.height*0.61));
	selected_2->retain();
	this->addChild(selected_2, 1);
	selected_2->setVisible(false);

	auto show3 = MenuItemImage::create("res/UI/a1CreatePlayer/plane3U.png", "res/UI/a1CreatePlayer/plane3U.png", CC_CALLBACK_1(CreateLayer::CallBack, this));
	show3->setPosition(Vec2(winSize.width *0.82, winSize.height*0.6));
	//show3->setScale(1.2);
	show3->setTag(12);
	selected_3 = Sprite::create("res/UI/a1CreatePlayer/plane3.png");
	selected_3->setPosition(Vec2(winSize.width *0.83, winSize.height*0.61));
	selected_3->retain();
	this->addChild(selected_3, 1);
	selected_3->setVisible(false);

	auto menu1 = Menu::create(show1,show2, show3, NULL);
	menu1->setPosition(Point::ZERO);
	this->addChild(menu1, 0);

	auto username = Label::createWithTTF("姓名", "fonts/simhei.ttf", 40);
	username->setPosition(Vec2(winSize.width*0.3, winSize.height*0.25));
	this->addChild(username);

	menuItem_1 = MenuItemImage::create("res/UI/a1CreatePlayer/createButton.png", "res/UI/a1CreatePlayer/createButtonS.png", "res/UI/a1CreatePlayer/createButtonForbidden.png",CC_CALLBACK_1(CreateLayer::CallBack, this));
	menuItem_1->setTag(1);
	menuItem_1->setEnabled(false);
	menuItem_1->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height*0.1));


	auto back = MenuItemImage::create("res/UI/b1Help/back.png", "res/UI/b1Help/backS.png", CC_CALLBACK_1(CreateLayer::CallBack, this));
	back->setTag(2);
	back->setPosition(Vec2(winSize.width*0.15, winSize.height*0.9));

	auto menu2 = Menu::create(menuItem_1, back, NULL);
	menu2->setPosition(Point::ZERO);
	this->addChild(menu2);
	
	

	warning = Label::createWithSystemFont("太多字啦", "fonts/simhei.ttf", 20);
	warning->setPosition(Vec2(winSize.width*0.9, winSize.height*0.25));
	warning->setVisible(false);
	this->addChild(warning);
	

    if(CC_TARGET_PLATFORM == CC_PLATFORM_MAC){
	//MAC编辑框
	nameEditBox = EditBox::create(CCSizeMake(250, 50), Scale9Sprite::create("res/UI/a1CreatePlayer/editBar.png"));
	nameEditBox->setPosition(Vec2(winSize.width*0.6, winSize.height*0.25));
	nameEditBox->setScale(1.0, 0.9);
	nameEditBox->setFontColor(Color3B(77, 77, 77));//设置字体颜色
	nameEditBox->setFontName("fonts/simhei.ttf");//设置字体样式
	nameEditBox->setPlaceHolder("请输入战机名");//预置文本
	nameEditBox->setMaxLength(8);//最大长度
	nameEditBox->setInputMode(cocos2d::ui::EditBox::InputMode::SINGLE_LINE);//单行输入
	nameEditBox->setInputFlag(cocos2d::ui::EditBox::InputFlag::INITIAL_CAPS_WORD);//输入标志位
	nameEditBox->setReturnType(cocos2d::ui::EditBox::KeyboardReturnType::DONE);//设置返回类型  
	nameEditBox->setDelegate(this);//当前类继承CCEditBoxDelegate类
	this->addChild(nameEditBox);
    }
    else if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32){
	//Win32编辑框
	auto editBox = Sprite::create("res/UI/a1CreatePlayer/editBar.png");
	editBox->setPosition(Vec2(winSize.width*0.6, winSize.height*0.25));
	editBox->setScale(1.3, 0.9);
	this->addChild(editBox,0);

	defaultLabel = Label::createWithSystemFont("请输10个以内字母支持大小写", "", 15);
	defaultLabel->setColor(Color3B(72, 72, 72));
	defaultLabel->setPosition(Vec2(winSize.width*0.56, winSize.height*0.25));
	this->addChild(defaultLabel, 1);
	
	//this->schedule(schedule_selector(CreateLayer::addWords),1.0f);
	cursor = Sprite::create("res/UI/a1CreatePlayer/cursor.png");
	cursor->setPosition(Vec2(winSize.width*0.4, winSize.height*0.25));
	cursor->setVisible(false);
	this->addChild(cursor, 2);
	auto cursorBlink = RepeatForever::create(Sequence::create(FadeOut::create(0.4f), FadeIn::create(0.4f), NULL));
	cursor->runAction(cursorBlink);

	auto cursorListener = EventListenerTouchOneByOne::create();
	cursorListener->setSwallowTouches(true);
	cursorListener->onTouchBegan = CC_CALLBACK_2(CreateLayer::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(cursorListener, editBox);

	listenerKeyboard = EventListenerKeyboard::create();
	listenerKeyboard->onKeyPressed = CC_CALLBACK_2(CreateLayer::onKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyboard, this);
	listenerKeyboard->setEnabled(false);
    }
    else ;

	
        
	return true;
        
}

bool CreateLayer::onTouchBegan(Touch *touch, Event *unused_event) {
	auto target = static_cast<Layer*>(unused_event->getCurrentTarget());
	if (target == nullptr)
	{
		return true;
	}
	Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	
	if (rect.containsPoint(locationInNode))
	{
		cursor->setVisible(true);
		listenerKeyboard->setEnabled(true);
		
		return true;
	}
	else {
		listenerKeyboard->setEnabled(false);
		cursor->setVisible(false);
	}
	return false;
}

void CreateLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	key = keyCode;
	CCLOG("%d",capslock);
	
	
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	if (GetKeyState(VK_CAPITAL) & 0x1) {   //判断大小写状态
		capslock = true;
	}
	else {
		capslock = false;
    }
#endif
    
	std::string temp;
	switch (key) {
	case EventKeyboard::KeyCode::KEY_Q:
		if (capslock) {
			temp = "Q";
		}
		else {
			temp = "q";
		}
		
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_W:
		if (capslock) {
			temp = "W";
		}
		else {
			temp = "w";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_E:
		if (capslock) {
			temp = "E";
		}
		else {
			temp = "e";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_R:
		if (capslock) {
			temp = "R";
		}
		else {
			temp = "r";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_T:
		if (capslock) {
			temp = "T";
		}
		else {
			temp = "t";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_Y:
		if (capslock) {
			temp = "Y";
		}
		else {
			temp = "y";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_U:
		if (capslock) {
			temp = "U";
		}
		else {
			temp = "u";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_I:
		if (capslock) {
			temp = "I";
		}
		else {
			temp = "i";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_O:
		if (capslock) {
			temp = "O";
		}
		else {
			temp = "o";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_P:
		if (capslock) {
			temp = "P";
		}
		else {
			temp = "p";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_A:
		if (capslock) {
			temp = "A";
		}
		else {
			temp = "a";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_S:
		if (capslock) {
			temp = "S";
		}
		else {
			temp = "s";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_D:
		if (capslock) {
			temp = "D";
		}
		else {
			temp = "d";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_F:
		if (capslock) {
			temp = "F";
		}
		else {
			temp = "f";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_G:
		if (capslock) {
			temp = "G";
		}
		else {
			temp = "g";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_H:
		if (capslock) {
			temp = "H";
		}
		else {
			temp = "h";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_J:
		if (capslock) {
			temp = "J";
		}
		else {
			temp = "j";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_K:
		if (capslock) {
			temp = "K";
		}
		else {
			temp = "k";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_L:
		if (capslock) {
			temp = "L";
		}
		else {
			temp = "l";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_Z:
		if (capslock) {
			temp = "Z";
		}
		else {
			temp = "z";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_X:
		if (capslock) {
			temp = "X";
		}
		else {
			temp = "x";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_C:
		if (capslock) {
			temp = "C";
		}
		else {
			temp = "c";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_V:
		if (capslock) {
			temp = "V";
		}
		else {
			temp = "v";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_B:
		if (capslock) {
			temp = "B";
		}
		else {
			temp = "b";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_N:
		if (capslock) {
			temp = "N";
		}
		else {
			temp = "n";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_M:
		if (capslock) {
			temp = "M";
		}
		else {
			temp = "m";
		}
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_BACKSPACE:
		if (planeName != "") {
			minusWords(temp);
		}
		break;
	case EventKeyboard::KeyCode::KEY_0:
		temp = "0";
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_1:
		temp = "1";
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_2:
		temp = "2";
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_3:
		temp = "3";
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_4:
		temp = "4";
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_5:
		temp = "5";
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_6:
		temp = "6";
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_7:
		temp = "7";
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_8:
		temp = "8";
		addWords(temp);
		break;
	case EventKeyboard::KeyCode::KEY_9:
		temp = "9";
		addWords(temp);
		break;

	}
	if (planeName != "") {
		defaultLabel->setVisible(false);
		cursor->setVisible(true);
	}
	else {
		defaultLabel->setVisible(true);
		cursor->setVisible(false);
	}
}

void CreateLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (key == keyCode)
	{
		key = EventKeyboard::KeyCode::KEY_NONE;
	}
}


void CreateLayer::addWords(std::string temp) {
	
	auto winSize = Director::getInstance()->getWinSize();
	auto word = Label::createWithSystemFont(temp.c_str(), "fonts/simhei.ttf", 20);
	
	
	if (planeName.length() < 10) {
		warning->setVisible(false);
		planeName += temp;
		addTimes++;
		label.pushBack(word);
		int move = planeName.length();
		CCLOG("%d", move);
		auto setWord = label.at(addTimes-1);
		auto vec = Vec2(winSize.width*0.38+move*10, winSize.height*0.24);
		setWord->setAnchorPoint(Vec2(0,0));
		setWord->setPosition(vec);
		setWord->setColor(Color3B(0, 0, 0));
		this->addChild(setWord,1);
		auto cursorMove = MoveTo::create(0.1f, Vec2(vec.x + 10, vec.y + 8.5));
		cursor->runAction(cursorMove);
		
		if (selected_1->isVisible() || selected_2->isVisible() || selected_3->isVisible()) {
			menuItem_1->setEnabled(true);
		}
		
		CCLOG("%s", planeName.c_str());
	}
	else {
		warning->setVisible(true);
	}
}

void CreateLayer::minusWords(std::string temp) {
	auto winSize = Director::getInstance()->getWinSize();
	warning->setVisible(false);
	planeName.pop_back();
	int move = planeName.length();
	CCLOG("%d", move);
	auto vec = Vec2(winSize.width*0.38 + (move+1) * 10, winSize.height*0.24);
	
	CCLOG("%s", planeName.c_str());
	label.back()->removeFromParentAndCleanup(true);
	label.popBack();
	auto cursorMove = MoveTo::create(0.1f, Vec2(vec.x, vec.y + 8.5));
	cursor->runAction(cursorMove);
	addTimes--;
}

void CreateLayer::CallBack(Ref *pSender) {
	int tag = ((MenuItem*)pSender)->getTag();
	auto winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	switch (tag)
	{
	case 1:
	{
		if (SetLayer::getEffectState() == 1) {
			SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
			SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
		}
		auto file = new UserInfo();
		UserInfo user = file->createUser(planeName, planeType);
		//CCLOG(user.getUserName().c_str());
		delete file;
		SceneManager::goMapLayer(tag, user);

	}break;
	case 2: {
		if (SetLayer::getEffectState() == 1) {
			SimpleAudioEngine::getInstance()->playEffect("music/trans1.wav");
			SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
		}
		int transiTimes = 1;
		SceneManager::goMenuLayer(tag,transiTimes);
	}break;
	case 10: {
		if (SetLayer::getEffectState() == 1) {
			
			SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
		}
		if (selected_2->isVisible())
			selected_2->setVisible(false);
		if (selected_3->isVisible())
			selected_3->setVisible(false);
		selected_1->setVisible(true);
		if (!(planeName == "")) {
			menuItem_1->setEnabled(true);
		}
		planeType = 1;
	}break;
	case 11: {
		if (SetLayer::getEffectState() == 1) {
			
			SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
		}
		if(selected_1->isVisible())
			selected_1->setVisible(false);
		if (selected_3->isVisible())
			selected_3->setVisible(false);
		selected_2->setVisible(true);
		if (!(planeName == "")) {
			menuItem_1->setEnabled(true);
		}
		planeType = 2;
	}break;
	case 12: {
		if (SetLayer::getEffectState() == 1) {
			
			SimpleAudioEngine::sharedEngine()->playEffect("music/click8.wav");
		}
		if (selected_1->isVisible())
			selected_1->setVisible(false);
		if (selected_2->isVisible())
			selected_2->setVisible(false);
		selected_3->setVisible(true);
		if (!(planeName == "")) {
			menuItem_1->setEnabled(true);
		}
		planeType = 3;
	}break;
	}
}


void CreateLayer::editBoxEditingDidBegin(EditBox *editBox) {
	CCLOG("start edit");
}

void CreateLayer::editBoxEditingDidEnd(EditBox *editBox)
{
	CCLOG("end edit");
	if ((!planeType==0)&& !(planeName == "")) {
		menuItem_1->setEnabled(true);
	}

}
void CreateLayer::editBoxReturn(EditBox *editBox)
{
	CCLOG("editbox return");
}

void CreateLayer::editBoxTextChanged(EditBox *editBox,const std::string &text) {
	auto editbox = (EditBox*)editBox;
	CCLOG("EditBox_name changed");
	planeName = text;

	
}
