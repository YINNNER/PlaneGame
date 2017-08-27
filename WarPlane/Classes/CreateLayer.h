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


private:
	Sprite *selected_1;
	Sprite *selected_2;
	Sprite *selected_3;
	MenuItemImage * menuItem_1;
	std::string planeName;
	EditBox *nameEditBox;
	int planeType;

};
