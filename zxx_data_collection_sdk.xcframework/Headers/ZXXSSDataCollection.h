//
//  ZXXSSDataCollection.h
//  zxx_data_collection_sdk
//
//  Created by 陈子慜 on 2024/6/20.
//

#import <Foundation/Foundation.h>
#import "ZXXSSConfigOption.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZXXSSDataCollection : NSObject


/// Hello Baby
+ (NSString *)testPrint;

/// 初始化SDK
///  @param option 数据对象
+ (void)onInitWithOption:(ZXXSSConfigOption *)option;

+ (void)disableSDK;


/// 点击事件
/// @param event 事件名称
/// @param properties 事件参数，内部自动补充event_type = clickEvent
+ (void)clickEvent:(NSString *)event properties:(NSDictionary *)properties;

/// 页面事件
/// @param event 事件名称
/// @param properties 事件参数，内部自动补充event_type = pageEvent
+ (void)pageEvent:(NSString *)event properties:(NSDictionary *)properties;


/// 业务事件
/// @param event 事件名称
/// @param properties 事件参数，内部自动补充event_type = businessEvent
+ (void)businessEvent:(NSString *)event properties:(NSDictionary *)properties;

/// 自定义事件类型
/// @param event 事件名称
/// @param properties 事件参数，外部event_type必传，如果为空无法上报
+ (void)customEvent:(NSString *)event properties:(NSDictionary *)properties;

/// 注册事件公共属性
/// @param params 添加的参数字典
+ (NSDictionary *)registerSuperProperties:(NSDictionary *)params;

/// 移除事件公共属性
/// @param property 要移除的参数key
+ (NSDictionary *)unregisterSuperProperty:(NSString *)property;

/// 强制上传数据
+ (void)flush;

@end

NS_ASSUME_NONNULL_END
