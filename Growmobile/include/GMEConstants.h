//
//  GMEConstants.h
//
//  Created by tal shahar on 11/6/14.
//  Copyright (c) 2014 tal shahar. All rights reserved.
//

static NSString* const kGmeEventUserDataKey = @"user_data";
static NSString* const kGmeDeepLinkKey = @"deep_link";
static NSString* const kGmeInAppMessageRootKey = @"iam";
static NSString* const kGmeInAppMessageInboxTriggerKey = @"inbox_trigger";
static NSString* const kGmeInAppMessageId = @"iam_id";

//in app message dictionary keys
static NSString* const kGmeInAppMessageImageUrl = @"image_url";
static NSString* const kGmeInAppMessageTitle = @"title";
static NSString* const kGmeInAppMessageSubtitle = @"sub_title";
static NSString* const kGmeInAppMessageButtons = @"buttons";

//name GME notification posted through NSNotificationCenter to report events with an in app message
//listen to this notification if you need to get notified in case an in app message is covering the screen or being dismissed
static NSString* const kGmeIamEventNotification = @"tbIamEventNotification";

//keys for dictionary passed with this notification
static NSString* const kGmeIamEvent = @"iam_event";
static NSString* const kGmeIamAction = @"iam_action";
static NSString* const kGmeIamDescription = @"iam_description";
static NSString* const kGmeIamLaunched = @"iam_launched";
static NSString* const kGmeIamExpired = @"iam_expired";
static NSString* const kGmeIamClosed = @"iam_closed";
static NSString* const kGmeIamDismissedCloseButton = @"dismiss";
static NSString* const kGmeIamDismissedTimeout = @"time out";

//roam
