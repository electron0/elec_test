function updateImages()
	{
		if( bImageSwitch )
		{
			self.showImage(iImgIndex, oImgFrameA, oImgFrameB);
			// setTimeout(self.hideImage, iInterval/2, iImgIndex, oImgFrameB);
		}
		else
		{
			self.showImage(iImgIndex, oImgFrameB, oImgFrameA);
			// setTimeout(self.hideImage, iInterval/2, iImgIndex, oImgFrameA);
		}
		
		bImageSwitch = !bImageSwitch;
		
		// kopieren
		// z = 10
		// fadeIn
		// #and: z = 0
		// #and: hide
		
		// setTimeout(self.hideImage, iInterval*2, iImgIndex);
		
		++iImgIndex;
		if( iImgIndex >= self.arImages.length )
			iImgIndex = 0;
			
		
	};
	
	this.toggleAni = function()
	{
		if( bAni )
		{
			// stop
			
			bAni = false;
		}
		else
		{
			//start
			updateGUI( oImgFrameA, this.arImages[iImgIndex].title, this.arImages[iImgIndex].desc );
			
			// this.showImage(iImgIndex++, oImgFrameA);
			updateImages();
			
			trIntervalTimer = setInterval(updateImages, iInterval);
			bAni = true;
		}
		
		
		
	};
	
	function createGUI()
	{
		try
		{
			if(!document.getElementById("galleryStyle"))
			{
				addStyles();
			}
		}
		catch (e)
		{
			console.log("head not found");
		}

	};

	this.init = function(oProps)
	{
		// TODO: alle props auf vorhandensein checken
		iWidth = oProps.width;
		iHeight = oProps.height;
		bAspectRadio = oProps.aspectRadio;
		iInterval = oProps.slideInterval;
		
		if(!$)
			alert("jQuery not found");
		
		oImgFrameA = new ImgContainer();
		oImgFrameB = new ImgContainer();
		
		oGalleryObj.appendChild(oImgFrameA);
		oGalleryObj.appendChild(oImgFrameB);
		
		
		createGUI();
	};
	this.hide = function( index, frm )
	{
		
		
		// frm.img = self.arImages[index].img;
		
		$(frm).hide();
		
		frm.removeChild(frm.img);
		frm.appendChild(self.arImages[index].img);
		frm.img = self.arImages[index].img;
		updateGUI(frm, self.arImages[index].title, self.arImages[index].desc);
		
		
		
		// $(self.arImages[index].imgFrm).css("z-index", 0);
		// $(self.arImages[index].imgFrm).hide();
		
		console.log("hide: index: " + index);
	};