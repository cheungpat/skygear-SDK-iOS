//
//  ODContainer.h
//  askq
//
//  Created by Kenji Pa on 19/1/15.
//  Copyright (c) 2015 Rocky Chan. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ODDatabase.h"
#import "ODAccessToken.h"

@class ODUserRecordID;
@class ODOperation;

// keep it in sync with ODUserOperationActionCompletion
typedef void(^ODContainerUserOperationActionCompletion)(ODUserRecordID *user, NSError *error);

@interface ODContainer : NSObject

// seems we need a way to authenticate app
+(ODContainer *)defaultContainer;

@property (nonatomic, readonly) ODDatabase *publicCloudDatabase;
@property (nonatomic, readonly) ODDatabase *privateCloudDatabase;

@property (nonatomic, readonly) NSString *containerIdentifier;

@property (nonatomic, readonly) ODUserRecordID *currentUserRecordID;
@property (nonatomic, readonly) ODAccessToken *currentAccessToken;

- (void)addOperation:(ODOperation *)operation;

- (void)signupUserWithUsername:(NSString *)username password:(NSString *)password completionHandler:(ODContainerUserOperationActionCompletion)completionHandler;
- (void)loginUserWithUsername:(NSString *)username password:(NSString *)password completionHandler:(ODContainerUserOperationActionCompletion)completionHandler;
- (void)logoutUserWithcompletionHandler:(ODContainerUserOperationActionCompletion)completionHandler;

@end

@interface ODContainer (ODPushOperation)

- (void)pushToUserRecordID:(ODUserRecordID *)userRecordID alertBody:(NSString *)alertBody;
- (void)pushToUserRecordIDs:(NSArray *)userRecordIDs alertBody:(NSString *)alertBody;

- (void)pushToUserRecordID:(ODUserRecordID *)userRecordID alertLocalizationKey:(NSString *)alertLocalizationKey alertLocalizationArgs:(NSArray *)alertLocalizationArgs;
- (void)pushToUserRecordIDs:(NSArray *)userRecordIDs alertLocalizationKey:(NSString *)alertLocalizationKey alertLocalizationArgs:(NSArray *)alertLocalizationArgs;

@end