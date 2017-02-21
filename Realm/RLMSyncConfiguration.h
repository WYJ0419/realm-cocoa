////////////////////////////////////////////////////////////////////////////
//
// Copyright 2016 Realm Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
////////////////////////////////////////////////////////////////////////////

#import <Foundation/Foundation.h>

@class RLMSyncUser;

NS_ASSUME_NONNULL_BEGIN

/**
 A configuration object representing configuration state for a Realm which is intended to sync with a Realm Object
 Server.
 */
@interface RLMSyncConfiguration : NSObject

/// The user to which the remote Realm belongs.
@property (nonatomic, readonly) RLMSyncUser *user;

/**
 If YES, a Realm opened using this configuration will behave differently in a number of ways.

 If the Realm is opened synchronously on a background thread, the initializer will block
 until an initial set of changes have been downloaded and applied to the Realm.

 If the Realm is opened asynchronously, the callback will only run once an initial set of
 changes have been downloaded and applied to the Realm, or an error occurs.

 If the Realm is opened synchronously on the main thread, an exception will be thrown.
 */
@property (nonatomic) BOOL waitForServerChanges;

/**
 If `waitForServerChanges` is set, how long Realm should wait for a Realm to download before
 timing out. If this value is 0 or negative, it is ignored and a Realm download will never
 time out.

 If `waitForServerChanges` is not set, this property is ignored.
 */
@property (nonatomic) NSTimeInterval serverWaitTimeout;

/**
 The URL of the remote Realm upon the Realm Object Server.
 
 @warning The URL cannot end with `.realm`, `.realm.lock` or `.realm.management`.
 */
@property (nonatomic, readonly) NSURL *realmURL;

/**
 Create a sync configuration instance.

 @param user    A `RLMSyncUser` that owns the Realm at the given URL.
 @param url     The unresolved absolute URL to the Realm on the Realm Object Server, e.g.
                `realm://example.org/~/path/to/realm`. "Unresolved" means the path should
                contain the wildcard marker `~`, which will automatically be filled in with
                the user identity by the Realm Object Server.
 */
- (instancetype)initWithUser:(RLMSyncUser *)user realmURL:(NSURL *)url;

/// :nodoc:
- (instancetype)init __attribute__((unavailable("This type cannot be created directly")));

/// :nodoc:
+ (instancetype)new __attribute__((unavailable("This type cannot be created directly")));

@end

NS_ASSUME_NONNULL_END
