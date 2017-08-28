#include "CreateLayer.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;


CreateLayer::CreateLayer() {
	
}


bool CreateLayer::init() {
	auto winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	planeName = "";
	planeType = 0;
	

	auto _background = Sprite::create("res/UI/1Menu/background.png");
	_background->setPosition(Vec2(origin.x + winSize.width / 2, origin.y + winSize.height / 2));
	auto scale = winSize.width / _background->getContentSize().width;
	_background->setScale(scale);
	this->addChild(_background);
	//SpriteBatchNode*batchNode = SpriteBatchNode::create("res/UI/a1CreatePlayer/createScene.png");


	auto show1 = MenuItemImage::create("res/UI/a1CreatePlayer/plane1_unselected.png","res/UI/a1CreatePlayer/plane1_unselected.png", CC_CALLBACK_1(CreateLayer::CallBack, this));
	show1->setPosition(Vec2(winSize.width *0.18, winSize.height*0.6));
	show1->setTag(10);
	selected_1 = Sprite::create("res/UI/a1CreatePlayer/bar1.png");
	selected_1->setPosition(Vec2(winSize.width *0.19, winSize.height*0.61));
	selected_1->retain();
	this->addChild(selected_1, 1);
	selected_1->setVisible(false);

	auto show2 = MenuItemImage::create("res/UI/a1CreatePlayer/plane3_unselected.png", "res/UI/a1CreatePlayer/plane3_unselected.png", CC_CALLBACK_1(CreateLayer::CallBack, this));
	show2->setPosition(Vec2(winSize.width *0.5, winSize.height*0.6));
	//show2->setScale(1.2);
	show2->setTag(11);
	selected_2 = Sprite::create("res/UI/a1CreatePlayer/bar2.png");
	selected_2->setPosition(Vec2(winSize.width *0.51, winSize.height*0.61));
	selected_2->retain();
	this->addChild(selected_2, 1);
	selected_2->setVisible(false);

	auto show3 = MenuItemImage::create("res/UI/a1CreatePlayer/plane1_unselected.png", "res/UI/a1CreatePlayer/plane1_unselected.png", CC_CALLBACK_1(CreateLayer::CallBack, this));
	show3->setPosition(Vec2(winSize.width *0.82, winSize.height*0.6));
	//show3->setScale(1.2);
	show3->setTag(12);
	selected_3 = Sprite::create("res/UI/a1CreatePlayer/bar3.png");
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
	

	


	//编辑框
	nameEditBox = EditBox::create(CCSizeMake(250, 50), Scale9Sprite::create("res/UI/a1CreatePlayer/editBar.png"));
	nameEditBox->setPosition(Vec2(winSize.width*0.6, winSize.height*0.25));
	nameEditBox->setScale(1.0, 0.9);
	nameEditBox->setFontColor(Color3B(77, 77, 77));//设置字体颜色
	nameEditBox->setFontName("fonts/simhei.ttf");//设置字体样式
	nameEditBox->setPlaceHolder("Name:");//预置文本
	nameEditBox->setMaxLength(8);//最大长度
	nameEditBox->setInputMode(cocos2d::ui::EditBox::InputMode::SINGLE_LINE);//单行输入
	nameEditBox->setInputFlag(cocos2d::ui::EditBox::InputFlag::INITIAL_CAPS_WORD);//输入标志位
	nameEditBox->setReturnType(cocos2d::ui::EditBox::KeyboardReturnType::DONE);//设置返回类型  
	nameEditBox->setDelegate(this);//当前类继承CCEditBoxDelegate类
	this->addChild(nameEditBox);

	//Win32编辑框
	

	return true;
}



void CreateLayer::CallBack(Ref *pSender) {
	int tag = ((MenuItem*)pSender)->getTag();
	auto winSize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	switch (tag)
	{
	case 1:
	{
		SimpleAudioEngine::sharedEngine()->playEffect("/music/trans1.wav");
		auto file = new UserInfo();
		UserInfo user = file->createUser(planeName, planeType);
		//CCLOG(user.getUserName().c_str());
		delete file;
		SceneManager::goMapLayer(tag, user);

	}break;
	case 2: {

		SimpleAudioEngine::sharedEngine()->playEffect("/music/trans1.wav");
		int transiTimes = 1;
		SceneManager::goMenuLayer(tag,transiTimes);
	}break;
	case 10: {
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
