//
//  SKYUnknownValue.h
//  SKYKit
//
//  Copyright 2015 Oursky Ltd.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import <Foundation/Foundation.h>

/**
 SKYUnknownValue indicates that the value is of unknown type to Skygear. This usually occurs
 when the database contains data that is not managed by Skygear.

 You should not instantiate an instance of this class.
 */
@interface SKYUnknownValue : NSObject <NSCoding>

/// Undocumented
- (instancetype)init NS_UNAVAILABLE;
/// Undocumented
- (instancetype)initWithUnderlyingType:(NSString *)underlyingType NS_DESIGNATED_INITIALIZER;

/// Undocumented
+ (instancetype)unknownValueWithUnderlyingType:(NSString *)underlyingType;

/// Undocumented
@property (nonatomic, readonly, copy) NSString *underlyingType;

@end
