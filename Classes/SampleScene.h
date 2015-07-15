//
//  SampleScene.h
//  cocos2dx_sample
//
//  Created by OKAYA YOHEI on 2015/07/15.
//
//

#ifndef __cocos2dx_sample__SampleScene__
#define __cocos2dx_sample__SampleScene__

#include "cocos2d.h"
#include "editor-support/cocosbuilder/CocosBuilder.h"

class SampleScene
: public cocos2d::Layer
, public cocosbuilder::CCBMemberVariableAssigner
, public cocosbuilder::CCBAnimationManagerDelegate
, public cocosbuilder::CCBSelectorResolver
{
public:

    // CCBMemberVariableAssigner
    virtual bool onAssignCCBMemberVariable(cocos2d::Ref* target, const char* memberVariableName, cocos2d::Node* node);
    virtual bool onAssignCCBCustomProperty(cocos2d::Ref* target, const char* memberVariableName, const cocos2d::Value& value);
    // CCBAnimationManagerDelegate
    virtual void completedAnimationSequenceNamed(const char *name);

    // CCBSelectorResolver
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget, const char* pSelectorName);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(cocos2d::Ref * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(cocos2d::Ref * pTarget, const char* pSelectorName);

    // 初期化
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();

    // タッチイベント
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);

    // implement the "static create()" method manually
    CREATE_FUNC(SampleScene);

    cocos2d::RefPtr<cocos2d::Label> _label;
};

// cocosLoaderクラス
class SampleSceneLoader : public cocosbuilder::LayerLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(SampleSceneLoader, loader);

protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(SampleScene);
};

#endif /* defined(__cocos2dx_sample__SampleScene__) */
