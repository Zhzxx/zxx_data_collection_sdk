#
#  Be sure to run `pod spec lint zxx_data_collection_sdk.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  s.name         = "zxx_data_collection_sdk"
  s.version      = "0.0.1"
  s.summary      = "zxx_data_collection_sdk的一个简单示范工程."

  s.description  = <<-DESC
                   zxx_data_collection_sdk的一个简单示范工程示范工程的长描述.
                   DESC

  s.homepage     = "https://github.com/Zhzxx/zxx_data_collection_sdk"

  s.license      = "MIT"

  s.author       = { "ZXX" => "zxxiosmail@163.com" }

  s.platform     = :ios, "12.0"

  s.source       = { :git => "https://github.com/Zhzxx/zxx_data_collection_sdk.git", :tag => "#{s.version}" }

  s.preserve_paths = 'Demos', '.cocoapods.yml', "#{s.name}.podspec.json", "#{s.name}/src/oc/module.modulemap", "#{s.name}/src/oc/zxx_data_collection_sdkOCHeader.h"

  s.swift_versions = ['5.0']
  
  s.user_target_xcconfig = { 'LIBRARY_SEARCH_PATHS' => '$(TOOLCHAIN_DIR)/usr/lib/swift/$(PLATFORM_NAME) $(TOOLCHAIN_DIR)/usr/lib/swift-5.0/$(PLATFORM_NAME)' }
  s.pod_target_xcconfig = {
    # 路径根据实际情况进行引用，必须保证路径是正确的
    'SWIFT_INCLUDE_PATHS' => ["$(PODS_ROOT)/#{s.name}/src/oc", "$(PODS_TARGET_SRCROOT)/#{s.name}/src/oc"]
  }

  s.default_subspecs = 'Core'

  s.subspec 'Core' do |core|
    core.dependency 'UMCommon',"~>1.4.3.P"
    core.dependency 'UMDevice',"~>2.2.1"

    core.vendored_frameworks = "zxx_data_collection_sdk.xcframework" 

#    core.resource_bundles = {
#      "#{s.name}" => ["#{s.name}/Resources/**/*"]
#    }
  end
end
