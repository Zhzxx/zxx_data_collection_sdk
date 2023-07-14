//
//  ZXXDataCollection.h
//  zxx_data_collection_sdk
//
//  Created by 陈子慜 on 2023/7/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZXXDataCollection : NSObject

/// Hello Baby
+ (NSString *)testPrint;

/** 集成测试[在AppDelegate.m 文件类中实现]
 - (BOOL)application:(UIApplication *)application openURL:(nonnull NSURL *)url options:(nonnull NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options {
     if ([ZXXDataCollection handleUrl:url]) {
         return YES;
     }
     return YES;
 }
 */
+ (BOOL)handleUrl:(NSURL *)url;

/// 正式初始化，建议用户同意隐私协议时调用，已同意过可在应用启动时调用
///  @param clientId 租户ID
///  @param appKey 开发者申请的appkey
+ (void)onInitWithClientId:(NSString *)clientId appKey:(NSString *)appKey;

/// 设置是否在console输出sdk的log信息.
///  @param bFlag 默认NO(不输出log); 设置为YES, 输出可供调试参考的log信息. 发布产品时必须设置为NO.
+ (void)setLogEnabled:(BOOL)bFlag;

/// 是否开启统计，默认为YES(开启状态)
///  @param value 设置为NO,可关闭统计功能.
+ (void)analyticsEnabled:(BOOL)value;

/// 公共参数：键值对 会覆盖同名的key
+ (void)registerGlobalProperties:(NSDictionary *)dic;

/// 公共参数：删除指定超级事件属性
/// @param propertyName key
+ (void)unregisterGlobalProperty:(NSString *)propertyName;

/// 用户登录
/// @param puid user's ID
+ (void)onUserLogin:(NSString *)puid;

/// 用户登出
+ (void)logOutEvent;

/// H5桥接接口， WKWebView对象
+ (void)attachWebView:(id)wkWebView;

/// 页面事件上报，开始记录某个页面展示时长
/// @param pageName 事件名称
/// @param params 事件参数
+ (void)onPageStart:(NSString *)pageName params:(nullable NSDictionary<NSString *, NSString *> *)params;

/// 页面事件上报，结束记录某个页面展示时长
/// @param pageName 事件名称
/// @param params 事件参数
+ (void)onPageEnd:(NSString *)pageName params:(nullable NSDictionary<NSString *, NSString *> *)params;

/// 更新页面埋点上报参数
/// @param pageName 事件名称
/// @param params 事件参数
+ (void)setPageProperty:(NSString *)pageName params:(nullable NSDictionary<NSString *, NSString *> *)params;

/// 点击事件上报
/// @param eventId 事件Id
/// @param params 事件参数
+ (void)sendEvent:(NSString *)eventId params:(nullable NSDictionary<NSString *, NSString *> *)params;

@end

NS_ASSUME_NONNULL_END
