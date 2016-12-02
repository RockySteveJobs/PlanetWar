//
//  MenuScene.cpp
//  PlanetWar
//
//  Created by Xinhou Jiang on 8/11/16.
//
//

#include "MenuScene.h"
#include "Game.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

/**
 * 创建菜单场景
 */
Scene* MenuScene::createScene() {
    auto scene = Scene::create();
    auto layer = MenuScene::create();
    scene->addChild(layer);
    return scene;
}

/**
 * 菜单初始化
 */
bool MenuScene::init() {
    if (!Layer::init()) {
        return false;
    }
    
    // 打印屏幕尺寸
    using namespace std;
    cout<<"screenWidth:"<<ScreenWidth<<endl;
    cout<<"screenHeight:"<<ScreenHeight<<endl;
    
    // 开场背景音乐
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("music_menu_bg.mp3", true);
    
    // 菜单页面背景图片
    auto menu_bg = Sprite::create("menu_bg.jpg");
    menu_bg->setPosition(Vec2(ScreenWidth/2, ScreenHeight/2));
    addChild(menu_bg);
    
    // 粒子
    ParticleSystemQuad *particle = ParticleSystemQuad::create("particle_galaxy.plist");
    particle->setPosition(ScreenWidth*2/3,ScreenHeight*2/3);
    addChild(particle, 10);
    
    // 云层
    auto menu_cloud = Sprite::create("menu_cloud.png");
    menu_cloud->setPosition(Vec2(ScreenWidth/2, ScreenHeight/2));
    addChild(menu_cloud, 20);
    
    // 开始游戏按钮
    auto item_startgame = MenuItemImage::create("btn_start_normal.png", "btn_start_pressed.png", CC_CALLBACK_1(MenuScene::startGame, this));
    item_startgame->setPosition(Vec2::ZERO);
    // 历史记录按钮
    auto item_history = MenuItemImage::create("btn_history_normal.png","btn_history_pressed.png", CC_CALLBACK_1(MenuScene::openHistory, this));
    item_history->setPosition(Vec2(0, -50));
    
    // 按钮菜单
    auto menu = Menu::create(item_startgame, NULL);
    menu->setPosition(Vec2(ScreenWidth/2, ScreenHeight/2));
    addChild(menu,100);
    
    return true;
}

/**
 * 跳转到游戏场景
 */
void MenuScene::startGame(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("effect_click.mp3");
    Director::getInstance()->replaceScene(TransitionFade::create(0.5, Game::createScene()));
}

/**
 * 历史记录
 */
void MenuScene::openHistory(cocos2d::Ref *pSender) {
    
}

/**
 * 场景进入
 */
//void MenuScene::onEnter() {}

/**
 * 场景退出
 */
void MenuScene::onExit() {
    this->removeAllChildren();
    Layer::onExit();
}
