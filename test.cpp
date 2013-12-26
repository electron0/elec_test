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
	
	function addStyles()
	{
		var oStyleSheet = document.createElement("style");
		oStyleSheet.setAttribute("id", "galleryStyle");
		// TODO: type auf css setzten
		// oStyleSheet.innerHTML += ".gallery {background: none repeat scroll 0 0 #333333;height: 200px;width: 300px;}";
		
		oStyleSheet.innerHTML += ".gallery {height: " + iHeight + "px; width: " + iWidth + "px;}";
		// oStyleSheet.innerHTML += ".gallery .picdesc {width: " + (iWidth-30) + "px;}";
		
		document.getElementsByTagName("head")[0].appendChild(oStyleSheet);
	};
	
	function updateGUI( frm, sTitle, sDesc )
	{
		frm.desc.updateTitle(sTitle);
		frm.desc.updateDesc(sDesc);
	};