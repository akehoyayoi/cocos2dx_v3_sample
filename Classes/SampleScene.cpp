//
//  SampleScene.cpp
//  cocos2dx_sample
//
//  Created by OKAYA YOHEI on 2015/07/15.
//
//

#include "SampleScene.h"

// 通信
#include "network/HttpClient.h"
#include "json/document.h"

// on "init" you need to initialize your instance
bool SampleScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    return true;
}

bool SampleScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    _label->setString("onTouchBegan");
    return true;
}

void SampleScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    _label->setString("onTouchMoved");
}

void SampleScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    _label->setString("onTouchEnded");
}


void SampleScene::onEnter()
{
    cocos2d::Layer::onEnter();

    // タッチイベントを登録
    const auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(SampleScene::onTouchBegan,this);
    listener->onTouchMoved = CC_CALLBACK_2(SampleScene::onTouchMoved,this);
    listener->onTouchEnded = CC_CALLBACK_2(SampleScene::onTouchEnded,this);
    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void SampleScene::onExit()
{
    cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
    cocos2d::Layer::onExit();
}

bool SampleScene::onAssignCCBMemberVariable(cocos2d::Ref* target,
                                            const char* memberVariableName,
                                            cocos2d::Node* node)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this, "_label", cocos2d::Label*, this->_label);
    return false;
}

bool SampleScene::onAssignCCBCustomProperty(cocos2d::Ref* target,
                                            const char* memberVariableName,
                                            const cocos2d::Value& value)
{
    return false;
}

void SampleScene::completedAnimationSequenceNamed(const char *name)
{
}

cocos2d::SEL_MenuHandler SampleScene::onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget,
                                                                     const char* pSelectorName)
{
    return NULL;
}

cocos2d::SEL_CallFuncN SampleScene::onResolveCCBCCCallFuncSelector(cocos2d::Ref * pTarget,
                                                                   const char* pSelectorName)
{
    return NULL;
}

cocos2d::extension::Control::Handler SampleScene::onResolveCCBCCControlSelector(cocos2d::Ref * pTarget,
                                                                                const char* pSelectorName)
{
    return NULL;
}
