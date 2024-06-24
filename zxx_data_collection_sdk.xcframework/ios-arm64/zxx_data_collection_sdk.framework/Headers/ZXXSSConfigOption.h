//
//  ZXXSSConfigOption.h
//  zxx_data_collection_sdk
//
//  Created by 陈子慜 on 2024/6/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZXXSSConfigOption : NSObject

/// 非必传，数据接收地址（用于覆盖默认配置中的数据采集SDK数据上报地址）
@property (nonatomic, copy) NSString *serverUrl;
/// 必传，馆内系统平台需要数据采集组件申请应用的AK
@property (nonatomic, copy) NSString *appKey;

/// 非必传，在控制台打印埋点日志，默认NO：不打印
@property (nonatomic, assign) BOOL enableLog;
// 非必传，是否开启 app 代理上报。默认true
@property (nonatomic, assign) BOOL bridge;
// 非必传，是否进行 session 切割。默认 YES，，会进行 session 切割；设置 NO，不会进行 session 切割
@property (nonatomic, assign,readonly) BOOL enableSession;
// 非必传，会话超时时间，单位 ms（默认 60 * 60 * 1000，即：60分钟），超过该时间会重新生成 event_session_id
@property (nonatomic, assign) NSUInteger sessionTimeout;
// 非必传，两次数据发送的最小时间间隔，单位毫秒，默认 1 * 60 *1000，即1分钟
@property (nonatomic, assign) NSUInteger flushInterval;

@end

NS_ASSUME_NONNULL_END
