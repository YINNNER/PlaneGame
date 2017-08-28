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
	Sprite *selected_1;//��һ�ַɻ���ѡ��
	Sprite *selected_2;//�ڶ��ַɻ���ѡ��
	Sprite *selected_3;//�����ַɻ���ѡ��
	MenuItemImage * menuItem_1;//������ɫ��ť
	std::string planeName;//�洢�û�д��ս����
	EditBox *nameEditBox; //mac�±༭��
	int planeType;//�û�ѡ���ս������
	EventKeyboard::KeyCode key;
	Sprite *cursor;//���
	Vector<Label*>label;//����������ַ�
	int addTimes;//������������ַ��ĸ���
	static bool capslock;//��Ǵ�Сд״̬
	Label *warning;

};
