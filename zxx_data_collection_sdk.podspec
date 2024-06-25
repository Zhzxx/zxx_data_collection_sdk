Pod::Spec.new do |s|
  s.name         = "zxx_data_collection_sdk"
  s.version      = "0.0.2.S"
  s.summary      = "zxx_data_collection_sdk的一个简单示范工程."

  s.description  = <<-DESC
                   zxx_data_collection_sdk的一个简单示范工程示范工程的长描述.
                   DESC

  s.homepage     = "https://github.com/Zhzxx/zxx_data_collection_sdk"
  s.license      = "MIT"
  s.author       = { "ZXX" => "zxxiosmail@163.com" }

  s.platform     = :ios, "12.0"
  s.ios.deployment_target = '12.0'

  s.source       = { :git => "git@github.com:Zhzxx/zxx_data_collection_sdk.git", :tag => "#{s.version}" }

#  s.swift_versions = ['5.0']

  s.user_target_xcconfig = {
#    'LIBRARY_SEARCH_PATHS' => '$(TOOLCHAIN_DIR)/usr/lib/swift/$(PLATFORM_NAME) $(TOOLCHAIN_DIR)/usr/lib/swift-5.0/$(PLATFORM_NAME)'
  }

  s.pod_target_xcconfig = {
    'GENERATE_INFOPLIST_FILE' => 'YES',
#    'SWIFT_INCLUDE_PATHS' => ["$(PODS_ROOT)/#{s.name}/src/oc", "$(PODS_TARGET_SRCROOT)/#{s.name}/src/oc"]
  }

  s.default_subspecs = 'Core'

  s.subspec 'Core' do |core|
#    core.dependency 'UMCommon', '1.4.3.P'
#    core.dependency 'UMDevice', '2.2.1'

    core.ios.deployment_target = '12.0'

    core.vendored_frameworks = 'zxx_data_collection_sdk.xcframework'

    core.pod_target_xcconfig = {
      'GENERATE_INFOPLIST_FILE' => 'YES',
      'IPHONEOS_DEPLOYMENT_TARGET' => '12.0'
    }
  end
end
