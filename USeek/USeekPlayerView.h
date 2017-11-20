//
//  USeekPlayerView.h
//  Pods
//
//  Created by Chris Lin on 7/19/17.
//  Copyright © 2017 USeek. All rights reserved.
//

#import <UIKit/UIKit.h>

@class USeekPlayerView;

/**
 *
 * The USeekPlayerViewDelegate protocol provides a mechanism for your application to take
 * action on events that occur in the USeekWebView. You can make use of these calls by
 * assigning an object to the USeekPlayerView's delegate property directly.
 *
 */
@protocol USeekPlayerViewDelegate <NSObject>

@optional

/**
 *
 * Called when USeekPlayerView starts loading the video.
 *
 * @param playerView        The USeekPlayerView object which initiated this event.
 *
 */
- (void) useekPlayerViewDidStartLoad: (USeekPlayerView *) playerView;

/**
 *
 * Called when USeekPlayerView finished loading the video.
 *
 * @param playerView        The USeekPlayerView object which initiated this event.
 *
 */
- (void) useekPlayerViewDidFinishLoad: (USeekPlayerView *) playerView;

/**
 *
 * Called when USeekPlayerView detected an error while loading the video.
 *
 * @param playerView        The USeekPlayerView object which initiated this event.
 * @param error             The NSError object with error information.
 *
 */
- (void) useekPlayerView: (USeekPlayerView *) playerView didFailWithError: (NSError *) error;

@end

/**
 *
 * This class inherits UIView, which you can easily drop in storyboard or create anywhere in your code.
 *
 * There are 2 ways to use USeekPlayerView.
 *
 * - Add as a subview programmatically
 *
 *      ```objective-c
 *      USeekPlayerView *playerView = [[USeekPlayerView alloc] initWithFrame:CGRectMake(0, 0, 100, 60)];
 *      [self.view addSubview:playerView];
 *      ```
 *
 * - Add in storyboard
 *
 * Just change the class name of the view to USeekPlayerView in storyboard.
 * Now you can add the view as IBOutlet and use.
 *
 */
@interface USeekPlayerView : UIView

/**
 *
 * IBOutlet for the loading label.
 * By using this label, you can customize the loading text, color and fonts.
 *
 */
@property (weak, nonatomic) IBOutlet UILabel *loadingTitleLabel;

/**
 *
 * Validates the configuration.
 * If any of publisher id or game id is not set, validation fails.
 *
 */
- (BOOL) validateConfiguration;

/**
 *
 * Starts loading the video in UIWebView instance.
 *
 * - Precondition: Publisher ID should be set.
 *
 * @param gameId      unique game id provided by USeek, not nullable.
 * @param userId      user's unque id registered in USeek, nullable.
 *
 */
- (void) loadVideoWithGameId: (NSString *) gameId UserId: (NSString *) userId;

/**
 *
 * The delegate can be used to handle the events occured while playing video.
 *
 */
@property (weak, nonatomic) id<USeekPlayerViewDelegate> delegate;

@end
