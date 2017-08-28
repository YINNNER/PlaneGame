#pragma once
#include <cocos2d.h>
#include "MapLayer.h"
#include "cocos-ext.h"

USING_NS_CC_EXT;
USING_NS_CC;
class CreateLayer :
	public Layer,public EditBoxDelegate
{
public:
	CreateLayer();
	virtual bool init();
	CREATE_FUNC(CreateLayer);
	

	void CallBack(Ref *pSender);


	virtual void editBoxEditingDidBegin(cocos2d::extension::EditBox* editBox);
	virtual void editBoxEditingDidEnd(cocos2d::extension::EditBox* editBox);
	virtual void editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string &text);
	virtual void editBoxReturn(cocos2d::extension::EditBox *editBox);

	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void addWords(std::string temp);
	void minusWords(std::string temp);


private:
	Label *defaultLabel;
	Sprite *selected_1;//第一种飞机被选中
	Sprite *selected_2;//第二种飞机被选中
	Sprite *selected_3;//第三种飞机被选中
	MenuItemImage * menuItem_1;//创建角色按钮
	std::string planeName;//存储用户写入战机名
	EditBox *nameEditBox; //mac下编辑框
	int planeType;//用户选择的战机类型
	EventKeyboard::KeyCode key;
	Sprite *cursor;//光标
	Vector<Label*>label;//放置输入的字符
	int addTimes;//输入框中增加字符的个数
	static bool capslock;//标记大小写状态
	Label *warning;

};
